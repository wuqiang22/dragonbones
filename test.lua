local function testAsynFileUtils(scene)

  local dragonBonesName = "DragonBoy"
  local textureAtlasName = "DragonBoy"
  local armatueName = "dragonBoy"
  local dragonBonesFile = "dragonbones/DragonBoy/skeleton.xml"
  local textureAtalsFile = "dragonbones/DragonBoy/texture.xml"
  db.DragonBonesAsyncUtil:getInstance():buildArmatureNode(dragonBonesFile,dragonBonesName,textureAtalsFile,textureAtlasName,armatueName,function(dbArmatureNode)
      scene:addChild(dbArmatureNode)
      local size = cc.Director:getInstance():getWinSize()
      dbArmatureNode:setPosition(cc.p(size.width/2,size.height/4))
      dbArmatureNode:getAnimation():play()
  end)

end