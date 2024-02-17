import mraa
import time
print(mraa.getVersion())
 
while True:
    # initialise AIO
    x = mraa.Aio(6)
 
    # read integer value
    print(x.read())
 
    # read float value
    print("%.5f" % x.readFloat())
    time.sleep(1)


