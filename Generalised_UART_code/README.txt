/******************************************
File: Describes the test procedure of UART 
Uses: uart-check (app)
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

Step-4: Run the uart-check app as

	 [./uart-check "/dev/ttyXX" "message"]

	# ./uart-check "/dev/tty01" "PHYTEC"

[This app gives you flexibility of /dev/ttyXX and text-messages]

