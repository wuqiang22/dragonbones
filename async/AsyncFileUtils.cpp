#include "async/AsyncFileUtils.h"
#include "CCFileUtils.h"


GAEM_NAME_SPACE_BEGIN

AsyncFileUtils* AsyncFileUtils::instance = nullptr;

AsyncFileUtils* AsyncFileUtils::getInstance()
{
	if (instance == nullptr)
	{
		instance = new AsyncFileUtils();
	}

	return instance;
}

void AsyncFileUtils::destoryInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

AsyncFileUtils::AsyncFileUtils() :_loadingThread(nullptr), _asyncRefCount(0), _needQuit(false){}

AsyncFileUtils::~AsyncFileUtils(){
	CC_SAFE_DELETE(_loadingThread);
}

void AsyncFileUtils::loadDataAsync(const std::string &filepath, const std::function<void(const cocos2d::Data&)>& callback)
{
	std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename(filepath);
	if (fullpath.empty() || !cocos2d::FileUtils::getInstance()->isFileExist(fullpath)) {
		if (callback) callback(cocos2d::Data());
		return;
	}
	if (_loadingThread == nullptr)
	{
		// create a new thread to load images
		_loadingThread = new (std::nothrow) std::thread(&AsyncFileUtils::loadData, this);
		_needQuit = false;
	}
	if (0 == _asyncRefCount)
	{
		cocos2d::Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(AsyncFileUtils::loadDataAsyncCallBack), this, 0, false);
	}
	++_asyncRefCount;
	bool exist = false;
	for (auto iter : _asyncStructQueue)
	{
		if (iter->filename == fullpath)
		{
			iter->emplace_back(callback);
			exist = true;
			break;
		}
	}
	if (!exist)
	{
		AsyncStruct *data = new (std::nothrow) AsyncStruct(fullpath, callback);
		_asyncStructQueue.push_back(data);
		_requestMutex.lock();
		_requestQueue.push_back(data);
		_requestMutex.unlock();
	}

	_sleepCondition.notify_one();
}


void AsyncFileUtils::loadData()
{
	AsyncStruct *asyncStruct = nullptr;
	std::mutex signalMutex;
	std::unique_lock<std::mutex> signal(signalMutex);
	while (!_needQuit)
	{
		// pop an AsyncStruct from request queue
		_requestMutex.lock();
		if (_requestQueue.empty())
		{
			asyncStruct = nullptr;
		}
		else
		{
			asyncStruct = _requestQueue.front();
			_requestQueue.pop_front();
		}
		_requestMutex.unlock();

		if (nullptr == asyncStruct) {
			_sleepCondition.wait(signal);
			continue;
		}

		asyncStruct->data = cocos2d::FileUtils::getInstance()->getDataFromFile(asyncStruct->filename);

		// push the asyncStruct to response queue
		_responseMutex.lock();
		_responseQueue.push_back(asyncStruct);
		_responseMutex.unlock();
	}
}


void AsyncFileUtils::loadDataAsyncCallBack(float dt)
{
	AsyncStruct *asyncStruct = nullptr;
	while (true)
	{
		// pop an AsyncStruct from response queue
		_responseMutex.lock();
		if (_responseQueue.empty())
		{
			asyncStruct = nullptr;
		}
		else
		{
			asyncStruct = _responseQueue.front();
			_responseQueue.pop_front();

			// the asyncStruct's sequence order in _asyncStructQueue must equal to the order in _responseQueue
			CC_ASSERT(asyncStruct == _asyncStructQueue.front());
			_asyncStructQueue.pop_front();
		}
		_responseMutex.unlock();

		if (nullptr == asyncStruct) {
			break;
		}
	
		if (asyncStruct->data.getSize() > 0)
		{
			for (auto& callback : asyncStruct->callbacks)
			{
				callback(asyncStruct->data);
			}
		}

		// release the asyncStruct
		delete asyncStruct;
		--_asyncRefCount;
	}

	if (0 == _asyncRefCount)
	{
		cocos2d::Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(AsyncFileUtils::loadDataAsyncCallBack), this);
	}
}


void AsyncFileUtils::cancelLoadDataAsync(const std::string& filePath)
{
	const std::string& fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(filePath);

	for (auto iter : _asyncStructQueue)
	{
		if (iter->filename == fullPath)
		{
			iter->callbacks.clear();
		}
	}

}

GAME_NAME_SPACE_END