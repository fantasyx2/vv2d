
local UIButton = import("framework.cc.ui.UIButton")
local UIPushButton = import("framework.cc.ui.UIPushButton")
local CellPushButton = class("CellPushButton",UIPushButton)



function CellPushButton:ctor(images, options)
    CellPushButton.super.ctor(self, images, options)
    self.className = "CellPushButton"
    self:setTouchEnabled(false)
    self.pressAnim = false
    self.enable = true
    self.originalScale = 1.0
    self.pressScale = 1.2
    self.pressDt = 0.2
end
--不处理
function CellPushButton:onTouch_(event)
end

function CellPushButton:setPressAnima(flag)
    self.pressAnim = flag
end

function CellPushButton:setOriginalScale(originalScale)
    self.originalScale = originalScale
end
function CellPushButton:setPressScale(pressScale)
    self.pressScale = pressScale
end
function CellPushButton:setPressAnimaDt(dt)
    self.pressDt = dt
end

function CellPushButton:setButtonEnabled(enabled)
    CellPushButton.super.setButtonEnabled(self,enabled)
    self.enable = enabled
end

function CellPushButton:onCellTouch_(name,x,y,isMoveCell)
    --print("CellPushButton:onCellTouch_aaaaaaaaaaa111",name,x,y,isMoveCell)
    if(not self.enable) then
        return
    end
    -- print("CellPushButton:onCellTouch_",name,x,y)
    if name == "began" then
        if not self:checkTouchInSprite_(x, y) then return false end
        self.fsm_:doEvent("press") 
        self:dispatchEvent({name = UIButton.PRESSED_EVENT, x = x, y = y, touchInTarget = true})
        if(self.pressAnim) then
            self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.pressScale*self.originalScale)))
        end    
        return true
    end

    local touchInTarget = self:checkTouchInSprite_(x, y)
    if name == "moved" then
        if touchInTarget and self.fsm_:canDoEvent("press") then
            self.fsm_:doEvent("press")
            self:dispatchEvent({name = UIButton.PRESSED_EVENT, x = x, y = y, touchInTarget = true})
            if(self.pressAnim) then
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.pressScale*self.originalScale)))
            end
        elseif not touchInTarget and self.fsm_:canDoEvent("release") then
            self.fsm_:doEvent("release")
            self:dispatchEvent({name = UIButton.RELEASE_EVENT, x = x, y = y, touchInTarget = false, isMoveCell = true})
            if(self.pressAnim) then
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale)))
            end
        end
    else
        if self.fsm_:canDoEvent("release") then
            self.fsm_:doEvent("release")
            if(self.pressAnim) then
                self:runAction(CCEaseBackOut:create(CCScaleTo:create(self.pressDt, self.originalScale)))
            end
            if isMoveCell then
                self:dispatchEvent({name = UIButton.RELEASE_EVENT, x = x, y = y, touchInTarget = touchInTarget, isMoveCell = true})
            else
                self:dispatchEvent({name = UIButton.RELEASE_EVENT, x = x, y = y, touchInTarget = touchInTarget})
            end
        end
        if name == "ended" and touchInTarget then
            self:dispatchEvent({name = UIButton.CLICKED_EVENT, x = x, y = y, touchInTarget = true})
        end
    end
end

return CellPushButton
