 -- follower, by rnd
 if not state then
	name  = "Kiwi";
	owner = "smk";
      --name  = "singleplayer";
      --owner = "singleplayer";
	gdist = 3;	
	state = 0;
	self.set_properties({visual="mesh", mesh="mobs_kitten.b3d", textures={"mobs_kitten_splotchy.png"}, visual_size={x=0.8, y=0.8}}) animation={stand={x=97, y=192}, walk={x=0, y=96}}
	self.label("Snow_Ball")
	self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
	self.listen(1)
	self.spam(1)
 end
	-- process commands: follow / attack a player
	speaker, msg = self.listen_msg();
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
			elseif string.sub(msg,2,3) == "go" then
				name = string.sub(msg,5) or owner;
				say(string.concat("ok master, i follow ", name, " now"))
			end
		end
	end
 
	-- calculate positions and directions:
	pos  = self.pos()
	tpos = player.getpos(name);
	if not tpos then say (string.concat("master " ,name , " left ")); name = owner; tpos = player.getpos(name); end
	dir = self.viewdir();
 
	tpos.x = tpos.x-pos.x; tpos.z = tpos.z-pos.z;
	tdir   = {x=math.abs(tpos.x),z=math.abs(tpos.z)};
 
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
		if state == 0 then state = 3 end -- stuck
		node =  read_node.forward()
		if node~="air" and state == 3 then
			if read_node.down()~="air" then move.up() end
		else
			if math.random(2)==1 then turn.left() else turn.right() end
		end
	else
		move.down()
	end
 end