const int n=4;
const int led=5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(led, OUTPUT);
}

void loop() {
  int val=analogRead(n);
 val=val/16;
  // Serial.println(val);
analogWrite(led,val);
}