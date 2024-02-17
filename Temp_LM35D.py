import mraa

print(mraa.getVersion())

while True:
    # get temp data from mara
    global tmp
    tmp = mraa.Aio(6)
    tmp = tmp.read()/8

    print("Temp :" +str(tmp))

