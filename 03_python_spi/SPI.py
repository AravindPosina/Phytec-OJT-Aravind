import mraa
import time

# initialise SPI
dev = mraa.Spi(0)

# prepare data to send
txbuf = bytearray(3)
txbuf[0] = 100
txbuf[1] = 123
txbuf[2] = 75

while True:
    # send data through SPI
    rxbuf = dev.write(txbuf)
    print(rxbuf[0],end=" ")
    print(rxbuf[1],end=" ")
    print(rxbuf[2])

    time.sleep(0.5)
