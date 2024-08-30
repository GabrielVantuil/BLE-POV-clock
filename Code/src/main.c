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

void draw_emoji(){
	for(uint8_t col = 0; col < 17; col++){
		coloredLedsTest(smileSunGlass[col]);
		nrf_delay_ms(1);
	}
}

/**@brief Function for application main entry.
 */
int main(void){
    // Initialize.
    lfclk_config();
    log_init();
    leds_init();
//	leds_test();
    NRF_LOG_INFO("Start");	NRF_LOG_PROCESS();
    timers_init();
									
//    APP_ERROR_CHECK(nrf_pwr_mgmt_init());
//    ble_stack_init();
//    gap_params_init();
//    gatt_init();
//    services_init();
//    advertising_init();
//    conn_params_init();
//    calcBatteryLevel(NULL);
//	
//    advertising_start();
	
	
	uint8_t rainbow[3][LED_COUNT] = {	
		{255, 255, 148, 148, 75, 75, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255},	//RED
		{255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 127, 127, 0, 0, 255, 255},			//GREEN
		{255, 255, 211, 211, 130, 130, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255}			//BLUE
	};
	convertTrueRGB(rainbow);
									
	char test[] = "GABRIEL";
	#define ALFABET (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    // Enter main loop.
    for (;;){
		draw_emoji();
//		coloredLedsTest(rainbow);
//		writeWordFont(ALFABET, 26, 16, 500, 1, true, false, 255, 235, 212);
//		writeWordFont(test, sizeof(test)-1, 16, 500, 1, true, false, 255, 235, 212);
//		writeWordFont(test, 3, 7, 100, 10, true, false, 83, 230, 183);
//		writeWordFont(&test[3], 4, 7, 100, 7, true, false, 0, 255, 0);
		
		NRF_LOG_PROCESS();
		nrf_delay_ms(10);
//        idle_state_handle();
    }
}


/**
 * @}
 */
