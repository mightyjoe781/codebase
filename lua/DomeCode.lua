if not state then
self.set_properties({visual="mesh", mesh="zmobs_lava_flan.x",textures={"zmobs_lava_flan3.png"}, visual_size={x=0.5, y=0.5}})
self.label(" ")
pos=self.spawnpos( )
state=1
r=14
r2=13
height=-1
length=-10
width=-10
end
if  height<11 then
   if width<11 then
       while length<11 do
          if math.ceil( (length)^2+(height)^2+(width)^2)<r^2 and math.ceil( (length)^2+(height)^2+(width)^2)>r2^2 then
             
  keyboard.set({x=pos.x+length,y=pos.y+height,z=pos.z+width}, 236)
         end
           length=length+1
      end
  end
end
   if length==11 then
       width=width+1
       length=-10
  end
  if width==11 then
      height=height+1
      width=-10
  end
if height==11 then
 self.remove( )
end