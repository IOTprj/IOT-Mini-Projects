//led Blink without delay
const int led=5;
unsigned long prevTime=0;
const int interval=1000;
int ledState=LOW;
void setup() {
pinMode(led, OUTPUT);
Serial.begin(9600);
}

void loop() {
unsigned long currTime=millis();
if(currTime-prevTime>=interval){
prevTime=currTime;
if(ledState==LOW) ledState=HIGH;
else ledState=LOW;
}
digitalWrite(led,ledState);
}

