/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

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
#include "ccUtils.h"
#include "CCDirector.h"
#include "CCScheduler.h"
#include "platform/platform.h"
#include "platform/CCFileUtils.h"
#include "platform/CCImage.h"
#include "CCEGLView.h"
#include <thread>

namespace cocos2d {

unsigned long ccNextPOT(unsigned long x)
{
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >>16);
    return x + 1;
}
static void onCaptureScreen(const std::function<void(bool, const std::string&)>& afterCaptured, const std::string& filename)
    {
        static bool startedCapture = false;
        
        if (startedCapture)
        {
            CCLOG("Screen capture is already working");
            if (afterCaptured)
            {
                afterCaptured(false, filename);
            }
            return;
        }
        else
        {
            startedCapture = true;
        }
        
        
        CCEGLView* glView = CCDirector::sharedDirector()->getOpenGLView();
        auto frameSize = glView->getFrameSize();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        //frameSize = frameSize * glView->getFrameZoomFactor() * glView->getRetinaFactor();
#endif
        
        int width = static_cast<int>(frameSize.width);
        int height = static_cast<int>(frameSize.height);
        
        bool succeed = false;
        std::string outputFile = "";
        
        do
        {
            std::shared_ptr<GLubyte> buffer(new GLubyte[width * height * 4], [](GLubyte* p){ CC_SAFE_DELETE_ARRAY(p); });
            if (!buffer)
            {
                break;
            }
            
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer.get());
            
            std::shared_ptr<GLubyte> flippedBuffer(new GLubyte[width * height * 4], [](GLubyte* p) { CC_SAFE_DELETE_ARRAY(p); });
            if (!flippedBuffer)
            {
                break;
            }
            
            for (int row = 0; row < height; ++row)
            {
                memcpy(flippedBuffer.get() + (height - row - 1) * width * 4, buffer.get() + row * width * 4, width * 4);
            }
            
            CCImage* image = new (std::nothrow) CCImage;
            if (image)
            {
                image->initWithImageData(flippedBuffer.get(), width * height * 4, kFmtRawData, width, height, 8);
                if (CCFileUtils::sharedFileUtils()->isAbsolutePath(filename))
                {
                    outputFile = filename;
                }
                else
                {
                    CCAssert(filename.find("/") == std::string::npos, "The existence of a relative path is not guaranteed!");
                    outputFile = CCFileUtils::sharedFileUtils()->getWritablePath() + filename;
                }
                
                typedef std::function<void(bool,const std::string&)> OVER_FNC;
                //typedef std::function<void(OVER_FNC&,const std::string&)> RUN_FNC;
                OVER_FNC overfunc = afterCaptured;
                std::string filename = outputFile;
                auto task = std::thread([=]()
                                        {
                                            bool rst = image->saveToFile(filename.c_str());
                                            if(overfunc)
                                            {
                                                CCDirector::sharedDirector()->getScheduler()->performFunctionInCocosThread([=]{
                                                    overfunc(rst,filename);
                                                });
                                            }
                                            startedCapture = false;
                                            delete image;
                                        }
                                        );
                task.join();
            }
            else
            {
                CCLOG("Malloc Image memory failed!");
                if (afterCaptured)
                {
                    afterCaptured(succeed, outputFile);
                }
                startedCapture = false;
            }
        } while (0);
    }
    
void  captureScreen(const std::function<void(bool, const std::string&)>& afterCaptured, const std::string& filename)
{
    CCDirector::sharedDirector()->setAfterDrawFunc([=]()->int{
        onCaptureScreen(afterCaptured,filename);
        return 1;
    });
}
    

}
