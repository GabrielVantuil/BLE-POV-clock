#ifndef WRITE_TEXT_H__
#define WRITE_TEXT_H__
#include "characters.h"
#include "board_config.h"
#include <string.h>

#include "app_timer.h"
#include "nrf_drv_gpiote.h"
#include "nrf_delay.h"
#include "app_timer.h"


#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

void delayRgbUs(uint32_t us_time, uint8_t R, uint8_t G, uint8_t B);

void writeFont(char character, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B);
void writeWordFont(char* word, uint8_t wordLen, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B);

void leds_init(void);
void leds_test(void);
void simple_leds_test(void);
void convertTrueRGB(uint8_t RGB[3][LED_COUNT]);
void coloredLedsTest(uint8_t RGB[3][LED_COUNT]);
void printColoredLine(uint8_t line[LED_COUNT][3], bool inv);
bool from16toFullSize(uint8_t oldArray[16][3], uint8_t newArray[LED_COUNT][3], uint8_t offset, uint8_t bgColor[3]);
bool from32toFullSize(uint8_t oldArray[32][3], uint8_t newArray[LED_COUNT][3], uint8_t offset, uint8_t bgColor[3]);
bool double16array(uint8_t oldArray[16][3], uint8_t newArray[LED_COUNT][3], uint8_t offset, uint8_t bgColor[3]);
#endif
