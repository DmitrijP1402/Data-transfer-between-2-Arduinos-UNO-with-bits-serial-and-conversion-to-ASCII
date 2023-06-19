/********************************************
date:      "19.06.2023"
author:    "DmitrijP1402 & nico0123456"
filename:  "Receiver.ino"
********************************************/

void setup() {
  Serial.begin(9600);  // Start the Serial Monitor
  
  pinMode(12, INPUT); // Set pin 12/13 as INPUT
  pinMode(13, INPUT);
}

void loop() {
  bool startbit = digitalRead(13); // Read the state of the start bit
  byte receivedByte = 0;
  
  if (startbit == 1) {
    startbit = 0;
    
    for(int i = 7; i >= 0; i--) { // Receive bits and store them in a byte
      delay(10);
      receivedByte |= digitalRead(12) << i;
      delay(82);
    }
    char receivedChar = (char)receivedByte; // Convert the byte to ASCII and print it
    Serial.print(receivedChar);
    receivedByte = 0;
  }
}
