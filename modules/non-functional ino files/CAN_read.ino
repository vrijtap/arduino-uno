/**
 * This module is controlling the can bus (reading) on the arduino side.
 * 
 * Date:   25-09-2023
 */
#include <mcp2515.h>
#include <SPI.h>

MCP2515 mcp2515(10);
struct can_frame canMsg;

void setup() {
  Serial.begin(9600);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data
   {
     int message = canMsg.data[0];
     Serial.print("message: ");
     Serial.print(message);
   }
}