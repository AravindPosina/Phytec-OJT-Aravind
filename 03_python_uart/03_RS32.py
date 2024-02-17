import mraa
import time
import sys

# serial port
port = "/dev/ttyS4"

data = 'Greetings from PHYTEC!'

# initialise UART
uart = mraa.Uart(port)

# send data through UART
uart.write(bytearray(data, 'utf-8'))
time.sleep(1)

while True:
        if uart.dataAvailable():
                data_byte = uart.readStr(1)
                print(data_byte,end=" ")
        if data_byte == "!":
                print("")
                break

