#!/bin/sh
#Note -y refer to yes
#use i2c tools to make basic control of i2c device
echo "detect i2c devives attached to adapter 1"
i2cdetect -y 1

echo "get i2c Who I am value, from adapter 1 at slave address 0x68 and register 0x38, expected output 0x68"
i2cget -y 1 0x68 0x75
# 0x38 INT_EN Reg

echo "set i2c value, in adapter 1, register 0x38, value 1"

echo "read current oldval"
oldval=$(i2cget -y 1 0x68 0x38)
echo currentVal=${oldval}
echo "set new value 1"
i2cset -y 1 0x68 0x38 0x01
newval=$(i2cget -y 1 0x68 0x38)
echo newvalue=${newval}
echo "restore old value"
i2cset -y 1 0x68 0x38 ${oldval}
echo "get old restored value"
i2cget -y 1 0x68 0x38
