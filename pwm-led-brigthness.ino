const int led=5;
int intensity=5;
int frequency = 5;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  analogWrite(led,intensity);
  Serial.println(intensity);
  if(intensity>255 || intensity < 0) frequency=-frequency;
  intensity += frequency;
  delay(500);
}
