require("config")
require("framework.init")
require("framework.shortcodes")
require("framework.cc.init")
require("framework.scheduler")
require("util.util")
require("util.luabridge")
require("util.zip")
add_search_path(game_upd_path)
add_search_path("res/")
----------------------------
run_lua_file("config_game.lua")
run_lua_file(get_tst_cfg_file())

require("config_debug")
----------------------------
require("util.weaktable")
require("ccs.ccs310")
require("tiled.tiledload")
----------------------------
----------------------------
print(string.format("%-10s%10s","67890","12345"))
print(string.format("%-10d%10s",1234567,"12345"))
print(string.format("%-10d%10s",346788899,"12345"))
print(string.format("%10s%10s","67890","12345"))
print(string.format("%s","1234567890"))

--print(string.gsub("format: RGBA8888   \n324","(%a+):%s(%w+)","%1===%2"))
-- a,b,c=string.gsub("format: RGBA8888 \nxy: t240,320\n","(%a+):%s?([%a%d]+[,%s]?[%a%d]+)",function(a,b)
-- 	print(a.."="..b)
-- end)
-- print(a,"==",b,"==",c)

-- local str = get_file_data("skeleton.atlas")
-- string.gsub(str,"(%a+):%s+([%-]?[%a%d]+[,]?[%s]?[%-]?[%a%d]+)",function(a,b)
-- 	print(a.."="..b)
-- end)

local MyApp = class("MyApp", cc.mvc.AppBase)

function MyApp:ctor()
    MyApp.super.ctor(self)
end

function MyApp:run()
    CCFileUtils:sharedFileUtils():addSearchPath("res/")
    self:enterScene("MainScene")
end

return MyApp
