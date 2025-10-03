//Q. how to fade an LED on pin 9 using the analogWrite() function.
const int led = 9;
int brightness = 1;
int intensity = 5;
int red = 4, blue = 2, green = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  analogWrite(led, brightness);
  // brightness = brightness % 255 + intensity;
  if(brightness > 255 || brightness <= 0){
    intensity = -intensity;
  }
  
  //setup the rgb light
  if(brightness <= 85){
     digitalWrite(red, HIGH);
     digitalWrite(blue, LOW);
     digitalWrite(green, LOW);
     Serial.println("glow red");
  }
  else if(brightness <= 170){
     digitalWrite(red, LOW);
     digitalWrite(blue, HIGH);
     digitalWrite(green, LOW);
        Serial.println("glow green");
  }
  else{
     digitalWrite(red, LOW);
     digitalWrite(blue, LOW);
     digitalWrite(green, HIGH); 
    Serial.println("glow blue");
  }

  brightness += intensity;
  Serial.println(brightness);
  delay(100);
}
