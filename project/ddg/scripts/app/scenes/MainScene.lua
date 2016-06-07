import("uis.GenUiUtil")
local ALayer = import(".ALayer")
local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)

function MainScene:ctor()
	-- self:tstGenUi()
	-- self:tstJson()
	-- self:tstShader()
	-- self:tstJz()
	-- self:tstTween()
	-- self:tstSpine()
	-- self:tstCCS()
	self:tstScrollview()
	-- self:tstListview()
	-- self:tstPageview()
	-- local i=0
	-- for i=1,2000 do
	-- 	local x = math.random(20,600)
	-- 	local y = math.random(100,700)
	-- 	local sp = display.newSprite("UI/crit.png")
	-- 	self:addChild(sp, 0)
	-- 	sp:setPosition(x, y)
	-- end

end

function MainScene:onEnter()
end

function MainScene:onExit()
end

function MainScene:initUi()
end

function MainScene:tstPageview()
	local timer = require("framework.scheduler")	
	local PageView = require("uis.listview.PageView")
	local ListViewCell = require("uis.listview.ListViewCell")
	local CellBtn = require("uis.listview.CellButton")
	local nd = PageView.new(CCRect:new(0,0,200,200),2,true)
	
	local tb={
		"UI/crit.png",
		"UI/god.png",
		"UI/missA.png",
		"UI/missB.png",		
		"UI/xishouA.png",
		"UI/xishouB.png",
	}
	local cells={}
	for i,v in pairs(tb) do
		local cell = ListViewCell.new(CCSize(200,200))
		local bg = CCDrawNode:create()
		local points={}
	    points[1] = {0,0}
	    points[2] = {0,200}
	    points[3] = {200,200}
	    points[4] = {200,0}	   
		bg:drawPolygon(points,
                        {   
                            fillColor = cc.c4f(1,1,1,0.5),
                            borderWidth =   1,
                            borderColor =   cc.c4f(1,1,1,0.5)
                        }
                    )        
		local cellbtn = CellBtn.new(
				{
				    normal  = tb[i],
				}
			)
		bg:setAnchorPoint(ccp(0,0))
		bg:setPosition(0, 0)
		cell:addChild(bg)
		cellbtn:setAnchorPoint(ccp(0.5,0.5))
		cellbtn:setPosition(100, 100)
		cellbtn:setPressAnima(true)
		cell:addNode(cellbtn)
		table.insert(cells,cell)
	end
	nd:addCells(cells)
	nd:setPosition(320/2, 480/2)
	nd:ignoreAnchorPointForPosition(false)
	nd:setAnchorPoint(ccp(0.5,0.5))
	self:addChild(nd)
	nd:setTouchEnabled(true)
	nd:setCellAlign(0.0)
	--timer.performWithDelayGlobal(function() print("llllllll") nd:skipToCellIfNeed(5,0) end,2.0)
end

function MainScene:tstListview()
	local timer = require("framework.scheduler")	
	local ListView = require("uis.listview.ListView")
	local ListViewCell = require("uis.listview.ListViewCell")
	local CellBtn = require("uis.listview.CellButton")
	local nd = ListView.new(CCRect:new(0,0,200,180),1,true)
	
	local tb={
		"UI/crit.png",
		"UI/god.png",
		"UI/missA.png",
		"UI/missB.png",		
		"UI/xishouA.png",
		"UI/xishouB.png",

		"UI/crit.png",
		"UI/god.png",
		"UI/missA.png",
		"UI/missB.png",		
		"UI/xishouA.png",
		"UI/xishouB.png",

		"UI/crit.png",
		"UI/god.png",
		"UI/missA.png",
		"UI/missB.png",		
		"UI/xishouA.png",
		"UI/xishouB.png",

		"UI/crit.png",
		"UI/god.png",
		"UI/missA.png",
		"UI/missB.png",		
		"UI/xishouA.png",
		"UI/xishouB.png",
	}
	local cells={}
	for i,v in pairs(tb) do
		local cell = ListViewCell.new(CCSize(120,80))
		local bg = CCDrawNode:create()
		local points={}
	    points[1] = {0,0}
	    points[2] = {0,80}
	    points[3] = {120,80}
	    points[4] = {120,0}	   
		bg:drawPolygon(points,
                        {   
                            fillColor = cc.c4f(1,1,1,0.5),
                            borderWidth =   1,
                            borderColor =   cc.c4f(1,1,1,0.5)
                        }
                    )
		local cellbtn = CellBtn.new(
				{
				    normal  = tb[i],
				}
			)
		bg:setAnchorPoint(ccp(0,0))
		bg:setPosition(0, 0)
		cell:addChild(bg)
		cellbtn:setAnchorPoint(ccp(0.5,0.5))
		cellbtn:setPosition(60, 40)
		cellbtn:setPressAnima(true)
		cell:addNode(cellbtn)
		table.insert(cells,cell)
	end
	nd:addCells(cells)
	nd:setPosition(50, 50)
	self:addChild(nd)
	nd:setTouchEnabled(true)
	nd:setCellAlign(0.8)
	timer.performWithDelayGlobal(function() print("llllllll") nd:skipToCellIfNeed(5,0) end,2.0)
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
