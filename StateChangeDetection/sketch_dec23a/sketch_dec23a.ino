const int led=5;
const int butt=4;
int buttState=LOW;
int currState=1;
int prevState=1;

int c=0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(butt, INPUT_PULLUP);
  digitalWrite(led,buttState);
  Serial.begin(9600);
}

void loop() {
  currState=digitalRead(butt);
  if(currState==0 && prevState==1){
    c++;
    if(c%2!=0){
      Serial.println("on");
    }
    else{
     Serial.println("off");
     Serial.println("number of butt pushes:");
      Serial.println(c/2);
    }
  }
  prevState=currState;
  if(c%4==0){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  delay(50);
}
