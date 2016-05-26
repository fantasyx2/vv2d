local M={}
local function set_param(nd,t)
	local a
	a=t.Position
	if(a) then
		--print("set_param pos",a.X,a.Y)
		nd:setPosition(a.X, a.Y)
	end
	a=t.AnchorPoint
	if(a and a.ScaleX and a.ScaleY) then
		--print("set_param arc",a.ScaleX, a.ScaleY)
		nd:setAnchorPoint(ccp(a.ScaleX, a.ScaleY))
	end
	a=t.Scale
	if(a) then
		nd:setScaleX(a.ScaleX or 1.0)
		nd:setScaleY(a.ScaleY or 1.0)
	end
	a=t.Size
	if(a) then
		nd:setContentSize(CCSize(a.X, a.Y))
	end
	a=t.RotationSkewX
	if(a) then
		nd:setRotationX(a)
	end	
	a=t.RotationSkewY
	if(a) then
		nd:setRotationY(a)
	end
	a=t.CColor
	if(a) then
		local c = ccc3(a.R or 255, a.G or 255, a.B or 255)
		nd:setColor(c)
	end
	a=t.IconVisible
	if(a) then
		nd:setVisible(a)
	end
	a=t.Tag
	if(a) then
		nd:setTag(a)
	end
	a=t.Name
	if(a) then
		nd:setName(a)
	end
	a=t.BlendFunc
	if(a) then
		local bld = ccBlendFunc()
		if(a.Dst) then bld.dst=a.Dst end
		if(a.Src) then bld.src=a.Src end
		nd:setBlendFunc(bld)
	end
end
local function get_scale9cap(t)
	if(t.Scale9Enable) then
		return CCRect(t.Scale9OriginX, t.Scale9OriginY, t.Scale9Width, t.Scale9Height)
	end
end
local function gen_node(t)
	local nd = display.newNode()
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_btn(t)
	local s9cap = get_scale9cap(t)
	--print("gen_btn_1",s9cap)
	local a = t.NormalFileData and t.NormalFileData.Path
	local b = t.PressedFileData and t.PressedFileData.Path
	local c = t.DisabledFileData and t.DisabledFileData.Path
	--print("gen_btn_2",a,b,c)
	local nd=cc.ui.UIPushButton.new(
				{
				    normal  = a,
				    pressed = b,
				    disabled = c,
				}, 
			    {scale9 = s9cap and true or false},
			    {scale9Size = false},
				{scale9CapInsets = s9cap}
			)
	if(nd) then	
		nd:setName(t.Name)
		set_param(nd,t)

		local a = t.ButtonText
		local b = t.FontSize or 24
		local cr = t.TextColor and 	t.TextColor.R or 255
		local cg = t.TextColor and 	t.TextColor.G or 255
		local cb = t.TextColor and 	t.TextColor.B or 255
		if(a) then
			local cl=ccc3(cr,cg,cb)
        	local lb
        	lb = CCLabelTTF:create(a,CFG_SYSTEM_FONT,b)    
        	lb:setColor(cl)    	
        	nd:setButtonLabel("normal", lb)
			lb = CCLabelTTF:create(a,CFG_SYSTEM_FONT,b)
			lb:setColor(cl)
        	nd:setButtonLabel("pressed", lb)
        	nd:setButtonLabelOffset(0,-8)
    	end

		
		--print("gen_btn_3",nd)
		return nd
	end
end

local function gen_checkbox(t)
	local nd = display.newNode()
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_map(t)
	local nd = display.newNode()
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_imgview(t)
	local s9cap = get_scale9cap(t)
	local a = t.FileData
	if(a and a.Path) then
		local nd
		if(s9cap) then
			nd = display.newScale9Sprite(a.Path,nil,nil,nil,s9cap)
		else	
			nd = display.newSprite(a.Path)
		end
		if(nd) then
			nd:setName(t.Name)
			set_param(nd,t)			
			return nd
		end		
	end	
end
local ListView = require("uis.listview.ListView")
local function gen_listview(t)
	local sz = t.Size
    local direct = t.DirectionType=="Vertical" and 1 or 2
	local nd = ListView.new(CCRect:new(0,0,sz.X,sz.Y),direct,t.ClipAble)
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_loading(t)
	local nd = display.newNode()
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local PageView = require("uis.listview.PageView")
local function gen_pageview(t)
	local sz = t.Size
    local direct = t.DirectionType=="Vertical" and 1 or 2
	local nd = PageView.new(CCRect:new(0,0,sz.X,sz.Y),direct,t.ClipAble)
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_panel(t)
	local nd = display.newNode()
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_particle(t)
	local a=t.FileData
	if(a and a.Path) then
		local nd = CCParticleSystemQuad:create(a.Path)
		if(nd) then
			nd:setName(t.Name)
			set_param(nd,t)
			return nd
		end		
	end
end
local ScrollView = require("uis.listview.ScrollView")
local function gen_scrollview(t)
    local sz = t.Size
    local direct = t.DirectionType=="Vertical" and 1 or 2
	local nd = ScrollView.new(CCRect:new(0,0,sz.X,sz.Y),direct,t.ClipAble)
	--nd:setContainer(display.newSprite("UI/cpt_bg_01.png"))
	--nd:setTouchEnabled(true)
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_audio(t)
	local nd = display.newNode()
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end
local function gen_sprite(t)
	local a=t.FileData
	if(a and a.Path) then
		local nd = display.newSprite(a.Path)
		if(nd) then
			print("gen_sprite---",a.Path)
			nd:setName(t.Name)
			set_param(nd,t)		
			print("gen_sprite---",a.Path)	
			return nd
		end		
	end	
end
local function gen_textatlas(t)
	if(t.LabelAtlasFileImage_CNB and t.LabelAtlasFileImage_CNB.Path and t.CharWidth and t.CharHeight and t.StartChar) then
		local nd = CCLabelAtlas:create(t.LabelText or "", t.LabelAtlasFileImage_CNB.Path, t.CharWidth, t.CharHeight, string.byte(t.StartChar))	
		if(nd) then
			nd:setName(t.Name)
			set_param(nd,t)
			return nd
		end
	end
end
local function gen_input(t)
	--dump(t)
	-- local nd = ui.newEditBox(
 --                        {
 --                            image = t.res or "",
 --                            size = CCSize(t.Size.X,t.Size.Y),
 --                            imageOpacity = 255,
 --                            --listener =,
 --                        })
	-- print("gen_input")
	-- if(nd) then
	-- 	nd:setName(t.Name)
	-- 	set_param(nd,t)
	-- 	return nd
	-- end
end

local align_map=
{
  HT_Top=ui.TEXT_ALIGN_LEFT,
  HT_Center=ui.TEXT_ALIGN_CENTER,
  HT_Bottom=ui.TEXT_ALIGN_RIGHT,
  VT_Top   =ui.TEXT_VALIGN_TOP,
  VT_Center=ui.TEXT_VALIGN_CENTER,
  VT_Bottom=ui.TEXT_VALIGN_BOTTOM,
}

local function gen_text(t)
	local nd
	local fontsz = t.FontSize or 24
	local txt = t.LabelText or ""
	local a=t.Size
	if(a and a.X and a.Y) then
		local align=align_map[a.HorizontalAlignmentType or "HT_Center"]
		local valign=align_map[a.VerticalAlignmentType or "VT_Center"]
		nd = CCLabelTTF:create(txt, CFG_SYSTEM_FONT, fontsz, CCSize(a.X,a.Y), align, valign)
	else
		nd = CCLabelTTF:create(txt, CFG_SYSTEM_FONT, fontsz)
	end	
	a=t.OutlineColor
	if(a) then		
		local c = ccc3(a.R or 255, a.G or 255, a.B or 255)		
		nd:enableStroke(c, 2)
	end
	a=t.ShadowColor
	if(a) then		
		--local c = ccc3(a.R or 255, a.G or 255, a.B or 255)		
		--nd:enableStroke(c, 2)
	end
	a=t.ShadowEnabled
	if(a) then		
		local sz = CCSize(t.ShadowOffsetX or 1.0,t.ShadowOffsetY or -1.0)		
		nd:enableShadow(sz,0.8,0.5)
	end
	if(nd) then
		nd:setName(t.Name)
		set_param(nd,t)
		return nd
	end
end


local function gen_bmfont(t)
	local a=t.LabelBMFontFile_CNB
	if(a and a.Path) then
		local nd = CCLabelBMFont:create()
		if(nd) then
			nd:setFntFile(a.Path)
			nd:setString(t.LabelText or "")
			nd:setName(t.Name)
			set_param(nd,t)
			return nd
		end
	end
end
--------------------------------------
local config=
{
	ButtonObjectData	= gen_btn,
	CheckBoxObjectData	= gen_checkbox,
	GameMapObjectData	= gen_map,
	ImageViewObjectData	= gen_imgview,
	ListViewObjectData	= gen_listview,
	LoadingBarObjectData	= gen_loading,
	PageViewObjectData		= gen_pageview,
	PanelObjectData			= gen_panel,
	ParticleObjectData		= gen_particle,
	ScrollViewObjectData	= gen_scrollview,
	SimpleAudioObjectData	= gen_audio,
	SingleNodeObjectData	= gen_node,
	SpriteObjectData		= gen_sprite,
	TextAtlasObjectData		= gen_textatlas,
	TextFieldObjectData		= gen_input,
	TextObjectData 			= gen_text,
	TextBMFontObjectData    = gen_bmfont,
}
--------------------------------------
--[[[
"ccsload" = {
    "childs" = {
        "AtlasLabel" = {
            "node" = userdata: 05FCD028
            "tag"  = 18
        }
        "Button" = {
            "node" = userdata: 05FCB720
            "tag"  = 14
        }
        "Image" = {
            "node" = userdata: 05FCCAD0
            "tag"  = 16
        }
        "LoadingBar" = {
            "node" = userdata: 05FCD0B8
            "tag"  = 19
        }
        "Particle" = {
            "node" = userdata: 05FCB5B8
            "tag"  = 9
        }
        "Sprite" = {
            "node" = userdata: 05FCCBF0
            "tag"  = 12
        }
        "Text" = {
            "node" = userdata: 05FCCDE8
            "tag"  = 17
        }
        "TextField" = {
            "node" = userdata: 05FCD1D8
            "tag"  = 21
        }
    }
    "node"   = userdata: 05FCAD90
    "tag"    = -1
}
--]]
--------------------------------------
local MM={}
MM.__index=function(self,k)
	if(MM[k]) then
		return MM[k]
	elseif(type(k)=="string") then
		return MM.getChildByName(self,k)
	elseif(type(k)=="number") then
		return 	MM.getChildByTag(self,k)
	end
	return nil
end
function MM:getChildByTag(tag)
	if(tag>=0 and self.childs) then
		for _,v in pairs(self.childs) do
			if(v.tag==tag) then
				return v.node
			end
		end
	end
end
function MM:getChildByName(name)
	return self.childs and self.childs[name] and self.childs[name].node
end
function MM:getChildRoot(name)
	return self.childs and self.childs[name]
end

local function gen(a)
	local tp = a.ctype
	if(not tp) then
		return
	end
	print("-----"..tp)
	local f = config[tp]
	if(not f) then
		print("-----no config----"..tp)
		return
	end
	local r={}
	r.node = f(a)
	if(not r.node) then
		return
	end
	r.tag = a.Tag or -1
	if(a.Children) then
		r.childs={}
		--parse childs
		for _,v in pairs(a.Children) do
			local n = gen(v)
			if(n and n.node) then
				r.node:addChild(n.node)
				--table.insert(r.childs,n)
				r.childs[v.Name]=n
			end
		end
	end
	setmetatable(r, MM)	
	return r
end	
--conver json to table
function M.load(jsonfile)
	local str = get_file_data(jsonfile)
	if(not str) then
		return false
	end
	local rst={}
	local jsontb = 	json.decode(str)
	if(not jsontb) then
		return false
	end
	local res = jsontb.Content.Content.UsedResources
	local root = jsontb.Content.Content.ObjectData
	local size = root.Size
	local name = root.Name
	local nodes = root.Children
	local r=gen(root)
	return r
end
----------------------------------------------
--gen node
function M.createNode(jsonfile)
	local r=M.load(jsonfile)
	if(r) then
		dump(r,"ccsload",5)
		print("r.getChildRoot_Text		",tostring(r:getChildRoot"Text"))
		print("r.getChildByName_Text	",tostring(r:getChildByName"Text"))
		print("r.getChildByTag_17		",tostring(r:getChildByTag(17)))
		print("r.Text					",tostring(r.Text))
		print("r[17]					",tostring(r[17]))
		return r
	end
end
ccsload=M

 
