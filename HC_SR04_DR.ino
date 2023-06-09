// Test the ADNS3080 Optical Flow Sensor
#include "SPI.h"


const int trig = 12;
const int echo = 13;
const int green_alert = 5;
const int yellow_alert = 6;
const int red_alert = 7;

int duration = 0;
float distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);

  pinMode(red_alert, OUTPUT);
  pinMode(yellow_alert, OUTPUT);
  pinMode(green_alert, OUTPUT);
  
    
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 29.1 ;
  Serial.println(distance);
  
  if (distance < 5){
    digitalWrite(red_alert, HIGH);
  }
  else if (distance <10){
    digitalWrite(yellow_alert, HIGH);
  }
  else {
    digitalWrite(red_alert, LOW);
    digitalWrite(yellow_alert, LOW);
    digitalWrite(green_alert, HIGH);
  }

}