#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H
#include <stdint.h>

#define LED_ON	1
#define LED_OFF	0

#define RED_FET	    25
#define GREEN_FET   26
#define BLUE_FET    27
#define LED_COUNT   18

#define LED_0	2
#define LED_1	3
#define LED_2	4
#define LED_3	5
#define LED_4	6
#define LED_5	7
#define LED_6	8
#define LED_7	9
#define LED_8	10
#define LED_9	11
#define LED_10	12
#define LED_11	13
#define LED_12	14
#define LED_13	15
#define LED_14	16
#define LED_15	17
#define LED_16	18
#define LED_17	19

const static uint8_t LED_PIN[LED_COUNT] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10, LED_11, LED_12, LED_13, LED_14, LED_15, LED_16, LED_17};
const static uint8_t RGB_PINS[] = {RED_FET, GREEN_FET, BLUE_FET};	
	
#endif
