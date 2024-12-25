#include <pitches.h>
const int threshold = 4000;

// Define valid GPIO pins for analog inputs
int analogPins[] = {34, 35, 32};
int notes[] = {NOTE_A4, NOTE_D4, NOTE_C3};
const int buzzerPin = 5;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    int sensorReading = analogRead(analogPins[thisSensor]);
    Serial.print("Sensor ");
    Serial.print(thisSensor);
    Serial.print(" reading: ");
    Serial.println(sensorReading);

    if (sensorReading > threshold) {
      tone(buzzerPin, notes[thisSensor], 200); // Play tone for 200ms
      delay(200); // Wait to avoid continuous buzzing
      noTone(buzzerPin); // Stop the tone
    }
  }
  delay(100); // Small delay for sensor stability
}

