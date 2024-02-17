import mraa 
                                                                
gpio_1 = mraa.Gpio(35)
gpio_2 = mraa.Gpio(63)                                  
          
gpio_1.dir(mraa.DIR_IN)
gpio_2.dir(mraa.DIR_OUT)                                                 

while True:                                                          
    sw_input=gpio_1.read()
    if sw_input == 1:                                                  
           gpio_2.write(1)
    else :
          gpio_2.write(0)

