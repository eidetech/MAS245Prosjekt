#include <FlexCAN.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/FreeMono9pt7b.h>

#define OLED_DC     6
#define OLED_CS     10
#define OLED_RESET  5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

static CAN_message_t msg;

void setup(){
  
  Can0.begin(500000);
  Can1.begin(500000);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // Clear the display buffer.
  display.clearDisplay();

  // Configure display settings
  display.setTextSize(0);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  // Print static text on display
  display.println(" MAS245 - Gruppe 2");
  display.println(" CAN - Statistikk");
  display.println(" --------------------");
  display.display();

  // Setup message structure
  msg.id = 0x00;
  msg.buf[0] = 0x00;
 
}

void loop() {

  CAN_message_t inMsg;

  // Send msg with Can0 bus:
  Can0.write(msg);

  // Read msg from Can0 with Can1 bus:
  while (Can1.available()) 
  {
    Serial.println("Can1 is available.");
    Can1.read(inMsg);
    Serial.print("CAN bus 1 reading: ");
    Serial.println(inMsg.buf[0]);
      display.fillRect(0,23,128, 30,BLACK);
      display.print(" Antall mottatt:");
      display.println(msg.buf[0]);
      display.print(" Mottok sist ID:0x");
      display.println(msg.id, HEX);
      display.println(" --------------------");
      display.setCursor(0,24);
      display.display();

      
      // Increase data in buffer 0 with 1
      msg.buf[0]++;

      // Add 2 to the ID, for display effect
      msg.id = msg.id + 2;
     delay(1000);
  }   
}
