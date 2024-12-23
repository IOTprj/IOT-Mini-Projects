const int led = 5;
const int butt = 4;
int buttState;
int lastButtState = HIGH; 
int c = 0;              
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;  
int buttPushCount=0;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(butt, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(butt);
  if (reading != lastButtState) {
    lastDebounceTime = millis(); 
  }
//with the help of millis this if condition is true at every 0.05 sec after every debounce
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && buttState == HIGH) {
      c=c==0? 1:0;
      if(c){
          buttPushCount++;
        Serial.println(buttPushCount);
        Serial.println("ON");
      }
      else  Serial.println("OFF");
    }
    buttState = reading;
  }
  digitalWrite(led, c);
  lastButtState = reading; 
}
