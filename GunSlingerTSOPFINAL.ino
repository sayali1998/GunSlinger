#include <IRremoteESP8266.h>
#include <IRrecv.h>

#define RECV_PIN D2

int buzzer = D7;
int h1 = D1;
int h2 = D3;
int h3 = D4;
int h4 = D5;
int h5 = D6;
int count = 1;

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
  
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    
    //Serial.println(results.value, HEX);
    if(count == 1)
    {

        digitalWrite(h1, LOW);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        count++;
      
    }
    else if(count == 2)
    {

        digitalWrite(h2, LOW);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        count++;
      
    }
    else if(count == 3)
    {

        digitalWrite(h3, LOW);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        count++;
      
    }
    else if(count == 4)
    {

        digitalWrite(h4, LOW);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        count++;
      
    }
    else if(count == 5)
    {

        digitalWrite(h5, LOW);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        count++;
      
    }
    else
    {
      
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
      
    }
    irrecv.resume();  // Receive the next value 
  }
  delay(100);
}
