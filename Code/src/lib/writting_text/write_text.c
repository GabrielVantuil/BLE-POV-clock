#include "write_text.h"

//static inline uint64_t getTimeSinceBootMs(){
//	return get_now();//*1000/(APP_TIMER_CLOCK_FREQ/(APP_TIMER_CONFIG_RTC_FREQUENCY + 1));
//}

void delayRgbUs(uint32_t us_time, uint8_t R, uint8_t G, uint8_t B){
	uint8_t rgb[] = {R, G, B};
//			nrf_delay_us(ms_time*1000);
//	uint64_t start = getTimeSinceBootMs();
//	while(((getTimeSinceBootMs() - start)) < (uint64_t)ms_time){
	for(uint32_t t = 0; t < us_time; t+=3){
		for(uint8_t color = 0; color < 3; color++){
			nrf_gpio_pin_write(RGB_PINS[color], rgb[color] > ((t*us_time) % 256));
			nrf_delay_us(1);
			nrf_gpio_pin_write(RGB_PINS[color], 0);
		}
	}
}
void writeFont(char character, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B) {
	for (int col = 0; col < font; col++) {
		for (uint8_t row = 0; row < font; row++){
			if(font==7)		nrf_gpio_pin_write(LED_PIN[row + offset], (char7[(int)character - 64][flip?(6 - row):row]>>(ccw?col:(6-col))) & 1);
			if(font==16)	nrf_gpio_pin_write(LED_PIN[row + offset], (char16[(int)character - 64][flip?(15 - row):row]>>(ccw?col:(15-col))) & 1);
		}
		delayRgbUs(pixelLengthUs, R, G, B);
		for (uint8_t row = 0; row < font; row++)	nrf_gpio_pin_write(LED_PIN[row + offset], 0);
		delayRgbUs(pixelLengthUs/2, R, G, B);
	}
}
void writeWordFont(char* word, uint8_t wordLen, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B){
  for(int i = 0; i < wordLen; i++){
    char toWrite = word[ccw?(wordLen-1-i) : i];
    if(toWrite == 32)	writeFont(64, font, pixelLengthUs, offset, flip, ccw, R, G, B);
    else	writeFont(toWrite, font, pixelLengthUs, offset, flip, ccw, R, G, B);
  }
}

void leds_init(void){
	for(uint8_t i = 0; i < LED_COUNT; i++){
		nrf_gpio_cfg_output(LED_PIN[i]);
		nrf_gpio_pin_write(LED_PIN[i], 0);
	}
	nrf_gpio_cfg_output(RED_FET);
	nrf_gpio_cfg_output(GREEN_FET);
	nrf_gpio_cfg_output(BLUE_FET);
	nrf_gpio_pin_write(RED_FET,   0);
	nrf_gpio_pin_write(GREEN_FET, 0);
	nrf_gpio_pin_write(BLUE_FET,  0);
}
void leds_test(void){
	const uint32_t delay = 10000;
	for(uint8_t b = LED_COUNT; b > 0; --b)
	for(uint8_t i = 0; i < LED_COUNT; i++){
		nrf_gpio_pin_write(LED_PIN[i], 1);
		for(uint32_t j = 0; j <= (delay); j+=(b+1))
			for(uint8_t c = 0; c <= 2; c++){
				nrf_gpio_pin_write(RGB_PINS[c], 1);
				nrf_gpio_pin_write(RGB_PINS[c], 0);
			}
		if(i < b)	nrf_gpio_pin_write(LED_PIN[i], 0);
		else break;
	}
	for(uint8_t b = LED_COUNT; b > 0; --b)
	for(uint8_t i = b; i < LED_COUNT; i++){
		nrf_gpio_pin_write(LED_PIN[i], 1);
		for(uint32_t j = 0; j <= (delay); j+=(LED_COUNT-b+1))
			for(uint8_t c = 0; c <= 2; c++){
				nrf_gpio_pin_write(RGB_PINS[c], 1);
				nrf_gpio_pin_write(RGB_PINS[c], 0);
			}
		nrf_gpio_pin_write(LED_PIN[i], 0);
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
		nrf_gpio_pin_write(RGB_PINS[color], 1);
		for(uint16_t intensity = 0; intensity < 256; intensity+=10){
			for(uint8_t led = 0; led < LED_COUNT; led++)	nrf_gpio_pin_write(LED_PIN[led], (RGB[color][led] > intensity));
		}
		nrf_gpio_pin_write(RGB_PINS[color], 0);
	}
}

