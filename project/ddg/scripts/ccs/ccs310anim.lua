local FRAME_DT = 0.0166
local function gen_pos(frames,start,speed,delay)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            table.insert(arr,CCMoveTo:create(0,ccp(f.X,f.Y)))
            --table.insert(arr,CCPlace:create(ccp(f.X,f.Y)))
            lastIdx = start
        elseif(f.FrameIndex>start) then
            table.insert(arr,CCMoveTo:create((f.FrameIndex-lastIdx)*speed,ccp(f.X,f.Y)))
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end
local function gen_scale(frames,start,speed,delay)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            table.insert(arr,CCScaleTo:create(0,f.X,f.Y))
            lastIdx = start
        elseif(f.FrameIndex>start) then
            table.insert(arr,CCScaleTo:create((f.FrameIndex-lastIdx)*speed,f.X,f.Y))
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end
local function gen_rotate(frames,start,speed,delay)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            table.insert(arr,CCRotateTo:create(0,f.X,f.Y))
            lastIdx = start
        elseif(f.FrameIndex>start) then
            table.insert(arr,CCRotateTo:create((f.FrameIndex-lastIdx)*speed,f.X,f.Y))
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end
local function gen_visible(frames,start,speed,delay)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            if(f.Value) then
                table.insert(arr,CCShow:create())
            else
                table.insert(arr,CCHide:create())
            end  
            lastIdx = start
        elseif(f.FrameIndex>start) then
            table.insert(arr,CCDelayTime:create((f.FrameIndex-lastIdx)*speed))
            if(f.Value) then
                table.insert(arr,CCShow:create())
            else
                table.insert(arr,CCHide:create())
            end
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end

local function gen_color(frames,start,speed,delay)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            local color = f.Color or {}
            color.R=color.R or 255
            color.G=color.G or 255
            color.B=color.B or 255
            table.insert(arr,CCTintTo:create(0,color.R,color.G,color.B))
            lastIdx = start
        elseif(f.FrameIndex>start) then
          local color = f.Color or {}
            color.R=color.R or 255
            color.G=color.G or 255
            color.B=color.B or 255
            table.insert(arr,CCTintTo:create((f.FrameIndex-lastIdx)*speed,color.R,color.G,color.B))
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end
local function gen_alpha(frames,start,speed,delay)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            table.insert(arr,CCFadeTo:create(0,f.Value))
            lastIdx = start
        elseif(f.FrameIndex>start) then
          local color = f.Color or {}
            color.R=color.R or 255
            color.G=color.G or 255
            color.B=color.B or 255
            table.insert(arr,CCFadeTo:create((f.FrameIndex-lastIdx)*speed,f.Value))
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end
local function gen_evt(frames,start,speed,delay,evthandler)
    local arr={}
    local lastIdx=0
    for _,f in ipairs(frames) do
        if(f.FrameIndex==start) then
            if(start>0 and delay) then
                table.insert(arr,CCDelayTime:create(start*speed))
            end
            local fk=f.Value
            table.insert(arr,CCCallFunc:create(function()
                if(evthandler) then
                    evthandler(fk)
                end  
            end))
            lastIdx = start
        elseif(f.FrameIndex>start) then
            local fk=f.Value
            table.insert(arr,CCDelayTime:create((f.FrameIndex-lastIdx)*speed))
            table.insert(arr,CCCallFunc:create(function()
                if(evthandler) then
                    evthandler(fk)
                end  
            end))
            lastIdx = f.FrameIndex
        end
    end
    return transition.sequence(arr)
end

local config=
{
  Position            = gen_pos,
  Scale               = gen_scale,
  --AnchorPoint       = gen_arch,
  RotationSkew        = gen_rotate,
  VisibleForFrame     = gen_visible,
  CColor        = gen_color,
  Alpha         = gen_alpha,
  FrameEvent    = gen_evt,
}

function ccsanim_genaction(tagorname,anim,animlist,evthandler)
  -- print("========================")
  -- print("=======")
  -- print("=======")
  -- print("ccsanim_genaction ",tagorname)
  -- print("ccsanim_genaction ",anim)
  -- print("ccsanim_genaction ",animlist)
  -- print("ccsanim_genaction ",evthandler)
  -- print("=======")
  -- print("=======")
  -- print("========================")
  
  if(type(tagorname)=='number')then
  --gen one action by tag
      local speed = anim.Speed*FRAME_DT
      local tb={}
      for _,v in ipairs(anim.Timelines) do
          if(v.ActionTag==tagorname) then
              local f=config[v.Property]
              --print("==",v.Property,f)
              if(f) then
                  local act = f(v.Frames,0,speed,true,evthandler)
                  if(act) then
                      table.insert(tb,act)
                  end
              end
          end
      end
      -- if #tb == 2 then return tb end
      if #tb < 1 then return end
      if #tb < 2 then return tb[1] end
      local prev = tb[1]
      for i = 2, #tb do
          prev = CCSpawn:createWithTwoActions(prev, tb[i])
      end
      return prev
  else
  --gen array action by name

  end
end

