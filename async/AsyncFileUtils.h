#ifndef Async_File_Utils_H
#define Async_File_Utils_H

#include "cocos2d.h"

#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <string>
#include <unordered_map>

#define GAEM_NAME_SPACE_BEGIN namespace game{
#define GAME_NAME_SPACE_END	  }


GAEM_NAME_SPACE_BEGIN
class AsyncFileUtils :public cocos2d::Ref{
public:
	
	static AsyncFileUtils* getInstance();
	static void destoryInstance();

	AsyncFileUtils();
	virtual ~AsyncFileUtils();

public:
	struct AsyncStruct
	{
	public:
		AsyncStruct(const std::string& fn, const std::function<void(const cocos2d::Data&)> f) : filename(fn) {
			emplace_back(f);
		}

		std::string filename;
		std::vector<std::function<void(const cocos2d::Data&)>> callbacks;

		void emplace_back(const std::function<void(const cocos2d::Data&)>& func)
		{
			callbacks.emplace_back(func);
		}

		cocos2d::Data data;
	};

	void loadDataAsync(const std::string &filepath, const std::function<void(const cocos2d::Data&)>& callback);
	void cancelLoadDataAsync(const std::string& filePath);
private:
	void loadData();
	void loadDataAsyncCallBack(float dt);
private:
	static AsyncFileUtils* instance;

	std::deque<AsyncStruct*> _asyncStructQueue;
	std::deque<AsyncStruct*> _requestQueue;
	std::deque<AsyncStruct*> _responseQueue;

	std::mutex _requestMutex;
	std::mutex _responseMutex;

	std::condition_variable _sleepCondition;

	bool _needQuit;
	int _asyncRefCount;
	std::thread* _loadingThread;
};
GAME_NAME_SPACE_END

#endif