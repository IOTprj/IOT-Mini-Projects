//control rgb using button
//concept -> when we push button then it goes from 1 to 0 (bcoz we use INPUT_PULLUP). so when prevState=1 and currState = 0 then increase the count.
int pushBtn=14;
int red=5;
int green=18;
int blue=19;
void setup() {
Serial.begin(9600);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(pushBtn, INPUT_PULLUP);
}
int count=0;
int prev=1;

void loop() {
int curr=digitalRead(pushBtn);
Serial.println(curr);
if(prev==1 && curr==0){
  count++;
  if(count>3) count=1;

}
if(count==1){
   rGlow();
}
else if(count==2){
bGlow();
}
else{
  gGlow();
}
prev=curr;
delay(10);
}
void rGlow(){
digitalWrite(red, HIGH);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
}
void bGlow(){
digitalWrite(red, LOW);
digitalWrite(green, HIGH);
digitalWrite(blue, LOW); 
}
void gGlow(){
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, HIGH);
}
