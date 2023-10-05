# NiclaV_Scan_I2C - By: marcelo_rovai - Mon Sep 25 2023

import time
from pyb import LED
from pyb import I2C

greenLED = LED(2) # built-in green
i2c = I2C(1, I2C.MASTER)

print('Scanning I2C bus.')
devices = i2c.scan() # this returns a list of devices

device_count = len(devices)

if device_count == 0:
    print('No i2c devices found.')
if device_count == 1:
    print('1 device found.')
    greenLED.on()
    time.sleep_ms(1000)
else:
    print(device_count, 'device(s) found.')

for device in devices:
    print('Decimal address:', device, ", Hex address: ", hex(device))
