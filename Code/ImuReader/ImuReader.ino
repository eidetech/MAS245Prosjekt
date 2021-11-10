// Skriver ut verdier fra IMU MPU6050 og sender de over CAN

#include <FlexCAN.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;


static CAN_message_t msg;
int imuReading;



void setup(void) {
  delay(1000);

  Can0.begin(250000);
     //if using enable pins on a transceiver they need to be set on
  pinMode(2, OUTPUT);
  pinMode(35, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(35, HIGH);
  
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



  msg.ext = 0;
  msg.id = 0x200;
  msg.len = 8;
  msg.buf[0] = 10;
  msg.buf[1] = 20;
  msg.buf[2] = 0;
  msg.buf[3] = 100;
  msg.buf[4] = 128;
  msg.buf[5] = 64;
  msg.buf[6] = 32;
  msg.buf[7] = 16;
}

void loop() {
  
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  
  imuReading = a.acceleration.x*100;

  /* Skriver ut x verdiene til IMUen */
  

    /* Les og skriv sensorverdi over CAN   */
  
  Can0.write(msg);
  msg.buf[0]++;

  Serial.println(msg.buf[0]);

  delay(20);
}
