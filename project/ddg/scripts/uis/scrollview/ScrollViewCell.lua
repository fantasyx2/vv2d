
local ScrollViewCell = class("ScrollViewCell", function(contentSize)
    local node = display.newNode()
    if contentSize then node:setContentSize(contentSize) end
    node:setNodeEventEnabled(true)
    cc(node):addComponent("components.behavior.EventProtocol"):exportMethods()
    return node
end)

function ScrollViewCell:ctor(contentSize,id)
	self.id = id
	self.btns = {}	
	self.actbtn = nil
	self.__addChild = CCNode.addChild
end

function ScrollViewCell:addNode(nd,od,tg)
	self.btns = self.btns or {}
	local isBtn = iskindof(nd,"CellPushButton")
	-- print("ScrollViewCell:addNode",isBtn,nd)
	if(isBtn) then		
		--插入顺序决定接收触摸顺序
	 	table.insert(self.btns,1,nd)
	 	-- table.insert(self.btns,nd)
	end
	self.__addChild(self,nd,od or 0,tg or 0)
end
function ScrollViewCell:addChild(nd,od,tg)
	self:addNode(nd,od,tg)
end

function ScrollViewCell:setHilight(flag,tag)
	for _,v in pairs(self.btns) do
		if(v:getTag()==tag) then
			v:setButtonEnabled(not flag)
		end
	end
end

function ScrollViewCell:onTouch(event, x, y,isMoveCell)
	--print("ScrollViewCell:onTouch",event, x, y,isMoveCell)
	-- if(not self:getCascadeBoundingBox():containsPoint(ccp(x, y))) then
	-- 	return false
	-- end
	-- print("ScrollViewCell:onTouch",self.id,event, x, y)
	self.btns = self.btns or {}
	if(event=="began") then
		self.actbtn = nil		
		for _,btn in pairs(self.btns) do
			if(btn:isVisible() and btn:onCellTouch_(event,x,y)) then
				self.actbtn = btn
				return true
			end
		end
	elseif(self.actbtn) then		
		self.actbtn:onCellTouch_(event,x,y,isMoveCell)			
		if(event=="cancelled" or event=="ended") then
			self.actbtn = nil
		end
	end
	return true
end

function ScrollViewCell:onTap(x, y)
	self:dispatchEvent({name = "onCellTap", id = self.id})
end

function ScrollViewCell:onCleanup()
    self:removeAllEventListeners()
end

return ScrollViewCell
