#include "write_text.h"

void writeFont(char character, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B) {
	if(offset + font > LED_COUNT) offset = LED_COUNT - font;
	for (int col = 0; col < font; col++) {
		uint64_t leds = 0;
		if(font==FONT7)			leds = char7[(int)character - 64][ccw?col:(font - col - 1)]>>1;
		else if(font==FONT14)	leds = char14[(int)character - 64][ccw?col:(font - col - 1)]>>1;
		if(flip){
			leds = __rbit(leds)>>(32-font);
		}
		
		leds = leds<<offset;
		
		for(uint8_t i = 0; i < (pixelLengthUs/(25*3*RGB_ROWS)) + 1; i++)
			printSingleColorLine(leds, R, G, B);
		//nrf_delay_us(pixelLengthUs/3);
	}
}
void writeWordFont(char* word, uint8_t wordLen, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B){
	for(int i = 0; i < wordLen; i++){
		char toWrite = word[ccw?(wordLen-1-i) : i];
		if(toWrite == 32)	writeFont(64, font, pixelLengthUs, offset, flip, ccw, R, G, B);
		else	writeFont(toWrite, font, pixelLengthUs, offset, flip, ccw, R, G, B);
	}
}

