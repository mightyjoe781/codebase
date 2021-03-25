n = 10
height = 10
story = 1
mode = 2

-- 0=air
--1-6=colored blocks
-- 236 Basic_Buttons 

if not state then
	state = 1
	size = n
	cone = -n
	ht = 0
	flr = 0
end
pos = self.spawnpos()
function wall(k)
	-- body
		self.label(string.concat({"Building Wall at height :", ht}))
	for i = -size,size do
		keyboard.set({x=pos.x+i,y=pos.y+ht,z=pos.z-size},mode)
		keyboard.set({x=pos.x+i,y=pos.y+ht,z=pos.z+size},mode)
		keyboard.set({x=pos.x-size,y=pos.y+ht,z=pos.z+i},mode)
		keyboard.set({x=pos.x+size,y=pos.y+ht,z=pos.z+i},mode)
	end
end
if state == 1 then
	if ht<height then
		wall(ht)
		ht = ht+1
	else
		state = 2 
	end
end
if state == 2 then
	if cone < size + 1 then
		self.label(string.concat({"Floor in progress :", flr}))
		for i = -size,size do
			keyboard.set({x=pos.x+cone,y=pos.y-1+((height*flr)/story),z=pos.z+i}, mode)
		end			
		cone = cone + 1
	else
		state = 3 
	end 
end
if state == 3 then
	if flr == story then state = 4
	else state = 2
		flr = flr + 1
		cone = -n
	end 
end
if state == 4 then
	self.remove()
end