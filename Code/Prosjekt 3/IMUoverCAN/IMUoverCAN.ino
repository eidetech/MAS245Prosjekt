#include <FlexCAN.h>
#include <SPI.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Servo.h>

#include <Fonts/FreeMono9pt7b.h>

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

#define OLED_DC     6
#define OLED_CS     10
#define OLED_RESET  5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

static CAN_message_t msg;
Adafruit_MPU6050 mpu;
Servo servo;

int imuReading;

// -------------------------------------------------------------
void setup(void)
{
  Serial.begin(9600);
  delay(1000);

  Can0.begin(250000);  

  //if using enable pins on a transceiver they need to be set on
  pinMode(2, OUTPUT);
  pinMode(35, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(35, HIGH);

  msg.ext = 0;
  msg.id = 0x200;
  msg.len = 8;
  msg.buf[0] = 10;

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.fillScreen(BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  servo.attach(35);
}


// -------------------------------------------------------------
void loop(void)
{
  display.fillScreen(BLACK);
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /*Leser IMUData*/
  imuReading = a.acceleration.x*10;

  /*Sender IMUData ut på CAN-bus*/
  msg.buf[0] = imuReading;
  Can0.write(msg);

  /*Printer info på teensy skjerm*/
  Serial.println(imuReading);
  display.setCursor(1,1);
  display.print("Servostyring fra IMU");
  display.setCursor(1,10);
  display.print("TX til RPi: ");
  display.print(imuReading);

  CAN_message_t inMsg;
  if(Can0.available())
      {
        /* Leser CAN fra RPI*/
        Can0.read(inMsg);
        if(inMsg.id == 0x300)
        {
          /*Printer innkommende CAN*/
          display.setCursor(1,20);
          display.print("RX fra RPi: ");
          display.print(inMsg.buf[0]);
          }
          
          /*Konverterer IMUdata til Servodata*/
          int val = map(inMsg.buf[0], 0,200, 0, 180);

          /*Lager "dødgang* for IMU/*/
          if(inMsg.buf[0] > 80 && inMsg.buf[0] < 120)
          {
            /*Setter servo i ro i midtstilling*/
            servo.write(92);
          }else
          {
            servo.write(val);
          }
          /*Printer verdi som sendes til servo*/
          display.setCursor(1,30);
          display.print("Servo signal: ");
          display.print(val);
      }
  /*Oppdateringsfrekvens på skjermen*/
  display.display();
  delay(60);
}
