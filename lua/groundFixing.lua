minht = -1 --inclusive
maxht =  0 --exclusive
minlen = -10 --inclusive
maxlen = 11 --exclusive
minwid = -10 --inclusive
maxwid = 10 --inclusive 
rem = 0 
if not state then
self.set_properties({visual="mesh", mesh="zmobs_lava_flan.x", textures={"zmobs_lava_flan3.png"}, visual_size={x=1, y=1}})
state=1
cone=minlen
j = minht 
end

pos=self.spawnpos( )
if state == 1 then
if cone<maxlen then
       self.label(string.concat({"len = ", cone," , height = ",j}));
       for i=minwid,maxwid do
              if i ==0 and j == 0 then else 
                     keyboard.set({x=pos.x+cone,y=pos.y+j,z=pos.z+i},rem)
              end
       end
       cone=cone+1
else state = 2
end
end
if state == 2 then
       -- do something 
       j = j + 1
       cone = minlen;
       state = 1;
       if j == maxht then state = 11 end
end
if state == 11 then
   self.remove( )
end