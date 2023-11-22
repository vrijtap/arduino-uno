#include <Wire.h>

int receivedData = 0;

void setup() {
  Wire.begin(0x8); // Arduino as a slave, with address 8
  Wire.onReceive(receiveData); // Register a callback for incoming I2C data
  Wire.onRequest(sendData); // Register a callback for outgoing I2C data
  Serial.begin(9600);
}

void loop() {
  delay(100);
  // Your Arduino code can do other things here.
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    receivedData = Wire.read();
    Serial.println("Received data: " + String(receivedData));
  }
}

void sendData() {
  Wire.write(receivedData); // Send back the received data
}
