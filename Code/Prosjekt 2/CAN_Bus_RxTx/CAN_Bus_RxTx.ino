#include <FlexCAN.h>

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

static CAN_message_t msg;

// -------------------------------------------------------------
void setup(void)
{
  delay(1000);
  Serial.println(F("CAN Bus send and receive message test (Tx-Rx-Tx)"));

  Can0.begin(250000);
  Can1.begin(250000);  

  //if using enable pins on a transceiver they need to be set on
  pinMode(2, OUTPUT);
  pinMode(35, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(35, HIGH);

  msg.ext = 0;
  msg.id = 0x00;
  msg.len = 1;
  msg.buf[0] = 0x00;

}


// -------------------------------------------------------------
void loop(void)
{
  CAN_message_t inMsg;

  // Send msg with Can0 bus:
  Can0.write(msg);

  // Read msg from Can0 with Can1 bus:
  if (Can1.available()) 
  {
    Serial.println("Can1 is available.");
    Can1.read(inMsg);
    Serial.print("CAN bus 1 reading: ");
    Serial.println(inMsg.buf[0]);
  }

  // Return msg from Can0 with Can1 to Can0:
  Can1.write(inMsg);

  if (Can0.available()) 
  {
    Serial.println("Can0 is available.");
    Can0.read(inMsg);
    Serial.print("CAN bus 0 reading: ");
    Serial.println(inMsg.buf[0]);
  }

    msg.buf[0]++;
  
  delay(20);
}
