#include <stdint.h>
#include <string.h>
#include "nordic_common.h"
#include "nrf.h"
#include "app_error.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "nrf_drv_clock.h"
#include "nrf_delay.h"

#include "app_ble.h"
#include "handles.h"
#include "Battery_level.h"
#include "write_text.h"
#include "images.h"


uint8_t mode = 0;
uint8_t genericLedsSetup[LED_COUNT][3];	
char text[] = "GABRIEL";
uint8_t textLenght = 7;
uint8_t r = 255, g = 235,  b = 212;

#define TOTAL_MODES 4

static void log_init(void){
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

static void lfclk_config(void){
	// initialize the low power low frequency clock
  APP_ERROR_CHECK(nrf_drv_clock_init());

	// request the lf clock to not to generate any events on ticks
	// One tick =  1 value increment in the counter register
  nrf_drv_clock_lfclk_request(NULL);
}

void draw_image(uint8_t image[][32][3], bool inv){
	uint8_t whiteBg[3] = {255, 235, 212};
	for(uint8_t col = 0; col < 32; col++){
		uint8_t temp[LED_COUNT][3];
//		from16toFullSize(smileSunGlass[col], temp, 44-16); 
//		double16array(emojiSunGlass16[col/2], temp, (44-32)/2, whiteBg); 
		from32toFullSize(image[col], temp, (44-32)/2, whiteBg); 
		printColoredLine(temp, inv);
		nrf_delay_us(1200);
	}
}

/**@brief Function for application main entry.
 */
int main(void){
    // Initialize.
    lfclk_config();
    log_init();
    leds_init();
	simple_leds_test();
    NRF_LOG_INFO("Start");	NRF_LOG_PROCESS();
    timers_init();		
    APP_ERROR_CHECK(nrf_pwr_mgmt_init());
    ble_stack_init();
    gap_params_init();
    gatt_init();
    services_init();
    advertising_init();
    conn_params_init();
//    calcBatteryLevel(NULL);
//	
    advertising_start();
	nrf_gpio_cfg_input(SENSOR_PIN, NRF_GPIO_PIN_PULLUP);
	
	
	uint8_t rainbow[3][LED_COUNT] = {	
		{255, 148,  148, 148,  148, 148,  148, 75,  75,  75,  75,  75,  75,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255},	//RED
		{255, 0,    0,   0,    0,   0,    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 127, 127, 127, 127, 127, 0,   0,   0,   0,   0,   0,   255},	//GREEN
		{255, 211,  211, 211,  211, 211,  211, 130, 130, 130, 130, 130, 130, 255, 255, 255, 255, 255, 255, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   255}	    //BLUE
	};
	convertTrueRGB(rainbow);
								
	#define ALFABET (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    bool button_latch = false;
	
    for (;;){
		if(!nrf_gpio_pin_read(SENSOR_PIN) && !button_latch){
			mode = (256 - TOTAL_MODES) + (mode - 256 + TOTAL_MODES+ 1) % TOTAL_MODES;
			button_latch = true;
		}
		if(nrf_gpio_pin_read(SENSOR_PIN)) button_latch = false;
		switch(mode){
			case 0:
				writeWordFont(text, textLenght, 16, 100, 0, false, true, r, g, b);//255, 235, 212
				break;
			case 1:
				printColoredLine(genericLedsSetup, false);
				break;
			case 253:
				draw_image(emojiSunGlass32, false);
				break;
			case 254:
				draw_image(imgSuperMario32, false);
				break;
			case 255:
				draw_image(emojiSunGlass32, true);
				break;
		}
//		coloredLedsTest(rainbow);
//		writeWordFont(ALFABET, 26, 16, 500, 1, true, false, 255, 235, 212);
//		writeWordFont(test, sizeof(test)-1, 16, 500, 1, true, false, 255, 235, 212);
//		writeWordFont(test, 3, 7, 100, 10, true, false, 83, 230, 183);
//		writeWordFont(&test[3], 4, 7, 100, 7, true, false, 0, 255, 0);
		
//		NRF_LOG_PROCESS();
//		nrf_delay_ms(10);
//        idle_state_handle();
    }
}


/**
 * @}
 */
