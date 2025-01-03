#include "write_text.h"

//static inline uint64_t getTimeSinceBootMs(){
//	return get_now()*1000/(APP_TIMER_CLOCK_FREQ/(APP_TIMER_CONFIG_RTC_FREQUENCY + 1));
//}

void delayRgbUs(uint32_t us_time, uint8_t R, uint8_t G, uint8_t B){
//	uint8_t rgb[] = {R, G, B};
//	us_time = us_time*25600/78000;
//	for(uint32_t t = 0; t < us_time; t++){
//		for(uint8_t color = 0; color < 3; color++){
//			nrf_gpio_pin_write(RGB_PINS[color], rgb[color] > ((t*us_time) % 256));
////			nrf_delay_us(1);
//			nrf_gpio_pin_write(RGB_PINS[color], 0);
//		}
//	}
}
void writeFont(char character, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B) {
	for (int col = 0; col < font; col++) {
		uint8_t temp[LED_COUNT][3];
		memset(temp, 0, LED_COUNT*3);
		for (uint8_t row = 0; row < font; row++){
			if(font==7 && ((char7[(int)character - 64][flip?(6 - row):row]>>(ccw?col:(6-col))) & 1)) {
				temp[row + offset][0] = R;
				temp[row + offset][1] = G;
				temp[row + offset][2] = B;
			}
			if(font==16 && ((char16[(int)character - 64][flip?(15 - row):row]>>(ccw?col:(15-col))) & 1)){
				temp[row + offset][0] = R;
				temp[row + offset][1] = G;
				temp[row + offset][2] = B;
			}
		}
		printColoredLine(temp, false);
		
		nrf_delay_us(pixelLengthUs);
//		delayRgbUs(pixelLengthUs, R, G, B);
//		for (uint8_t row = 0; row < font; row++)	nrf_gpio_pin_write(LED_PIN[row + offset], 0);
//		delayRgbUs(pixelLengthUs/2, R, G, B);
	}
	
	
}
void writeWordFont(char* word, uint8_t wordLen, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B){
	for(int i = 0; i < wordLen; i++){
		char toWrite = word[ccw?(wordLen-1-i) : i];
		if(toWrite == 32)	writeFont(64, font, pixelLengthUs, offset, !flip, ccw, R, G, B);
		else	writeFont(toWrite, font, pixelLengthUs, offset, !flip, ccw, R, G, B);
	}
}

void leds_init(void){
	for(uint8_t i = 0; i < LED_SIGNALS_COUNT; i++){
		nrf_gpio_cfg_output(LED_PIN[i]);
		nrf_gpio_pin_write(LED_PIN[i], 0);
	}
	for(uint8_t rgb = 0; rgb < 3; rgb++){
		for(uint8_t i = 0; i < 2; i++){
			nrf_gpio_cfg_output(RGB_PINS[i][rgb]);
			nrf_gpio_pin_write(RGB_PINS[i][rgb], 0);
		}
	}
}
void leds_test(void){
	const uint32_t delay = 10000;
	for(uint8_t b = LED_COUNT; b > 0; --b)
	for(uint8_t i = 0; i < LED_COUNT; i++){
		nrf_gpio_pin_write(LED_PIN[i], 1);
		for(uint32_t j = 0; j <= (delay); j+=(b+1))
			for(uint8_t c = 0; c <= 2; c++){
				nrf_gpio_pin_write(RGB_PINS[i/LED_SIGNALS_COUNT][c], 1);
				nrf_gpio_pin_write(RGB_PINS[i/LED_SIGNALS_COUNT][c], 0);
			}
		if(i < b)	nrf_gpio_pin_write(LED_PIN[i], 0);
		else break;
	}
	for(uint8_t b = LED_COUNT; b > 0; --b)
	for(uint8_t i = b; i < LED_COUNT; i++){
		nrf_gpio_pin_write(LED_PIN[i], 1);
		for(uint32_t j = 0; j <= (delay); j+=(LED_COUNT-b+1))
			for(uint8_t c = 0; c <= 2; c++){
				nrf_gpio_pin_write(RGB_PINS[i/LED_SIGNALS_COUNT][c], 1);
				nrf_gpio_pin_write(RGB_PINS[i/LED_SIGNALS_COUNT][c], 0);
			}
		nrf_gpio_pin_write(LED_PIN[i], 0);
	}
}
void simple_leds_test(void){
	for(uint8_t c = 0; c <= 2; c++){
		for(uint8_t i = 0; i < 2; i++){
			nrf_gpio_pin_write(RGB_PINS[i][c], 1);
			for(uint8_t i = 0; i < LED_SIGNALS_COUNT; i++){
				nrf_gpio_pin_write(LED_PIN[i], 1);
				nrf_delay_ms(5);
				nrf_gpio_pin_write(LED_PIN[i], 0);
			}
			nrf_gpio_pin_write(RGB_PINS[i][c], 0);
		}
	}
}
void convertTrueRGB(uint8_t RGB[3][LED_COUNT]){
	uint8_t trueRGB[] = {255, 235, 212};
	for(uint8_t color = 0; color < 3; color++)
		for(uint8_t led = 0; led < LED_COUNT; led++)
			RGB[color][led] = (uint8_t)((uint32_t)RGB[color][led] * trueRGB[color] / 255);
}

void coloredLedsTest(uint8_t RGB[3][LED_COUNT]){
	for(uint8_t color = 0; color < 3; color++){
		for(uint8_t m = 0; m < 2; m++){
			nrf_gpio_pin_write(RGB_PINS[m][color], 1);
			for(uint16_t intensity = 0; intensity < 256; intensity+=25){
				for(uint8_t led = 0; led < LED_SIGNALS_COUNT; led++)	nrf_gpio_pin_write(LED_PIN[led], (RGB[color][led + LED_SIGNALS_COUNT*m] > intensity));
			}
			nrf_gpio_pin_write(RGB_PINS[m][color], 0);
			for(uint8_t led = 0; led < LED_SIGNALS_COUNT; led++)	nrf_gpio_pin_write(LED_PIN[led], 0);
		}
	}
}

void printColoredLine(uint8_t line[LED_COUNT][3], bool inv){
	for(uint8_t color = 0; color < 3; color++){
		for(uint8_t m = 0; m < 2; m++){
			nrf_gpio_pin_write(RGB_PINS[m][color], 1);
			for(uint16_t intensity = 0; intensity < 256; intensity+=25){
				if(inv) for(uint8_t led = 0; led < LED_SIGNALS_COUNT; led++)	nrf_gpio_pin_write(LED_PIN[led], (line[LED_COUNT - (led + LED_SIGNALS_COUNT*m)][color] > intensity));
				else 	for(uint8_t led = 0; led < LED_SIGNALS_COUNT; led++)	nrf_gpio_pin_write(LED_PIN[led], (line[led + LED_SIGNALS_COUNT*m][color] > intensity));
			}
			nrf_gpio_pin_write(RGB_PINS[m][color], 0);
			for(uint8_t led = 0; led < LED_SIGNALS_COUNT; led++)	nrf_gpio_pin_write(LED_PIN[led], 0);
		}
	}
}

bool from16toFullSize(uint8_t oldArray[16][3], uint8_t newArray[LED_COUNT][3], uint8_t offset, uint8_t bgColor[3]){
	if((offset + 16) > LED_COUNT)	return false;
	for(uint8_t i = 0; i < LED_COUNT; i++){
		newArray[i][0] = bgColor[0]; 
		newArray[i][1] = bgColor[1]; 
		newArray[i][2] = bgColor[2];
	}
	for(uint8_t i = 0; i < 16; i++){
		newArray[i + offset][0] = oldArray[i][0];
		newArray[i + offset][1] = oldArray[i][1];
		newArray[i + offset][2] = oldArray[i][2];
	}
	return true;
}

bool from32toFullSize(uint8_t oldArray[32][3], uint8_t newArray[LED_COUNT][3], uint8_t offset, uint8_t bgColor[3]){
	if((offset + 32) > LED_COUNT)	return false;
	for(uint8_t i = 0; i < LED_COUNT; i++){
		newArray[i][0] = bgColor[0]; 
		newArray[i][1] = bgColor[1]; 
		newArray[i][2] = bgColor[2];
	}
	for(uint8_t i = 0; i < 32; i++){
		newArray[i + offset][0] = oldArray[i][0];
		newArray[i + offset][1] = oldArray[i][1];
		newArray[i + offset][2] = oldArray[i][2];
	}
	return true;
}

bool double16array(uint8_t oldArray[16][3], uint8_t newArray[LED_COUNT][3], uint8_t offset, uint8_t bgColor[3]){
	if((offset + 32)>LED_COUNT)	return false;
	for(uint8_t i = 0; i < LED_COUNT; i++){
		newArray[i][0] = bgColor[0]; 
		newArray[i][1] = bgColor[1]; 
		newArray[i][2] = bgColor[2];
	}
	for(uint8_t i = 0; i < 16; i++){
		newArray[2*i + offset][0] = oldArray[i][0];
		newArray[2*i + offset][1] = oldArray[i][1];
		newArray[2*i + offset][2] = oldArray[i][2];
		newArray[2*i + 1 + offset][0] = oldArray[i][0];
		newArray[2*i + 1 + offset][1] = oldArray[i][1];
		newArray[2*i + 1 + offset][2] = oldArray[i][2];
	}
	return true;
}
