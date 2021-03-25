n = 4 -- length of each strip :)
m = 2 -- obsidian strips we want :)
-- m in some sense have direction too 
-- m is even -> its goes left
-- m is odd -> right 
--======================================--
--MATERIALS REQuired
-- mxn Obsidian 
-- mxn Lava_Sources (actually less)
-- mxn mese_crystals_ore1
-- (4m+2n+4) ~ (enough for boundary) stacks of stones :)
--=======================================--
--=======================================--
if not state then state = 1; len_bndry = n + 1; length = n; wid_bndry = 2 * m + 2 ; width = m ;
	x = len_bndry;
	y = wid_bndry;
	size = n;
	move.forward();
	dir = 3;
end
function pool()
	place.down('default:stone');
	move.forward();
end
function obsidian()
	place.down("default:obsidian");
	--place.down('default:stone');
	move.forward();
end
function ore1()
	place.down("mese_crystals:mese_crystal_ore1");
--	place.down('default:stone');
	move.forward();
end
function lava_sources()
	place.down('default:lava_source');
--	place.down('default:stone');
	move.forward();
end

--=======================================--
--=======================================--
if state == 1 then
	self.label("Creating Boundry");
	if x == 0 then state = 2
	else 
	pool();
	x = x - 1;
end
end
if state == 2 then
	move.backward(); turn.left(); move.forward();
	if dir%2 == 0 then x = len_bndry; else x = wid_bndry; end
	state = 1;
	if dir == 0 then state = 3; else dir = dir - 1; end
end
--=======================================--
 -- This code does the obsidian portion of farm 
if state == 4 then
	if x == 0 then state = 5; 
	else 
	obsidian();
	x = x - 1;
end
end

if state == 3 then
	x = length
	y = width
	self.label("Creating Obsidian Strips");	
	self.reset();
	move.left();
	move.left();
	move.forward();
	state = 4 
end

if state ==  5 then
	if y%2 == 0 then move.backward() move.left();  move.left();
	else  move.backward() move.right(); move.right();
	end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 4;
	if y == 0 then state = 6; say('Placed All Obsidian'); end
end
--=======================================--
--This piece of code place the seeds_mese_ore1
if state == 10 then
	if x == 0 then state = 11 
	else 
	ore1();
	x = x - 1;
end
end
if state == 9 then
	x = length
	y = width
	self.label("Placing Ore!");
	self.reset();
	move.up();
	move.left()
	move.left()
	move.forward();
	state = 10 
end
if state == 11 then
	if y%2 == 0 then move.backward() move.left();  move.left();
	else  move.backward() move.right(); move.right();
	end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 10;
	if y == 0 then state = 12; say('Place Ore!'); end
end

--=======================================--
--This code is for putting lava :) although it happens before the ores we need it below :)
-- server limitations bypass due to if condition before so don't change the order of code :)
if state == 7 then
	if x == 0 then state = 8; 
	else 
	lava_sources();
	x = x - 1;
end
end
if state == 6 then
 	x = length
	y = width + 1
	self.reset();
	self.label("laying lava too hot!");
	move.left();
	move.forward();
	state = 7 
end
if state == 8 then
	if y%2 == 1 then move.backward() move.left();  move.left();
	else  move.backward() move.right(); move.right();
	end
	turn.angle(180);
	x = length;
	y = y-1;
	state = 7;
	if y == 0 then state = 9; say('Placed All Lava_Sources') end
end

if state == 12 then
	say('auto-removing work done successfully');
	self.remove();
end
