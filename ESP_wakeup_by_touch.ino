const int led=5;
int c=0;
#define THRESHOLD 40
RTC_DATA_ATTR int bootCount=0;
touch_pad_t touchPin;
void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}

void print_wakeup_touchpad(){
  touchPin=esp_sleep_get_touchpad_wakeup_status();
  switch(touchPin){
      case 0  : Serial.println("Touch detected on GPIO 4"); break;
      case 1  : Serial.println("Touch detected on GPIO 0"); break;
      case 2  : Serial.println("Touch detected on GPIO 2"); break;
      case 3  : Serial.println("Touch detected on GPIO 15"); break;
      case 4  : Serial.println("Touch detected on GPIO 13"); break;
      case 5  : Serial.println("Touch detected on GPIO 12"); break;
      case 6  : Serial.println("Touch detected on GPIO 14"); break;
      case 7  : Serial.println("Touch detected on GPIO 27"); break;
      case 8  : Serial.println("Touch detected on GPIO 33"); break;
      case 9  : Serial.println("Touch detected on GPIO 32"); break;
      default : Serial.println("Wakeup not by touchpad"); break;
  }
}
void setup() {
  pinMode(led,OUTPUT);
Serial.begin(115200);
delay(1000);
++bootCount;
Serial.println("Boot number: " + String(bootCount));
print_wakeup_reason();
print_wakeup_touchpad();
touchSleepWakeUpEnable(T3,THRESHOLD); //GPIO15
touchSleepWakeUpEnable(T7,THRESHOLD); //GPIO27
//go to sleep

}

void loop() {
   digitalWrite(led,HIGH);
int a=touchRead(15);
 if(a<20){
  Serial.println("going to sleep");
esp_deep_sleep_start();
Serial.println("this will never be printed");
 }
}
