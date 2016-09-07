
package org.cocos2dx.lib;

public class Cocos2dxJavaInterface
{
    public static void show_webview(String url,int luafuncid){
    	
    	final String furl = url;
    	final int flua = luafuncid;
    	Cocos2dxActivity.getActivity().runOnUiThread(new Runnable(){    
            public void run(){
            	Cocos2dxActivity.getActivity().show_webview(furl,flua);
            }
        }); 
    }
    public static void hide_webview(){
    	Cocos2dxActivity.getActivity().runOnUiThread(new Runnable(){    
            public void run(){    
            	Cocos2dxActivity.getActivity().hide_webview();
            }
        }); 
    }
    public static void del_webview(){
    	Cocos2dxActivity.getActivity().runOnUiThread(new Runnable(){    
            public void run(){    
            	Cocos2dxActivity.getActivity().del_webview();
            }
        }); 
    }    
}
