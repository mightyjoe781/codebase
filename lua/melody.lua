if not state then
 owner = "smk"
 rad = 180/(math.pi)
 state = 1
 count = 0
self.set_properties({visual="mesh", mesh="mobs_kitten.b3d", textures={"mobs_kitten_splotchy.png"}, visual_size={x=0.8, y=0.8}}) animation={stand={x=97, y=192}, walk={x=0, y=96}}
self.label("Snow_Ball")
self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
end

if player.getpos(owner) then
name = owner
else
if find_player(1) then
p = find_player(1)
name = p[1]
else
if find_player(2) then
p = find_player(2)
name = p[1]
else
if find_player(3) then
p = find_player(3)
name = p[1]
else
if find_player(4) then
p = find_player(4)
name = p[1]	
else
if find_player(5) then
p = find_player(5)
name = p[1]
else
if find_player(6) then
p = find_player(6)
name = p[1]
else
if find_player(7) then
p = find_player(7)
name = p[1]
else
if find_player(8) then
p = find_player(8)
name = p[1]
else
if find_player(9) then
p = find_player(9)
name = p[1]
else
if find_player(10) then
p = find_player(10)
name = p[1]
end
end
end
end
end
end
end
end
end
end
end

pos  = self.pos()
tpos = player.getpos(name)

if not tpos then  
 name = owner
 tpos = player.getpos(name)
 end


x = math.abs(tpos.x-pos.x)
z = math.abs(tpos.z-pos.z)
tpos.x = tpos.x-pos.x
tpos.z = tpos.z-pos.z 



if (tpos.x>0) and (tpos.z>0) then
deg = math.atan(z/x)*rad + 270
else
	if (tpos.x>0) and (tpos.z<0)  then
deg = math.atan(x/z)*rad + 180
else

if (tpos.x<0) and (tpos.z<0)  then
deg = math.atan(z/x)*rad + 90
else

if (tpos.x<0) and (tpos.z>0)  then
deg = math.atan(x/z)*rad + 0
end
end
end
end


if (count>360) then
count = count - 360
end
if (count<0) then
count = count +360
end

dif=math.abs(count-deg)

if (count>deg) then
count = count-dif
dif = -dif
else

if (count<deg) then
count = count+dif
dif = dif
end
end

turn.angle(dif)

 self.listen(1)
 speaker, msg = self.listen_msg()

if speaker == name then
			if string.sub(msg,1,2)== "up" then
 self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
 state = 1
  else
 		if string.sub(msg,1,3)== "sit" then
self.set_animation(animation.stand.x, animation.stand.y, 15, 0)
 state = 0
end
end
end

if (state == 1) then
if move.forward_down() then
if read_node.up() == "default:water_source" then
	move.up()
end
if not find_player(1) then
move.forward()
end
else
if move.forward() then
if not find_player(1) then
move.forward()
end
else
if move.forward_up() then
if not find_player(1) then
move.forward()
end
end
end
end
else
pickup(2)
end

self.label("SnowBall")
self.set_properties({visual="mesh", mesh="mobs_kitten.b3d", textures={"mobs_kitten_splotchy.png"}, visual_size={x=0.8, y=0.8}}) animation={stand={x=97, y=192}, walk={x=0, y=96}}



-- if (math.random(30) == 1) then
	-- self.sound("mobs_kitten")
-- end