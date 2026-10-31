#include <Adafruit_NeoPixel.h>

#define PIN 18        
#define NUMPIXELS 4 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 150;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setColor() {
  redColor = random(0, 255);
  greenColor = random(0, 255);
  blueColor = random(0, 255);
  
  Serial.print("red: "); Serial.print(redColor);
  Serial.print(" | green: "); Serial.print(greenColor);
  Serial.print(" | blue: "); Serial.println(blueColor);
}

void setup() {
  Serial.begin(115200);
  pixels.begin();
}

void loop() {
  setColor();

  // Запалюємо кожен діод один за одним цим кольором
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    pixels.show(); // Відправляємо дані на світлодіоди
    delay(delayval); 
  }
  
  // Невелика пауза перед тим, як вибрати наступний випадковий колір
  delay(500); 
}
