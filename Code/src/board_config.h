#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H
#include <stdint.h>

#define LED_ON	1
#define LED_OFF	0
#define MOTOR_ON	0
#define MOTOR_OFF	1

#define RED_FET1	27
#define GREEN_FET1  28
#define BLUE_FET1   29
#define RED_FET2	24
#define GREEN_FET2  25
#define BLUE_FET2   26
#define SENSOR_PIN  30
#define MOTOR_PIN   31

#define MASK_ALL_LEDS	0x00FFFFFF
#define MASK_ALL_RGB	0xCF000000
#define MASK_LEDS_AND_RGB	MASK_ALL_LEDS | MASK_ALL_RGB

#define RGB_ROWS	2
#define LED_SIGNALS_COUNT  	24
#define LED_COUNT (RGB_ROWS*LED_SIGNALS_COUNT)

#define LED_0	0
#define LED_1	1
#define LED_2	2
#define LED_3	3
#define LED_4	4
#define LED_5	5
#define LED_6	6
#define LED_7	7
#define LED_8	8
#define LED_9	9
#define LED_10	10
#define LED_11	11
#define LED_12	12
#define LED_13	13
#define LED_14	14
#define LED_15	15
#define LED_16	16
#define LED_17	17
#define LED_18	18
#define LED_19	19
#define LED_20	20
#define LED_21	21
#define LED_22	22
#define LED_23	23

const static uint8_t LED_PIN[LED_SIGNALS_COUNT] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10, LED_11, LED_12, LED_13, LED_14, LED_15, LED_16, LED_17, LED_18, LED_19, LED_20, LED_21, LED_22, LED_23};
const static uint8_t RGB_PINS[RGB_ROWS][3] = {{RED_FET1, GREEN_FET1, BLUE_FET1}, {RED_FET2, GREEN_FET2, BLUE_FET2}};	
	
#endif
