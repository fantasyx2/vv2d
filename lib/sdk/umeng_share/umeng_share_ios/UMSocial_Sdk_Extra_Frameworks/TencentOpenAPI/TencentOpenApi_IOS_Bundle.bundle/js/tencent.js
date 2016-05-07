(function(){
	var MTA = {
        Setstart: function () {
            SendCmd._sendMessageToObjectC('TCDataReport', 'mtaStart');
        }
    };
})();(function (){
	var tencent_constants = {
        K_REST_SERVER_BASE_URL: "https://openmobile.qq.com/",
        GET_USER_INFO: "user/get_simple_userinfo",
        //BASE_REQUEST_URL: "https://graph.qq.com/",
        BASE_REQUEST_URL:"https://openmobile.qq.com/",
        GRAPH_OPEN_ID: "oauth2.0/m_me",
        GRAPH_SIMPLE_USER_INFO: "user/get_simple_userinfo",
        GRAPH_USER_INFO: "user/get_user_info",
        GRAPH_USER_PROFILE: "user/get_user_profile",
        GRAPH_ADD_SHARE: "share/add_share",
        GRAPH_ADD_ONE_BLOG: "blog/add_one_blog",
        GRAPH_VIP_INFO: "user/get_vip_info",
        GRAPH_VIP_RICH_INFO: "user/get_vip_rich_info",
        GRAPH_ADD_TOPIC: "shuoshuo/add_topic",
        GRAPH_LIST_ALBUM: "photo/list_album",
        GRAPH_LIST_PHOTO: "photo/list_photo",
        GRAPH_ADD_ALBUM: "photo/add_album",
        GRAPH_UPLOAD_PIC: "photo/upload_pic",
        GRAPH_ADD_PIC_T: "t/add_pic_t",
        GRAPH_ADD_T: "t/add_t",
        GRAPH_GET_T_INFO: "user/get_info",
        GRAPH_DEL_T: "t/del_t",
        GRAPH_SET_AVATAR: "user/set_user_face",
        GRAPH_INTIMATE_FRIENDS: "friends/get_intimate_friends_weibo",
        GRAPH_NICK_TIPS: "friends/match_nick_tips_weibo",
        GRAPH_GET_TENPAY_ADDR: "cft_info/get_tenpay_addr",
        GRAPH_GET_APP_FRIENDS: "user/get_app_friends",
        GRAPH_GET_TENPAY_ADDR:"cft_info/get_tenpay_addr",
        IS_ADD: "1"
    };
    tencent.constants = tencent_constants;
})();

(function(){
	var tencent_info = {
        getUserInfo: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.K_REST_SERVER_BASE_URL + tencent.constants.GET_USER_INFO;
            httpUtils.httpGet(fullURL, key,callBackKey);
            return true;
        },
        getVipUserInfo: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.K_REST_SERVER_BASE_URL + tencent.constants.GRAPH_VIP_INFO;
            httpUtils.httpGet(fullURL, key,callBackKey);
            return true;
        },
        getVipUserRichInfo: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.K_REST_SERVER_BASE_URL +
                tencent.constants.GRAPH_VIP_RICH_INFO;
                httpUtils.httpGet(fullURL, key,callBackKey);
            return true;
        },
        setAvatar: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL =
                tencent.constants.K_REST_SERVER_BASE_URL +
                tencent.constants.GRAPH_SET_AVATAR;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        getTenpayAddr : function(key,callBackkey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.K_REST_SERVER_BASE_URL+
                tencent.constants.GRAPH_GET_TENPAY_ADDR;
            httpUtils.httpGet(fullURL,key,callBackkey);
            return true;
         }
    };
    tencent.info = tencent_info;
})();(function(){
	var local_result = {

        sendStory: function (key, callback) {
            if (!tencent.oauth.validateToken()) return false;
            var url = {
                'accesstoken': tencent.oauth.accessToken,
                'openid': tencent.oauth.openId
            };
            oauth.sendStoryImple(JSON.stringify(url));
            return true;
        },

        httpResponse: function (key, callback) {
            switch (key) {
            case 'getListAlbumResponse:':
            case 'getListPhotoResponse:':
            case 'addShareResponse:':
            case 'addAlbumResponse:':
            case 'uploadPicResponse:':
            case 'checkPageFansResponse:':
            case 'addOneBlogResponse:':
            case 'addTopicResponse:':
                var url = {
                    "key": key,
                    "callback": callback
                };
                oauth.httpJsResponseCallback(JSON.stringify(url));
                break;

            case 'getVipInfoResponse:':
            case 'getVipRichInfoResponse:':
            case 'matchNickTipsResponse:':
            case 'getIntimateFriendsResponse:':
                var url = {
                    "key": key,
                    "callback": callback
                };
                oauth.httpJsResponseCallbackType2(JSON.stringify(url));
                break;

            case 'getUserInfoResponse:':
                var url = {
                    "key": key,
                    "callback": callback
                };
                oauth.httpJsResponseCallbackUserInfo(JSON.stringify(url));
                break;

            case 'onCGIRequestDidResponse:':
                var url = {
                    "key": key,
                    "callback": callback
                };
                oauth.httpJsResponseCallbackType3(JSON.stringify(url));
                break;
            case 'getUserInfoNotShowResponse:':
                var url = {
                    "key": key,
                    "callback": callback
                };
                oauth.httpJsResponseNotShowCallbackUserInfo(JSON.stringify(url));
                break;
            }
        },

        handleAuthorizeResult: function (urlStr) {
            var url = {
                "urlStr": urlStr
            };
            var json = JSON.stringify(url);
            var result =
                openApi.handleOpenUrlJudge(json);
            if ('YES' == result) {
                var getLocation = function (href) {
                    var l = document.createElement("a");
                    l.href = href;
                    return l;
                };

                var urlObject = getLocation(decodeURIComponent(urlStr));
                if (urlObject.protocol.length < 1) {
                    return 'NO';
                }
                var urlScheme = urlObject.protocol.substring(0,
                    urlObject.protocol.length - 1);
                var urlHost =
                    urlObject.hostname;

                if (loacl_appSchema == urlScheme && 'qzapp' == urlHost) {
                    return oauth.jsCallHandleOpenUrlByOpenApi(json);
                } else {
                    return oauth.jsCallHandleOpenURLByOAuth(json);
                }
            }
            return 'NO';
        },
    };
	
	tencent.localresult = local_result;
})();(function(){
	var tencent_logic = {
        initWithAppid: function (appid) {
            tencent.control.initWithAppId(appid);
        },
        getQzoneVersion: function () {
            var answer;
            answer = appUtils.getQzoneVersion();
            log.d("logic","QzoneVersion"+ answer);
            tencent.oauth.QzoneVersion = answer;
        },
        getQQVersion: function () {
            var answer;
            answer = appUtils.getQQVersion();
            log.d("logic", "QQversion="+answer);
            tencent.oauth.QQVersion =
                answer;
        },
        pullQZone: function () {
            log.d("logic", "pullQzone");

            if (tencent.oauth.QzoneVersion == null ||
                tencent.oauth.QzoneVersion == undefined)
                return false;
            if (appUtils.compareVersion(tencent.oauth.QzoneVersion,
                config_version.QzoneLeastVersion) >= 0) {
                var result;
                result = tencent.control.startQzone();
                return result;
            }
            return false;
        },
        pullQQ: function () {
            log.d("logic", "pullQQ");
            if (tencent.oauth.QQVersion == null || tencent.oauth.QQVersion == undefined)
                return false;
            if (appUtils.compareVersion(tencent.oauth.QQVersion,
                config_version.QQLeastVersion) >= 0) {
                var result;
                result = tencent.control.startQQ();
                return result;
            }
            return false;
        },
        pullBrower: function () {
            log.d("logic", "pullBrower()");
            var result;
            result =
                tencent.control.startBrower();
            return result;
        },

    };
    tencent.logic = tencent_logic;
})();(function(){
	 var tencent_netmonitor = {
        //记录当前的网络状�?
        currentNetStatus: undefined,

        //开启Native网络监听模块�?返回值：当前网络状态，包括网络不可用，wifi和wwan三种
        start: function () {
            currentNetStatus =
                SendCmd._sendMessageToObjectC('TCOSDKNetworkMonitor',
                    'StartNotifyNetWork');
            return currentNetStatus;
        },

        //当native发现网络状态发生变化时，会通过此方法通知JS变化后的网络状�?
        statusChanged: function (nstatus) {
            currentNetStatus = nstatus;
            return currentNetStatus;
        }
    };
    tencent.netmonitor = tencent_netmonitor;
})();(function(){
	var tencent_oauth = {
        appid: null,
        QzoneVersion: null,
        QQVersion: null,
        accessToken: null,
        openId: null,
        expirationDate: null,
        UserInfo: true,
        isAdd: false,
        validateToken: function () {
            var myDate = new Date();
            var myDateSeconds = myDate.getTime(); //1970.1.1
            if (QQToken.getAccessToken() == null || QQToken.getOpenId() == null 
            	|| myDateSeconds > QQToken.getExpiresIn() || QQToken.getAppId() == null) {
                return false;
            }
            return true;
        }
    };
	tencent.oauth = tencent_oauth;
})();(function(){
	var tencent_qzone = {
        listAlbum: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_LIST_ALBUM;
                httpUtils.httpGet(fullURL, key,callBackKey);
            return true;
        },
        listPhotos: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_LIST_PHOTO;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        uploadPicture: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_UPLOAD_PIC;
                httpUtils.httpPost(fullURL, key,callBackKey);
                reportUtils.trackCustomEvent('requireApi',tencent.constants.GRAPH_UPLOAD_PIC);
            return true;
        },
        addAlbum: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_ADD_ALBUM;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        sendBlog: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_ADD_ONE_BLOG;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        sendShuoshuo: function (key, callBackKey) {
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_ADD_TOPIC;
                httpUtils.httpPost(fullURL, key,callBackKey);
                reportUtils.trackCustomEvent('requireApi',tencent.constants.GRAPH_ADD_TOPIC);
            return true;
        },
        addShare: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_ADD_SHARE;
            httpUtils.httpPost(fullURL,key,callBackKey);
            reportUtils.trackCustomEvent('requireApi',tencent.constants.GRAPH_ADD_SHARE);
            return true;
        }
    };
	tencent.qzone = tencent_qzone;
})();(function(){
	var tencent_result = {
        loginComplete: function (accessToken, openId, expirationDate) {
            tencent.oauth.isAdd = false;
            tencent.oauth.accessToken =
                accessToken;
            tencent.oauth.openId = openId;
            tencent.oauth.expirationDate = expirationDate;
            reportUtils.reportQQ(openId);
            
            return 'login argument ' + tencent.oauth.accessToken + '...' +
                tencent.oauth.openId + '...' + tencent.oauth.expirationDate;
        },

        shouldUserGetUserInfo: function () {
            return tencent.oauth.UserInfo;
        },

        httpResponse: function (key, callback) {
            try {
                return tencent.localresult.httpResponse(key, callback);
            } catch (e) {
                return e.message;
            }
        },

    };
    tencent.result = tencent_result;
})();(function () {
    /**
     * 定向分享的常�?
     * @type {{RESULTCODE_SUCCESS: number, RESULTCODE_QQNOTINSTALLED: number, RESULTCODE_QQNOTSUPPORTAPI: number, RESULTCODE_MESSAGETYPEINVALID: number, RESULTCODE_CONTENTNULL: number, RESULTCODE_CONTENTINVALID: number, RESULTCODE_APPNOTREGISTED: number, RESULTCODE_APPSHAREASYNC: number, RESULTCODE_APPSHAREASYNC_FAIL: number, RESULTCODE_NOSDCARD: number, RESULTCODE_OPENBROWSEFAIL: number, FILE_NOTEXISTS: number, RESULTCODE_SENDFAILD: number, RESULTCODE_LEGAL: number, MEG_CHECKED: string, ANDROID_QQSHARE_TITLELIMITLENGTH: number, ANDROID_QQSHARE_SUMMAYLIMITLENGTH: number, IOS_QQSHARE_TITLELIMITLENGTH: number, IOS_QQSHARE_SUMMAYLIMITLENGTH: number, SHARE2H5QQ_URL: string, PLATFORM_IOS: string, PLATFORM_ANDROID: string, android_Template: string}}
     */
    var Constants = {
        //错误�?
        RESULTCODE_SUCCESS: 0, //成功

        RESULTCODE_QQNOTINSTALLED: 1, //qq没有安装

        RESULTCODE_QQNOTSUPPORTAPI: 2, //QQ版本不支�?
        RESULTCODE_MESSAGETYPEINVALID: 3, //消息类型不支�?
        RESULTCODE_CONTENTNULL: 4, //内容为空
        RESULTCODE_CONTENTINVALID: 5, //内容不支�?
        RESULTCODE_APPNOTREGISTED: 6, //app没注�?
        RESULTCODE_APPSHAREASYNC: 7, //异步加载图片
        RESULTCODE_APPSHAREASYNC_FAIL: 8,  //异步加载图片失败

        RESULTCODE_NOSDCARD: 9,  //没有SD�?
        RESULTCODE_OPENBROWSEFAIL: 11, //打开浏览器失�?
        FILE_NOTEXISTS: 12,//本地路径不存�?
        RESULTCODE_COMPRESS_FAIL : 13,// 压缩失败
        RESULTCODE_SENDFAILD: -1, //发送失�?
        RESULTCODE_LEGAL: 10, //判断过程合法
        MEG_CHECKED: "checked",//参数已经检查过一遍了，检查完所有的参数后才下载网络图片�?
        DOWNLOAD_SUCCESS : "download_success",
        DOWNLOAD_FAIL : "download_fail",
        COMPRESS_SUCCESS : "compress_success",
        COMPRESS_FAIL : "compress_fail",
        //messageJSON.checked字段会在下载完成网络图片后赋值为1.
        //参数宏定�?
        ANDROID_QQSHARE_TITLELIMITLENGTH: 30, //信息头长�?
        ANDROID_QQSHARE_SUMMAYLIMITLENGTH: 40, //描述长度
        QZONE_SHARE_TITLE_MAX_LENGTH : 200,
        QZONE_SHARE_SUMMARY_MAX_LENGTH : 600,

        //参数宏定�?
        IOS_QQSHARE_TITLELIMITLENGTH: 128, //信息头长�?
        IOS_QQSHARE_SUMMAYLIMITLENGTH: 512, //描述长度


                        
        //qq api objects
        kQQApiResultObject      :"QQApiResultObject",
        kQQApiTextObject        :"QQApiTextObject",
        kQQApiPayObject         :"QQApiPayObject",
        kQQApiAdItem            :"QQApiAdItem",
        kQQApiCommonContentObject   :"QQApiCommonContentObject",
        kQQApiExtendObject      :"QQApiExtendObject",
        kQQApiImageObject       :"QQApiImageObject",
        kQQApiURLObject         :"QQApiURLObject",
        kQQApiAudioObject       :"QQApiAudioObject",
        kQQApiVideoObject       :"QQApiVideoObject",
        kQQApiNewsObject        :"QQApiNewsObject",
        kQQApiWPAObject         :"QQApiWPAObject",
        //ios QQ Message Type
        QQApiMessageTypeShowMessageFromQQRequest  : 1,
        QQApiMessageTypeShowMessageFromQQResponse : 2,
        QQApiMessageTypeGetMessageFromQQRequest   : 3,
        QQApiMessageTypeGetMessageFromQQResponse  : 4,
        QQApiMessageTypeSendMessageToQQRequest    : 5,
        QQApiMessageTypeSendMessageToQQResponse   : 6,
        QQApiMessageTypeSendMessageToQQQZoneRequest : 7,
        QQApiMessageTypeReserved   : 0,
	
		SHARE_TO_QQ_KEY_TYPE : "req_type",
        //android QQ Message Type
        SHARE_TO_QQ_TYPE_DEFAULT: 1,
        SHARE_TO_QQ_TYPE_AUDIO: 2,
        SHARE_TO_QQ_TYPE_HYPERTEXT: 3, // 这个暂时不对外开�?
        SHARE_TO_QQ_TYPE_VIDEO: 4, // 这个暂时不对外开�? 暂不支持视频分享
        SHARE_TO_QQ_TYPE_IMAGE: 5 ,// 纯图片分�?
        SHARE_TO_QQ_TYPE_DEFAULT_SDCARD:6,
        SHARE_TO_QQ_TYPE_AUDIO_SDCARD:7,


        //平台差异
        PLATFORM_IOS: "ios",
        PLATFORM_ANDROID: "android",
        //多图分享到QZone最多支�?�?
        QZONE_SHARE_IMAGE_MAX_NUMBER : 9,
        android_ShareToQZone_Template: 'mqqapi://share/to_qzone?src_type=app&version=1&file_type=news' +
            '&image_url={ImageLocalPath}' +
            '&title={object_title}' +
            '&description={object_description}' +
            '&app_name={app_name}' +
            '&open_id={open_id}' +
            '&share_id={share_id}' +
            '&url={object_targetUrl}'+
            '&req_type={req_type}'+
            '&cflag={cflag}', // 增加扩展字段，后续新加字段可考虑复用此字�?
		//非纯图分享的scheme  对应 android QQ Message Type 1
        android_Template: 'mqqapi://share/to_fri?src_type=app&version=1&file_type=news' +
			'&file_data={ImageLocalPath}' +
            '&image_url={object_imageUrl}' +
            '&title={object_title}' +
            '&description={object_description}' +
            '&app_name={app_name}' +
            '&open_id={open_id}' +
            '&share_id={share_id}' +
            '&url={object_targetUrl}'+
            '&req_type={req_type}'+
            '&cflag={cflag}', // 增加扩展字段，后续新加字段可考虑复用此字�?

        android_Template_SdCard: 'mqqapi://share/to_fri?src_type=app&version=1&file_type=news' +
            '&file_data={ImageLocalPath}' +
            '&title={object_title}' +
            '&description={object_description}' +
            '&app_name={app_name}' +
            '&open_id={open_id}' +
            '&share_id={share_id}' +
            '&url={object_targetUrl}'+
            '&req_type={req_type}'+
            '&cflag={cflag}',


		//纯图分享的scheme           对应 android QQ Message Type 5
		android_Image_Template:'mqqapi://share/to_fri?src_type=app&version=1&file_type=news' +
				'&file_data={ImageLocalPath}' +
				'&app_name={app_name}' +
				'&share_id={share_id}'+
                '&open_id={open_id}' +
				'&req_type={req_type}'+
				'&cflag={cflag}',
        //audio分享                            对应 android QQ Message Type 2
        android_Audio_Template: 'mqqapi://share/to_fri?src_type=app&version=1&file_type=news' +
            '&file_data={ImageLocalPath}' +
            '&image_url={object_imageUrl}' +
            '&title={object_title}' +
            '&description={object_description}' +
            '&app_name={app_name}' +
            '&open_id={open_id}' +
            '&share_id={share_id}' +
            '&url={object_targetUrl}'+
            '&req_type={req_type}'+
            '&cflag={cflag}'+
            '&audioUrl={audioUrl}',

        android_Audio_SD_Template: 'mqqapi://share/to_fri?src_type=app&version=1&file_type=news' +
            '&file_data={ImageLocalPath}' +
            '&title={object_title}' +
            '&description={object_description}' +
            '&app_name={app_name}' +
            '&open_id={open_id}' +
            '&share_id={share_id}' +
            '&url={object_targetUrl}'+
            '&req_type={req_type}'+
            '&cflag={cflag}'+
            '&audioUrl={audioUrl}',


            //分享到QQ的ID 3000，用于回调Listener      Android
            SHARE_TO_QQ_ID:3000,

            // 分享标志�?
            SHARE_TO_QQ:0,
            SHARE_TO_QZONE:1,

	    SHARE_TO_H5_DISABLED: 0,
	    SHARE_TO_H5_ERRURL: 'http://qzs.qq.com/open/mobile/login/qzsjump.html',
	    SHARE_TO_H5_DISABLED_TIP: '错误'
    
    };

    /**
     * 定向分享。分享主要有两种方式：通过手Q分享，通过H5分享。Android目前支持的分享的内容主要�?种类型，HYPERTEXT和VIDEO类型暂不对外开发�?
     *
     * @class QQShare
     */
    var QQShare = {

        /**
         * 分享消息的json对象.for ios only
         *
         * @property QQApiMessageJson
         * @type {object_title}
         * @type {object_description}
         * @type {object_url}
         * @type {object_previewImageUrl}
         * @type {platform}
         * @type {object_type}
         * @type {message_type}
         * @type {app_name}
         * @type {text_data}
         * @type {flash_url}
         * @default "undefined"
         */
        QQApiMessageJson: undefined,

        resultCode: undefined,

        previewLocalhost: "http://openmobile.qq.com/api/check?page=shareindex.html&style=9",

        SHARE_QZONE_H5_URL : "http://openmobile.qq.com/api/check2?page=qzshare.html&loginpage=loginindex.html&logintype=qzone",


    /**
         * 分享的入口，native封装好json数据后，直接调用QQShare.shareMessageToQQ
         *
         * @method shareMessageToQQ
         * @param {Object} MessageJson，这里为了去掉平台的差异性，iOS这边需要将大量的参数传�?
         * 方便统一，native把参数封装成JSON串再传入js
         * @return {Number} Returns resultCode，根据resultCode判断分享成功与否
         */
        shareMessageToQQ: function (MessageJson) {
            if (MessageJson.platform === Constants.PLATFORM_IOS) 
	    log.d("MessageJson",JSON.stringify(MessageJson));
            log.d("platform", MessageJson.platform);
            //检查参数是否合法，并返回一个结果码
            if (MessageJson.platform === Constants.PLATFORM_IOS) {
                var resultCode = this.IOScheckParams(MessageJson);
                if (resultCode !== Constants.RESULTCODE_LEGAL) {
                    log.d('参数失败', resultCode);
                    //根据错误码做出响�?
                    return resultCode;
                }
                MessageJson = this.QQApiMessageJson;
                if(MessageJson.object_type === Constants.kQQApiWPAObject)
                {
                    var url = this.fillPrams(this.QQApiMessageJson);
                    return QQApi.handleWPAMessageShare(url);
                }
            } else {
                MessageJson = qqShareUtils.initMsg(MessageJson);
                resultCode = this.AndroidcheckParams(MessageJson);
            }
            log.d('参数检查完�?, resultCode);
            if (resultCode !== Constants.RESULTCODE_LEGAL) {
                log.d('参数失败', resultCode);
                //根据错误码做出响�?
                return resultCode;
            } else {
                log.d('参数成功', resultCode);
                //checkMobileQQ()：判断手Q是否安装或是否支持（android、IOS共有），
                //isPlatformSupport()�?平台支持，appregist等，iOS需要检查scheme是否有效；判断手Q是否安装或是否支持（android、IOS共有�?
                //把checkMobileQQ结合到isPlatformSupport()


                resultCode = qqShareUtils.isPlatformSupport();

                if (resultCode === Constants.RESULTCODE_LEGAL) {
                       //目前是分享多图，手Q小于5.0  平台是Qzone就走分享h5    这里暂时使用的是android平台判断
                    if(MessageJson.platform === Constants.PLATFORM_ANDROID){
			if (appUtils.compareVersion(appUtils.getQQVersion(), "5.0.0") < 0&&MessageJson.IsImageUrlArrayList&&MessageJson.shareType===Constants.SHARE_TO_QZONE) {
    
			    retCode = this.share2H5QQ(MessageJson);
			    if (retCode !== Constants.RESULTCODE_SUCCESS) {
				return retCode;
			    } else {
				return resultCode;
			    }
			}
                    }
		    else if (MessageJson.platform === Constants.PLATFORM_IOS) {
			if (MessageJson.shareType == Constants.SHARE_TO_QZONE && appUtils.getQQVersion() < ios_constants.kQQ_VERSION_5_0) {
			    if (MessageJson.object_type === Constants.kQQApiTextObject || MessageJson.object_type === Constants.kQQApiImageObject ) {
				return Constants.RESULTCODE_QQNOTINSTALLED;
			    }
			    else {
				retCode = this.share2H5QQ(MessageJson);
				if (retCode !== Constants.RESULTCODE_SUCCESS) {
				    return retCode;
				} else {
				    return resultCode;
				}
			    }
			}
		    }
                    //分享到手Q
                    return this.share2MobileQQ(MessageJson);
                } else {
                    //h5 分享
                    retCode = this.share2H5QQ(MessageJson);
                    if (retCode !== Constants.RESULTCODE_SUCCESS) {
                        return retCode;
                    } else {
                        return resultCode;
                    }
                }
            }
        },
        /**
         * 通过手Q分享
         *
         * @method share2MobileQQ
         * @param {Object} MessageJson
         * @return {Number} Returns resultCode，根据resultCode判断分享成功与否
         */
        share2MobileQQ: function (MessageJson) {
            log.d("share2MobileQQ", MessageJson.platform);
            if(MessageJson.platform === Constants.PLATFORM_ANDROID){
                reportUtils.trackCustomEvent("requireApi", "shareToNativeQQ");
            }
            if (MessageJson.platform === Constants.PLATFORM_IOS) {
                var resultCode = this.isImageDataLegal(MessageJson);
                if (resultCode !== Constants.RESULTCODE_LEGAL) {
                    return resultCode;
                }
            }

            var url = this.fillPrams(MessageJson);
            //跳转到Native
            return qqShareUtils.callNativeQQShare(url);
        },
        /**
         * 通过H5分享
         *
         * @method share2H5QQ
         * @param {Object} MessageJson
         * @return {Number} Returns resultCode，根据resultCode判断分享成功与否
         */
        share2H5QQ: function (MessageJson) {
	    //如果不允许H5分享，拉起webView并导航至错误页面
	    if (MessageJson.shareType == Constants.SHARE_TO_QZONE && Constants.SHARE_TO_H5_DISABLED) {
		log.d("shareh5","disable");
		appUtils.openNativeWebView(Constants.SHARE_TO_H5_ERRURL, Constants.SHARE_TO_H5_DISABLED_TIP);
		return Constants.RESULTCODE_SENDFAILD;
	    }
	    
            log.d("share2H5QQ","platform="+MessageJson.platform);
            if (MessageJson.platform === Constants.PLATFORM_ANDROID) {
                reportUtils.trackCustomEvent("requireApi", "shareToH5QQ");
            }
            log.d('after','reportUtils');
            if (MessageJson.platform === Constants.PLATFORM_IOS) {
                if(MessageJson.isUrlObject === 'NO')
                   return Constants.RESULTCODE_QQNOTINSTALLED;
                var result1 = QQApi.isRegistScheme(loacl_appSchema);//?
                if(result1 === 'NO')
                    return Constants.RESULTCODE_QQNOTINSTALLED;
            }
            log.d('define','h5json');
            var h5json = {};
            h5json = qqShareUtils.getSDKInfo();

            if (0 < MessageJson.object_title.length) {
                if(MessageJson.object_title.length>40)
                    MessageJson.object_title=MessageJson.object_title.substring(0,40)+"...";
                var title = MessageJson.object_title;
                h5json['title'] = title;
            } else
                return Constants.RESULTCODE_CONTENTINVALID;
            if (0 < MessageJson.object_description.length) {
                if(MessageJson.object_description.length>80)
                    MessageJson.object_description=MessageJson.object_description.substring(0,80)+"...";
                var description = MessageJson.object_description;
                h5json['summary'] = description;
            }
            if (0 < MessageJson.object_targetUrl.length) {

                h5json['targeturl'] = MessageJson.object_targetUrl;
            }
            else
                return Constants.RESULTCODE_CONTENTINVALID;

            if(MessageJson.object_type === Constants.kQQApiAudioObject){
                h5json['audio_url'] = MessageJson.object_targetUrl;
                h5json['req_type'] = '2';
            }

            //tencent_oauth.appid = "222222";
	    if (MessageJson.platform === Constants.PLATFORM_ANDROID) {
		var appId = sdk_QQToken.getAppId() + "";
	    } else if (MessageJson.platform === Constants.PLATFORM_IOS) {
		var appId = QQToken.getAppId() + "";
	    }
            if (0 < appId.length) {
                h5json['appId'] = appId;
            } else
                return Constants.RESULTCODE_SENDFAILD;

            if (0 < MessageJson.object_imageUrl.length) {//ios:object_previewImageUrl
                h5json['imageUrl'] = MessageJson.object_imageUrl;
            }
            h5json['site'] = MessageJson.app_name;
            if(MessageJson.app_name==undefined)  {
                h5json['site'] = appUtils.getAppName();
            }
            h5json['type'] = MessageJson.type;
            h5json['appName']= appUtils.getAppName();

            var query_temp = '';
            for (var itm in h5json) {

                query_temp += '&' + itm + '=' + encodeURIComponent(h5json[itm]);


            }
            query_temp=query_temp.replace(new RegExp('\\+', 'g'), '%20');
 
            if(MessageJson.shareType)
            {
                if(MessageJson.shareType===Constants.SHARE_TO_QQ){
                var share_url = this.previewLocalhost+query_temp;
                } else if(MessageJson.shareType===Constants.SHARE_TO_QZONE){

                var share_url = this.SHARE_QZONE_H5_URL+query_temp;
                }
            }
            else
            {
                var share_url = this.previewLocalhost+query_temp;
            }

            log.d('url', share_url);
           return qqShareUtils._openH5QQToShare(share_url);

        },

        /**
         * 判断图片大小是否合法
         */
        isImageDataLegal:function(MessageJson)
        {
	    log.d('isImageDataLegal');
	    if (MessageJson.key_ImageDataArray) {
		var imgDataArrayKey = MessageJson.key_ImageDataArray;

		if (TencentDataMgr.objSize(imgDataArrayKey) > (10 * 1024 * 1024)) {
		    return Constants.RESULTCODE_CONTENTINVALID;
		}
	    }
	    
            if(QQApi.isLargeDataLengthLegal(MessageJson.file_type))
            {
                return Constants.RESULTCODE_LEGAL;
            }
            return Constants.RESULTCODE_CONTENTINVALID;
        },

        /**
         * 参数检�?
         *
         * @method IOScheckParams
         * @param {Object} MessageJson
         * @return {Number} Returns resultCode，根据resultCode判断参数与否合法
         */
        IOScheckParams: function (MessageJson) {
            var tail = "...";
             if(!MessageJson.object_title || MessageJson.object_title.length <= 0){
                if(MessageJson.isUrlObject === 'YES')
                    return Constants.RESULTCODE_CONTENTNULL;
             }
             log.d('title');
             if(!MessageJson.text_data || MessageJson.text_data.length <= 0){
                if(MessageJson.object_type === Constants.kQQApiTextObject){
                    return Constants.RESULTCODE_CONTENTNULL;
                }
             }
             log.d('text');
	        if (MessageJson.object_title !== null && MessageJson.object_title.length > Constants.QQSHARE_TITLELIMITLENGTH) {
		        MessageJson.object_title = MessageJson.object_title.substring(0, Constants.QQSHARE_TITLELIMITLENGTH) + tail;
	        }
	        if (MessageJson.object_description !== null && MessageJson.object_description.length > Constants.QQSHARE_SUMMAYLIMITLENGTH) {
		       MessageJson.object_description = MessageJson.object_description.substring(0, Constants.QQSHARE_SUMMAYLIMITLENGTH) + tail;
	        }
            //wpa
            if(MessageJson.object_type === Constants.kQQApiWPAObject)
            {
                log.d('uin',MessageJson.uin);
                this.QQApiMessageJson = MessageJson;
                if (MessageJson.uin && MessageJson.uin.length)
                {
                    return Constants.RESULTCODE_LEGAL;
                }
                return Constants.RESULTCODE_SENDFAILD;
            }

            if(MessageJson.object_type === Constants.kQQApiPayObject){
                if('NO' === QQApi.isQQSupportApiForWallet())
                    return Constants.RESULTCODE_QQNOTSUPPORTAPI;
            }

            if('NO' === QQApi.isRegistScheme())
            {
                return Constants.RESULTCODE_APPNOTREGISTED;
            }

            var messageType = Number(MessageJson.message_type);
            var objectType = MessageJson.object_type;
 
            //判断消息类型
            if(messageType !== Constants.QQApiMessageTypeShowMessageFromQQResponse &&
               messageType !== Constants.QQApiMessageTypeGetMessageFromQQResponse &&
               messageType !== Constants.QQApiMessageTypeSendMessageToQQRequest &&
               messageType !== Constants.QQApiMessageTypeSendMessageToQQQZoneRequest){
                //log.d("parame error: illegal message type");
                //#dbg
                log.d("parame error: illegal message type " + messageType);
                return Constants.RESULTCODE_MESSAGETYPEINVALID;
            }
 
            //判断消息体类型是否为支持类型
            if(objectType !== Constants.kQQApiTextObject &&
               objectType !== Constants.kQQApiExtendObject &&
               objectType !== Constants.kQQApiImageObject &&
               objectType !== Constants.kQQApiCommonContentObject &&
               objectType !== Constants.kQQApiPayObject &&
               MessageJson.isUrlObject !== 'YES'){
                log.d("param error: illegal object type");
                return Constants.RESULTCODE_CONTENTINVALID;
            }

            var urlflag = true;
            if (MessageJson.isUrlObject !== 'YES') {
                urlflag = false;
            }
            if (urlflag === true) {
                if('NO' === QQApi.checkQQApiURLMessage())
                {
                    return Constants.RESULTCODE_CONTENTINVALID;
                }
                retCode = QQApi.resendUrlObjectSyncShare();
                log.d('异步加载图片',retCode);
                if (Number(retCode) === Constants.RESULTCODE_APPSHAREASYNC) {
                    return Constants.RESULTCODE_APPSHAREASYNC;
                }
            }

            //将MessageJson赋值给QQApiMessageJson对象，并返回一个成功码
            this.QQApiMessageJson = MessageJson;
            log.d('赋�?, 'QQApiMessageJson');
            return Constants.RESULTCODE_LEGAL;
        },

        /**
         * 参数检�?
         *
         * @method AndroidcheckParams
         * @param {Object} MessageJson
         * @return {Number} Returns resultCode，根据resultCode判断参数与否合法
         */
        AndroidcheckParams: function (MessageJson) {


             log.d("qqsharejs", "checkParams-begin");
                //下载网络图片或者是压缩图片后会重新进入js，之前已经检查过一遍了，直接返回检查正�?
                if (MessageJson.checkedflag === Constants.MEG_CHECKED){
                    return Constants.RESULTCODE_LEGAL;
                }
                 // 感觉这个有点怪应该是本地图片才判断这个，但是和主干保持一致哈�?
                if (!appUtils.hasSDcard()) {
                //没有sd卡，返回一个错误码
                uiListener.onError("-6","分享图片失败，检测不到SD�?",null,Constants.SHARE_TO_QQ_ID);
                return Constants.RESULTCODE_NOSDCARD;
                }



                /**
                 * 对于ImageUrl的处理，这里比较蛋疼
                 */
                log.d("qqsharejs",MessageJson.IsImageUrlArrayList);
                if (MessageJson.IsImageUrlArrayList) {//分享多图
                    log.d("qqsharejs","MessageJson.object_imageUrl�? + MessageJson.object_imageUrl.toString());
                    var imageUrlArray = MessageJson.object_imageUrl.toString().split(";");
                    log.d("qqsharejs","imageUrlArray:" + imageUrlArray.toString());
                    if (!Array.isArray(imageUrlArray)) {
                        uiListener.onError("-6","分享图片失败，object_imageUrl传入不正�?",null,Constants.SHARE_TO_QQ_ID);
                        return ;
                    }
                    for (var i = 0; i < imageUrlArray.length; i++) {

                        if (!appUtils.isValidUrl(imageUrlArray[i]) || !appUtils.fileExists(imageUrlArray[i])) {
                            imageUrlArray.slice(i,1);
                        }

                    }
                    MessageJson.object_imageUrl = imageUrlArray.toString();

                    if (appUtils.compareVersion(appUtils.getQQVersion(), "5.0.0") < 0) {

                        return Constants.RESULTCODE_LEGAL;
                    }
                    //交给Native压缩图片再返回压缩后的图片给js
                    qqShareUtils.AsynscaleCompressImage(MessageJson);
                    return;
                } else {//分享单图
								var type = Number(MessageJson.type);
                var extFlags = Number(MessageJson.cflag);   // 扩展字段可以用，只是在旧版本不做处理
                log.d("type",type) ;
                if (type === Constants.SHARE_TO_QQ_TYPE_IMAGE /*|| extFlags != 0 || !TextUtils.isEmpty(extStr)*/) {//纯图分享
                    // 扩展字段和纯图分享只能在QQ4.3及以上版本使�?
                if (appUtils.compareVersion(appUtils.getQQVersion(), "4.5.0") < 0) {
                    uiListener.onError("-6","QQ4.5及以上版本才支持纯图分享!",null,Constants.SHARE_TO_QQ_ID);
                    return Constants.RESULTCODE_QQNOTSUPPORTAPI;
                }
								// 判断imageUrl是否是合法的url或者本地path
                    log.d("object_imageUrl",MessageJson.object_imageUrl) ;
                                         //之前的逻辑对url是否为网络图片判断有问题，这里首先保证imageurl不是网络且不为空
									if (MessageJson.object_imageUrl !== null &&!strUtil.isUrlValidate(MessageJson.object_imageUrl )) {
										// imageUrl不为�? 并且imageUrl不是网络地址
										MessageJson.ImageLocalPath = MessageJson.object_imageUrl;
										
										if (!appUtils.fileExists(MessageJson.object_imageUrl)) {
											// 文件不存�? 表示不是合法的本地路�?
											return Constants.FILE_NOTEXISTS;
										}

                                        resultCode = qqShareUtils.isPlatformSupport();

                                        if (resultCode != Constants.RESULTCODE_LEGAL) {
                                            uiListener.onError("-6","未安装手Q h5不支持本地图片纯图分�?,null,Constants.SHARE_TO_QQ_ID);
                                            return;
                                        }
										
									}
                } else {//非纯图分�?
                    /**
                     * 对于title、summary的处�?
                     */
                    if(strUtil.isEmpty(MessageJson.object_title)||MessageJson.object_title === null){
                        uiListener.onError("-6","title不能为空!!",null,Constants.SHARE_TO_QQ_ID);
                        log.v("share.js", "shareToQQ() title null--end");
                        return Constants.RESULTCODE_CONTENTNULL;
                    }
                    //title、summary有字数限�?     Qzone 和QQ分享对字数限制不一�?
                    if(MessageJson.shareType===Constants.SHARE_TO_QQ){
                        qqShareUtils.lengthLimite(MessageJson.object_title, Constants.ANDROID_QQSHARE_TITLELIMITLENGTH);
                        qqShareUtils.lengthLimite(MessageJson.object_description , Constants.ANDROID_QQSHARE_SUMMAYLIMITLENGTH);
                    } else if(MessageJson.shareType===Constants.SHARE_TO_QZONE){
                        qqShareUtils.lengthLimite(MessageJson.object_title, Constants. QZONE_SHARE_TITLE_MAX_LENGTH );
                        qqShareUtils.lengthLimite(MessageJson.object_description , Constants.QZONE_SHARE_SUMMARY_MAX_LENGTH);
                    }



                //检测target_url
                if(strUtil.isEmpty(MessageJson.object_targetUrl)||!strUtil.isUrlValidate(MessageJson.object_targetUrl)) {

                    uiListener.onError("-6","传入参数有误!",null,Constants.SHARE_TO_QQ_ID);
                    log.v("share.js", "shareToQQ() targetUrl error--end");
                    return ;
                }

                 //判断是本地路路径 使用本地模版，但是不要和使用Audio模版混淆
                if (!strUtil.isEmpty(MessageJson.object_imageUrl)&&!strUtil.isUrlValidate(MessageJson.object_imageUrl)&&MessageJson.type==Constants.SHARE_TO_QQ_TYPE_DEFAULT ) {
                    // 判断文件是否存在
                    if(!appUtils.fileExists(MessageJson.object_imageUrl))
                    {      uiListener.onError("-6","非法的图片地址!",null,Constants.SHARE_TO_QQ_ID);
                        return ;
                    }
                    MessageJson.type=  Constants.SHARE_TO_QQ_TYPE_DEFAULT_SDCARD;
                }

                //音乐有本地图片分享模版，这种拼模版的方式真是要搞死了....以后一定要重构�?       MessageJson.type===Constants.SHARE_TO_QQ_TYPE_AUDIO     为false
                if(!strUtil.isEmpty(MessageJson.object_imageUrl)&&!strUtil.isUrlValidate(MessageJson.object_imageUrl)&&MessageJson.type==Constants.SHARE_TO_QQ_TYPE_AUDIO){
                    if(!appUtils.fileExists(MessageJson.object_imageUrl))
                    {      uiListener.onError("-6","非法的图片地址!",null,Constants.SHARE_TO_QQ_ID);
                        return ;
                    }
                    MessageJson.type=  Constants.SHARE_TO_QQ_TYPE_AUDIO_SDCARD;
                    log.d("ismusic","musicSD");
                }

                    log.d("message_type",MessageJson.type);

										// android 先判断imageUrl是否网络图片，如果是网络图片先下�?先保证有sd�?
							// ios 判断是否为URL Object，是则异步加载图片，android则是判断http://
							if (!strUtil.isEmpty(MessageJson.object_imageUrl)&&strUtil.isUrlValidate(MessageJson.object_imageUrl)) {
							//是网络图片android则要检测sd卡，
							// sd卡为空，不允许分享，发图片需要sd卡支持，这个步骤放到局部去实现
					        // 先判断是否网络图片，如果是网络图片先下载,先保证有sd�?
					
							log.d("分享", "网络图片");
							if (!appUtils.hasSDcard()) {
					            uiListener.onError("-6","分享图片失败，检测不到SD�?",null,Constants.SHARE_TO_QQ_ID);
					             return Constants.RESULTCODE_NOSDCARD;
								}
					
					         if (appUtils.compareVersion(appUtils.getQQVersion(), "4.5.0") >=0) {
					          //  4.5以上的版�? 由于不需要拼�? 所以可以不下载图片, 直接分享
					             } else{
					          // 根据网址的md5判断本地图片是否存在
					          qShareUtils.AsynLoadImage(MessageJson);
					            return;
					           }
						} else{
                                // 4.5以上的版�?�?.5)先压缩本地图片至140px, 再将压缩后的图片存储, 把新图片的路径传给SHARE_TO_QQ_IMAGE_LOCAL_URL
                                // 本地图片在手Q中的表现为imageUrl为空(待手Q上传图片后获取到网络地址再在手Q中赋�?, localPath有�?
                                if(!appUtils.fileExists(MessageJson.object_imageUrl))
                                {      uiListener.onError("-6","非法的图片地址!",null,Constants.SHARE_TO_QQ_ID);
                                    return ;
                                }
                          if (appUtils.compareVersion(appUtils.getQQVersion(), "4.5.0") >= 0) {
                              qqShareUtils.AsynscaleCompressImage(MessageJson);
                              return;
                          } else{
                              MessageJson.ImageLocalPath = undefined;
                              uiListener.onError("-6","QQ4.5及以上版本才支持本地图片压缩!",null,Constants.SHARE_TO_QQ_ID);
                          }
                }

            } }


            log.d("localjs", "checkparams end，ok");
            //将MessageJson赋值给QQApiMessageJson对象，并返回一个成功码
            this.QQApiMessageJson = MessageJson;
            return Constants.RESULTCODE_LEGAL;
        },
        /**
         * 封装通用参数，封装的参数主要有平台参数，请求CGI的参数，并对参数进行BASE64编码
         *
         * @method fillPrams
         * @param {Object} MessageJson
         * @return {JSON} 返回封装好参数的JSON
         */
        fillPrams: function (MessageJson) {
            log.d("fillPrams");
            if (MessageJson.platform === Constants.PLATFORM_IOS) {
                var queryJson = {};
                queryJson['callback_type'] = 'scheme';
                queryJson['version'] = '1';
                queryJson['src_type'] = 'app';
		
		if (MessageJson.key_ImageDataArray) {
		    log.d('fillParms - keyImageDataArray')
		    //queryJson['pasteboard_obj'] = TencentDataMgr.addObjectInPastboard(MessageJson.key_ImageDataArray);
		    TencentDataMgr.removeKeyFromDataMgr(MessageJson.key_ImageDataArray);
		}

                var tscheme = QQApi.getQQScheme();//'QQ0003640E';
                if(tscheme && tscheme.length)
                {
                    queryJson['callback_name'] = tscheme;
                }
                log.d('scheme',tscheme);

                var title = MessageJson.object_title;
                if (title && title.length)
                    queryJson['title'] = window.btoa(unescape(encodeURIComponent(title)));

                var description = MessageJson.object_description;
                if (description && description.length)
                    queryJson['description'] = window.btoa(unescape(encodeURIComponent(description)));
                log.d('title&description',title+'&'+description);

                if(MessageJson.object_type === Constants.kQQApiWPAObject)
                {
                    var wpaName = appUtils.getAppName();
                    log.d('wpagetappname',wpaName);

                    queryJson['thirdAppDisplayName'] = window.btoa(unescape(encodeURIComponent(wpaName)));
                    //如果scheme为空，不应该有callback_type，如果出错，优先考虑这里
                    queryJson['chat_type'] = 'wpa';
                    queryJson['uin'] = MessageJson.uin;

                    log.d('wpafillparams','start');
                    var wpalocalhost = 'mqqwpa://im/chat?';
                    var wquery = '';
                    for(var key in queryJson)
                    {
                        wquery +='&' + key + '='+queryJson[key];
                    }
                    wpalocalhost += wquery.slice(1);

                    return wpalocalhost;
                }else{
                    var appname = MessageJson.app_name;
                    if(appname && appname.length)
                    {
                        queryJson['thirdAppDisplayName'] = window.btoa(unescape(encodeURIComponent(appname)));
                    }
                }

                if(MessageJson.message_type === Constants.QQApiMessageTypeGetMessageFromQQResponse)
                {
                    queryJson['messagetype'] = 'responsefromapp';
                }
                //pay
                if(MessageJson.object_type === Constants.kQQApiPayObject)
                {
                    queryJson['order_no'] = MessageJson.order_no;

                    var walletlocalhost = 'mqqapiwallet://wallet/pay?';
                    var wquery = '';
                    for(var key in queryJson)
                    {
                        wquery +='&' + key + '='+queryJson[key];
                    }
                    walletlocalhost += wquery.slice(1);
                    return walletlocalhost;
                }

                if(MessageJson.isUrlObject === 'YES')
                {
                    queryJson['objectlocation'] = 'pasteboard';
                    var turl = MessageJson.object_targetUrl;
                    if(turl && turl.length)
                    {
                        queryJson['url'] = window.btoa(unescape(encodeURIComponent(turl)));
                    }
                    var tpreurl = MessageJson.object_imageUrl;
                    if(tpreurl && tpreurl.length)
                    {
                        queryJson['previewimageUrl'] = window.btoa(unescape(encodeURIComponent(tpreurl)));
                    }
                    if (MessageJson.flash_url && MessageJson.flash_url.length)
                        queryJson['flashurl']= window.btoa(unescape(encodeURIComponent(MessageJson.flash_url)));
                }
                switch(MessageJson.object_type)
                {
                    case Constants.kQQApiTextObject:
                        queryJson['file_type'] = 'text';
                        var text = MessageJson.text_data;
                        if (text && text.length)
                            queryJson['file_data'] = window.btoa(unescape(encodeURIComponent(text)));
                    break;
                    case Constants.kQQApiExtendObject:
                        queryJson['file_type'] = 'file';
                        queryJson['objectlocation'] = 'pasteboard';
                    break;
                    case Constants.kQQApiImageObject:
                        queryJson['file_type'] = 'img';
                        queryJson['objectlocation'] = 'pasteboard';
                    break;
                    case Constants.kQQApiAudioObject:
                    queryJson['file_type'] = 'audio';
                    break;
                    case Constants.kQQApiNewsObject:
                    queryJson['file_type'] = 'news';
                    break;
                    case Constants.kQQApiVideoObject:
                    queryJson['file_type'] = 'video';
                    break;
                    case Constants.kQQApiURLObject:
                    queryJson['file_type'] = 'url';
                    break;
                    case Constants.kQQApiCommonContentObject:
                        queryJson['file_type'] = 'common';
                        queryJson['objectlocation'] = 'pasteboard';
                    break;
                    default:
                        queryJson['file_type'] = 'unknown';
                    break;
                }
                var topenid = tencent.oauth.openId;
                if( topenid && topenid.length)
                {
                    queryJson['openId'] = topenid;
                }

                if(QQApi.isQQSupportApiGeneralPastboard() === 'YES')
                {
                    queryJson['generalpastboard'] = '1';
                }
                queryJson['cflag'] = MessageJson.cflag;
        
                //pangzhang qzone qq分享
                queryJson['shareType'] =  '0';
                if(MessageJson.shareType
                   && MessageJson.shareType===Constants.SHARE_TO_QZONE)
                {
                    queryJson['shareType'] =  '1';
                }

                //query url
                var localhost = 'mqqapi://share/to_fri?';
                var cquery = '';
                for(var key in queryJson)
                {
                    cquery +='&' + key + '='+queryJson[key];
                }
                localhost += cquery.slice(1);

                //set big data
                if(MessageJson.isUrlObject == 'YES'){
                    QQApi.setURLObjectPasteBoardDatas();
                }else{
                    switch(MessageJson.object_type){
                        case Constants.kQQApiImageObject: QQApi.setImageObjectPasteBoardDatas();
                            break;
                        case Constants.kQQApiExtendObject: QQApi.setExtendObjectPasteBoardDatas();
                            break;
                        case Constants.kQQApiCommonContentObject: QQApi.setCommonObjectPasteBoardDatas();
                            break;
                        default: break;
                    }
                }
                return localhost;
            } else {//android
                MessageJson.app_name =   appUtils.getApplicationLable()===null? MessageJson.app_name : appUtils.getApplicationLable();
                var appId = sdk_mToken.getAppId();
                var openId = sdk_mToken.getOpenId();
                MessageJson.share_id = appId+"";
                MessageJson.open_id = sdk_QQToken.getOpenId()+"";

                for (key in MessageJson) {
                    if (MessageJson[key] !== undefined&&MessageJson[key] !="undefined") {
                        log.d("key:" + key, "value:" + MessageJson[key]);

                        if (key === "share_id"||key === "type"||key === "shareType")continue;

                        if(key==="appName"){
                            if(!strUtil.isEmpty(MessageJson[key])) {
                                 if(MessageJson[key].length>20){
                                     MessageJson[key]=MessageJson[key].substring(0,20);
                                 }
                            }
                        }
                        //多图分享，对每个url进行URI编码
                        if (MessageJson.shareType===Constants.SHARE_TO_QZONE) {
                            //  分享到Qzone
                            if (key === "ImageLocalPath") {
                                var imageUrl = "";
                                log.d("imageU",MessageJson[key]);
                                var object_imageUrl_array =  MessageJson[key].split(",");
                                log.d("imageUrl-",object_imageUrl_array.toString());
                                if (Array.isArray(object_imageUrl_array)){
                                    for (var i = 0; i < object_imageUrl_array.length; i++)  {
                                        log.d("imageUrl-",object_imageUrl_array[i].toString());
                                        imageUrl =imageUrl+ encodeURIComponent(object_imageUrl_array[i]) + ";";
                                        log.d("imageUrl--",imageUrl.toString());
                                    }
                                }
                                MessageJson[key] =imageUrl.substring(0,imageUrl.length-1);

                                log.d("imageUrl---",imageUrl.toString());
                            }

                        }

                        MessageJson[key] = BASE64.encode(MessageJson[key]);
                    }

                }
                log.d("sharetoQzone",MessageJson.shareType === Constants.SHARE_TO_QZONE );
                //直接唤起分享到手Q中的QZone
                if (MessageJson.shareType === Constants.SHARE_TO_QZONE ) {
                    log.d("sharetoQzone","success");
                    return this.substitute(Constants.android_ShareToQZone_Template, MessageJson);
                }
				var type = Number(MessageJson.type);
                switch(type){
                    case Constants.SHARE_TO_QQ_TYPE_AUDIO:
                        return this.substitute(Constants.android_Audio_Template, MessageJson);
                    break;
                    case Constants.SHARE_TO_QQ_TYPE_IMAGE:
                        return this.substitute(Constants.android_Image_Template, MessageJson);
                    break;
                    case Constants.SHARE_TO_QQ_TYPE_DEFAULT_SDCARD:
                         return this.substitute(Constants.android_Template_SdCard,MessageJson);
                        break;
                    case Constants.SHARE_TO_QQ_TYPE_AUDIO_SDCARD:

                        return this.substitute(Constants.android_Audio_SD_Template,MessageJson);
                    break;
                    default:   //common share
                        return this.substitute(Constants.android_Template, MessageJson);
                        break;
                }

            }
        },
        /**
         * 这里主要是为做url拼接提供模板的替换函�?
         *
         * @method substitute
         * @param {String} 拼接的模�?
         * @param {Object} MessageJson
         * @return {String} 返回按模板拼接好的url
         */
        substitute: function (str, obj) {
            return str.replace(/\{([^{}]+)\}/g, function (match, key) {
                var value = obj[key];
                log.d(key, value);
                return (value !== undefined&& value!="undefined"&& value.length > 0) ? '' + value : '';
            });
        }
    };

    window.tencent.share = QQShare;

})();(function(){
	   var tencent_socialApi = {
        invite: function () {
            reportUtils.trackCustomEvent("requireApi", "invite");
            jumpParams.action = android_contants.ACTION_INVITE;
            tencent.logic.getQzoneVersion();
            tencent.logic.getQQVersion();
 			var dic = new Object();
        	dic["QQ"] = tencent.logic.pullQQ;
        	dic["Qzone"] = tencent.logic.pullQZone;
        	dic["Browser"] = tencent.logic.pullBrower;
       		var array = start_order.start_list;
       		for (var i = 0; i < array.length; i++) {
           	 	var value = array[i];
           		 var res = dic[value]();
            	if (res) {
                	break;
            	}
        	}
        },
        story: function () {
            reportUtils.trackCustomEvent("requireApi", "story");
            jumpParams.action = android_contants.ACTION_STORY;
            tencent.logic.getQzoneVersion();
            tencent.logic.getQQVersion();
  			var dic = new Object();
        	dic["QQ"] = tencent.logic.pullQQ;
        	dic["Qzone"] = tencent.logic.pullQZone;
        	dic["Browser"] = tencent.logic.pullBrower;
       		var array = start_order.start_list;
       		for (var i = 0; i < array.length; i++) {
           	 	var value = array[i];
           		 var res = dic[value]();
            	if (res) {
                	break;
            	}
        	}
        },
        gift: function () {
            jumpParams.action = android_contants.ACTION_GIFT;
            tencent.logic.getQzoneVersion();
            tencent.logic.getQQVersion();
  			var dic = new Object();
        	dic["QQ"] = tencent.logic.pullQQ;
        	dic["Qzone"] = tencent.logic.pullQZone;
        	dic["Browser"] = tencent.logic.pullBrower;
       		var array = start_order.start_list;
       		for (var i = 0; i < array.length; i++) {
           	 	var value = array[i];
           		 var res = dic[value]();
            	if (res) {
                	break;
            	}
        	}
        },
        ask: function () {
            jumpParams.action = android_contants.ACTION_ASK;
            tencent.logic.getQzoneVersion();
            tencent.logic.getQQVersion();
 			var dic = new Object();
        	dic["QQ"] = tencent.logic.pullQQ;
        	dic["Qzone"] = tencent.logic.pullQZone;
        	dic["Browser"] = tencent.logic.pullBrower;
       		var array = start_order.start_list;
       		for (var i = 0; i < array.length; i++) {
           	 	var value = array[i];
           		 var res = dic[value]();
            	if (res) {
                	break;
            	}
        	}
        },
        brag: function () {
            jumpParams.action = android_contants.ACTION_BRAG;
            tencent.logic.getQzoneVersion();
            tencent.logic.getQQVersion();
 			var dic = new Object();
        	dic["QQ"] = tencent.logic.pullQQ;
        	dic["Qzone"] = tencent.logic.pullQZone;
        	dic["Browser"] = tencent.logic.pullBrower;
       		var array = start_order.start_list;
       		for (var i = 0; i < array.length; i++) {
           	 	var value = array[i];
           		 var res = dic[value]();
            	if (res) {
                	break;
            	}
        	}
        },
        challenge: function () {
            jumpParams.action = android_contants.ACTION_CHALLENGE;
            tencent.logic.getQzoneVersion();
            tencent.logic.getQQVersion();
 			var dic = new Object();
        	dic["QQ"] = tencent.logic.pullQQ;
        	dic["Qzone"] = tencent.logic.pullQZone;
        	dic["Browser"] = tencent.logic.pullBrower;
       		var array = start_order.start_list;
       		for (var i = 0; i < array.length; i++) {
           	 	var value = array[i];
           		 var res = dic[value]();
            	if (res) {
                	break;
            	}
        	}
        },
        grade: function () {

        },
        getAppFriends: function (key, callBackKey) {
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_GET_APP_FRIENDS;
                httpUtils.httpGet(fullURL, key,callBackKey);
        }
    };
    tencent.socialApi = tencent_socialApi;
})();(function(){
	var tencent_tauth = {
        init: function (appid, params) {
            //空方�?ios需�?
                log.d("tencent", "init");
                tencent.oauth.appid = appid;
                tencent.logic.initWithAppid(appid);
                reportUtils.startQQ4Connect(appid);
                return true;
        },
        login: function (permissions) {
        	log.d("tauth","login()");

            try {
                appUtils.setPermissions(permissions);
                tencent.logic.getQzoneVersion();
                tencent.logic.getQQVersion();
                var dic = new Object();
                dic["QQ"] = tencent.logic.pullQQ;
                dic["Qzone"] =
                    tencent.logic.pullQZone;
                dic["Browser"] =
                    tencent.logic.pullBrower;

                var array = start_order.start_list;
                for (var i = 0; i <
                    array.length; i++) {
                    var value = array[i];
                    //console.log("pull " + value);
                    var res = dic[value]();
                    if (res) {
                        return true;
                    }
                }

                return false;
            } catch (e) {
                return e.message;
            }
        },
        inAuth: function (permissions) {
            if (tencent.oauth.accessToken == null || permissions ==
                null) {
                return false;
            } else {
                tencent.oauth.isAdd = true;
                tencent.tauth.login(permissions);
                return true;
            }

        },
        reAuth: function (permissions) {

            tencent.tauth.login(permissions);
        },
        getOpenId: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL =
                tencent.constants.K_REST_SERVER_BASE_URL +
                tencent.constants.GRAPH_OPEN_ID;
                httpUtils.httpGet(fullURL, key,callBackKey);
            requestListener.dealResponse(response, callBackKey);
            return true;
        }
    };
    tencent.tauth = tencent_tauth;
})();(function(){
    var tencent_webview = {
	requestUrl: function(url) {
	    
	}
    };
    tencent.webview = tencent_webview;
})();(function(){
	var tencent_weibo = {
        getWeiboInfo: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_GET_T_INFO;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        sendText: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_ADD_T;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        delWeibo : function(key, callBackKey){
            if (!tencent.oauth.validateToken()) return false;
            var fullURL =tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_DEL_T;
            httpUtils.httpPost(fullURL,key,callBackKey);
        },
        sendPicText: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_ADD_PIC_T;
                httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        },
        nickTips: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_NICK_TIPS;
                httpUtils.httpGet(fullURL, key,callBackKey);
            return true;
        },
        atFriends: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                tencent.constants.GRAPH_INTIMATE_FRIENDS;
                httpUtils.httpGet(fullURL, key,callBackKey);
            return true;
        },
        checkFans: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                "user/check_page_fans";
            var response =
                httpUtils.httpPost(fullURL, key);
            log.d("checkFans",
                "resposne =" + response);
            return true;
        },

        sendAPIRequest: function (key, callBackKey) {
            if (!tencent.oauth.validateToken()) return false;
            var fullURL = tencent.constants.BASE_REQUEST_URL +
                "t/add_pic_t";
            httpUtils.httpPost(fullURL, key,callBackKey);
            return true;
        }
    };
    tencent.weibo = tencent_weibo;
})();(function(){
	var tencent_weiyunApi = {

    };
    tencent.weiyunApi = tencent_weiyunApi;
})();(function(){
	    //wpaApi
    var tencent_wpaApi = {
        /**
         * getWAPUserState 异步cgi请求
         * @param url
         * @param callBackKey ：回调中listener的key，listener在native中缓�?
         */
        getWAPUserState:function(url,paramsKey,callBackKey){
            log.d(TAG,"requestAsync for getWAPUserSatte");
            httpUtils.httpGet(url,paramsKey,callBackKey);
        },
    };
    tencent.wpaApi = tencent_wpaApi;
})();