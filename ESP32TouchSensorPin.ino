const int led=5;
int frequency=500;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println("Hii what up");
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=touchRead(4);
  if(val<20) digitalWrite(led,HIGH);
  else digitalWrite(led,LOW);
  Serial.println(val);
  delay(500);
}
