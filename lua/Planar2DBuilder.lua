if not state then state = 1; l = 10; w = 10; turn.left(); end
-- defined the state define 2 task placing a block but testing whethere there is a ground or not

function work()
	-- body
	clr();
	for i = 1,3 do
	block_below = read_node.forward_down();
	if block_below == "air" then task = 1; else task = 2; end
	if task == 1 then
		if not read_node.forward() == "air" then task = 3;else task = 2; end
	end
	if task == 1 then move.forward(); end
	if task == 2 then place.forward_down('default:stone'); end
	if task == 3 then dig.forward(); end;
end

end
if state == 1 then
	l=l - 1;
	work();
	if l == 0 then state = 2; end
end
if state == 2 then
	dig.left();
	dig.forward();
	if w%2 == 0 then move.left() else move.right() end
	turn.angle(180);
	w = w - 1;
	l = 10;
	state = 1;
end
