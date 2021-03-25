if not state then
self.set_properties({visual="mesh", mesh="zmobs_lava_flan.x", textures={"zmobs_lava_flan3.png"}, visual_size={x=0.5, y=0.5}})
state=1
cone=-10
ctwo=-10
ctwoa=-10
cthree=-10
cthreea=-10
height=-10
end

pos=self.spawnpos( )
if height==-10 or height==-4 or  height==2 or height==8 then
  if cone<11 then
    for i=-10,10 do
       keyboard.set({x=pos.x+cone,y=pos.y+height,z=pos.z+i}, 236)
    end
       cone=cone+1
  end

  if cone==11 then 
      height=height+6
      cone=-10
  end
end
if height==14 then
  if ctwo<11 then
    for i = -10,10 do
       keyboard.set({x=pos.x+ctwo,y=pos.y+i,z=pos.z+ctwoa}, 236)
    end
       ctwo=ctwo+1
  end

  if ctwo==11 then
      ctwoa=ctwoa+20
      ctwo=-10
  end

if cthree<11 then
  for i = -10,10 do
        keyboard.set({x=pos.x+cthreea,y=pos.y+i,z=pos.z+cthree}, 236)
  end
       cthree=cthree+1
   end

   if cthree==11 then
       cthreea=cthreea+20
      cthree=-10
   end
end

if cthreea==30 then
  self.remove(1)
end