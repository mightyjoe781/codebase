if not state then state = 1; length = 20;  width = 10 ; x = length ;  y = width;
	move.forward();
end

function node_breaker()
-- one unit work at item (string) 
	place.down("pipeworks:nodebreaker_off",17);
	move.forward();

end
function cond_tube()
-- one unit work at item (string) 
	place.down("pipeworks:conductor_tube_off_1");
	move.forward();

end
function put_seeds()

end

if state == 3 then
	say('Going Back to Spawner')
	self.reset();
	move.up();
	move.forward();
	state = 4
end

--Node_breaker placing code :)
if state == 1 then
	if x == 0 then state = 2 place.down('basic_robot:button_219');
	else 
	node_breaker();
	x = x - 1;
end
end
if state == 2 then
	if y%2 == 0 then move.backward() move.left(); 
		place.down('basic_robot:button_219')
		 move.left();  else  move.backward() move.right(); 
		place.down('basic_robot:button_219') 
		move.right();
		  end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 1;
	if y == 0 then state = 3; say('Placed All Node_Breakers') y = width end
end

--Placing pipes code :)
if state == 4 then
	if x == 0 then state = 5
	else 
	cond_tube();
	x = x - 1;
end
end
if state == 5 then
	if y%2 == 0 then move.backward() move.left(); 
		place.down('pipeworks:conductor_tube_off_1');
		 move.left(); else  move.backward() move.right(); 
		 place.down('pipeworks:conductor_tube_off_1');
		  move.right();  
		end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 4;
	if y == 0 then state = 6; 
		say('Placed All Pipes :)') 
	end
end

if state == 6 then
	say('auto-removing work done successfully');
	self.remove();
end
