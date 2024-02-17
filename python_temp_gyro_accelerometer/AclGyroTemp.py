from __future__ import print_function
import time, sys, atexit
from upm import pyupm_lsm6dsl as sensorObj
 
def main():
    # Instantiate a BMP250E instance using default i2c bus and address
    sensor = sensorObj.LSM6DSL(0,0x6b,-1)
 
    # For SPI, bus 0, you would pass -1 as the address, and a valid pin for CS:
     #LSM6DSL(0, -1, 10);
 
 
    # now output data every 250 milliseconds
    while (1):
        sensor.update()
 
        data = sensor.getAccelerometer()
        print("Accelerometer x:", data[0], end=' ')
        print(" y:", data[1], end=' ')
        print(" z:", data[2], end=' ')
        print(" g")
 
        data = sensor.getGyroscope()
        print("Gyroscope x:", data[0], end=' ')
        print(" y:", data[1], end=' ')
        print(" z:", data[2], end=' ')
        print(" dps")
 
        # we show both C and F for temperature
        print("Compensation Temperature:", sensor.getTemperature(), "C /", end=' ')
        print(sensor.getTemperature(True), "F")
 
        print()
        time.sleep(.250)
 
if __name__ == '__main__':
    main()


