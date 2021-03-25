
self.label(machine.energy( ))
check=0

ok1=check_inventory.self("basic_machines:mese_extractor","main")
ok2=check_inventory.self("basic_machines:mese_dust_33","main")
ok3=check_inventory.self("basic_machines:mese_dust_66","main")

if ok1 then
  check=1
end
if ok2 and check~=1 and check~=3 then
  check=2
end
if ok3 and check~=1 and check ~=2 then
  check=3
end 


if ok1 and check==1 then
  machine.smelt("basic_machines:mese_extractor",64)
  check=0
end

if ok2 and check==2 then
  machine.smelt("basic_machines:mese_dust_33",64)
  check=0
end

if ok3  and check==3 then
  machine.smelt("basic_machines:mese_dust_66",64)
  check=0
end

if not ok1 and not ok2 and not ok3 then
  machine.generate_power("W00HOO",16)
end
