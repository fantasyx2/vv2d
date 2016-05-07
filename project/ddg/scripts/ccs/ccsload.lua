local csp=import(".ccsparam")
local M={}
local config=
{
	[csp.tp_panel]=csp.P_PANEL,
	[csp.tp_button]=csp.P_BTN,
	[csp.tp_label]=csp.P_LABEL,
	[csp.tp_list]=csp.P_LISTVIEW,
	[csp.tp_imgview]=csp.P_IMAGEVIEW,
	[csp.tp_labelatlas]=csp.P_LABELATLAS,
	[csp.tp_labelbmfont]=csp.P_BMFONT,
	[csp.tp_loadingbar]=csp.P_LOADINDBAR,
	[csp.tp_input]=csp.P_INPUT,
}
local creater=
{
	[csp.tp_panel]=gen_panel,
	[csp.tp_button]=gen_button,
	[csp.tp_label]=gen_label,
	[csp.tp_list]=gen_list,
	[csp.tp_imgview]=gen_img,
	[csp.tp_labelatlas]=gen_labelatlas,
	[csp.tp_labelbmfont]=gen_bmfont,
	[csp.tp_loadingbar]=gen_loadingbar,
	[csp.tp_input]=gen_input,
}
--parse ccs format to our format
local function parse(a)
	local r={}
	local tp = a[csp.cname]
	if(not tp) then
		return
	end
	print("-----"..tp)
	if(not config[tp]) then
		print("-----no config----"..tp)
		return
	end
	--read common property
	for k,v in pairs(csp.P_COM) do
		--print(k,v,a)
		if(type(v)=="function") then
			r[k]=v(a[csp.opts])
		else	
			r[k]=a[csp.opts][v]
		end	
	end
	--read special property
	for k,v in pairs(config[tp]) do
		--print(k,v,a)
		if(type(v)=="function") then
			r[k]=v(a[csp.opts])
		else	
			r[k]=a[csp.opts][v]
		end
	end
	local rsub={}
	local has
	--parse childs
	for _,v in pairs(a[csp.childs]) do
		local cr = parse(v)
		if(cr) then
			has=true
			table.insert(rsub,cr)
		end
	end
	if(has) then
		r["childs"]=rsub
	end
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
	rst=parse(jsontb[csp.tree])
	--dump(rst,"ccsload",3)
	--print("...ccsload..." .. (rst and "true" or "false"))
	return rst	
end
----------------------------------------------
local function gen_node(tb)
	if(csp.tp_button==tb.class) then

	end
end
----------------------------------------------
--gen node
function M.createNode(jsonfile)
	local r=M.load(jsonfile)
	if(r) then
		dump(r,"ccsload",3)
	end
end

ccsload=M

 