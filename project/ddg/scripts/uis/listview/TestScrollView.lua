local ScrollView = import("app.view.layer.scrollview.ScrollView")
local ScrollViewCell = import("app.view.layer.scrollview.ScrollViewCell")
local CellPushButton = import("app.view.layer.scrollview.CellPushButton")
local PageControl = import("app.view.layer.scrollview.PageControl") 

local ResRead = import("app.model.resaccess.ResRead")
local ResGen = import("app.model.resaccess.ResGen")

local VarWImageFont = import("app.view.layer.VarWImageFont")
local MultiProgressBar = import("app.view.layer.MultiProgressBar")
local ProgressBar = import("app.view.layer.ProgressBar")


local TestScrollView = class("TestScrollView", function()    
    return display.newNode()
end)

function TestScrollView:addBtn(x,y,hd)
    local btnpos = {n="city1",  t="movebtn", x=1000, y=360,  tg = 1, ftg = 0, od=1,  pressanima=true,res = {"img/UI/common/button/XJ_UI_butun_12.png","img/UI/common/button/XJ_UI_butun_13.png"} }
    btnpos.x = x
    btnpos.y = y
    local btn = GenUiUtil.genUi(btnpos,self,"")
    if(hd) then
        btn:onButtonClicked(hd) 
    end
end

function TestScrollView:ctor()    
    self:setNodeEventEnabled(true)
    -- self:setTouchEnabled(true)
    Image_DL_Bg = display.newSprite("img/UI/Login/DL_BJ001_1.jpg")
    --Image_DL_Bg = display.newSprite("cccc.jpg")
    Image_DL_Bg:setPosition(display.cx, display.cy)
    Image_DL_Bg:addTo(self,0)
    -- GenUiUtil.attackShader(Image_DL_Bg,'LIGHTF') 
    self:test32()
    -- self:test31()
    -- self:test30()
    -- self:test29()
    -- self:test28()
    -- self:test27()
    -- self:test26()
    -- self:test25()
    -- self:test24()
    --self:test23()
    -- self:test22()
    -- self:test21()
    --self:test20()
    -- self:test19()
    -- self:test18()
    -- self:test17()
    -- self:test16()
    -- self:test15()
    -- self:test14()
    -- self:test13()
    -- self:test12()
    -- self:test11()
    -- self:test9()
    -- self:test5()
    -- self:test0()
    -- self:test8()
    -- self:test6()
    -- self:test4()
    -- local map = {
    --     "1" = 1,
    --     "2" = 2,
    --     "3" = 3,
    --     "4" = 4,
    --     "5" = 5,
    --     "6" = 6,
    --     "7" = 7,
    --     "8" = 8,
    --     "9" = 9,
    --     "0" = 10,
    --     "+" = 11,
    --     "-" = 12,
    -- }

end 
function TestScrollView:test32()
    require("lfs")
    self.writablePath = CCFileUtils:sharedFileUtils():getWritablePath() .. "load/"
    --写文件
    local function writefile(path, content, mode)
        mode = mode or "w+b"
        local file = io.open(path, mode)
        if file then
            if file:write(content) == nil then return false end
            io.close(file)
            return true
        else
            return false
        end
    end
    local function fileExists(path)
        return CCFileUtils:sharedFileUtils():isFileExist(path)
    end
    --创建目录
    local function mkDir(path)
        if not fileExists(path) then
            printDM("__mkDir__",path)
            return lfs.mkdir(path)
        end
        return true
    end

    local function strSplit(input, delimiter)
        input = tostring(input)
        delimiter = tostring(delimiter)
        if (delimiter=='') then return false end
        local pos,arr = 0, {}
        -- for each divider found
        for st,sp in function() return string.find(input, delimiter, pos, true) end do
            table.insert(arr, string.sub(input, pos, st - 1))
            pos = sp + 1
        end
        table.insert(arr, string.sub(input, pos))
        return arr
    end



    if(not self._zipFile) then
        local path = CCFileUtils:sharedFileUtils():fullPathForFilename("load.zip")
        if(path) then           
            self._zipFile = CCZipFile:createWithPathName(path)
            if(self._zipFile) then
                self._zipFile:retain()
                local ret = self._zipFile:genFileList()
                printDM("____________DataManager_load_fileData.zip",ret)
            end
        end     
    end
    if(self._zipFile) then
        local str = self._zipFile:getFirstFilename()
        local idx = 1
        while(str~="") do    
                        
            --"res/img/UI/gonghui/GH_ui_button_c10.png"

            local tb = strSplit(str, "/")
            local ct = #tb
            local name = tb[ct]
            -- printDM("____________self._zipFile__",idx,str,name)
            if(name~="") then
                local con = self._zipFile:getFileDataNoOrder(str)         
                if(con) then
                    writefile(self.writablePath..str, con, mode)
                end
            else
                
                mkDir(self.writablePath..str)  
            end
            str = self._zipFile:getNextFilename()

            idx = idx+1
        end
        -- local con = self._zipFile:getFileDataNoOrder(filename)
        -- if(con) then    
        --     printDM("____________DataManager_load_fileData succ ",filename) 
        --     return con
        -- else
        --     printDM("\n\n\n")
        --     printDM("************************************************************")
        --     printDM("************DataManager_load_error1 ",filename)            
        --     printDM("************************************************************")             
        --     printDM("\n\n\n")
        --     return
        -- end
        self._zipFile:release()
        self._zipFile:close()
        self._zipFile=nil
    end
end
function TestScrollView:test31()
    local tb=
    {   
        "action_hero1001", 
        "action_hero1001.xml",
        {"stand","move","move","move","move","move","move","attack1","attack2","attack5","move","death"}
    }
    GenUiUtil.addArmatureFile(tb[2],"res/arm/")
    local arm = GenUiUtil.createArmature(tb[1])
    arm:setScale(2.0)
    arm:setPosition(ccp(640,300))
    arm:setAnchorPoint(ccp(0.5,0))
    arm:getAnimation():setSpeedScale(CFG_ANIMA_SPEED)    
    self:addChild(arm,2)
    -- GenUiUtil.attackShader(arm,'LIGHTF') 

    -- LIGHT  = {"LightShader.vsh","LightShader.fsh"},
    -- LIGHTF  = {"LightFShader.vsh","LightFShader.fsh"},
    -- TRANS  = {"TransShader.vsh","TransShader.fsh"},
    -- LK  = {"LKShader.vsh","LKShader.fsh"},

    -- arm:getAnimation():play("stand")
    arm:getAnimation():playWithNames(tb[3],0,true)

    addToWeakTb(arm)

    local acc = transition.sequence(
            {
                CCDelayTime:create(25.0),
                CCCallFunc:create(function()
                    arm:removeFromParent()
                end),              

            }
        )
    arm:runAction(acc)
end

--arm xml to json
function TestScrollView:test30()
     local tb={    
            "action_hero1012.xml",
    }
    GenUiUtil.addArmatureFile("AAA_action_hero1012.xml","res/arm/")
    local arm = GenUiUtil.createArmature("action_hero1012")
    arm:setScale(2.0)
    arm:setPosition(ccp(640,300))
    arm:setAnchorPoint(ccp(0.5,0))
    arm:getAnimation():setSpeedScale(CFG_ANIMA_SPEED)
    arm:getAnimation():play("stand")
    self:addChild(arm,2)
end
--scale 负方向增长
--flip 只作用sprite
function TestScrollView:test29()
    Image_DL_Bg:setScale(0.5)
    Image_DL_Bg:setAnchorPoint(ccp(0,0))
    Image_DL_Bg:setPosition(640,360)
    self:addBtn(700,200,function()
            if(Image_DL_Bg:getScaleX()>0) then
                Image_DL_Bg:setScaleX(-0.5)
            else
                Image_DL_Bg:setScaleX(0.5)
            end                
        end)

end

function TestScrollView:test28()
    -- self:setTouchSwallowEnabled(true)
    local function aaaa()
        -- self:setTouchEnabled(true)
        -- self:setTag(67890)
        -- self:addNodeEventListener(cc.NODE_TOUCH_EVENT, 
        --         function(event)
        --             print("TestScrollView:-----------",event.name)
        --             if(event.name == "began" ) then                    
        --                 return true                    
        --             elseif(event.name == "ended" ) then
        --             end
        --         end
        --     ) 

        local lll = display.newColorLayer(ccc4(255,0, 0,128))
        -- self:addChild(lll)
        app:addDialog(lll,1,1)
        lll:setTouchEnabled(true)
        lll:setTag(12345)
        -- lll:setTouchSwallowEnabled(false)
        lll:addNodeEventListener(cc.NODE_TOUCH_EVENT, 
            function(event)
                printSk("TestScrollView:++++++++",event.name)
                if(event.name == "began" ) then
                    return true
                elseif(event.name == "ended" ) then
                    lll:removeSelf()
                end
            end
            ) 
    end
    -- self:performWithDelay(aaaa, 1.0)

    local aaaaa=1
    self:addBtn(640,360,function ()
        printSk("test28Btn:-----------"..aaaaa)
        aaaaa=aaaaa+1
        aaaa()
    end)


end

function TestScrollView:test27()

 --3D晃动的特效  
   -- CCActionInterval* shaky3D = CCShaky3D::create(5, CCSize(10, 10), 15, false);  
   -- sp->runAction(shaky3D);  
--作用：创建一个3d晃动的特效--    参数1：晃动的范围--    参数2：是否有z轴晃动--    参数3：  网格大小--    参数4：特效持续的时间  
    -- local shaky3D = CCShaky3D:create(50, CCSizeMake(50, 50), 5, true);  
    -- Image_DL_Bg:runAction(shaky3D); 
--=======================================================================
    --3D瓷砖晃动特效  
--    CCActionInterval* shakyTiles3D = CCShakyTiles3D::create(5, CCSize(10, 10), 5, false);  
--    sp->runAction(shakyTiles3D);  
--    作用：创建一个3d瓷砖晃动的特效    --    参数1：晃动的范围    --    参数2：是否有z轴晃动    --    参数3：  网格大小    --    参数4：特效持续的时间      
      -- local shakyTiles3D = CCShakyTiles3D:create(5, CCSize(10, 10), 5, false);  
      -- Image_DL_Bg:runAction(shakyTiles3D); 
--=======================================================================    
    --波动特效  
--    CCActionInterval* waves = CCWaves::create(5, CCSize(10, 10), 10, 20, true, true);  
--    sp->runAction(waves);  
 --    创建一个波动特效--    参数1：波动的速率--    参数2：振幅--    参数3:水平波动--    参数4：垂直波动--    参数5：网格大小--    参数6：特效持续时间     
       -- local waves = CCWaves:create(5, CCSize(20, 20), 5, 20, true, true);  
       --  Image_DL_Bg:runAction(waves)
--====================================================================== 
    --3D波动特效  
--    CCActionInterval* waves3D = CCWaves3D::create(5, CCSize(10, 10), 10, 20);  
--    sp->runAction(waves3D);
--    创建一个3D波动特效    --    参数1：波动的速率    --    参数2：振幅    --    参数3：网格大小    --    参数4：特效持续时间

      local waves3Dd = CCWaves3D:create(5, CCSize(10, 10), 10, 0.5);  
      Image_DL_Bg:runAction(waves3Dd)

--======================================================================

    --3D瓷砖波动特效  
--    CCActionInterval* wavesTiles3D = CCWavesTiles3D::create(5, CCSize(10, 10), 10, 20);  
--    sp->runAction(wavesTiles3D);  
   --    创建一个3D瓷砖波动特效    --    参数1：波动的速率    --    参数2：振幅    --    参数3：网格大小    --    参数4：特效持续时间  
    -- local wavesTiles3D = CCWavesTiles3D:create(100, CCSizeMake(10, 10), 10, 20)
    -- Image_DL_Bg:runAction(wavesTiles3D)
--========================================================================
    --X轴 3D反转特效  
--    CCActionInterval* filpX = CCFlipX3D::create(5);  
--    sp->runAction(filpX);  
      --    作用：x轴3D反转特效--    参数：特效持续的时间
    --Y轴3D反转特效  
--    CCActionInterval* filpY = CCFlipY3D::create(5);  
--    sp->runAction(filpY);  
--    CCActionInterval * flipY3D = CCFlipY3D::create(4);--    sp->runAction(flipY3D);  
--============================================================================================
    --凸透镜特效  
--    CCActionInterval* lens = CCLens3D::create(2, CCSize(10, 10),CCPointMake(240, 160), 240);  
--    sp->runAction(lens);  
--    作用：  凸镜特效--    参数1：凸镜中心点--    参数2：凸镜半径--    参数3：网格大小--    参数4：网格持续时间      
      -- local  lens = CCLens3D:create(50, CCSize(400, 400),ccp(60, 60), 240);  
      -- Image_DL_Bg:runAction(lens);  
--============================================================================================


    --水波纹特效  
--    CCActionInterval* ripple = CCRipple3D::create(5, CCSize(10, 10), CCPointMake(240, 160), 240, 4, 160);  
--    sp->runAction(ripple);  
--    作用：水波特效--    参数1：起始位子--    参数2：半径--    参数3：速率--    参数4：振幅--    参数5：网格大小--    参数6：特效持续的时间      
      -- local ripple = CCRipple3D:create(50, CCSize(110, 110), ccp(240, 160), 240, 4, 160);  
      -- Image_DL_Bg:runAction(ripple);  
--============================================================================================    
    --液体特效  
--    CCActionInterval* liquid = CCLiquid::create(5, CCSize(10, 10), 4, 20);  
--    sp->runAction(liquid);  
--    作用：液体特效--    参数1：速率--    参数2：振幅--    参数3：网格大小--    参数4：特效持续时间

end

function TestScrollView:test26()
    local psbar = CCProgressTimer:create(display.newSprite("img/zhezhao02.png")) 
    psbar:setOpacity(128) 
    psbar:setType(kCCProgressTimerTypeRadial)
    psbar:setPercentage(30)
    -- psbar:setBarChangeRate(ccp(1,1))    --对应方向上是否进行设置
    -- psbar:setMidpoint(ccp(0, 1))        --进度方向 
    Image_DL_Bg:addChild(psbar)  
    psbar:setPosition(640, 600)
    psbar:setScale(1.0)

end

function TestScrollView:test25() 
    function foo (a)  
        print("foo", a)  -- foo 2  
        return coroutine.yield(2 * a) -- return: a , b  
        end  
       
    local co = coroutine.create(function (a , b)  
        print("co-body", a, b) -- co-body 1 10  
        local rst,r2 = foo(a + 1)  
           
        print("co-body2", rst,r2,a,b)  
        local r, s = coroutine.yield(a + b, a - b)  
           
        print("co-body3", r, s)  
        return b, "end"  
    end)  
              
    print("main", coroutine.resume(co, 1, 10)) -- true, 4  
    print("------")  
    print("main", coroutine.resume(co, nil,"p")) -- true 11 -9  
    print("------")  
    print("main", coroutine.resume(co, "x", "y")) -- true 10 end  
    print("------")  
    print("main", coroutine.resume(co, "x", "y")) -- false cannot resume dead coroutine  
    print("------") 
end  

function TestScrollView:test24() 
    local mmk = string.format("+++%c%c%c5",100,0,0)
    print(mmk,string.len(mmk))

    mmk = "===" .. '\0' .. "+++"
    print(mmk,string.len(mmk))

    local aaa = crypto.encodeBase64(mmk)
    print(aaa,string.len(aaa))

    local bbb = crypto.decodeBase64(aaa)
    print(bbb,string.len(bbb))

end

function TestScrollView:test23()
    local tb={}
    table.insert(tb,{1})
    table.insert(tb,{2})
    table.insert(tb,{3})
    table.insert(tb,{4})
    table.insert(tb,{5})

    for k,v in pairs(tb) do
        print("______",k,v[1])
    end
    print("==================")

    tb[1] = nil
    table.insert(tb,{6})
    tb[5] = nil
    for k,v in pairs(tb) do
        print("______",k,v[1])
    end

    print("==================")
    table.insert(tb,{7})
    table.insert(tb,{8})
    for k,v in pairs(tb) do
        print("______",k,v[1])
    end
    print("==================")
end

function TestScrollView:test22()
    local tb={
        "quest.json",
        "dfLv.json",
        "dfLv.json",
        "store.json",
        "arenaAwardAll.json"
    }
    -- app.DataManager:loadData("quest.json")
    -- app.DataManager:loadData("dfLv.json")
    -- app.DataManager:loadData("df.json")
    -- app.DataManager:loadData("store.json")
    -- app.DataManager:loadData("arenaAwardAll.json")
    local acc = transition.sequence(
            {
                CCDelayTime:create(1.1),
                CCCallFunc:create(function()
                    app.DataManager:loadData("quest.json")
                end),
                CCDelayTime:create(1.1),
                CCCallFunc:create(function()
                    app.DataManager:loadData("dfLv.json")
                end),
                CCDelayTime:create(1.1),
                CCCallFunc:create(function()
                    app.DataManager:loadData("df.json")
                end),
                CCDelayTime:create(1.1),
                CCCallFunc:create(function()
                    app.DataManager:loadData("store.json")
                end),
                CCDelayTime:create(1.1),
                CCCallFunc:create(function()
                    app.DataManager:loadData("arenaAwardAll.json")
                end),

            }
        )
    self:runAction(acc)
end

function TestScrollView:test21()
    --local sp  = display.newSprite("img/UI/cptui/cpt_bg_01.png")
    local sp  = CCLabelTTF:create("中华人民共和国国旗国歌郭辉",CFG_SYSTEM_FONT,30) 
    if(sp) then
        sp:setPosition(display.cx, display.cy)
        sp:addTo(self,0)
        sp:setScale(0.96)
        GenUiUtil.runJzEffect(sp,3,60,5)
        -- GenUiUtil.runFadeOutEffect(sp,3,40,0.7)
    end
    
    -- -- sp = Image_DL_Bg
    -- GenUiUtil.attackShader(sp,"FADEINUV")
    -- local __mb = ccBlendFunc()
    -- __mb.src = GL_SRC_ALPHA
    -- __mb.dst = GL_ONE_MINUS_SRC_ALPHA
    -- sp:setBlendFunc(__mb)
    -- --方向 1 上到下
    -- --方向 2 下到上
    -- --方向 3 左到右
    -- --方向 4 右到左
    -- sp:setFparam1(3)
    -- --起点
    -- sp:setFparam2(-100/720)
    -- --间隔
    -- sp:setFparam3(100/720)    

    -- scheduler.scheduleGlobal(function()        
    --     -- body
    --     local dd = sp:getFparam2()
    --     sp:setFparam2(dd+0.005)

    -- end, 0.01)
end
function TestScrollView:test20()
    local tb = {
        {"a",5,1},
        {"b",5,2},
        {"c",1,3},
        {"d",1,4},
        {"e",1,5},
    }   
    dump(tb)
    table.sort(tb,
        function(a,b) 
            if(a[2]<b[2]) then
                return true
            elseif(a[2]==b[2]) then
                return a[3]<b[3]
            end
        end
     )

    dump(tb) 

end

function TestScrollView:test19()
    self.data={}
    self.data.tb={}
    self:schedule(function()     
            self.data = {}  
            self.data.tb = {}     
            for i=1,1024*1024 do
                self.data.tb[i] = "1111111111111111111111111111111111111111"
            end
            print("______test19",#self.data.tb)
        end, 5.0)

    self:schedule(function()  
            self.data = nil             
            collectgarbage("collect")         
            print("______test20",math.floor(collectgarbage("count")))
        end, 8.0)      

end

--测试特效
function TestScrollView:test18()  

    function genJpgMaskSp(name,maskName,pathflag)
        if(pathflag) then
            name = pathflag .. name
            maskName = pathflag .. maskName
        end

        local spp = display.newSprite(name)
        if(spp) then
            local maskTexture = CCTextureCache:sharedTextureCache():addImageForMask(maskName)
            if(maskTexture) then
                spp:setCC_Texture1_s(maskTexture)
                print("-------maskTexture stringForFormat",maskTexture:stringForFormat())            
            end    
            --print("-------spp stringForFormat",masksp:getTexture():stringForFormat())        
            spp:setShaderFromFile("shader/JpgMaskShader.vsh","shader/JpgMaskShader.fsh")
            --Png图片渲染，混合处理
            --如果原图是jpg不需要设置
            local __mb = ccBlendFunc()
            __mb.src = GL_SRC_ALPHA
            __mb.dst = GL_ONE_MINUS_SRC_ALPHA
            spp:setBlendFunc(__mb)
        end
        return spp
    end 

    -- local sp = genJpgMaskSp("Hdbody_hero1001.jpg","Hdbody_hero1001a.jpg","img/GENERAL/")
    -- sp:setPosition(640,360)
    -- self:addChild(sp)

    local sp = display.newSprite("Hdbody_hero1008.jpg")
    --local sp = display.newSprite("arm/action_npc20045.png")
    sp:setPosition(640,360)
    self:addChild(sp)
    
end

--测试特效
function TestScrollView:test17()   
    local bg = display.newColorLayer(ccc4(0,0,0,0))
    self:addChild(bg,2) 
    local spp = display.newSprite("img/UI/common/bg/Alchemy_dikuang_09.png",640,360)    
    self:addChild(spp,2)    

    local pathflag = 'img/UI/'
    local btnpos = {n="city1",  t="movebtn", x=1000, y=360,  tg = 1, ftg = 0, od=1,  pressanima=true,res = {"img/UI/common/button/XJ_UI_butun_12.png","img/UI/common/button/XJ_UI_butun_13.png"} }
    local btn = GenUiUtil.genUi(btnpos,self,"")
    btn:onButtonClicked(function()        
            GenUiUtil.runOpenEffect(spp)
            -- bg:runAction(seq)
        end)

    btnpos = {n="city2",  t="movebtn", x=1000, y=160,  tg = 1, ftg = 0, od=1,  pressanima=true,res = {"img/UI/common/button/XJ_UI_butun_12.png","img/UI/common/button/XJ_UI_butun_13.png"} }
    btn = GenUiUtil.genUi(btnpos,self,"")
    btn:onButtonClicked(function()  
            spp:setVisible(true)
            spp:setScale(1.0)
            GenUiUtil.runCloseEffect(spp)
            seq =transition.sequence(
                    {   
                        CCDelayTime:create(0.2),
                        CCFadeTo:create(0.08, 0),
                    }
                )
            bg:runAction(seq)
        end)


    
end

--测试播放函数
function TestScrollView:test16()        
    local tb={    
        "action_hero1001.xml",
        "effect_fx_npc20052.xml",
        "effect_fx_npc20044.xml",
        "effect_fx_npc20010.xml",
        "effect_hero1002.xml",
        "effect_fx_hero1003.xml",
        "action_hero1015.xml",
        "action_yeziren.xml",
        "action_laohu.xml",
        "action_hero1014.xml",
        "effect_system.xml",

    }
    GenUiUtil.addArmatureFile("effect_system.xml","res/arm/")
    local arm = GenUiUtil.createArmature("effect_system")
    arm:setPosition(ccp(640,300))
    arm:setAnchorPoint(ccp(0.5,0))
    arm:getAnimation():setSpeedScale(CFG_ANIMA_SPEED)
    arm:getAnimation():play("bomb13",0,-1,0)
    -- GenUiUtil.attackShader(arm,"LK") 
    -- arm:getAnimation():gotoAndPlay(8)
    -- arm:getAnimation():gotoAndPause(8)
    arm:setScale(2.0)
    self:addChild(arm,2)
    -- local sz = arm:getContentSize()
    -- local x,y,w,h = 640-sz.width/2, 300, sz.width, sz.height
    -- self:activeRect(x,y,w,h,'A')

    local ac = transition.sequence({
                CCDelayTime:create(1.5),
                CCCallFunc:create(function ()
                     arm:getAnimation():play("stand",0,-1,-1)
                end)

        })
    self:runAction(ac)
    local cfgg =
    {
        "RED",
        "BLUE",
        "GREEN",
        "STONE",
        --------------------------------------------
        "LIGHT",
        "LIGHTF",
        "TRANS",
        "LK",
        "GOLD",

    }
    local idx = 1
    self:addBtn(800,360,
        function()
            if(idx>#cfgg) then
                idx=1
            end
            GenUiUtil.attackShader(arm,cfgg[idx])
            idx = idx + 1 
        end
        )

    local x,y,w,h = 640-4, 300-4, 8, 8
    self:activeRect(x,y,w,h,'B')
end


function TestScrollView:test15()        
    local nm = "img/GENERAL/Hdbody_hero1001.jpg"
    local masknm = "img/GENERAL/Hdbody_hero1001a.jpg"
    local clipName = "img/UI/common/bg/enlist_kakuang_zhezhao_03.jpg"
    local sp = GenUiUtil.genJpgMaskClipSp(nm,masknm,clipName,"")
    if(sp) then
        sp:setScale(0.5)
        self:addChild(sp)
        sp:setPosition(400,400)      
    end

    local sp = GenUiUtil.genJpgMaskSp(nm,masknm,"")
    if(sp) then
        sp:setScale(0.5)
        self:addChild(sp)
        sp:setPosition(800,400)      
    end
end

function TestScrollView:test14()    
    GenUiUtil.addArmatureFile("img/UI/fight/playing_effect.xml")
    local nd = GenUiUtil.createArmature("playing_effect")
    if(nd) then
        self:addChild(nd)
        nd:setPosition(400,400)
        GenUiUtil.playArmature(nd,"common1",CFG_ANIMA_SPEED)
    end
end

function TestScrollView:test13()
    local REG_KEY_NUMB_4 = "([%-]?%d+)[^%d%-%+]+([%-]?%d+)[^%d%-%+]+([%-]?%d+)[^%d%-%+]+([%-]?%d+)"
    local REG_KEY_NUMB_2 = "([%-]?%d+)[^%d%-%+]+([%-]?%d+)"

    local param = "-1,，-5,jhj1,和规范化,-2"
    local _,_,a,b,c,d = string.find(param,REG_KEY_NUMB_4)
    print("TestScrollView:test13()",a,b,c,d) 

    for x,y  in string.gfind(param,REG_KEY_NUMB_2) do
        print("---------gfind",x,y)
    end


    self.progress = CCProgressTimer:create(display.newSprite("img/UI/common/bg/XJ_UI_ban_0702.png"))
    self.progress:setType(kCCProgressTimerTypeRadial)
    self.progress:ignoreAnchorPointForPosition(false)
    -- self.progress:setContentSize(sz)
    self.progress:setAnchorPoint(ccp(0.0, 0.0))
    -- self.progress:setMidpoint(ccp(0, 0))
    -- self.progress:setBarChangeRate(ccp(0,1))    --对应方向上是否进行设置
    -- self.progress:setMidpoint(ccp(0, 1))        --进度方向 
    self.progress:setPosition(400,400)
    -- self.progress:setPercentage(2.0,100)

    local acc =  CCProgressFromTo:create(2.0,0,100)
     self.progress:runAction(acc)

    self:addChild(self.progress)


end

--测试帧率动画
function TestScrollView:test12()
    local param =
    {
                arc={0.5,0.5},
                --res="img/UI/fight/playing_effect.plist",
                name="img/UI/common/bg/enlist_kakuangB_%02d.png",
                a=1,
                b=4,
                reverse = false,
                loop=true,
                autodel=true,
                onfinish = nil,
                delay=1.0,
                dt=0.1,
 
    }
    --帧动画生成
    local arm = GenUiUtil.genFrameAnim(param)
    arm:setPosition(ccp(640,300))
    arm:setAnchorPoint(ccp(0.5,0.5))
    self:addChild(arm,2)
    local sz = arm:getContentSize()
    local x,y,w,h = 640-sz.width/2, 300, sz.width, sz.height
    self:activeRect(x,y,w,h,'A')

    local x,y,w,h = 640-4, 300-4, 8, 8
    self:activeRect(x,y,w,h,'B')
end

--测试数字变化
function TestScrollView:test11()
    local pathflag = 'img/UI/'
    local btnpos = {n="city1",  t="movebtn", x=640, y=200,  tg = 1, ftg = 0, od=1,  pressanima=true,res = {"img/UI/common/button/XJ_UI_butun_12.png","img/UI/common/button/XJ_UI_butun_13.png"} }
    local btn = GenUiUtil.genUi(btnpos,self,"")

    local lbpos = {n="nm4",  t="txt", x=640, y=320,  tg = 4, ftg = 0,  od=1, color={255,0,0},size=36, txt="0"}

    self.ddi=0
    btn:onButtonClicked(function()        
            if(not self.lb) then
                lbpos.txt = "0"
                local lb = GenUiUtil.genUi(lbpos,self,"")   
                self.lb = lb
                self.ddi=0
                print("----------","new self.lb")
            end
            GenUiUtil.runNumEffect(self.lb,0,self.ddi+1000,0.01,0.5)
            self.ddi=self.ddi+100

            local lbstr = self.lb:getString()
            lbpos = {n="nm4",  t="txt", x=640, y=320,  tg = 4, ftg = 0,  od=1, color={255,0,0},size=36, txt="0"}
            lbpos.txt = "\111\100\30\46"  .. "\52"
            print("--------",lbpos.txt)
            local kslb = GenUiUtil.genUi(lbpos,nil,"")  
            GenUiUtil.runKsEffectSp(self.lb,kslb)            
            
        end)

    local closbtnpos = {n="city1",  t="movebtn", x=840, y=200,  tg = 1, ftg = 0, od=1,  pressanima=true,res = {"img/UI/common/button/XJ_UI_butun_12.png","img/UI/common/button/XJ_UI_butun_13.png"} }
    local closbtn = GenUiUtil.genUi(closbtnpos,self,"")
    closbtn:onButtonClicked(function()
            if(self.lb) then
                self.lb:removeFromParent()
                self.lb = nil
            end    
        end)
end

--测试压缩
function TestScrollView:test10()
    
    local path = CCFileUtils:sharedFileUtils():fullPathForFilename("fileData/skillLv.json")
    local str = io.readfile(path) 
    if str then
        -- str = "111111111"
        print("----get skillLv.json",string.len(str))
        local lz    = require("zlib")
        local Ysstr,eof,inby,outby = lz.deflate()(str,"finish") 
        print("----ys  skillLv.json",eof,inby,outby)
        -- local Jystr = lz.inflate()(Ysstr)        
        -- print("----jy  skillLv.json",string.len(Jystr))
    end

----------------------------------------------------------------------------------
              -- print("----MsgData OR ",string.len(oneMsg.data))
              --       local lz    = require("zlib")
              --       local Ysstr = lz.deflate()(oneMsg.data,"finish") 
              --       print("----MsgData YS ",string.len(Ysstr))
              --       local Jystr, eof = lz.inflate()(Ysstr,"finish")        
              --       print("----MsgData JYS",string.len(Jystr))
----------------------------------------------------------------------------------
end
--测试多血条
function TestScrollView:test9()
    local msp = MultiProgressBar.new("img/UI/common/bg/FB_namedikuang_01.png",
        {   
            "img/UI/fight/ZD_xue_ui03.png",
            "img/UI/fight/ZD_xue_ui02.png",
            "img/UI/fight/ZD_xue_ui03.png",
        },
        0,1)
    msp:pos(400,300);
    msp:addTo(self);
    msp:setPercent(100)

    -- msp.bgsp:setVisible(false)
    dump(msp.range,"-----------",2)

    local dt100 = 0.5
    local perd = 19
    local cellbtn = cc.ui.UIPushButton.new(
                                    {
                                        normal  = "img/UI/common/button/XJ_UI_butun_12.png",
                                        pressed = "img/UI/common/button/XJ_UI_butun_13.png",
                                        disabled = nil,
                                    }, 
                                    {scale9 = false}
                                )
        cellbtn:setAnchorPoint(ccp(0.5,0))
        cellbtn:setPosition(640,200)
        self:addChild(cellbtn,0,0)
        cellbtn:onButtonPressed(function() 
                    local per = msp:getPercent()
                    -- msp:setPercent(per+5)
                    msp:gotoPercent(dt100,per+perd)

                    -- msp:setPercent(per+perd)
                    print("---------getCurPerNum()",msp:getCurPerNum())
            end)  

    cellbtn = cc.ui.UIPushButton.new(
                                    {
                                        normal  = "img/UI/common/button/XJ_UI_butun_12.png",
                                        pressed = "img/UI/common/button/XJ_UI_butun_13.png",
                                        disabled = nil,
                                    }, 
                                    {scale9 = false}
                                )
        cellbtn:setAnchorPoint(ccp(0.5,0))
        cellbtn:setPosition(640,100)
        self:addChild(cellbtn,0,0)
        cellbtn:onButtonPressed(function() 
                    local per = msp:getPercent()
                    -- msp:setPercent(per-5)
                    msp:gotoPercent(dt100,per-perd)                    
                    -- GenUiUtil.runKsEffect(cellbtn,"img/UI/common/button/XJ_UI_butun_12.png")
                    -- msp:setPercent(per-perd)


                    print("---------getCurPerNum()",msp:getCurPerNum())
            end)


end    

--测试模虚影
function TestScrollView:test8()
    local paths = "img/UI/fight/ZD_shuaguai_06.png"


function ksEffect(sp)
    local eftSp = display.newSprite()
    eftSp:setTexture(sp:getTexture())
    eftSp:setTextureRect(sp:getTextureRect())
    eftSp:setAnchorPoint(sp:getAnchorPoint())
    eftSp:setPosition(sp:getPosition())
    sp:getParent():addChild(eftSp)
    local seq = transition.sequence({
            CCDelayTime:create(0.2),
            CCSpawn:createWithTwoActions(CCFadeOut:create(0.5), CCScaleTo:create(0.5,2.0)),
            CCCallFunc:create(function() eftSp:removeSelf() end)
            
        })
    eftSp:runAction(seq)    
end    

    local sppp = display.newSprite(paths);
        sppp:pos(400,300);
        sppp:addTo(self);

    -- GenUiUtil.runKsEffect(sppp,"img/UI/Login/Login_logo.png")
    GenUiUtil.runKsEffect(sppp)
    -- ksEffect(sppp)

     
end
--测试模糊
function TestScrollView:test7()
    EFT_SHADER_PATH = "res/shader/"
    local sppp = display.newSprite("img/UI/Login/Login_logo.png");
    sppp:pos(400,300);
    sppp:addTo(self);
    sppp:setShaderFromFile(EFT_SHADER_PATH .. "Blur.vsh" ,EFT_SHADER_PATH .. "Blur.fsh")    
end
--测试字库
function TestScrollView:test6()
    local nd = VarWImageFont.test()
    nd:setAnchorPoint(ccp(0.5,0.5))
    print("VarWImageFont.tst",nd:getContentSize().width,nd:getContentSize().height)
    nd:setPosition(display.cx, display.cy)
    nd:addTo(self,0) 
end
--测试资源
function TestScrollView:test5()
    ResRead.test()
    local tb = ResGen.getHeroInfo(1)
    dump(tb,"ResGen.getHeroInfo")
    local _,_,a,b = string.find("10023","(%d+)%-(%d+)")
    if(not a) then
        _,_,a = string.find("10023","(%d+)")
    end
    print("===========",a,b)

    _,_,a,b =  string.find("-20,fadfad++-+30","([%-%d]+)[^%d^%-]+([%-]*[%d]+)")
    print("-20p..+30",a,b)
end    

function TestScrollView:test4()
    local sppp = display.newSprite("img/UI/common/bg/item_ui_kang_bzz01.jpg");
    sppp:pos(400,300);
    sppp:addTo(self);

    sppp = GenUiUtil.genJpgMaskSp("img/GENERAL/icon_head_hero1001.png","img/UI/common/bg/item_ui_kang_bzz01.jpg");
    sppp:pos(600,300);
    sppp:addTo(self);
    local __mb = ccBlendFunc()
    __mb.src = GL_SRC_ALPHA
    -- __mb.dst = GL_ONE_MINUS_SRC_ALPHA
    __mb.dst = GL_ONE_MINUS_SRC_ALPHA
    sppp:setBlendFunc(__mb)

--     #define GL_ZERO                 0
-- #define GL_ONE                  1
-- #define GL_SRC_COLOR            0x0300
-- #define GL_ONE_MINUS_SRC_COLOR  0x0301
-- #define GL_SRC_ALPHA            0x0302
-- #define GL_ONE_MINUS_SRC_ALPHA  0x0303
-- #define GL_DST_ALPHA            0x0304
-- #define GL_ONE_MINUS_DST_ALPHA  0x0305
-- #define GL_DST_COLOR            0x0306
-- #define GL_ONE_MINUS_DST_COLOR  0x0307

    -- local __pb = ccBlendFunc()
    -- __pb.src = GL_DST_ALPHA
    -- __pb.dst = GL_ZERO

    local sppp = display.newSprite("img/GENERAL/icon_head_hero1001.png");
    sppp:pos(800,300);
    sppp:addTo(self);
end
function TestScrollView:test3()
    local cellbtn = cc.ui.UIPushButton.new(
                                    {
                                        normal  = "img/UI/common/button/XJ_UI_butun_12.png",
                                        pressed = "img/UI/common/button/XJ_UI_butun_13.png",
                                        disabled = nil,
                                    }, 
                                    {scale9 = false}
                                )
        cellbtn:setAnchorPoint(ccp(0.5,0))
        cellbtn:setPosition(640,40)
        self:addChild(cellbtn,0,0)

        local dis= 6*32
        
        SPEED_FIX = 1000
        SPEED_G = -1200

        self.g = SPEED_G
        cellbtn:onButtonPressed(function() 
                self.speed = SPEED_FIX     
                if(self.hd) then         
                    scheduler.unscheduleGlobal(self.hd)
                end    
                self.hd = scheduler.scheduleUpdateGlobal(
                function(dt)
                    self.speed  = self.speed  + dt*self.g
                    local x,y = cellbtn:getPosition()
                    y = y + (self.speed*0.1)
                    cellbtn:setPosition(x,y)
                    print("speed",self.speed,dt)

                    if(self.speed<-SPEED_FIX or (self.speed<0 and y<40 )) then
                        cellbtn:setPosition(x,40)
                        print("speed<-20",self.speed)
                        scheduler.unscheduleGlobal(self.hd)    
                    end
                end
                )
            end)  
end

function TestScrollView:test2()
    local cellbtn = cc.ui.UIPushButton.new(
                                    {
                                        normal  = "img/UI/common/button/XJ_UI_butun_12.png",
                                        pressed = "img/UI/common/button/XJ_UI_butun_13.png",
                                        disabled = nil,
                                    }, 
                                    {scale9 = false}
                                )
        cellbtn:setAnchorPoint(ccp(0.5,0))
        cellbtn:setPosition(640,0)
        self:addChild(cellbtn,0,0)

        local dis= 6*32
        local sped = 1200      
        local dt = dis/sped
        local rt = 0.2
        cellbtn:onButtonPressed(function() 
            local ac = CCMoveTo:create(dt,ccp(640,dis))
                  ac = CCEaseIn:create(ac,rt)

            local ac1  =  CCDelayTime:create(0.1)      

            local ac2  =  CCMoveTo:create(dt,ccp(640,0))
                  ac2 = CCEaseOut:create(ac2,rt)

            local actb = {ac,ac1,ac2}      
            local seqac = transition.sequence(actb)    

            cellbtn:runAction(seqac) 
            end)
end

function TestScrollView:test1()
    self.scView = ScrollView.new(CCRectMake(0, 0, 600 , 600),2)
    self.scView:setPosition(200,100)
    self:addChild(self.scView)
    for i=1,4 do
        local cell = ScrollViewCell.new(CCSizeMake(200,200),i)
        local sp = display.newSprite("img/UI/mail/mail_icon_0" .. i .. ".png",0,0)
        sp:setAnchorPoint(ccp(0.5,0.5))
        sp:pos(100,100)
        cell:addNode(sp,0,0)
        self.scView:addCell(cell)


        local cellbtn = CellPushButton.new(
                                    {
                                        normal  = "img/UI/common/button/XJ_UI_butun_12.png",
                                        pressed = "img/UI/common/button/XJ_UI_butun_13.png",
                                        disabled = nil,
                                    }, 
                                    {scale9 = false}
                                )
        cellbtn:setAnchorPoint(ccp(0.5,0.5))
        cellbtn:setPosition(100,100)
        cell:addNode(cellbtn,0,0)

        cellbtn:onButtonClicked(function() print("CellPushButton click ",i) end)
        print("iskindof(cellbtn)",iskindof(cellbtn, "CellPushButton"))
    end
    self.scView:setCurrentIndex(4)
    self.scView:setTouchEnabled(true)
end
--测试框框
function TestScrollView:test0()
    local tb={    
        "action_hero1012.xml",
    }
    GenUiUtil.addArmatureFile("action_hero1012.xml","res/arm/")
    local arm = GenUiUtil.createArmature("action_hero1012")
    arm:setPosition(ccp(640,300))
    arm:setAnchorPoint(ccp(0.5,0))
    arm:getAnimation():setSpeedScale(CFG_ANIMA_SPEED)
    arm:getAnimation():play("stand")
    self:addChild(arm,2)
    local sz = arm:getContentSize()
    local x,y,w,h = 640-sz.width/2, 300, sz.width, sz.height
    self:activeRect(x,y,w,h,'A')

    local x,y,w,h = 640-4, 300-4, 8, 8
    self:activeRect(x,y,w,h,'B')
end

function TestScrollView:activeRect(x,y,w,h,color)
    local points={}
    points[1] = {x,y}
    points[2] = {x,y+h}
    points[3] = {x+w,y+h}
    points[4] = {x+w,y}

    if(color=="A") then
        color = cc.c4f(0,1,0,0.5)
    elseif(color=="B") then
        color = cc.c4f(1,0,0,0.5)  
    elseif(color=="S") then
        color = cc.c4f(0,0,1,0.5) 
    elseif(color=="S") then
        color = cc.c4f(0,0,1,0.5)            
    elseif(color=="1") then
        color = cc.c4f(1,1,0,0.5)   
    elseif(color=="2") then
        color = cc.c4f(1,1,1,0.5) 
    else
        color = cc.c4f(0,0,0,0.5) 
    end

    -- local rcnd = CCRectShape:create(cc.size(w, h))
    -- rcnd:setLineColor(color)
    -- rcnd:setFill(true)
    -- rcnd:setLineWidth(1)
    -- rcnd:setContentSize(cc.size(w, h))
    -- display.align(rcnd,display.BOTTOM_LEFT,x,y)
    -- rcnd:addTo(self.GIRDS2)

    local rcnd = display.newDrawNode()
    rcnd:drawPolygon(points,
                        {   
                            fillColor = color,
                            borderWidth =   1,
                            borderColor =   cc.c4f(1,1,1,0.5)
                        }
                    )
    display.align(rcnd,display.BOTTOM_LEFT,0,0)
    self:addChild(rcnd)


end  

return TestScrollView
