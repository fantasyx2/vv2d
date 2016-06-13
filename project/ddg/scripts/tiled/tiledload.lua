local M={}
--------------------------------------
--------------------------------------
M.__index=M
function M:getObjectByName(tag)
end
function M:getLayerByName(name)
	return self.nodes[name]
end
--格子元素属性
function M:getGirdInfo(id)
	return self.girdinfo[id]
end
--对象属性
function M:getObjectInfo(name)
end
--------------------------------------
local function unzip(data)
	local tb={}
	local str = unzip_decode_str(data) or ""
	for i=1,string.len(str),4 do
		local __,__v= string.unpack(str,"<I",i)
		-- print(math.ceil(i/4).."=="..__v)
		tb[math.ceil(i/4)] = __v
	end
	return tb
end
local function gen(T)
	local r={}
	local nodes={}
	local girdrect={}
	local girdinfo={}
	--r.data = T
	r.nodes=nodes
	r.girdrect=girdrect
	r.girdinfo=girdinfo
	-- r.objects={}
	-- r.tiles={}

	local tw = T.tilewidth
	local th = T.tileheight
	local gw = T.width
	local gh = T.height
	local w = tw*gw
	local h = th*gh
	--unzip for tilelayer
	--gid for objectgroup
	for _,v in pairs(T.layers) do
		if(v.type=='tilelayer') then
			if(type(v.data)=='string') then
				v.data =  unzip(v.data)
			end
		elseif(v.type=='objectgroup') then
			for _,vv in pairs(v.objects) do
				if(vv.x>w or vv.x<0 or vv.y>h or vv.y<0) then
					vv.gid = 0
				else	
					local x = math.ceil(vv.x/tw)
					local y = math.floor(vv.y/th)
					vv.gid = x + y*gw
				end
			end
		end
	end
	--modify tilesets
	for _,v in pairs(T.tilesets) do
		v.endgid = v.firstgid+v.tilecount-1
		--only one grid tiles empty
		local tw = v.tilewidth
		local th = v.tileheight
		local iw = v.imagewidth
		local ih = v.imageheight
		local mar = v.margin
		local spc = v.spacing
		local gw =  math.floor((iw-mar)/(tw+mar))
		local gh =  math.floor((ih-spc)/(th+spc))
		v.gw = gw
		v.hg = gh
		for i,vv in ipairs(v.tiles) do
			vv.x = mar + math.mod(i-1,gw)*(tw+mar)
			vv.y = math.floor((i-1)/gw)*(th+spc)
			--vv.y = ih - vv.y
			--add gird rect 
			girdrect[vv.id+v.firstgid] = {x=vv.x,y=vv.y,w=tw,h=th}
			girdinfo[vv.id+v.firstgid] = vv.properties
		end
	end
	-- dump(r.gird)
	-- dump(a.tilesets,"fuck",6)
	-- gen node
	for _,v in pairs(T.layers) do
		--prepare batchnd
		local batchnd={}
		for i,v in ipairs(T.tilesets) do
			batchnd[i]={}
			batchnd[i].use = false
			batchnd[i].img = v.image
			batchnd[i].nd = CCSpriteBatchNode:create(v.image)
			batchnd[i].firstgid = v.firstgid
			batchnd[i].endgid = v.endgid
		end
		local function __find(g)
			for i,bnd in ipairs(batchnd) do
				if(g>=bnd.firstgid and g<=bnd.endgid) then
					return bnd
				end
			end
		end
		local nd = display.newNode()
		local use=false
		if(v.type=='tilelayer') then			
			nd:setContentSize(CCSize(tw*v.width,th*v.height))
			for i,g in ipairs(v.data) do
				local col = math.mod(i-1,gw)
				local row = math.floor((gw+i-1)/gw)
				local x = col*tw
				local y = h-row*th
				--find batchnd
				local tb = __find(g)
				if(tb) then
					use = true
					local sx = girdrect[g].x
					local sy = girdrect[g].y
					local sw = girdrect[g].w
					local sh = girdrect[g].h
					local spt = CCSprite:create(tb.img,CCRect(sx,sy,sw,sh))
					spt:setTag(g*1000+i)
					--add to batch node
					--spt:setAnchorPoint(ccp(0,0))
					spt:setPosition(x+tw/2, y+th/2)
					tb.nd:addChild(spt)
					tb.use = true
				end	
			end
		elseif(v.type=='imagelayer') then
			local spt = CCSprite:create(v.image)
			local sz = spt:getContentSize()
			-- spt:setAnchorPoint(ccp(0,0))
			local x = v.offsetx
			local y = h-sz.height-v.offsety
			spt:setPosition(x+sz.width/2,y+sz.height/2)
			nd:addChild(spt)
			use=true
		end
		--add batchnd to node
		for i,bnd in ipairs(batchnd) do
			if(bnd.use) then
				use = true
				nd:addChild(bnd.nd)
				bnd.nd:setAnchorPoint(ccp(0,0))
				bnd.nd:setPosition(0,0)
			end
		end
		if(not v.visible) then
			nd:setVisible(false)
		end
		if(use) then
			nodes[v.name] = nd
		end
	end
	setmetatable(r, M)	
	return r
end	

--conver json to table
function M.load(luafile)
	local tb = run_lua_file(luafile)
	if(not tb) then
		return
	end
	return gen(tb)
end
----------------------------------------------
tiledload=M