
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define RECV_PIN D2

int buzzer = D7;
int h1 = D1;
int h2 = D3;
int h3 = D4;
int h4 = D5;
int h5 = D6;
int LED = D0;

int count = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() 
{
  
  Serial.begin(115200);
  irrecv.enableIRIn();
  
  pinMode(buzzer, OUTPUT);
  pinMode(RECV_PIN, INPUT);
  pinMode(h1, OUTPUT);
  digitalWrite(h1, HIGH); 
  pinMode(h2, OUTPUT);
  digitalWrite(h2, HIGH); 
  pinMode(h3, OUTPUT);
  digitalWrite(h3, HIGH); 
  pinMode(h4, OUTPUT);
  digitalWrite(h4, HIGH); 
  pinMode(h5, OUTPUT);
  digitalWrite(h5, HIGH);  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    
    serialPrintUint64(results.value,HEX);
    if(results.value == 0xa91)
    {

      count++;
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      
      if(count == 2)
      {

        digitalWrite(h1, LOW);
        
      
      }
      else if(count == 4)
      { 

        digitalWrite(h2, LOW);
      
      }
      else if(count == 6)
      {

        digitalWrite(h3, LOW);
      
      }
      else if(count == 8)
      {

        digitalWrite(h4, LOW);
      
      }
      else if(count == 10)
      {

        digitalWrite(h5, LOW);

        delay(50);

        digitalWrite(buzzer, HIGH);
        delay(5000);
        digitalWrite(buzzer, LOW);
      
      }
     
      irrecv.resume();  // Receive the next value 
    }
    delay(100);
  }
}
