if not state then state = 1; length = 6;  width = 2 ; x = length ;  y = width; end

function work()
-- one unit work at item (string) 
	insert.forward_down("mese_crystals:crystaline_bell","pipeworks:nodebreaker_off");
	move.forward();

end

if state == 1 then
	work();
	x = x - 1;
	if x == 0 then state = 2 end;
end

if state == 2 then
	if y%2 == 0 then move.left(); move.left(); insert.down("mese_crystals:crystaline_bell","pipeworks:nodebreaker_off")  else  move.right(); move.right(); insert.down("mese_crystals:crystaline_bell","pipeworks:nodebreaker_off") end
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
