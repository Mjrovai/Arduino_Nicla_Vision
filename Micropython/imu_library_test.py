# LSM6DSOX IMU test, using the IMU library.
import time
import imu

while (True):
    imu_pitch = imu.pitch()
    imu_roll = imu.roll()
    temperature = imu.temperature_c()
    x, y, z = imu.acceleration_mg()
    print(imu_pitch)
    print(imu_roll)
    print(temperature)
    print(x/1000,y/1000,z/1000)
    print("")
    time.sleep_ms(100)
