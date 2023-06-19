/********************************************
date:      "19.06.2023"
author:    "DmitrijP1402 & nico0123456"
filename:  "Transmitter.ino"
********************************************/

// max 53 characters possible --> 424 bits

void setup() {
  Serial.begin(9600); // Start the Serial Monitor

  pinMode(12, OUTPUT); // Set pin 12/13 as OUTPUT
  pinMode(13, OUTPUT);
}

byte startbit = 0; // Set start bit to 0

void loop() {
  if (Serial.available()) {
    char character = Serial.read(); // Read input text and store it in 'character'
    delay(10);
    startbit = 1;

    if (startbit == 1) {  // Send start bit
      digitalWrite(13, HIGH);
      startbit = 0;
    }

    Serial.println(character);

    for (int i = 7; i >= 0; i--) { // Convert character to bits and transmit them
      bool bit = bitRead(character, i);
      digitalWrite(12, bit);
      Serial.println(bit);
      delay(90);
    }
  } else {
    startbit = 0;
    digitalWrite(13, LOW); // Don't send start bit
  }
}
