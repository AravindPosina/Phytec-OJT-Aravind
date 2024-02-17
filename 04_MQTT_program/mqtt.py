import time
import paho.mqtt.client as mqtt
import json
import mraa

gpio_1 = mraa.Gpio(61)          
gpio_1.dir(mraa.DIR_OUT)
gpio_1.write(1)



temp_max = 35

def on_connect(client, userdata, flag, rc):
    # this will say if the connection is successful or not
    client.publish('iotLABS/client/connect', 'connection successful!!')
    print("connection successful!")


def on_message(client, userdata, mess):
    global temp_max
    topic = str(mess.topic)
    m = json.loads(str(mess.payload.decode("utf-8")))
    print(topic+':'+str(m))
    if(topic == 'iotLABS/SetMaxTemprature/data'):
        temp_max = int(m['temp'])  # this is to set max temp to start the fan
        print("temp_max : ",temp_max)
    elif(topic == 'iotLABS/fan/relay'):
        # we can replace this code with relay on or off
        print("fan state:", m['state'])
        print("relay number:", m['relay_no'])


client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect('broker.hivemq.com', port=1883)
client.subscribe('iotLABS/SetMaxTemprature/data')
client.subscribe('iotLABS/fan/relay')
print("done")
client.loop_start()

while 1:
    # get temp data from mara
    global tmp
    tmp = mraa.Aio(6)
    tmp = tmp.read()/8
    client.publish('iotLABS/temp_data/send', '{temp:'+str(tmp)+' Max_Temp:'+str(temp_max)+'}')
    print("Current Temp:"+str(tmp)+" Max temp: "+str(temp_max))
    if tmp >= temp_max:
        print("turn on fan!")  # relay should be on
        gpio_1.write(0)
    else:
        print("Turn off fan")
        gpio_1.write(1)

    time.sleep(3)
