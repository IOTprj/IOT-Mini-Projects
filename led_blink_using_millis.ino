const int led=5;
unsigned long prevMillis=0;
int ledState=LOW;
const long interval=500;
void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}

void loop() {
unsigned long currMillis=millis();
if(currMillis-prevMillis>=interval){
  prevMillis=currMillis;
  if(ledState==LOW) ledState=HIGH;
  else ledState=LOW;

  digitalWrite(led, ledState);
}
}
