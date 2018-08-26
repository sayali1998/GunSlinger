#include <IRremoteESP8266.h>
#include <IRsend.h>

#define IR_LED D2

int but=D1;
int bullets=5;
int buzzer=D0;

IRsend irsend(IR_LED);  

uint16_t rawdata= 3021;

void setup() {
  // put your setup code here, to run once:
  irsend.begin();
  Serial.begin(115200);
  pinMode(but,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(but) == HIGH && bullets!=0){
    irsend.sendRaw(rawdata,1,38);
    bullets=bullets-1;
    delay(200);
  }
  if(bullets==0){
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    bullets=5;    
  }

}
