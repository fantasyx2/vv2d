import("uis.GenUiUtil")
local ALayer = import(".ALayer")
local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)

function MainScene:ctor()
	--self:tstGenUi()
	--self:tstJson()
	--self:tstShader()
	self:tstJz()
	--self:tstTween()
	--self:tstSpine()
	--self:tstCCS()
	--self:tstScrollview()
	--self:tstListview()
end

function MainScene:onEnter()
end

function MainScene:onExit()
end

function MainScene:initUi()
end

function MainScene:tstListview()
	local timer = require("framework.scheduler")	
	local ListView = require("uis.listview.ListView")
	local ListViewCell = require("uis.listview.ListViewCell")
	local nd = ListView.new(CCRect:new(0,0,150,200),2,true)
	local cell1 = ListViewCell.new(CCSize(100,200));
	local sp1 = display.newSprite("UI/crit.png");
		  sp1:setAnchorPoint(ccp(0,0))
		  cell1:addChild(sp1)
	local cell2 = ListViewCell.new(CCSize(100,200));	
	local sp2 = display.newSprite("UI/god.png")
		  sp2:setAnchorPoint(ccp(0,0))
		  cell2:addChild(sp2)
	nd:addCells({cell1,cell2})
	nd:setPosition(50, 50)
	self:addChild(nd)
	nd:setTouchEnabled(true)
	timer.performWithDelayGlobal(function() print("llllllll") nd:skipToCellIfNeed(1) end,2.0)
end

function MainScene:tstScrollview()
	local ScrollView = require("uis.listview.ScrollView")
	local nd = ScrollView.new(CCRect:new(0,0,200,200),2,true)
	local sp1 = display.newSprite("UI/cpt_bg_01.png")	
	local sp2 = display.newSprite("UI/god.png")
	sp2:addTo(sp1, 0, 100)
	print("sp2===tag",sp2:getTag())
	sp2:pos(640, 310)
	nd:setContainer(sp1)
	nd:setPosition(50, 50)
	self:addChild(nd)
	nd:setTouchEnabled(true)
end

function MainScene:tstCCS()
	--ccsload.createNode("test.json")
	local r = ccsload.createNode("MainScene.json")
	if(r and r.node) then
		r.node:setPosition(0, 0)
		self:addChild(r.node,10);
	end
end

function MainScene:tstJson()
	local str = get_file_data("test.json")
	if(str) then
		print("test.json len",string.len(str),json.decode(str))
	end	
end

function MainScene:tstGenUi()
	local al = ALayer:new()
	self:addChild(al)
end
function MainScene:tstShader()
	local bg = display.newColorLayer(cc.c4b(0, 128, 128,255))
	self:addChild(bg)
	--local spp = GenUiUtil.genJpgMaskSp("hero1014.jpg","hero1014a.jpg","UI/")
	local spp = CCShaderSprite:create("UI/pig.jpg")	
	--spp:setSdf4(1,0.5,0.1,0.9,1.0)
	spp:setScale(0.2)
	local w = spp:getContentSize().width
	local h = spp:getContentSize().height
	print("tstShader---",w,h)
	spp:setQuadVertex(0,h, w,h, 0,0, w,0)
	spp:setPosition(display.cx,display.cy)
	self:addChild(spp)

	local act = CCActionTween:create(1.0,"look",5,20,function(v,key)
		local t=v
		local a,b,c,d = math.random(-t,t),math.random(-t,t),math.random(-t,t),math.random(-t,t)
		local i,j,k,l = math.random(-t,t),math.random(-t,t),math.random(-t,t),math.random(-t,t)
		spp:setQuadVertex(0+a,h+b, w+c,h+d, 0+i,0+j, w+k,0+l)
	end)
	spp:runAction(CCRepeatForever:create(act))

	spp:runAction(CCScaleTo:create(0.3,0.6,0.6))

	cc(spp):addComponent("components.ui.DraggableProtocol")
        :exportMethods()
        :setDraggableEnable(true)
end
function MainScene:tstJz()
	local spp = CCShaderSprite:create("UI/cpt_bg_01.png")
	GenUiUtil.runJzEffect(spp,2.0,1,64,6,false,function (...)
		print("tstJzAnim over")
		GenUiUtil.runJzEffect(spp,1.0,1,64,12,true)
	end)
	spp:setSdf(4,1.0)
	spp:setPosition(display.cx,display.cy)
	self:addChild(spp)
end

function MainScene:tstTween()
	local act = CCActionTween:create(1.0,"look",100,200,function(v,key)
		print("CCActionTween",v,key)
	end)
	local act2 = CCActionTween:create(1.0,"good",100,200,function(v,key)
		print("CCActionTween2",v,key)
	end) 
	local ac = transition.sequence({
		act,act2
		})
	self:runAction(ac)
end

function MainScene:tstSpine()
	local skeletonNode = SkeletonAnimation:createWithFile("data/spineboy.json", "data/spineboy.atlas", 0.3)
	dump(SkeletonRenderer)

	skeletonNode:setMix("walk", "jump", 0.2);
	skeletonNode:setMix("jump", "run", 0.2);
	skeletonNode:setAnimation(0, "walk", true);
	local jumpEntry = skeletonNode:addAnimation(0, "jump", false, 3);
	skeletonNode:addAnimation(0, "run", true);
	skeletonNode:setPosition(display.width / 2, 20);
	self:addChild(skeletonNode);
	skeletonNode:setScriptHandlerForAnima(function(name,trackidx,tp,evt,loopct)
		print(name,trackidx,tp,evt.data.name,loopct)
	end)
	skeletonNode:setScriptHandlerForTrack(function(name,trackidx,tp,evt,loopct)
		print(name,trackidx,tp,evt.data.name,loopct)
	end)
end
return MainScene
