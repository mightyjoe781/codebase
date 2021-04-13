if not state then
 owner = "smk"
 rad = 180/(math.pi)
 state = 1
 count = 0
self.set_properties({visual="mesh", mesh="mobs_kitten.b3d", textures={"mobs_kitten_splotchy.png"}, visual_size={x=0.8, y=0.8}}) animation={stand={x=97, y=192}, walk={x=0, y=96}}
self.label("Snickers")
self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
end

if player.getpos(owner) then
name = owner
elseif find_player(10) then
p = find_player(10)
name = p[1]
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
elseif (tpos.x>0) and (tpos.z<0)  then
deg = math.atan(x/z)*rad + 180
elseif (tpos.x<0) and (tpos.z<0)  then
deg = math.atan(z/x)*rad + 90
elseif (tpos.x<0) and (tpos.z>0)  then
deg = math.atan(x/z)*rad + 0
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
  elseif string.sub(msg,1,3)== "sit" then
self.set_animation(animation.stand.x, animation.stand.y, 15, 0)
self.set_properties({automatic_rotate = "0"});
 state = 0
 elseif string.sub(msg,1,6) == "rotate" then
   self.set_properties({automatic_rotate = "10"});
   state = 0
 elseif string.sub(msg,1,4) == "purr" then
  self.set_animation(animation.stand.x, animation.stand.y, 15, 0)
  state = 2
 elseif string.sub(msg,1,4) == "grab" then
    grab(string.sub(msg,6))
   self.set_animation(animation.walk.x, animation.walk.y, 15, 0)
   self.set_properties({automatic_rotate = "0"});
    state = 3
  elseif string.sub(msg,1,7) == "release" then
    self.remove()
  elseif string.sub(msg,1,4) == "turn" then
   if( string.sub(msg,6) == "left") then
     turn.left();
     state = 3;
   elseif ( string.sub(msg,6) == "right") then
     turn.right();
     state = 3;
   end
   elseif string.sub(msg,1,6) == "attack" then
    attack(string.sub(msg,8));
end
end

if (state == 3) then
 -- ADVANCED EXPLORER, can climb stairs
 node = read_node.down()
 if node == "air" then
    move.down()
 else -- walk around

    if read_node.forward()~="air" then
        move.up()
    end

    if not move.forward() then
        if math.random(2)==1 then
            turn.left()
        else
            turn.right()
        end
    end
 end
end

if ( state == 2 ) then
    if (math.random(7) ==  2) then
    self.sound("mobs_kitten")
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

self.label("Snickers")
self.set_properties({visual="mesh", mesh="mobs_kitten.b3d", textures={"mobs_kitten_splotchy.png"}, visual_size={x=1.5, y=1.5}}) animation={stand={x=97, y=192}, walk={x=0, y=96}}


--if (math.random(30) == 1) then
     --self.sound("mobs_kitten")
--end