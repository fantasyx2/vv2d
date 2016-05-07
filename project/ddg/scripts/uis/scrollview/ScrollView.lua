
local ScrollView = class("ScrollView", function(rect)
	-- if not rect then rect = CCRect(0, 0, 0, 0) end
	-- local node = display.newClippingRegionNode(rect)
	local node = display.newNode()
	node:setNodeEventEnabled(true)
	cc(node):addComponent("components.behavior.EventProtocol"):exportMethods()
	return node
end)

ScrollView.DIRECTION_VERTICAL   = 1
ScrollView.DIRECTION_HORIZONTAL = 2

function ScrollView:ctor(rect, direction,isnotClip,isCheckClip,maskPara)
	assert(direction == ScrollView.DIRECTION_VERTICAL or direction == ScrollView.DIRECTION_HORIZONTAL,
		   "ScrollView:ctor() - invalid direction")
	self.dragThreshold = 20
	self.bouncThreshold = 0
	self.defaultAnimateTime = 0.25
	self.defaultAnimateEasing = "backOut"
	--self.defaultAnimateEasing = "sineOut"
	--拖拽允许超出边界
	self.dragOutOfRg = true

	self.direction = direction
	self.touchRect = rect
	self.offsetX = 0
	self.offsetY = 0    
	self.cells = {}
	self.currentIndex = 0

	self.isScrollEnable = true
	self.animOffset = 400
	self:setNodeEventEnabled(true)
	-- self:addNodeEventListener(cc.NODE_EVENT, function(event)
	--     if event.name == "enter" then
	--         self:onEnter()
	--     elseif event.name == "exit" then
	--         self:onExit()
	--     end
	-- end)

	-- create container layer
	-- self.view = display.newLayer()
	-- self:setContentSize(rect.size)
	self.clipnd = nil
	if isnotClip then
		self.clipnd = display.newNode()
	else
		self.clipnd = display.newClippingRegionNode(rect)
	end
	
	self:addChild(self.clipnd)
	
	self.view = display.newNode()
	self.clipnd:addChild(self.view)
	if(direction==ScrollView.DIRECTION_VERTICAL) then          
		self.offsetY = self.touchRect.size.height       
		self.view:setPosition(0, self.offsetY)
		self.offsetBase = self.offsetY
		self.animOffset = self.touchRect.size.height
	else
		self.offsetBase = 0
		self.animOffset = self.touchRect.size.width
	end
	-- self.clipnd:setNodeEventEnabled(true)
	-- self.clipnd:setTouchEnabled(true)
	-- self.clipnd:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
	--     print("ScrollView self.clipnd touch22",self:getContentSize().width,self:getContentSize().height)
	--     return self:onTouch(event.name, event.x, event.y)
	-- end)

	 self.view:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
		--print("ScrollView self.view touch22",self:getContentSize().width,self:getContentSize().height)
		return self:onTouch(event.name, event.x, event.y)
	end)

	-- self.view:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
	--     print("ScrollView self.view touch22",self:getContentSize().width,self:getContentSize().height)
	--     return self:onTouch(event.name, event.x, event.y)
	-- end)


	-- self:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
	--     print("ScrollView touch   ")
	--     return false
	-- end)
	-- self.view:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT, function(event)
	if(isCheckClip) then
		self.checkdt = 0
		self:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT,        
			function(dt)
				self.checkdt = self.checkdt + dt
				if(self.checkdt>0.05) then
					self.checkdt = 0
					local x,y = self.view:getPosition()
					for i,cell in pairs(self.cells) do
						local crect = cell:getBoundingBox()            
						crect.origin.x = crect.origin.x+x +2
						crect.origin.y = crect.origin.y+y +2 
						crect.size.width = crect.size.width - 4
						crect.size.height = crect.size.height -4
						if(crect:intersectsRect(self.touchRect)) then
							cell:setVisible(true)  
							-- print("ScrollView show",i)              
						else
							cell:setVisible(false)                
							-- print("ScrollView hide",i)
						end            
					end
				end
			end)
		self:scheduleUpdate_()
	end

	-- self.baseNd = display.newNode():addTo(self)
	-- 触摸cell
	self.touchCell = nil

	--上下的渐变遮罩,偏移位置写死了，后面的组件有需求可设置为参数
	if maskPara then
		if maskPara.topPath then
			self.maskTopSp = display.newSprite(maskPara.topPath)
			if self.direction == ScrollView.DIRECTION_VERTICAL then
	        	self.maskTopSp:setAnchorPoint(ccp(0.5,1))
	       	 	self.maskTopSp:setPosition(self.touchRect.size.width/2,self.touchRect.size.height)
	       	else
	       	 	self.maskTopSp:setAnchorPoint(ccp(0,0.5))
	       	 	self.maskTopSp:setPosition(-5,self.touchRect.size.height/2 + 35)
	        end
	        self.maskTopSp:addTo(self,200)
	        self.maskTopSp:setVisible(false)
		end
		if maskPara.btmPath then
			self.maskBtmSp = display.newSprite(maskPara.btmPath)
	        if self.direction == ScrollView.DIRECTION_VERTICAL then
	        	self.maskBtmSp:setAnchorPoint(ccp(0.5,0))
	        	self.maskBtmSp:setPosition(self.touchRect.size.width/2,0)
	       	else
	       	 	self.maskBtmSp:setAnchorPoint(ccp(0,0.5))
	       	 	self.maskBtmSp:setPosition(self.touchRect.size.width-self.maskBtmSp:getContentSize().width/2-5,self.touchRect.size.height/2 + 35)
	        end
	        self.maskBtmSp:addTo(self,200)
	        self.maskBtmSp:setVisible(false)
		end
	end
end

function ScrollView:setDragOutOfRange(flag)    
	self.dragOutOfRg = flag
	if(not flag) then        
		self.defaultAnimateEasing = "sineOut"
	end
end

function ScrollView:getOffset()
	if(self.direction==ScrollView.DIRECTION_VERTICAL) then   
		return self.offsetY
	else
		return self.offsetX
	end
end

function ScrollView:getTouchCell()
	return self.touchCell
end

function ScrollView:getCurrentCell()
	if self.currentIndex > 0 then
		return self.cells[self.currentIndex]
	else
		return nil
	end
end

function ScrollView:getCurrentIndex()
	return self.currentIndex
end

function ScrollView:setCurrentIndex(index,animate)
	self:scrollToCell__(index,animate)
end
function ScrollView:skipToIdx(index,animate)
	self:scrollToCell__(index,animate)
end
function ScrollView:skipToIdxIfNeed(index,animate)
	local count = #self.cells
	if index < 1 or index>count then        
		return
	end
	local offset = self.offsetBase
	local curoff = 0
	for i = 1, index-1 do
		local cell = self.cells[i]
		local size = cell:getContentSize()
		if self.direction == ScrollView.DIRECTION_HORIZONTAL then
			curoff = self.offsetX
			offset = offset + size.width
		else
			curoff = self.offsetY
			offset = offset - size.height
		end
	end 
	local w = self.cells[index]:getContentSize().width
	local h = self.cells[index]:getContentSize().height
	if(direction==ScrollView.DIRECTION_VERTICAL) then  
		if(curoff+offset<self.touchRect.size.height and curoff+offset-h>0) then
			return
		end
	else   
		if(curoff+offset>0 and curoff+offset+w<self.touchRect.size.width) then
			return
		end     
	end
	self:scrollToCell__(index,animate)    
end

function ScrollView:addCell(cell)
	self.view:addChild(cell)
	self.cells[#self.cells + 1] = cell
	self:reorderAllCells()
	self:dispatchEvent({name = "addCell", count = #self.cells})
end

function ScrollView:addCells(cells)
	for _,cell in pairs(cells) do
		self:addCell(cell)
	end
end


function ScrollView:setHilight(idx,tag)
	self.selectIdx = idx
    for i,v in pairs(self.cells) do
        if(i==idx) then
            v:setHilight(true,tag)
        else
            v:setHilight(false,tag)
        end
    end
end

function ScrollView:getHilight()
	return self.selectIdx or 1
end

function ScrollView:insertCellAtIndex(cell, index, isRunAction)
	self.view:addChild(cell)
	table.insert(self.cells, index, cell)
	self:reorderAllCells(isRunAction)
	self:dispatchEvent({name = "insertCellAtIndex", index = index, count = #self.cells})
end

function ScrollView:removeCellAtIndex(index, isRunAction)
	local cell = self.cells[index]
	if isRunAction == true then
	    local pMoveTo = CCMoveTo:create(0.5, ccp(cell:getPositionX()-cell:getContentSize().width, cell:getPositionY()))
	    local pCallFunc = CCCallFunc:create(function ()
	        cell:removeSelf()
	    end)
	    cell:runAction(transition.sequence({pMoveTo, pCallFunc}))
	else
		cell:removeSelf()
	end
	
	table.remove(self.cells, index)
	self:reorderAllCells(isRunAction)
	self:dispatchEvent({name = "removeCellAtIndex", index = index, count = #self.cells})
end

function ScrollView:getView()
	return self.view
end

function ScrollView:getTouchRect()
	return self.touchRect
end

function ScrollView:setTouchRect(rect)
	self.touchRect = rect
	self:dispatchEvent({name = "setTouchRect", rect = rect})
end

function ScrollView:getClippingRect()
	return self:getClippingRegion()
end

function ScrollView:setClippingRect(rect)
	self:setClippingRegion(rect)
	self:dispatchEvent({name = "setClippingRect", rect = rect})
end

function ScrollView:scrollToCell(index, animated, time, easing)
	self:scrollToCell__(index, true, time, 0)
end

function ScrollView:scrollToCell__(index, animated, time, easing)
	local count = #self.cells
	if count < 1 then
		self.currentIndex = 0
		return
	end

	if index < 1 then
		index = 1
	elseif index > count then
		index = count
	end
	self.currentIndex = index

	local offset = self.offsetBase
	for i = 2, index do
		local cell = self.cells[i - 1]
		local size = cell:getContentSize()
		if self.direction == ScrollView.DIRECTION_HORIZONTAL then
			offset = offset - size.width
		else
			offset = offset + size.height
		end
	end    
	if(animated) then
		self:setContentOffsetWithAnim(offset,true,time)
	else
		self:setContentOffset(offset, false, 0, 0,0)    
	end
	self:dispatchEvent({name = "scrollToCell", animated = animated, time = time, easing = easing})
end

function ScrollView:isTouchEnabled()
	return self.view:isTouchEnabled()
end

function ScrollView:setTouchEnabled(enabled)
	self.view:setTouchEnabled(enabled)
	self:dispatchEvent({name = "setTouchEnabled", enabled = enabled})
end

---- events

-- function ScrollView:scrollToCell(x,y)
--     local count = #self.cells
--     local offset = 0
--     for i = 2, index do
--         local cell = self.cells[i - 1]
--         local size = cell:getContentSize()
--         if self.direction == ScrollView.DIRECTION_HORIZONTAL then
--             offset = offset - size.width

--         else
--             offset = offset + size.height
--         end
--     end
-- end

function ScrollView:onTouchBegan(x, y)
	self.drag = {
		currentOffsetX = self.offsetX,
		currentOffsetY = self.offsetY,
		startX = x,
		startY = y,
		moveX = x,
		moveY = y,
		endX = x,
		endY = y,
		lastclock = os.clock(),
		endclock = os.clock(),
		isTap = true,
	}

	-- local cell = self:getCurrentCell()
	self.touchCell = nil
	self.touchCellIdx = nil
	local touchpp = self.view:convertToNodeSpace(ccp(x,y))
	local xx= touchpp.x
	local yy= touchpp.y
	for i,cell in pairs(self.cells) do
		if(cell:getBoundingBox():containsPoint(ccp(xx, yy))) then
			self.touchCellIdx = i
			self.touchCell = cell
			self.touchCell:onTouch("began", x, y)
			-- print("onTouchBegan touchCellIdx",i)

			break
		end
	end  
	-- print("self:onTouchBegan() 11111111 ",self.offsetX)

	return true
end

function ScrollView:onTouchMoved(x, y)
	local cell = self:getTouchCell()
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then
		if self.drag.isTap and math.abs(x - self.drag.startX) >= self.dragThreshold then
			--消除跳帧
			self.drag.startX = x

			self.drag.isTap = false
			if(cell) then
				cell:onTouch("cancelled", x, y, true)
			end
		end

		if not self.drag.isTap then
			local min,max= self:getOutRg()
			local curoff = self.offsetX
			local off = x - self.drag.startX + self.drag.currentOffsetX
			if(off<curoff and off<min) then
				off = min + (off-min)/2
			elseif(off>curoff and off>max) then
				off = max + (off-max)/2   
			end
			if(not self.dragOutOfRg) then
				off = math.max(off,min)
				off = math.min(off,max)
			end
			self:setContentOffsetWithDrag(off)
		else
			if(cell) then
				cell:onTouch("moved", x, y)
			end    
		end
	else
		if self.drag.isTap and math.abs(y - self.drag.startY) >= self.dragThreshold then
			--消除跳帧
			self.drag.startY = y
			
			self.drag.isTap = false
			if(cell) then
				cell:onTouch("cancelled", x, y, true)
			end
		end

		if not self.drag.isTap then
			local min,max= self:getOutRg()
			local curoff = self.offsetY
			local off = y - self.drag.startY + self.drag.currentOffsetY
			if(off<curoff and off<min) then
				off = min + (off-min)/2
			elseif(off>curoff and off>max) then
				off = max + (off-max)/2   
			end            
			self:setContentOffsetWithDrag(off)
		else
			if(cell) then
				cell:onTouch("moved", x, y)
			end
		end
	end
	-- print("self:onTouchMoved() 11111111 ",self.offsetX)
	self.drag.moveX = self.drag.endX
	self.drag.moveY = self.drag.endY
	self.drag.endX = x
	self.drag.endY = y
end

function ScrollView:onTouchEnded(x, y)
	self.drag.endX = x
	self.drag.endY = y
	self.drag.endclock = os.clock()
	if self.drag.isTap then
		self:onTouchEndedWithTap(x, y)
	else
		self:onTouchEndedWithoutTap(x, y)
	end
	self.drag = nil
end

function ScrollView:onTouchEndedWithTap(x, y)
	local cell = self:getTouchCell()
	if(cell) then
		cell:onTouch("ended", x, y)
		cell:onTap(x, y)
	end
end

function ScrollView:onTouchEndedWithoutTap(x, y)
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

	local outRg,offset = self:getIsOutOfRg()
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then
		if outRg then
			self:setContentOffsetWithAnim(self.offsetX+xt, true)
		elseif math.abs(xt)>30 and ct<0.5 then
			-- self:setContentOffsetWithAnim(self.offsetX+xt, true)
			outRg,offset = self:getIsOutOfRg(self.offsetX+xt)
			if outRg then
				self.offsetX = offset
			else
				self.offsetX = self.offsetX+xt
			end
			--self.view:runAction(CCEaseIn:create(CCMoveTo:create(0.5, ccp(self.offsetX, self.offsetY)), 0.5))
			local tb = {}
	        tb = {
	                CCEaseIn:create(CCMoveTo:create(0.5, ccp(self.offsetX, self.offsetY)), 0.5),
	                CCCallFunc:create(function() self:checkMaskShow() end)
	            }
		    local seq = transition.sequence(tb)
		    self.view:runAction(seq)
		else
			self:checkMaskShow()
		end
	else
		if outRg then
			self:setContentOffsetWithAnim(self.offsetY+yt, true)
		elseif math.abs(yt)>30  and ct<0.5 then
			-- self:setContentOffsetWithAnim(self.offsetY+yt, true)
			outRg,offset = self:getIsOutOfRg(self.offsetY+yt)
			if outRg then
				self.offsetY = offset
			else
				self.offsetY = self.offsetY+yt
			end
			--self.view:runAction(CCEaseIn:create(CCMoveTo:create(0.5, ccp(self.offsetX, self.offsetY)), 0.5))
			local tb = {}
	        tb = {
	                CCEaseIn:create(CCMoveTo:create(0.5, ccp(self.offsetX, self.offsetY)), 0.5),
	                CCCallFunc:create(function() self:checkMaskShow() end)
	            }
		    local seq = transition.sequence(tb)
		    self.view:runAction(seq)
		else
			self:checkMaskShow()
		end
	end
end

function ScrollView:onTouchCancelled(x, y)
	self.drag = nil
end

function ScrollView:onTouch(event, x, y)
	if self.currentIndex < 1 then return end
	local touchpp = self.clipnd:convertToNodeSpace(ccp(x,y))
	--local scrollpp = self.view:convertToNodeSpace(ccp(x,y))
	--move 不能用scrollpp 相对位置view位置不停在变化
	-- x = scrollpp.x
	-- y = scrollpp.y  
	if event == "began" then
		if not self.touchRect:containsPoint(touchpp) then return false end
		-- print("ScrollView:onTouch  ",x,y)
		return self:onTouchBegan(x, y)
	elseif event == "moved" then
		-- if not self.touchRect:containsPoint(touchpp) then return end
		if self.isScrollEnable then
			self:onTouchMoved(x, y)
		else
			return
		end
	elseif event == "ended" then
		self:onTouchEnded(x, y)
	else -- cancelled
		self:onTouchCancelled(x, y)
	end
end

---- private methods
--设置是否可滑动
function ScrollView:setScrollEnable(isEnable)
	self.isScrollEnable = isEnable
end

function ScrollView:reorderAllCells(isRunAction)
	local count = #self.cells
	local x, y = 0, 0
	local maxWidth, maxHeight = 0, 0
	for i = 1, count do
		local cell = self.cells[i]

		if isRunAction == true then
			local pMoveTo = CCMoveTo:create(0.15, ccp(x, y))
			cell:runAction(transition.sequence({CCDelayTime:create(0.55), pMoveTo}))
		else
			cell:setPosition(x, y)
		end
		if self.direction == ScrollView.DIRECTION_HORIZONTAL then
			local width = cell:getContentSize().width
			if width > maxWidth then maxWidth = width end
			x = x + width
		else
			cell:setAnchorPoint(0, 1)
			local height = cell:getContentSize().height
			if height > maxHeight then maxHeight = height end
			y = y - height
		end
	end

	if count > 0 then
		if self.currentIndex < 1 then
			self.currentIndex = 1
		elseif self.currentIndex > count then
			self.currentIndex = count
		end
	else
		self.currentIndex = 0
	end

	local size
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then
		--size = CCSize(x, maxHeight)
		size = CCSize(x, self.touchRect.size.height)
	else
		--size = CCSize(maxWidth, math.abs(y))
		size = CCSize(self.touchRect.size.width, math.abs(y))
	end
	self.view:setContentSize(size)
end

function ScrollView:checkOutType(offset)
	local outType = 2 
	if not offset then
		if self.direction == ScrollView.DIRECTION_HORIZONTAL then
			offset = self.offsetX
		else
			offset = self.offsetY
		end
	end
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then        
		local maxX = 0
		local minX = -self.view:getContentSize().width + self.touchRect.size.width
		if maxX == minX then
			outType = 4
		elseif offset >= maxX then
			outType = 3
		elseif offset <= minX then
			outType = 1
		end
	else
		local maxY = self.view:getContentSize().height
		local minY = self.touchRect.size.height
		maxY = math.max(minY,maxY)
		-- print("ScrollView:checkOutTypeaaaaaaaaaaa111",offset,maxY,minY)
		if maxY == minY then
			outType = 4
		elseif offset >= maxY then
			outType = 3
		elseif offset <= minY then
			outType = 1
		end
	end
	return outType
end

function ScrollView:checkMaskShow()
	local outType = self:checkOutType()
	-- print("ScrollView:checkMaskShowaaaaaaaaaaaa111",outType)
	if outType == 1 then
		if self.maskTopSp then
			-- print("ScrollView:checkMaskShowaaaaaaaaaaaa222",outType)
	        if self.direction == ScrollView.DIRECTION_VERTICAL then
	        	self.maskTopSp:setVisible(false)
	        else
	        	self.maskTopSp:setVisible(true)
	        end
		end
		if self.maskBtmSp then
			-- print("ScrollView:checkMaskShowaaaaaaaaaaaa333",outType)
	        if self.direction == ScrollView.DIRECTION_VERTICAL then
	        	self.maskBtmSp:setVisible(true)
	        else
	        	self.maskBtmSp:setVisible(false)
	        end
		end
	elseif outType == 3 then
		if self.maskTopSp then
	        if self.direction == ScrollView.DIRECTION_VERTICAL then
	        	self.maskTopSp:setVisible(true)
	        else
	        	self.maskTopSp:setVisible(false)
	        end
		end
		if self.maskBtmSp then
	        if self.direction == ScrollView.DIRECTION_VERTICAL then
	        	self.maskBtmSp:setVisible(false)
	        else
	        	self.maskBtmSp:setVisible(true)
	        end
		end
	elseif outType == 4 then
		if self.maskTopSp then
	        self.maskTopSp:setVisible(false)
		end
		if self.maskBtmSp then
	        self.maskBtmSp:setVisible(false)
		end
	else
		if self.maskTopSp then
	        self.maskTopSp:setVisible(true)
		end
		if self.maskBtmSp then
	        self.maskBtmSp:setVisible(true)
		end
	end
end

function ScrollView:getIsOutOfRg(offset)
	if not offset then
		if self.direction == ScrollView.DIRECTION_HORIZONTAL then
			offset = self.offsetX
		else
			offset = self.offsetY
		end
	end
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then        
		local maxX = 0
		local minX = -self.view:getContentSize().width + self.touchRect.size.width
		if offset > maxX then
			return true,maxX
		elseif offset < minX then
			return true,minX
		end        
	else
		-- local maxY = self.view:getContentSize().height  - self.touchRect.size.height
		-- local minY = 0
		local maxY = self.view:getContentSize().height
		local minY = self.touchRect.size.height
		maxY = math.max(minY,maxY)
		if offset > maxY then
			return true,maxY
		elseif offset < minY then
			return true,minY
		end        
	end
end

function ScrollView:getOutRg()
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then        
		local maxX = 0
		local minX = -self.view:getContentSize().width + self.touchRect.size.width
		minX = math.min(minX,maxX)
		return minX,maxX        
	else
		-- local maxY = self.view:getContentSize().height  - self.touchRect.size.height
		-- local minY = 0
		local maxY = self.view:getContentSize().height
		local minY = self.touchRect.size.height
		maxY = math.max(minY,maxY)
		return minY,maxY    
	end
end

function ScrollView:setContentOffset(offset, animated, time, easing,bounce)
	bounce = bounce or 0
	local ox, oy = self.offsetX, self.offsetY
	local x, y = ox, oy
	if self.direction == ScrollView.DIRECTION_HORIZONTAL then
		self.offsetX = offset
		x = offset

		local maxX = bounce
		local minX = -self.view:getContentSize().width - bounce + self.touchRect.size.width
		minX = math.min(minX,maxX)

		if x > maxX then
			x = maxX
		elseif x < minX then
			x = minX
		end
		self.offsetX = x
	else
		self.offsetY = offset
		y = offset

		-- local maxY = self.view:getContentSize().height + bounce - self.touchRect.size.height
		-- local minY = -bounce
		
		local maxY = self.view:getContentSize().height  + bounce
		local minY = self.touchRect.size.height -bounce

		maxY = math.max(minY,maxY)
		
		if y > maxY then
			y = maxY
		elseif y < minY then
			y = minY
		end
		self.offsetY = y
	end

	if animated then        
		-- print("self:setContentOffset() 000000 ",self.offsetX,self.offsetX)    
		transition.stopTarget(self.view)
		transition.moveTo(self.view, {
			x = x,
			y = y,
			time = time or self.defaultAnimateTime,
			easing = easing or self.defaultAnimateEasing,
			
			onComplete = function()
				-- print("move completed",bounce)
				self:checkMaskShow()

			end,
		})
	else
		transition.stopTarget(self.view)
		-- print("self:setContentOffset() 11111111 ",self.offsetX,x)
		self.view:setPosition(x, y)
	end
end

function ScrollView:setContentOffsetWithDrag(offset, animated, time, easing)
	self:setContentOffset(offset, false, time, easing,self.animOffset)
end
function ScrollView:setContentOffsetWithAnim(offset,animated,time)
	self:setContentOffset(offset, animated or true, time, nil--[["sineOut"--]],0)
end

function ScrollView:onCleanup()
	self:removeAllEventListeners()
end

return ScrollView
