import("uis.GenUiUtil")
local ALayer = import(".ALayer")
local TestScene = class("TestScene", function()
    return display.newScene("TestScene")
end)

function TestScene:ctor()
	local listconfig=
	{		
		{"tstScrollview",	handler(self,self.tstScrollview)},
		{"tstListview",		handler(self,self.tstListview)},
		{"tstPageview",		handler(self,self.tstPageview)},
		{"tstTiled",		handler(self,self.tstTiled)},
		{"tstMesh",			handler(self,self.tstMesh)},
		{"tstTween",		handler(self,self.tstTween)},		
		{"tstJson",			handler(self,self.tstJson)},
		{"tstShader",		handler(self,self.tstShader)},
		{"tstJz",			handler(self,self.tstJz)},
		{"tstCCS",			handler(self,self.tstCCS)},
		{"tstSpine",		handler(self,self.tstSpine)},
		{"tstGenUi",		handler(self,self.tstGenUi)},
	}
	self.TND = display.newNode()
	self.TND:setPosition(0, 0)
	self.TND:setTouchEnabled(true)
	self:addChild(self.TND, 2)
	local ListView = require("uis.listview.ListView")
	local ListViewCell = require("uis.listview.ListViewCell")
	local CellBtn = require("uis.listview.CellButton")
	local list = ListView.new(CCRect:new(0,0,display.width-100,display.height-200),1,true)
	local cells={}
	local cell_w = display.width-100
	local cell_h = 100
	for i,v in pairs(listconfig) do
		local cell = ListViewCell.new(CCSize(cell_w,cell_h),i)
		local bg = CCDrawNode:create()
		local points={}
	    points[1] = {0,0}
	    points[2] = {0,cell_h}
	    points[3] = {cell_w,cell_h}
	    points[4] = {cell_w,0}	   
		bg:drawPolygon(points,
                        {   
                            fillColor = cc.c4f(1,1,1,0.5),
                            borderWidth =   2,
                            borderColor =   cc.c4f(1,1,1,0.5)
                        }
                    )
		cell:addChild(bg)
		-------------------------------
		local color=ccc3(255,0,0)
		local outline = ccc3(0, 255, 0)
    	local label = CCLabelTTF:create(v[1],CFG_SYSTEM_FONT,48)    
    	label:setColor(color)
    	label:enableStroke(outline, 4)
    	cell:addChild(label) 
    	label:setAnchorPoint(ccp(0,0.5))
    	label:setPosition(20, cell_h/2)
    	-------------------------------
		cell:addEventListener("onCellTap",
			function(evt)
				print("cell-onCellTap",evt.id)
				listconfig[evt.id][2]()
			end
		)
		table.insert(cells,cell)
	end
	list:addCells(cells)
	list:setPosition(50, 100)
	self:addChild(list)
	list:setTouchEnabled(true)
	list:setCellAlign(0.8)	
end

function TestScene:onEnter()
end

function TestScene:onExit()
end

function TestScene:initUi()
end

function TestScene:addTestNd(nd,notrm)
	if(not notrm) then
		self.TND:removeAllChildren()
	end
	self.TND:addChild(nd)
end
function TestScene:cleanTestNd()
	self.TND:removeAllChildren()
end

function TestScene:initForMap()
	if(not self.initformap) then
		self.initformap=true
		local nd = display.newNode()
		nd:setPosition(0, 0)
		nd:setContentSize(CCSize(640,640))
		self:addTestNd(nd,true)
		self.pf=false
		self.px=0
		self.py=0
		self.ex=0
		self.ey=0
		nd:setTouchEnabled(true)
	    nd:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
	        if(event.name == 'began') then
	        	self.pf=true
	        	self.px = event.x
	        	self.py = event.y
	        	return true
	        end
	        if(not self.pf) then
	        	return
	        end	
	        if(event.name == 'moved' and self.pf) then 
	            self.ex = event.x
	        	self.ey = event.y
	        	local xx = math.floor(self.ex/90) - math.floor(self.px/90)
	        	local yy = math.floor(self.ey/90) - math.floor(self.py/90)
	        	if(xx~=0) then
	        		self:tstTiledSwap(self.px,self.py,self.ex,self.py)
	        		self.pf=false 	 	
	        	elseif(yy~=0) then
	        		self:tstTiledSwap(self.px,self.py,self.px,self.ey)
	        		self.pf=false
	        	end	
	        elseif event.name == "ended" or event.name == "cancelled" then
	        	local x,y=math.floor(event.x),math.floor(event.y)
	            self:tstTiledClick(x,y)            
	        end
	        return true
	    end)
	end
end

function TestScene:tstTiledSwap(a,b,c,d)
	local layer = self.map:getLayerByName('surface')
	-- layer:swapAtGid(a,b)
	layer:swapAt(a,b,c,d)
end
function TestScene:tstTiledClick(x,y)
	local layer = self.map:getLayerByName('surface')
	layer:setTileAt(math.random(1,126),x,y,true)
	local spt,tid  = layer:getTileAt(x,y)
	-- print(spt)
	-- print(tid)
	if(spt and tid) then
		-- print(spt)
		spt:runAction(
			transition.sequence(
				{
					CCRotateBy:create(1.0,720),
					CCScaleTo:create(0.2,0.0),
					CCScaleTo:create(0.2,1.0),
					-- CCMoveBy:create(0.2,ccp(100,100)),
					-- CCMoveBy:create(0.2,ccp(-100,-100)),
					-- CCCallFunc:create(function()
					-- 		layer:setTileGID(math.random(1,126),x,y)
					-- 	end),				
				}
			)
		)
		
	end
	-- batchnd:setTileGID()
	-- batchnd:setTileGID()
end

function TestScene:tstTiled()
	local map= tiledload.load("fruits.lua",true)
	if(map) then
		self:cleanTestNd()
		self:initForMap()
		for _,v in pairs(map.nodes) do
			self:addTestNd(v.root,true)
		end
		self.map=map
		dump(map,"map",1)
		dump(map:getRootByName('surface'),"root",1)
		dump(map:getLayerByName('surface'),"layer",1)
		dump(map:getObjectInfo("ground",5),"objinfo",1)
		dump(map:getObjectPropertys("ground",5),"objpro",1)
		dump(map:getTiledInfo(10),'tileinfo',1)
		dump(map:getTiledInfoByType('surface_02_04'))			
	end
end

function TestScene:tstMesh()
	local spp = CCShaderSprite:create("UI/cpt_bg_02.png")
	spp:setAnchorPoint(ccp(0,0))
	spp:setPosition(display.cx,display.cy)
	-- spp:initVerticesWithRegex(
	-- 	gl.GL_TRIANGLE_STRIP,
	-- 	"-50,50,0,0.5|-100,-50,0,0|100,100,1,1|100,-100,1,0,255,255,0,255",
	-- 	"[^\\|]{1,}\\|{0,1}",
	-- 	"[\\d\\.\\-]{1,}"
	-- 	)
	print(gl.GL_TRIANGLE_STRIP)
	print(spp)
	spp:initVertices(
		gl.GL_TRIANGLE_STRIP,
		"-50,50,0,0.5,255,0,0,255|-100,-50,0,0|100,100,1,1|100,-100,1,0,255,255,0,255"
		)
	self:addTestNd(spp)

	local spp = CCShaderSprite:create("UI/xishouA.png")
	spp:setAnchorPoint(ccp(0,0))
	spp:setScale(1.0)
	spp:setFlipX(true)
	spp:setPosition(display.cx,display.cy+200)
	spp:initVertices(gl.GL_TRIANGLE_FAN,"0,0,0.5,0.5|-100,100,0,1|-100,-100,0,0|100,-100,1,0|100,100,1,1|-100,100,0,1")
	-- spp:initVertices(gl.GL_TRIANGLE_STRIP,"-100,50,0,1|-100,-50,0,0|100,100,1,1|100,-100,1,0")
	-- spp:initVertices(gl.GL_QUADS,"-100,50,0,1|-100,-100,0,0|100,-100,1,0|100,100,1,1")
	-- spp:initVertices(gl.GL_TRIANGLE_STRIP,"100,100,1,1|100,50,1,0.7|-100,50,0,1|100,-50,1,0.3|-100,-50,0,0|100,-100,1,0")
	self:addTestNd(spp,true)
	--spp:runAction(CCRotateBy:create(10.0,720))
end

function TestScene:tstPageview()
	local timer = require("framework.scheduler")	
	local PageView = require("uis.listview.PageView")
	local ListViewCell = require("uis.listview.ListViewCell")
	local CellBtn = require("uis.listview.CellButton")
	local nd = PageView.new(CCRect:new(0,0,200,200),1,true)
	
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
	nd:setPosition(100, 100)
	nd:ignoreAnchorPointForPosition(false)
	nd:setAnchorPoint(ccp(0.5,0.5))
	self:addTestNd(nd)
	nd:setTouchEnabled(true)
	nd:setCellAlign(0.0)
	--timer.performWithDelayGlobal(function() print("llllllll") nd:skipToCellIfNeed(5,0) end,2.0)
end

function TestScene:tstListview()
	local timer = require("framework.scheduler")	
	local ListView = require("uis.listview.ListView")
	local ListViewCell = require("uis.listview.ListViewCell")
	local CellBtn = require("uis.listview.CellButton")
	local nd = ListView.new(CCRect:new(0,0,120,200),1,true)
	
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
	nd:setPosition(200, 200)
	self:addTestNd(nd)
	nd:setTouchEnabled(true)
	nd:setCellAlign(0.8)
	timer.performWithDelayGlobal(function() print("llllllll") nd:skipToCellIfNeed(5,0) end,2.0)
end

function TestScene:tstScrollview()
	local ScrollView = require("uis.listview.ScrollView")
	local nd = ScrollView.new(CCRect:new(0,0,200,200),2,true)
	local sp1 = display.newSprite("UI/cpt_bg_01.png")	
	local sp2 = display.newSprite("UI/god.png")
	sp2:addTo(sp1, 0, 100)	
	print("sp2===tag",sp2:getTag())
	sp2:pos(640, 310)
	nd:setContainer(sp1)
	nd:setPosition(300, 400)
	self:addTestNd(nd)
	nd:setTouchEnabled(true)
end

function TestScene:tstCCS()
	--ccsload.createNode("test.json")
	local r = ccsload.createNode("TestScene.json")
	if(r and r.node) then
		r.node:setPosition(0, 0)
		self:addTestNd(r.node,10);
	end
end

function TestScene:tstJson()
	local str = get_file_data("test.json")
	if(str) then
		print("test.json len",string.len(str),json.decode(str))
	end	
end

function TestScene:tstGenUi()
	local al = ALayer:new()
	self:addTestNd(al)
end
function TestScene:tstShader()
	local spp = GenUiUtil.genJpgMaskSp("hero1014.jpg","hero1014a.jpg","UI/")
	spp:setSdf4(1,0.5,0.1,0.9,1.0)
	spp:setScale(0.5)
	spp:setPosition(display.cx,display.cy)
	self:addTestNd(spp)
end
function TestScene:tstJz()
	local spp = CCShaderSprite:create("UI/cpt_bg_01.png")
	GenUiUtil.runJzEffect(spp,1,64,6,false,function (...)
		print("tstJzAnim over")
		GenUiUtil.runJzEffect(spp,1,64,12,true,function (...)
			self:cleanTestNd()
		end)
	end)
	spp:setSdf(4,1.0)
	spp:setPosition(display.cx,display.cy)
	self:addTestNd(spp)
end

function TestScene:tstTween()
	local act = CCActionTween:create(1.0,"look",100,200,function(v,key)
		print("CCActionTween",v,key)
	end)
	self:runAction(act)
end

function TestScene:tstSpine()
	local skeletonNode = SkeletonAnimation:createWithFile("data/spineboy.json", "data/spineboy.atlas", 0.3)
	dump(SkeletonRenderer)

	skeletonNode:setMix("walk", "jump", 0.2);
	skeletonNode:setMix("jump", "run", 0.2);
	skeletonNode:setAnimation(0, "walk", true);
	local jumpEntry = skeletonNode:addAnimation(0, "jump", false, 3);
	skeletonNode:addAnimation(0, "run", true);
	skeletonNode:setPosition(display.width / 2, 20);
	self:addTestNd(skeletonNode);
	skeletonNode:setScriptHandlerForAnima(function(name,trackidx,tp,evt,loopct)
		print(name,trackidx,tp,evt.data.name,loopct)
	end)
	skeletonNode:setScriptHandlerForTrack(function(name,trackidx,tp,evt,loopct)
		print(name,trackidx,tp,evt.data.name,loopct)
	end)
end
return TestScene