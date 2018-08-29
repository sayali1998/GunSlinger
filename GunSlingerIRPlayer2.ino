#include <IRremoteESP8266.h>
#include <IRsend.h>

#define IR_LED D2

int button = D0;
int bullets = 5;
int buzzer = D7;
int LED1 = D1;
int LED2 = D3;
int LED3 = D4;
int LED4 = D5;
int LED5 = D6;

IRsend irsend(IR_LED);  


void setup() 
{
  
  irsend.begin();
  Serial.begin(115200);
  pinMode(button,INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED3, LOW);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED4, LOW);
  pinMode(LED5, OUTPUT);
  digitalWrite(LED5, LOW); 
  
}

void loop() {


  if(digitalRead(button) == LOW && bullets != 0)
  {

    digitalWrite(LED1, HIGH);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(10);
    
    irsend.sendSony(0xa91, 12, 2);
    
    digitalWrite(LED3, HIGH);
    delay(100);
    digitalWrite(LED4, HIGH);
    delay(100);
    digitalWrite(LED5, HIGH);
    delay(100);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    
    bullets--;
    delay(1000);
    
  }
  
  if(bullets == 0)
  {
      for(int i = 1; i <= 5; i++)
      {
        
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
    
        delay(500);

      }

    bullets = 5;  
      
  }
  
}
