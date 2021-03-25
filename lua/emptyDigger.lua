if not state then state = 1; length = 10;  width = 10 ; x = length ;  y = width; end
function work()
-- one unit work at max = 3
	a = read_node.forward();
	b = read_node.forward_down();
	if a == "air" then
		if b == "air" then
			place.forward_down('default:stone');
			move.forward();
		else
			move.forward();
		end
	else
		if machine.energy() < 0.1 then state = 4; end
		if b == "air" then
			place.forward_down('default:stone');
			dig.forward();
			move.forward();
		else
			dig.forward();
			move.forward();
		end
	end
end
if state == 1 then
	work();
	x = x - 1;
	if x == 0 then state = 2 end;
end
if state == 2 then
	if y%2 == 0 then place.left_down('default:stone') move.left(); else place.right_down('default:stone') move.right(); end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 1;
	if y == 0 then state = 3 end;
end
if state == 3 then
	self.remove();
	say("work done smk")
end
if state == 4 then
	machine.generate_power(1);
	state = 1
end