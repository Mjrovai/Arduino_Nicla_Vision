/*
 * Based on Edge Impulse Data Forwarder Exampe (Arduino)
  - https://docs.edgeimpulse.com/docs/cli-data-forwarder
 * Developed by M.Rovai @11May23
 */

/* Include ----------------------------------------------------------------- */
#include <Arduino_LSM6DSOX.h>

/* Constant defines -------------------------------------------------------- */
#define CONVERT_G_TO_MS2 9.80665f
#define FREQUENCY_HZ        50
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

static unsigned long last_interval_ms = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  float x, y, z;
  
  if (millis() > last_interval_ms + INTERVAL_MS) {
    last_interval_ms = millis();
    
    if (IMU.accelerationAvailable()) {
      // read raw accelleration measurements from device
      IMU.readAcceleration(x, y, z);

      // converting to m/s2
      float ax_m_s2 = x * CONVERT_G_TO_MS2;
      float ay_m_s2 = y * CONVERT_G_TO_MS2;
      float az_m_s2 = z * CONVERT_G_TO_MS2;

      Serial.print(ax_m_s2); 
      Serial.print("\t");
      Serial.print(ay_m_s2); 
      Serial.print("\t");
      Serial.println(az_m_s2); 
    }
  }
}
