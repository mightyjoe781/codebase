if not state then
 owner = "smk"
 rad = 180/(math.pi)
 state = 3 
 count = 0
 gdist = 3
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

	if speaker == owner then
		if string.sub(msg,1,1)=="." then
			if string.sub(msg,2,5) == "attack" then
				pl=find_player(4);
				if pl and pl~= owner then
					if attack(pl) then
						attack(pl); attack(pl); attack(pl);
						say(string.concat("I hit " , pl , " master. "))
					end
				end
			elseif string.sub(msg,2,3) == "go2" then
				name = string.sub(msg,5) or owner;
				say(string.concat("ok master, i follow ", name, " now"))
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

	dir = self.viewdir();

tdir   = {x=math.abs(tpos.x),z=math.abs(tpos.z)};

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
			if string.sub(msg,1,6)== "follow" then
 self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
 state = 3
 say(string.concat("Ok i come follow you", speaker))
  else
 		if string.sub(msg,1,4)== "stay" then
self.set_animation(animation.stand.x, animation.stand.y, 15, 0)
 state = 4 
 say("ok i will stay back")
	else
		if string.sub(msg,1,2) == "go" then
 self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
			state = 0
			say("I want a owner ", name , " abandoned me!")
end
end
end
end

if state == 3 then
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

 if tdir.x<gdist and tdir.z< gdist then
	-- stay away
 else
	if state == 0 then
		if tdir.x>tdir.z then
			cdir = 1
		elseif  tdir.z>tdir.x then
			cdir = 2
		elseif math.rnd(2) == 1 then
			cdir = 1
		else
			cdir = 2
		end
 
		if cdir == 1 then -- x
			if dir.x^2<0.5 then
				turn.right();dir = self.viewdir();
			end
			if dir.x*tpos.x<0 then
				turn.angle(180)
			end
		elseif  cdir == 2 then -- z
			if dir.z^2<0.5 then
				turn.right();dir = self.viewdir();
			end
			if dir.z*tpos.z<0 then
				turn.angle(180)
			end
		end
	else
		state = state - 1
	end
 
	-- move:
	if not move.forward() then
		if state == 0 then state = 2 end -- stuck
		node =  read_node.forward()
		if node~="air" and state == 2 then
			if read_node.down()~="air" then move.up() end
		else
			if math.random(2)==1 then turn.left() else turn.right() end
		end
	else
		move.down()
	end
 end

-- if (math.random(30) == 1) then
	-- self.sound("mobs_kitten")
-- end