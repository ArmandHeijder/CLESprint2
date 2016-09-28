#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 9
#define NUM_LEDS 60
#define BRIGHTNESS 100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


const int buttonPinA = 2;
const int buttonPinB = 3;
const int buttonPinC = 4;

int buttonStateA = 0;
int previousStateA =0;
int buttonStateB = 0;
int previousStateB =0;
int buttonStateC = 0;
int previousStateC =0;


void setup() {
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);
  Serial.begin(9600);

    #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();
}

void loop () {
  buttonStateA = digitalRead(buttonPinA);
  if (buttonStateA != previousStateA && buttonStateA == LOW) {
    triggerLEDStripA();
  } 
  previousStateA = buttonStateA;

  buttonStateB = digitalRead(buttonPinB);
  if (buttonStateB != previousStateB && buttonStateB == LOW) {
    triggerLEDStripB();
  } 
  previousStateB = buttonStateB;

   buttonStateC = digitalRead(buttonPinC);
  if (buttonStateC != previousStateC && buttonStateC == LOW) {
    triggerLEDStripC();
  } 
  previousStateC = buttonStateC;

}

void triggerLEDStripA(){
  colorWipe(strip.Color(200, 0, 0), 10, 60);
  delay(200);
  colorWipe(strip.Color(0,0,0), 10, 60);
}

void triggerLEDStripB(){
  colorWipe(strip.Color(0, 200, 0), 10, 45);
  delay(200);
  colorWipe(strip.Color(0,0,0) ,10, 45);
}

void triggerLEDStripC(){
  colorWipe(strip.Color(0, 0, 200), 10, 30);
  delay(200);
  colorWipe(strip.Color(0,0,0),10, 30);
}


void colorWipe(uint32_t c, uint8_t wait, int pixelNum) {
  for(uint16_t i=0; i<pixelNum; i++) {
    delay(0);
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
