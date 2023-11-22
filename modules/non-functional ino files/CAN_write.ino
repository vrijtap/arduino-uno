/**
 * This module is controlling the can bus (writing) on the arduino side.
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
  canMsg.can_id = 0x036; //CAN id as 0x036
  canMsg.can_dlc = 8; //CAN data length as 8
  canMsg.data[0] = "Wow!";
  canMsg.data[1] = 0x00; //Rest all with 0 
  canMsg.data[2] = 0x00;
  canMsg.data[3] = 0x00;
  canMsg.data[4] = 0x00;
  canMsg.data[5] = 0x00;
  canMsg.data[6] = 0x00;
  canMsg.data[7] = 0x00;

  Serial.print(canMsg.data[0]);

  mcp2515.sendMessage(&canMsg);//Sends the CAN message
  delay(100);
}