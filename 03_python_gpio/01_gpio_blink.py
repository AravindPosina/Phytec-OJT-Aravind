import mraa 
import time                                                                
gpio_1 = mraa.Gpio(61)
gpio_2 = mraa.Gpio(62)                                  
gpio_3 = mraa.Gpio(63)          
gpio_1.dir(mraa.DIR_OUT)
gpio_2.dir(mraa.DIR_OUT)                                                 
gpio_3.dir(mraa.DIR_OUT)
while True:                                                          
    gpio_1.write(1)                                                  
    gpio_2.write(0)
    gpio_3.write(1)                                                   
    time.sleep(1)                                                      
    gpio_1.write(0)                                                                      
    gpio_2.write(1) 
    gpio_3.write(0)                                                                                                                                                   
    time.sleep(1)                                                 
    gpio_1.write(0)                                                
    gpio_2.write(0)                                                   
    gpio_3.write(1)  
    time.sleep(1)

#Execution:
#                      python3 gpio_blink.py

