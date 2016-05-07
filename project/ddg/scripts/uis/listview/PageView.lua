
local ScrollView = import(".ScrollView")
local PageControl = class("PageControl", ScrollView)
--过半翻页
function PageControl:oooo(x, y)
    local offsetX, offsetY = self.offsetX, self.offsetY
    local index = 0
    local count = #self.cells
    local offsetBase = self.offsetBase
    if self.direction == ScrollView.DIRECTION_HORIZONTAL then
        offsetX = -offsetX
        local x = 0
        local i = 1
        while i <= count do
            local cell = self.cells[i]
            local size = cell:getContentSize()
            if offsetX < offsetBase+x + size.width / 2 then
                index = i
                break
            end
            x = x + size.width
            i = i + 1
        end
        if i > count then index = count end
    else
        local y = 0
        local i = 1
        while i <= count do
            local cell = self.cells[i]
            local size = cell:getContentSize()
            if offsetY < offsetBase+y + size.height / 2 then
                index = i
                break
            end
            y = y + size.height
            i = i + 1
        end
        if i > count then index = count end
    end

    self:scrollToCell(index, true)
end


--时间，速度控制翻页
function PageControl:onTouchEndedWithoutTap(x, y)
    if(not self.touchCellIdx) then
        print("onTouchEndedWithoutTap",self.touchCellIdx)
        self:oooo(x,y)
        return
    end
    local cur = self.touchCellIdx
    local count = #self.cells
    -- error("ScrollView:onTouchEndedWithoutTap() - inherited class must override this method")    
    local xt = 30*(self.drag.endX-self.drag.moveX)
    local yt = 30*(self.drag.endY-self.drag.moveY)
    local ct = self.drag.endclock - self.drag.lastclock
    -- self.baseNd:stopAllActions()
    -- self.baseNd:setPosition(self.offsetX, self.offsetY)
    -- local seqac = transition.sequence(
    --         {
    --             CCMoveBy:create(0.2, ccp(xt,yt)),
    --             CCCallFunc:create(function()  end)
    --         }
    --     )
    -- self.baseNd:runAction(seqac)
    --print("onTouchEndedWithoutTap",xt,yt,ct)
    -- print("self:getIsOutOfRg()",self:getIsOutOfRg())
    -- print("self:getIsOutOfRg() 11111111 ",self.offsetX,self.view:getContentSize().width,self.touchRect.size.width)

    if self.direction == ScrollView.DIRECTION_HORIZONTAL then
        if(math.abs(xt)>60 and ct<0.5) then
            -- self:setContentOffsetWithAnim(self.offsetX+xt, true)
            if(xt<0) then
                cur = cur + 1
            else
                cur = cur - 1
            end
            if(cur<1) then
                cur=1
            elseif(cur>count)then
                cur=count
            end
            self:scrollToCell(cur, true)
        else
            self:oooo(x,y)  
        end
    else
        if(math.abs(yt)>60  and ct<0.5) then
            -- self:setContentOffsetWithAnim(self.offsetY+yt, true)
            if(yt<0) then
                cur = cur -1
            else
                cur = cur + 1
            end
            if(cur<1) then
                cur=1
            elseif(cur>count)then
                cur=count
            end
            print("self:scrollToCell(",cur,yt,count)
            self:scrollToCell(cur, true)
        else
            self:oooo(x,y) 
        end
    end
end

return PageControl
