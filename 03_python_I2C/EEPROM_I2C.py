import mraa as m
import time

x = m.I2c(0)
x.address(0x50)

add=0x00
i=0
while True:
        value=x.readReg(add+i)
        print(chr(value),end="")
        i=i+1


