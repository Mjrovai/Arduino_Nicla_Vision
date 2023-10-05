# Nicla_OLED_Hello_World - By: marcelo_rovai - Sat Sep 30 2023

# Save on device: ssd1306.py
# MicroPython SSD1306 OLED driver, I2C and SPI interfaces created by Adafruit

import ssd1306

from machine import I2C
i2c = I2C(1)

oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

oled.text('Hello, World', 10, 10)
oled.show()
