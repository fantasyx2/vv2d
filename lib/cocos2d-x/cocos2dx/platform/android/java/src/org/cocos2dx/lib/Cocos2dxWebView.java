/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package org.cocos2dx.lib;

import org.cocos2dx.lib.Cocos2dxWebViewClient.WVJBResponseCallback;
import org.json.JSONException;
import org.json.JSONObject;

import android.content.Context;
import android.view.View;
import android.webkit.WebView;
import android.widget.LinearLayout;

public class Cocos2dxWebView extends WebView {
	// ===========================================================
	// Constants
	// ===========================================================
	public MyWebViewClient webViewClient;
	public int mLuaFuncid;
	public void setLuaCallback(int id){
		mLuaFuncid=id;
	}
	public void resetLuaCallback(){
		mLuaFuncid=0;
	}
	public Cocos2dxWebView(Context context) {
		super(context);
		mLuaFuncid = 0;
		// TODO Auto-generated constructor stub
		getSettings().setJavaScriptEnabled(true);
        webViewClient = new MyWebViewClient(this);
        webViewClient.enableLogging();        
        this.setWebViewClient(webViewClient);   
        initBridge();
		
//		int dimens = 120;
//		float density = context.getResources().getDisplayMetrics().density;
//		int finalDimens = (int)(dimens * density);
//
//		LinearLayout.LayoutParams imgvwDimens = 
//		        new LinearLayout.LayoutParams(finalDimens, finalDimens);
//		this.setLayoutParams(imgvwDimens);
	}

	/*
	 * This function is called before Cocos2dxRenderer.nativeInit(), so the
	 * width and height is correct.
	 */
	@Override
	protected void onSizeChanged(final int pNewSurfaceWidth, final int pNewSurfaceHeight, final int pOldSurfaceWidth, final int pOldSurfaceHeight) {
	}
	
	@Override
	public void loadUrl(String url){
		if(url.startsWith("http")){ 
			super.loadUrl(url);
		}
		else if(url.startsWith("/")){ 
			super.loadUrl(url);
		}
		else if(url.startsWith("javascript")){ 
			super.loadUrl(url);
			
		}
		else{
			super.loadUrl("file:///android_asset/"+url);
		}
	}
	public void setVisibility(boolean b) {
		// TODO Auto-generated method stub
		if(b){
			setVisibility(View.VISIBLE);
			setEnabled(true);
			this.requestFocus();
		}
		else{
			setVisibility(View.GONE);
			setEnabled(false);
		}
	}
	public void regist(String funcname,Cocos2dxWebViewClient.WVJBHandler handle){
		webViewClient.registerHandler(funcname,handle);
	}
	public void send(String msg,String funcname,Cocos2dxWebViewClient.WVJBResponseCallback callback){
		if(funcname.length()==0){
			webViewClient.send(funcname,callback);
		}
		else{
			webViewClient.callHandler(funcname, msg,callback);
		}
	}
	public void regist(String funcname,int luafuncid){	
		final int fluaid = luafuncid;
		webViewClient.registerHandler(funcname,new Cocos2dxWebViewClient.WVJBHandler() {
			@Override
			public void request(Object data, WVJBResponseCallback callback) {
				//luafuncid
				Cocos2dxLuaJavaBridge.callLuaFunctionWithString(fluaid, data.toString());
				callback.callback("");
			}
        });
	}
	public void send(String msg,String funcname,int luafuncid){	
		final int fluaid = luafuncid;
		WVJBResponseCallback callback = new Cocos2dxWebViewClient.WVJBResponseCallback(){
			public void callback(Object data) {
				//luafuncid
				Cocos2dxLuaJavaBridge.callLuaFunctionWithString(fluaid, data.toString());
			}
		};
		if(funcname.length()==0){
			webViewClient.send(funcname,callback);
		}
		else{
			webViewClient.callHandler(funcname, msg,callback);
		}
	}
	public void regist(String funcname){
		webViewClient.registerHandler(funcname,new Cocos2dxWebViewClient.WVJBHandler() {
			@Override
			public void request(Object data, WVJBResponseCallback callback) {
				if(mLuaFuncid>0){
					final Object fdata = data;
					Cocos2dxActivity.getActivity().runOnGLThread(new Runnable(){    
			            public void run(){
			            	Cocos2dxLuaJavaBridge.callLuaFunctionWithString(mLuaFuncid, fdata.toString());
			            }
			        });
				}
				callback.callback("");
			}
        });
	}
	public void send(String msg,String funcname){	
		WVJBResponseCallback callback = new Cocos2dxWebViewClient.WVJBResponseCallback(){
			public void callback(Object data) {
				if(mLuaFuncid>0){
					final Object fdata = data;
					Cocos2dxActivity.getActivity().runOnGLThread(new Runnable(){    
			            public void run(){
			            	Cocos2dxLuaJavaBridge.callLuaFunctionWithString(mLuaFuncid, fdata.toString());
			            }
			        });
				}
			}
		};
		if(funcname.length()==0){
			webViewClient.send(funcname,callback);
		}
		else{
			webViewClient.callHandler(funcname, msg,callback);
		}
	}

	public void initBridge(){
		regist("call_native");
	}
	////////////////////////////////////////////////////////
	class MyWebViewClient extends Cocos2dxWebViewClient {
		public MyWebViewClient(WebView webView) {

			// support js send 
			super(webView, new Cocos2dxWebViewClient.WVJBHandler() {			
				@Override
				public void request(Object data, WVJBResponseCallback callback) {		
					callback.callback("Rsp from Android!");
				}
			});		
			enableLogging(); 	        
		}
		@Override
		public void onPageFinished(WebView view, String url) {
			super.onPageFinished(view, url);
			  //GameActivity.this.webview.loadUrl("javascript:(function() { var videos = document.getElementsByTagName('video'); for(var i=0;i<videos.length;i++){videos[i].play();}})()"); 
			  //this.webView.loadUrl("javascript:try{autoplay();}catch(e){}");
		}

		@Override
		public boolean shouldOverrideUrlLoading(WebView view, String url) {
			return super.shouldOverrideUrlLoading(view, url);
		}

	}
}
