local csp={}
---------------------------
csp.tp_panel="Panel"
csp.tp_label="Label"
csp.tp_button="Button"
csp.tp_list="ListView"
csp.tp_imgview="ImageView"
csp.tp_labelatlas="LabelAtlas"
csp.tp_labelbmfont="LabelBMFont"
csp.tp_loadingbar="LoadingBar"
csp.tp_input="TextField"
---------------------------
csp.cname="classname"
csp.name="name"
csp.anim="animation"
csp.dscale="dataScale"
csp.dsw="designWidth"
csp.dsh="designHeight"
csp.textures="texturesPng"
csp.ver="version"
csp.tree="widgetTree"
----------------------
csp.childs="children"
csp.clipable="clipAble"
csp.opts="options"
csp.z="ZOrder"
csp.ax="anchorPointX"
csp.ay="anchorPointY"
csp.fx="flipX"
csp.fy="flipY"
csp.w="width"
csp.h="height"      
csp.x="x"
csp.y="y"
csp.rt="rotation"
csp.sx="scaleX"
csp.sy="scaleY"

csp.acttag="actiontag"
csp.colorr="colorR"
csp.colorg="colorG"
csp.colorb="colorB"
csp.alpha="opacity"
      
csp.tag="tag"
csp.touch="touchAble"
csp.visible="visible"

csp.bgimg="backGroundImageData"--.path
csp.bgimgs9="backGroundScale9Enable"
csp.bgcb="bgColorB"
csp.bgcg="bgColorG"
csp.bgca="bgColorOpacity"
csp.bgcr="bgColorR"
csp.bgecb="bgEndColorB"
csp.bgecg="bgEndColorG"
csp.bgecr="bgEndColorR"
csp.bgscb="bgStartColorB"
csp.bgscg="bgStartColorG"
csp.bgscr="bgStartColorR"
csp.caph="capInsetsHeight"
csp.capw="capInsetsWidth"
csp.capx="capInsetsX"
csp.capy="capInsetsY"
csp.s9="scale9Enable"
csp.s9w="scale9Width"
csp.s9h="scale9Height"
---------tp_label----------
csp.fontfile="fontFile"
csp.fontname="fontName"
csp.fontsize="fontSize"
csp.halign="hAlignment"
csp.text="text"
csp.valign="vAlignment"
csp.rectw="areaHeight"
csp.recth="areaWidth"
--------tp_button----------
csp.btndisable_file="disabledData"--.path
csp.btnnormal_file="normalData"--.path
csp.btnpressed_file="pressedData"--.path
csp.btntext="text"
csp.btntcb="textColorB"
csp.btntcg="textColorG"
csp.btntcr="textColorR"
--[[
      "ignoreSize": false,
      "layoutParameter": null,
      "positionPercentX": 0,
      "positionPercentY": 0,
      "positionType": 0,
      "clipAble": false,
      "colorType": 1,
      "layoutType": 0,
      "vectorX": 0,
      "vectorY": -0.5
      "sizePercentX": 1,
      "sizePercentY": 1,
      "sizeType": 0,
      "useMergedTexture": false,
      "adaptScreen": false, 
--]]  
--------tp_imgview---------------
--csp.imgfile="fileName"--null
csp.img_file="fileNameData"--.path
--------tp_labelatlas------------
--csp.atlas_file="charMapFile"--null,
csp.atlas_file="charMapFileData"--path
csp.atlas_item_w="itemWidth"
csp.atlas_item_h="itemHeight"
csp.atlas_start_char="startCharMap"
csp.atlas_str="stringValue"
-------tp_labelbmfont------------
csp.bmfont_file="fileNameData"--path--XX.fnt
---------tp_loadingbar----------------
csp.direct="direction"--: 0,
csp.percent="percent"--: 100,
csp.loadbar_file="textureData"--.path,
--------tp_listview------------------
csp.gravity="gravity"--: 3,
csp.list_innerh="innerHeight"--: 0,
csp.list_innerw="innerWidth"--: 0,
csp.list_itemgap="itemMargin"--: 0,
------tp_input-----------------------
csp.input_limit="maxLength"--: 10,
csp.input_islimit="maxLengthEnable"--: false,
csp.input_ispassword="passwordEnable"--: false,
csp.input_password="passwordStyleText"--: "*",
csp.input_placeholder="placeHolder"--: "input words here",
csp.input_text="text"--: "Text Field"
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
csp.P_COM=
{
      class=csp.cname,      
      name=csp.name,
      --childs=csp.childs,
      x=csp.x,
      y=csp.y,
      z=csp.z,
      w=csp.w,
      h=csp.h,
      ax=csp.ax,
      ay=csp.ay,
      sx=csp.sx,
      sy=csp.sy,
      fx=csp.fx,
      fy=csp.fy,
      rt=csp.rt,
      r=csp.colorr,
      g=csp.colorg,
      b=csp.colorb,
      a=csp.alpha,      
      tag=csp.tag,
      touch=csp.touch,
      visible=csp.visible,
      clipable=csp.clipable,
      bgimg=function(tb) return tb[csp.bgimg] and tb[csp.bgimg].path end,
      bgimgs9=csp.bgimgs9,
      bgr=csp.bgcr,
      bgg=csp.bgcg,
      bgb=csp.bgcb,
      caph=csp.caph,
      capw=csp.capw,
      capx=csp.capx,
      capy=csp.capy,
      s9=csp.s9,
      s9w=csp.s9w,
      s9h=csp.s9h,
}
csp.P_PANEL=
{

}

csp.P_BTN=
{
      disable_img=function(tb) return tb[csp.btndisable_file] and tb[csp.btndisable_file].path end,  
      normal_img=function(tb) return tb[csp.btnnormal_file] and tb[csp.btnnormal_file].path end,  
      pressd_img=function(tb) return tb[csp.btnpressed_file] and tb[csp.btnpressed_file].path end,
      text=csp.btntext,
      text_r=csp.btntcr,
      text_g=csp.btntcg,
      text_b=csp.btntcb,
}
csp.P_LABEL=
{
      fontfile=csp.fontfile,  
      fontname=csp.fontname,  
      fontsize=csp.fontsize,
      text=csp.text,
      halign=csp.halign,
      valign=csp.valign,
      rectw=csp.rectw,
      recth=csp.recth,
}
csp.P_IMAGEVIEW=
{
      imgfile=function(tb) return tb[csp.img_file].path and tb[csp.img_file].path end,
}
csp.P_LABELATLAS=
{
      atlasfile=function(tb) return tb[csp.atlas_file] and tb[csp.atlas_file].path end,
      itemw=csp.atlas_item_w,
      itemh=csp.atlas_item_h,
      startchar=csp.atlas_start_char,
      text=csp.atlas_str,
}
csp.P_BMFONT=
{
      bmfile=function(tb) return tb[csp.bmfont_file] and tb[csp.bmfont_file].path end,
      text=csp.text,
}
csp.P_LOADINDBAR=
{
      img=function(tb) return tb[csp.loadbar_file] and tb[csp.loadbar_file].path end,
      direct=csp.direct,
      percent=csp.direct,
}
csp.P_LISTVIEW=
{
      gravity=csp.gravity,
      innerh=csp.list_innerh,
      innerw=csp.list_innerw,
      itemgap=csp.list_itemgap,
}

csp.P_INPUT=
{
      length_limit=csp.input_limit,
      length_islimit=csp.input_islimit,
      ispwd=csp.input_ispassword,
      pwdchar=csp.input_password,
      placeholder=csp.input_placeholder,
      text=csp.input_text,
}
local function INIT_CSP(TB)
   TB.__index=csp.P_COM
   setmetatable(TB, TB)
end
INIT_CSP(csp.P_PANEL)
INIT_CSP(csp.P_BTN)
INIT_CSP(csp.P_LABEL)
INIT_CSP(csp.P_IMAGEVIEW)
INIT_CSP(csp.P_LABELATLAS)
INIT_CSP(csp.P_BMFONT)
INIT_CSP(csp.P_LOADINDBAR)
INIT_CSP(csp.P_LISTVIEW)
INIT_CSP(csp.P_INPUT)
print("csp.P_BTN.x========",csp.P_BTN.x)
print("csp.P_INPUT.x========",csp.P_INPUT.x)
print("csp.P_LABEL.x========",csp.P_LABEL.x)
print("csp.P_LISTVIEW.x========",csp.P_LISTVIEW.x)
csp.P_LISTVIEW.x=10000
print("csp.P_LISTVIEW.x========",csp.P_LISTVIEW.x)
print("csp.P_COM.x========",csp.P_COM.x)

return csp