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

#define TEXT_SIZE 15
uint8_t mode = 0;
uint8_t genericLeds[LED_COUNT][3];	
char text[TEXT_SIZE] = "GABRIEL   ";
uint8_t textLength = 10;
uint8_t r = 255, g = 235,  b = 212;	//true RGB = 255, 235, 212
float RPM;
volatile bool zeroedPos = false;
volatile uint8_t sync = 255;

#define TOTAL_MODES 4

static inline uint64_t getTimeSinceBootMs(){
	return get_now()*1000/(APP_TIMER_CLOCK_FREQ/(APP_TIMER_CONFIG_RTC_FREQUENCY + 1));	//get_now()*1000/(32768/(31+1)) = 0.9765625
}
static void log_init(void){
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

static void gpiote_init(){
    //VCE: This block is a one time configuration
    if(!nrf_drv_gpiote_is_init()){
        APP_ERROR_CHECK(nrf_drv_gpiote_init());
    }

    //VCE: The below block needs to be called for each pin
    nrf_drv_gpiote_in_config_t in_config_1;
    in_config_1.pull = NRF_GPIO_PIN_PULLUP; //User defined
    in_config_1.sense = NRF_GPIOTE_POLARITY_HITOLO; //User defined
    in_config_1.hi_accuracy = false; //User defined
    in_config_1.is_watcher = false; //Don't change this
    in_config_1.skip_gpio_setup = false; //Don't change this

    //VCE: Configuring 
    APP_ERROR_CHECK(nrf_drv_gpiote_in_init(SENSOR_PIN, &in_config_1, in_pin_handler));
    nrf_drv_gpiote_in_event_enable(SENSOR_PIN, true);
}
void in_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action){
	static uint64_t count=0;
	static uint64_t last=0;
	count++;
	zeroedPos = true;
	
	if(count%10==0){
		uint64_t periodMs = getTimeSinceBootMs() - last;
		last = getTimeSinceBootMs();
		RPM = (60.0*1000*10)/periodMs;
	}
}

int main(void){
    log_init();
    leds_init();
	gpiote_init();
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
    advertising_start();
//    calcBatteryLevel(NULL);
	
    for (;;){
		while(!zeroedPos && (sync != 0xFF)){}
		zeroedPos = false;
		if(sync != 0xFF){
			uint32_t periodUs = (60.0*1000*1000)/RPM;
			nrf_delay_us(periodUs*sync/255);
		}
		switch(mode){
			case 0:
				writeWordFont(text, textLength, FONT14, 100, LED_COUNT-FONT14, false, false, r, g, b);//255, 235, 212
				break;
			case 1:
			case 2:
				printColoredLine(genericLeds, false);
				break;
			case 3:
				draw_image(emojiSunGlass32, false);
				break;
//			case 254:
//				draw_image(imgSuperMario32, false);
//				break;
//			case 255:
//				draw_image(emojiSunGlass32, true);
//				break;
		}
    }
}
