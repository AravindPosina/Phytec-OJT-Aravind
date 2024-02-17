/******************************************
File: Describes the test procedure of GPIO 
Uses: gpio-check (app)
*******************************************/

Before doing any thing we have to resolve some dependence:
HOST SIDE:

Step-1: set the toolchain path by exporting it
        # export PATH=$PATH:<the path of toolchain bin> (eg. go to toolchain/bin and type pwd)

Step-2: Run the Makefile
        # make CC=arm-cortexa8-linux-gnueabihf-gcc 

Step-3: Copy the binary into target board
        # using tftp, sd-card, pen-drive


TARGET TERMINAL:

Step-4: Run the gpio-check app as

		     [./gpio-check gpio_num direction value]
	
For Selection:
	GPIO_Num  (argv[1])   : 77
        Direction (argv[2])   : "out"  
	Value     (argv[3])   : 0 [ON]  [Kindly, note here Value@argv[2] is 1 (i.e., pass Value) which sets it to "1" - HIGH]

  Ex:# ./gpio-check 77 out 1   

For De-Selection:
	GPIO_Num  (argv[0])   : 77
        Direction (argv[1])   : "out"  
	Value     (argv[2])   :  1 [OFF]  [Kindly, note here Value@argv[2] is empty(i.e., Donot pass any Value) which sets it to "0" - LOW]


  Ex:# ./gpio-check 77 out 0   
