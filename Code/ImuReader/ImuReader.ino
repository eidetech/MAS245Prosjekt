// Skriver ut verdier fra IMU MPU6050 og sender de over CAN

#include <FlexCAN.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;


static CAN_message_t msg;


void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);

   Can1.begin();

   msg.ext = 0;
   msg.id = 0x100;
   msg.len = 8;
   msg.buf[0] = 0;
}

void loop() {
  
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  
  /* Les og skriv sensorverdi over CAN   */
  
  msg.buf[0] = a.acceleration.x;
  Can1.write(msg);
  
  
  

  /* Skriver ut x verdiene til IMUen */
  Serial.println(a.acceleration.x);

  delay(100);
}
