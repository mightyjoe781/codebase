if not state then state = 1; length = 4;  width = 2 ; x = length ;  y = width;
	move.forward();
end
function cond_tube()
-- one unit work at item (string) 
	place.down("pipeworks:nodebreaker_off",17);
	move.forward();

end
if state == 1 then
	if x == 0 then state = 2;
	else 
	cond_tube();
	x = x - 1;
end
end

if state == 2 then
	if y%2 == 0 then move.backward() move.left(); place.down('default:stone') move.left(); else  move.backward() move.right(); place.down('default:stone') move.right();  end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 1;
	if y == 0 then state = 3; y = width; --say('node_breaker done') 
	end
end

if state == 3 then
	say('auto-removing work done successfully');
	self.remove();
end