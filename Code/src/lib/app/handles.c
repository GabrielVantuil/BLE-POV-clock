#include "handles.h"
#include "utils.h"
#include "write_text.h"
#include "app_pwm.h"

extern uint8_t mode;
extern bool zeroedPos;
extern uint8_t genericLeds[LED_COUNT][3];
extern char text[];
extern uint8_t textLength;
extern uint8_t r,g,b;
extern uint8_t sync;

APP_PWM_INSTANCE(PWM1,1);

void timers_init(void){
    APP_ERROR_CHECK(app_timer_init());
}

void pwm_ready_callback(uint32_t pwm_id){}
void setPwm(uint8_t pin, uint16_t duty){
	app_pwm_uninit(&PWM1);
    app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(100, pin);
    APP_ERROR_CHECK(app_pwm_init(&PWM1, &pwm1_cfg, pwm_ready_callback));
    app_pwm_enable(&PWM1);
	while (app_pwm_channel_duty_set(&PWM1, 0, duty) == NRF_ERROR_BUSY);
}
void set_params_handler(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, const uint8_t *params, uint8_t len){
	nrf_gpio_cfg_output(MOTOR_PIN);
	uint16_t RPM = ((params[0]<<8) + params[1]);
	setPwm(MOTOR_PIN, 100-RPM);
	sync = params[2];
    NRF_LOG_INFO("S %d", sync);	NRF_LOG_PROCESS();
}

void mode_handler(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, uint8_t m){
	mode = m;
}

void set_text_handler(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, const uint8_t *params, uint8_t len){
	mode = 0;
	r = params[0];
	g = params[1];
	b = params[2];
	textLength = len-3;
	memcpy(text, &params[3], textLength);
}

void set_leds_handler(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, const uint8_t *params, uint8_t len){
	mode = 1;
	if((len/3) > LED_COUNT) len = LED_COUNT*3;
	for(uint8_t i = 0; i < LED_COUNT; i++){
		genericLeds[i][0] = 0;	
		genericLeds[i][1] = 0;	
		genericLeds[i][2] = 0;
	}
	if(len == 3){ //all leds
		for(uint8_t i = 0; i < LED_COUNT; i++){
			genericLeds[i][0] = params[0];	
			genericLeds[i][1] = params[1];	
			genericLeds[i][2] = params[2];
		}
	}
	else if(len == 4){	//single led
		genericLeds[params[3]][0] = params[0];	
		genericLeds[params[3]][1] = params[1];	
		genericLeds[params[3]][2] = params[2];
	}
	else{
		for(uint8_t i = 0; i < (len/3); i++){
			genericLeds[i][0] = params[i*3+0];
			genericLeds[i][1] = params[i*3+1];
			genericLeds[i][2] = params[i*3+2];
		}
	}
}
void connectionTimeout(void * p_context){
	sd_ble_gap_disconnect(m_conn_handle, BLE_HCI_CONN_INTERVAL_UNACCEPTABLE);
}

void idle_state_handle(void){
    if (NRF_LOG_PROCESS() == false){
        nrf_pwr_mgmt_run();
    }
}

void conn_params_error_handler(uint32_t nrf_error){
    APP_ERROR_HANDLER(nrf_error);
}
void assert_nrf_callback(uint16_t line_num, const uint8_t * p_file_name){
    app_error_handler(DEAD_BEEF, line_num, p_file_name);
}
