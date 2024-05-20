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


void writeFont(char character, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B);
void writeWordFont(char* word, uint8_t wordLen, uint8_t font, uint32_t pixelLengthUs, uint8_t offset, bool flip, bool ccw, uint8_t R, uint8_t G, uint8_t B);

void leds_init(void);
void leds_test(void);
void convertTrueRGB(uint8_t RGB[3][LED_COUNT]);
void coloredLedsTest(uint8_t RGB[3][LED_COUNT]);
#endif
