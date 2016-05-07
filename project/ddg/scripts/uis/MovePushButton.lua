
local UIButton = import("framework.cc.ui.UIButton")
local UIPushButton = import("framework.cc.ui.UIPushButton")
local MovePushButton = class("MovePushButton",UIPushButton)



function MovePushButton:ctor(images, options)
    MovePushButton.super.ctor(self, images, options)
    -- self:setTouchEnabled(false)
    self.moveable = false
    self.pressAnim = true
    self.originalScale = 1.0
    self.pressScale = 1.2
    self.pressDt = 0.2
end

function MovePushButton:setOscale(flag)
    self:setOriginalScale(flag)
end
function MovePushButton:setMoveAble(flag)
    self.moveable = flag
end

function MovePushButton:setPressAnima(flag)
    self.pressAnim = flag
end

function MovePushButton:setOriginalScale(originalScale)
    self.originalScale = originalScale
end
function MovePushButton:setPressScale(pressScale)
    self.pressScale = pressScale
end
function MovePushButton:setPressAnimaDt(dt)
    self.pressDt = dt
end

function MovePushButton:onTouch_(event)
    local name, x, y = event.name, event.x, event.y
    -- print("MovePushButton:onTouch_",name,self.hhh_mv_release)
    if name == "began" then
        if not self:checkTouchInSprite_(x, y) then self.hhh_mv_release = false return false end
        self.hhh_mv_release = false
        self.hhh_x = x
        self.hhh_y = y
        self.fsm_:doEvent("press")
        self:dispatchEvent({name = UIButton.PRESSED_EVENT, x = x, y = y, touchInTarget = true})
        if(self.pressAnim) then
            self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.pressScale*self.originalScale)))
        end 
        return true
    end
    if(self.moveable) then
        self.hhh_mv_release = false
    end
    if(self.hhh_mv_release) then return end
    local touchInTarget = self:checkTouchInSprite_(x, y)
    local moveRelease =  math.abs(x-self.hhh_x)>40 or math.abs(y-self.hhh_y)>40
    if name == "moved" then
        if(self.moveable) then
            self:setPosition(x, y)
            return
        end
        if touchInTarget and self.fsm_:canDoEvent("press") then
            self.fsm_:doEvent("press")
            self:dispatchEvent({name = UIButton.PRESSED_EVENT, x = x, y = y, touchInTarget = true})
        elseif not touchInTarget and self.fsm_:canDoEvent("release") then
            self.fsm_:doEvent("release")                
            self:dispatchEvent({name = UIButton.RELEASE_EVENT, x = x, y = y, touchInTarget = false})
            if(self.pressAnim) then
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale)))
            end        
        end
        if(moveRelease) then
            self.hhh_mv_release = true
            if(self.fsm_:canDoEvent("release")) then
                self.fsm_:doEvent("release")                 
                self:dispatchEvent({name = UIButton.RELEASE_EVENT, x = x, y = y, touchInTarget = false})                      
                if(self.pressAnim) then
                    self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale)))
                end
            end
        end 
    else
        if self.fsm_:canDoEvent("release") then            
            self.fsm_:doEvent("release")                        
            self:dispatchEvent({name = UIButton.RELEASE_EVENT, x = x, y = y, touchInTarget = touchInTarget})
            if(self.pressAnim) then
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, 1.0*self.originalScale)))
            end
        end
        if name == "ended" and touchInTarget and (self.hhh_mv_release == false)then
            self.hhh_mv_release = true
            self:setTouchEnabled(false)
            self:dispatchEvent({name = UIButton.CLICKED_EVENT, x = x, y = y, touchInTarget = true})
            self:setTouchEnabled(true)
        end
    end
end

function MovePushButton:doClickAnima()
    if self.fsm_:canDoEvent("press") then 
        self.fsm_:doEvent("press")
    end    
    self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale*self.pressScale)))
    scheduler.performWithDelayGlobal(
        function()
            if self.fsm_:canDoEvent("release") then            
                self.fsm_:doEvent("release")
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale*1.0)))
            end
        end
        , 0.2)        
end
function MovePushButton:doClick()
    if self.fsm_:canDoEvent("press") then 
        self.fsm_:doEvent("press")
    end    
    self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale*self.pressScale)))
    scheduler.performWithDelayGlobal(
        function()
            if self.fsm_:canDoEvent("release") then            
                self.fsm_:doEvent("release")
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale*1.0)))
                self:dispatchEvent({name = UIButton.CLICKED_EVENT, x = x, y = y, touchInTarget = true})
            end
        end
        , 0.2)        
end

return MovePushButton
