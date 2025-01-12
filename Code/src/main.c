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
char text[] = "GABRIEL   ";
uint8_t textLength = 10
;
uint8_t r = 255, g = 235,  b = 212;	//true RGB = 255, 235, 212
float RPM;
volatile bool zeroedPos = false;

#define TOTAL_MODES 4

static inline uint64_t getTimeSinceBootMs(){
	return get_now()*1000/(APP_TIMER_CLOCK_FREQ/(APP_TIMER_CONFIG_RTC_FREQUENCY + 1));	//get_now()*1000/(32768/(31+1)) = 0.9765625
}
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
		nrf_delay_us(300);
	}
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
	
	if(count%100==0){
		uint64_t periodMs = getTimeSinceBootMs() - last;
		last = getTimeSinceBootMs();
		RPM = (60.0*1000*100)/periodMs;
	}
}

/**@brief Function for application main entry.
 */
int main(void){
    // Initialize.
    lfclk_config();
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
	uint8_t a = 0xff;
	uint64_t leds = a;//0xFFFF;
	NRF_LOG_INFO("temp: %x", leds);
	leds = leds>>16;
	NRF_LOG_INFO("temp: %x", leds);//0xFFFF00
	leds = leds<<16;
	NRF_LOG_INFO("temp: %x", leds);//0xFFFF0000
	leds = ((leds>>(LED_SIGNALS_COUNT*1)) & MASK_ALL_LEDS);
	NRF_LOG_INFO("leds: %x", MASK_ALL_LEDS);
	NRF_LOG_INFO("temp: %x", leds);
    NRF_LOG_FLUSH();
	uint8_t RGB[3] = {255, 0, 255};
	leds = 0xAA;
	leds = leds<<36;
//    for (;;){
//		for(int i = 0; i < 255; i+=10){
//			for(uint8_t color = 0; color < 3; color++){
//				for(uint8_t m = 0; m < RGB_ROWS; m++){
//					uint32_t temp = (leds>>(LED_SIGNALS_COUNT*m)) & MASK_ALL_LEDS;
//					nrf_gpio_port_out_clear(NRF_P0, MASK_LEDS_AND_RGB);
//					if(temp){
//						nrf_gpio_pin_write(RGB_PINS[m][color], 1);
//						if(i < RGB[color])	nrf_gpio_port_out_set(NRF_P0, temp);
//						else 	nrf_gpio_port_out_clear(NRF_P0, MASK_LEDS_AND_RGB);
//					}
//					nrf_delay_us(1);
//				}
//			}
//		}
//	}
    for (;;){
		switch(mode){
			case 0:
				while(!zeroedPos);	
				zeroedPos = false;
				writeWordFont(text, textLength, FONT14, 100, LED_COUNT-FONT14, false, false, r, g, b);//255, 235, 212
				break;
			case 1:
			case 2:
				printColoredLine(genericLedsSetup, false);
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


/**
 * @}
 */
