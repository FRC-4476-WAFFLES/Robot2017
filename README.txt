Stuff to do tomorrow:
- Check all systems
    - Drive
    - Drawer
    - Gear
    - Climber
- Get setpoints
    - Drawer In, Out, Bumper
    - Gear Open, Closed
- Calibrate PIDS
    - Drawer PID
    - Gear PID
    - Climber PID
- Figure out how far from the wall to drop off the gear.
- Test auto selector
- Test autos (if we have time)

--------Robot Controls By Button-------
>>>>>>bumpers and triggers<<<<<<
R1,BumperTopRight(Right Bumper) = slow spin climber reverse

R2,BumperBottomRight(Right Trigger) = nothing

L1,BumperTopLeft(Left Bumper) = slow spin climber for grab

L2,BumperBottomLeft(Left Trigger) = nothing

>>>>>>center buttons<<<<<<
Start:
when pressed = open gear manipulator
when released = close gear manipulator

Back = nothing
mode = switch joystick and d-pad

>>>>>>right buttons<<<<<<
Y = drawer fully out
B = drawer to bumper
A = drawer fully in
X = nothing

>>>>>>D-Pad<<<<<<
D-Pad:
Left(pov=270) = nothing
Up(pov=0) = nothing
Right(pov=90) = nothing
Down(pov=180) = nothing
center = pov=-1 = nothing

>>>>>>joystick buttons and axis<<<<<<
left joystick horizontal axis(0) = nothing
left joystick vertical axis(1) = Climber fudge
left joystick center button(11?) = nothing
right joystick horizontal axis(2) = nothing
right joystick vertical axis(3) = climber fudge slow.
right joystick center button(12?) = nothing