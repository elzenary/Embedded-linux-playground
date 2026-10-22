echo "Use cross compiler created using cross tool ng"
ls /home/ahmed/x-tools/aarch64-rpi4-linux-gnu/bin/
echo "add the cross compiler to the PATH variable"
PATH=$PATH:/home/ahmed/x-tools/aarch64-rpi4-linux-gnu/bin/
echo $PATH
echo "Compile the libaray using cross compiler and static linking option"
aarch64-rpi4-linux-gnu-gcc helloPi.c -static -o helloPi.pi
aarch64-rpi4-linux-gnu-gcc helloPi.c -o helloPi.pishared
echo "get information about the excecutable file"
file helloPi.pi
file helloPi.pishared
echo "copy the excecutable to raspberrypi over ssh"
scp helloPi.pi pi@pi.local:/home/pi
scp helloPi.pishared pi@pi.local:/home/pi
