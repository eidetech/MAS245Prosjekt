#include <FlexCAN.h>

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

static CAN_message_t msg;

void setup(void)
{
  Serial.begin(9600);
  Serial.println("CAN Bus send and receive message test (Tx-Rx-Tx)");

  Can0.begin(250000);
  Can1.begin(250000);  

  msg.ext = 0;
  msg.id = 0x00;
  msg.len = 1;
  msg.buf[0] = 0x00;
}

void loop(void)
{
  CAN_message_t returMsg;

  // Send msg with Can0 bus:
  Can0.write(msg);

  // Read msg from Can0 with Can1 bus:
  if (Can1.available()) 
  {
    Serial.println("Can1 is available.");
    Can1.read(returMsg);
    Serial.print("CAN bus 1 reading: ");
    Serial.println(returMsg.buf[0]);
  }

  // Return msg from Can0 with Can1 to Can0:
  Can1.write(returMsg);

  if (Can0.available()) 
  {
    Serial.println("Can0 is available.");
    Can0.read(returMsg);
    Serial.print("CAN bus 0 reading: ");
    Serial.println(returMsg.buf[0]);
  }

    msg.buf[0]++;
  
  delay(20);
}
