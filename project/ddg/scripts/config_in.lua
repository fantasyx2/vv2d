
-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 1
DEBUG_FPS = true
DEBUG_MEM = false

-- auto encapsulation C++ object
AUTO_CC = false

-- auto binding short methods when encapsulation C++ object
AUTO_CC_SHORTCODES = true

-- load deprecated API
LOAD_DEPRECATED_API = false

-- screen orientation
CONFIG_SCREEN_ORIENTATION = "landscape"

-- design resolution
CONFIG_SCREEN_WIDTH  = 1280
CONFIG_SCREEN_HEIGHT = 720

-- auto scale mode
CONFIG_SCREEN_AUTOSCALE = "FIXED_WIDTH"

--游戏版本号
GAME_VISION = "0.1"

--安装包版本
SIZE_VISION_NUM = 
{
	NOMAL = 1,
	SMALL = 2,
	FULL = 3,
}

SIZE_VISION = SIZE_VISION_NUM.SMALL

--神仙有江湖
APP_ID = 2
APP_KEY = "1235f"

--1 普通副本战斗
--11 活动副本战斗
--12 活动副本战斗乾坤禁地
--13 降妖除魔战斗
--14 公会boss
--2 PVP战斗
--3 新手引导战斗 
--4 测试战斗
FIGHT_TYPE_PVE = 1
FIGHT_TYPE_PVE_AC = 11
FIGHT_TYPE_PVE_AC2 = 12
FIGHT_TYPE_PVE_AC3 = 13
FIGHT_TYPE_PVE_AC4 = 14
FIGHT_TYPE_PVP = 2
FIGHT_TYPE_GUIDE = 3
FIGHT_TYPE_TEST = 4


--历练 101-104
--乾坤禁地 301
--副本 401
--降妖除魔 501
--公会boss 601
--竞技场 201
FIGHT_TEAM_ID_PVE = 401
FIGHT_TEAM_ID_PVE_AC = 101--104
FIGHT_TEAM_ID_PVE_AC2 = 301 
FIGHT_TEAM_ID_PVE_AC3 = 501
FIGHT_TEAM_ID_PVE_AC4 = 601
FIGHT_TEAM_ID_PVP = 201

--红包跑马灯页面
CFG_HONGBAO_RUN_ORDER = 5000
--新手屏蔽页order
CFG_GUIDE_SD_ORDER = 9999
--新手页面的Oder
CFG_GUIDE_ODER = 10000
--网络菊花order
CFG_NET_LADOING_ODER = 15000
--网络页面的Oder
CFG_NET_ODER = 20000
--退出页面的Oder
CFG_EXIT_ODER = 30000

--延时
CFG_GUIDE_CHECK_DELAY = 0.1
CFG_GUIDE_BACK_DELAY = 0.3

--强制显示回能量
-- CFG_SHOW_ENEGY_ADD = true
--强制显示BUFFDOT
--CFG_SHOW_BUFF_DOT_ADD = true

--------------------------------------------------------------------------

--[[
--请求获取平台账号下所有角色信息
-- CFG_GET_SEV_ROLES_URL="http://182.92.23.178:8098/ServerReq4RoleInfo.s"
-- --请求获取公告信息和服务器列表信息
-- CFG_GET_SEV_NTC_URL="http://182.92.23.178:8098/ServerReq4servList.s"

--请求获取平台账号下所有角色信息
-- CFG_GET_SEV_ROLES_URL="http://180.150.189.181:8098/ServerReq4RoleInfo.s"
-- -- --请求获取公告信息和服务器列表信息
-- CFG_GET_SEV_NTC_URL="http://180.150.189.181:8098/ServerReq4servList.s"
--]]

--控制中心地址--在config_ip.lua定义                     
-- CFG_CTRL_BASE_URL = "http://120.132.53.92:8098"
--请求获取平台账号下所有角色信息
CFG_GET_SEV_ROLES_URL = CFG_CTRL_BASE_URL .. "/ServerReq4RoleInfo.s"
--请求获取公告信息和服务器列表信息
CFG_GET_SEV_NTC_URL   = CFG_CTRL_BASE_URL .. "/ServerReq4servList.s"


