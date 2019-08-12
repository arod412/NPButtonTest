/*

Name: NeoPixel and Button Test
Author: Alexis Rodriguez Jr.

Hardware needed:
5x Momentary Switches (Tactile Buttons) (SPST - Single Pole Single Throw)
4x NeoPixel LEDs
14x jumpers (5x GND button side, 5x SIGNAL button side, 3x NeoPixel, 1x GND breadboard)
*/

//Include Libraries
#include <Adafruit_NeoPixel.h>

//Define the digital DATA pin for NeoPixel
#define NEOPIXEL_IN 6

//Define number of LEDs in NeoPixel Strip
#define NUM_LIGHTS 4

//Define Simon Says Buttons
#define BUTTON_BLUE A0
#define BUTTON_YELLOW A1
#define BUTTON_RED A2
#define BUTTON_GREEN A3

//Define Simon Says NeoPixel LEDs position
#define NP_BLUE 0
#define NP_YELLOW 1
#define NP_RED 2
#define NP_GREEN 3

//Define Start/Stop button analog input
#define INIT_BUTTON A4

//Baud Rate for Serial
#define BAUD_RATE 115200

//GLOBAL VARIABLES

const boolean DEBUG = 1;				//Debug buttons
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LIGHTS, NEOPIXEL_IN);	//Initialize NeoPixel object

//Single 32-bit value to determine NeoPixel Color display
//0x00000000
//0xWWRRGGBB
//So to get RED: 0x00FF0000
//However, use low values to limit current draw since these are very bright!
const uint32_t red = 0x00040000;		//Display RED on NeoPixel
const uint32_t green = 0x00000400;	//Display GREEN on NeoPixel
const uint32_t yellow = 0x00040400;	//Display YELLOW on NeoPixel
const uint32_t blue = 0x00000004;	//Display BLUE on NeoPixel
const uint32_t white = 0x00040404;  //Display WHITE on NeoPixel

void setup() {
	
	//Used to debug [Use Serial.println("TEXT")]
	Serial.begin(BAUD_RATE);
	
	//Define all buttons used as inputs with a internal pullup
	pinMode(BUTTON_BLUE, INPUT_PULLUP);
	pinMode(BUTTON_YELLOW, INPUT_PULLUP);
	pinMode(BUTTON_RED, INPUT_PULLUP);
	pinMode(BUTTON_GREEN, INPUT_PULLUP);
	pinMode(INIT_BUTTON, INPUT_PULLUP);
	
	//NeoPixel Setup
	strip.begin();	//Fully initialize the pin and pixel count of object
	delay(100);
	strip.clear();  //Turn off all LEDs and clear frame matrix
	delay(100);
	
	//Show ready pattern
	strip.setPixelColor(NP_BLUE,blue);
	strip.setPixelColor(NP_YELLOW,yellow);
	strip.setPixelColor(NP_RED,red);
	strip.setPixelColor(NP_GREEN,green);
	strip.show();
	
	strip.clear();
	delay(500);
	strip.show();
	
}

void loop() {
	
	//This is to debug the buttons and LEDs in case something goes wrong with hardware connections
	if (DEBUG){
		while(1){
			//LOW = Pressed
			if (digitalRead(A0) == LOW) {
				Serial.println("BLUE");
				strip.setPixelColor(NP_BLUE,blue);
				delay(250);
				strip.show();
			}
			
			if (digitalRead(A1) == LOW) {
				Serial.println("YELLOW");
				strip.setPixelColor(NP_YELLOW,yellow);
				delay(250);
				strip.show();
			}
			
			if (digitalRead(A2) == LOW) {
				Serial.println("RED");
				strip.setPixelColor(NP_RED,red);
				delay(250);
				strip.show();
			}
			
			if (digitalRead(A3) == LOW) {
				Serial.println("GREEN");
				strip.setPixelColor(NP_GREEN,green);
				delay(250);
				strip.show();
			}
			
			if (digitalRead(A4) == LOW) {
				Serial.println("START");
				strip.setPixelColor(NP_BLUE,blue);
				strip.setPixelColor(NP_YELLOW,yellow);
				strip.setPixelColor(NP_RED,red);
				strip.setPixelColor(NP_GREEN,green);
				delay(250);
				strip.show();
			}
			delay(250);
			strip.clear();
			strip.show();
		}
	}
}