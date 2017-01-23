#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      16

//////////////////////////BT SERIAL/////////////////////////////////
SoftwareSerial BTSerial(2, 3); //Connect HC-06. Use your (TX, RX) settings
///////////////////////////Piezo Buzzer/////////////////////////////////
int piezo = 11;          // use pin 3 to control the tone
int del = 1000;        
///////////////////////////Neo_Pixel///////////////////////////////////
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500; // delay for half a second

void setup()  
{
 
  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);  // set the data rate for the BT port

  pinMode(piezo, OUTPUT); 

  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  
}

void loop()
{
  // BT –> Data –> Serial
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
    analogWrite(piezo, 64);         
    delay(del); 
  }
  // Serial –> Data –> BT
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(0,150,0));

    pixels.show(); 

    delay(1000); 
  }
}

