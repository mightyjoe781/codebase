--Sky ferry by someone and ksandr
if not initialized then
    last_pos = self.pos()
    self.label("")
    initialized = true
end

if last_pos.x == self.pos().x  and  last_pos.z == self.pos().z then
  local r = 2 --radius
  self.set_properties({
        collisionbox = {-r, -0.5, -r,  r, -0.4, r},
        visual = "mesh",
        mesh = "carts_cart.b3d",
        visual_size = {x = r*2, y = 1},
        textures = {"carts_cart.png"},
  })
 turn.angle(180)
end
boost(2)
last_pos = self.pos()