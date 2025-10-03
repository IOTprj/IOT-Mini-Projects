// Turns on and off a light emitting diode (LED) connected to a digital pin, 
// without using the delay() function. This means that other code can run at the 
// same time without being interrupted by the LED code.


const int led = 5;
int prevTime = 0;
const interval = 1000;
int ledState = LOW;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  Serial.println("Hello, ESP32!");
}

void loop() {
  unsigned int currTime = millis();
  if(currTime - prevTime >= interval){
    prevTime = currTime;
    ledState = ledState == LOW ? HIGH : LOW;
  }

  digitalWrite(led, ledState);
  delay(10); 
}