/*
 neo pixel test

   hardwware:  M5StackFire 

 please install the Adafruit library first!
 September 2018, ChrisMicro
*/
#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>

#define M5STACK_FIRE_NEO_NUM_LEDS 10
#define M5STACK_FIRE_NEO_DATA_PIN 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(M5STACK_FIRE_NEO_NUM_LEDS, M5STACK_FIRE_NEO_DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
	M5.begin(true, true, true, true);
	M5.Lcd.setTextSize(3);
	M5.Lcd.print("FACESII_RGB_BAR");
	pixels.begin();
}

void loop()
{

	static int pixelNumber = 0; // = random(0, M5STACK_FIRE_NEO_NUM_LEDS - 1);
	pixelNumber++;
	if (pixelNumber > 9)
		pixelNumber = 0;
	int r = 1 << random(0, 7);
	int g = 1 << random(0, 7);
	int b = 1 << random(0, 7);

	pixels.setPixelColor(pixelNumber, pixels.Color(r, g, b));
	pixels.show();

	delay(100);
}
