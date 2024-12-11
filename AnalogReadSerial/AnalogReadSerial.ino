// /*
//   AnalogReadSerial

//   Reads an analog input on pin 0, prints the result to the Serial Monitor.
//   Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
//   Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

//   This example code is in the public domain.

//   https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
// */

// // the setup routine runs once when you press reset:
// void setup() {
//   // initialize serial communication at 9600 bits per second:
//   Serial.begin(9600);
// }

// // the loop routine runs over and over again forever:
// void loop() {
//   // read the input on analog pin 0:
//   int sensorValue = analogRead(A0);
//   // print out the value you read:
//   Serial.println(sensorValue);
//   delay(1);  // delay in between reads for stability
// }

  /* ESP32 WiFi Scanning example */

const int a=4;

void setup() {
  Serial.begin(9600);
pinMode(a, OUTPUT);
pinMode(17, OUTPUT);
pinMode(5, OUTPUT);
pinMode(16, OUTPUT);
}

void loop() {
  int sVal=analogRead(a);
  int newVal=4095/255;
  int b=sVal/newVal;
  Serial.println(b);
  if(b<=50) blue();
  else if(b<=150) green();
  else red();
  }
  void blue(){
    Serial.println("b");
    digitalWrite(17, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(16, LOW);
  }
  void green(){
    Serial.println("g");
    digitalWrite(17, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(16, LOW);
  }
    void red(){
    Serial.println("r");
    digitalWrite(17, LOW);
    digitalWrite(5, LOW);
    digitalWrite(16, HIGH);
  }
