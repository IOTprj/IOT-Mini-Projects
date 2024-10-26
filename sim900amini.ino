#include <HardwareSerial.h>
HardwareSerial mySerial(1);

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.println("Start");
  Serial.println("GSM SIM900A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("h : to disconnect a call");
  Serial.println("i : to receive a call");
  Serial.println("s : to send message");
  Serial.println("c : to make a call");
  Serial.println("e : to redial");
  Serial.println();
  delay(100);
  mySerial.println("AT+CSQ");
}

void loop() {
  // Check if data is available on Serial (user input)
  if (Serial.available() > 0) {
    char ch = Serial.read();
    switch (ch) {
      case 's': sendMessage(); break;
      case 'c': makeCall(); break;
      case 'h': HangupCall(); break;
      case 'e': redialCall(); break;
      case 'i': receiveCall(); break; // Corrected spelling
      default: Serial.println("Invalid Option!"); break;
    }
  }

  // Check if data is available on the GSM module (mySerial)
  if (mySerial.available() > 0) {
    while (mySerial.available()) {
      Serial.write(mySerial.read());  // Print GSM response to Serial Monitor
    }
  }
}

// Function to send SMS
void sendMessage() {
  mySerial.println("AT+CMGF=1"); // Set the GSM module to Text Mode
  delay(1000);
  mySerial.println("AT+CMGS=\"+919257009141\""); // Replace with valid number
  delay(1000);
  mySerial.println("sim900a sms"); // SMS content
  delay(100);
  mySerial.println((char)26); // ASCII code for CTRL+Z (end of SMS)
  delay(1000);
  Serial.println("Message Sent");
}

// Function to make a call
void makeCall() {
  mySerial.println("ATD+919257009141;"); // Replace with valid number
  Serial.println("Calling");
}

// Function to hang up a call
void HangupCall() {
  mySerial.println("ATH");  // Hang up the call
  Serial.println("Call Hangup");
  delay(1000);
}

// Function to receive a call
void receiveCall() {
  mySerial.println("ATA"); // Answer incoming call
  delay(1000);
  Serial.println("Call Answered");
}
  
// Function to redial the last dialed number
void redialCall() {
  mySerial.println("ATDL"); // Redial the last number
  Serial.println("Redialing");
  delay(1000);
}
