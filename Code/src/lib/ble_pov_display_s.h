
#ifndef BLE_POV_DISPLAY_S_H__
#define BLE_POV_DISPLAY_S_H__

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"
#include "nrf_sdh_ble.h"
#include "app_timer.h"

#ifdef __cplusplus
extern "C" {
#endif

/**@brief   Macro for defining a ble_lbs instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */
#define BLE_POV_DISPLAY_S_DEF(_name)						\
	static ble_pov_display_s_t _name;      					\
	NRF_SDH_BLE_OBSERVER(_name ## _obs,                 	\
                     NRF_BLE_POV_DISPLAY_OBSERVER_PRIO,   	\
                     ble_pov_display_s_on_ble_evt, &_name)

//"4756-616e-7475-696c5f424c45" = "GVantuil_BLE"
#define POV_DISPLAY_S_UUID_PROJECT_ID            	0x01
#define POV_DISPLAY_S_UUID_BASE                 	{0x45, 0x4c, 0x42, 0x5f, 0x6c, 0x69, 0x75, 0x74, 0x6e, 0x61, 0x56, 0x47, 0, 0, POV_DISPLAY_S_UUID_PROJECT_ID, 0}
#define POV_DISPLAY_S_UUID_SERVICE            		0x0000
#define POV_DISPLAY_S_UUID_SET_PARAMS_CHAR          0x0001
#define POV_DISPLAY_S_UUID_GET_INFO_CHAR            0x0002
#define POV_DISPLAY_S_UUID_MODE_CHAR          		0x0003
#define POV_DISPLAY_S_UUID_SET_TEXT_CHAR      		0x0004
#define POV_DISPLAY_S_UUID_SET_LEDS_CHAR            0x0005


// Forward declaration of the ble_pov_display_s_t type.
typedef struct ble_pov_display_s_s ble_pov_display_s_t;

typedef void (*ble_pov_display_s_set_params_handler_t)     		(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, const uint8_t *params, uint8_t len);
typedef void (*ble_pov_display_s_mode_handler_t)         		(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, uint8_t mode);
typedef void (*ble_pov_display_s_set_text_handler_t)    		(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, const uint8_t *params, uint8_t len);
typedef void (*ble_pov_display_s_set_leds_handler_t)     		(uint16_t conn_handle, ble_pov_display_s_t * p_pov_display_s, const uint8_t *params, uint8_t len);

typedef struct{			/**< Event handler to be called when which Characteristic is written. */
    ble_pov_display_s_set_params_handler_t 	set_params_handler;
    ble_pov_display_s_mode_handler_t      	mode_handler;
    ble_pov_display_s_set_text_handler_t 	set_text_handler;
    ble_pov_display_s_set_leds_handler_t 	set_leds_handler;
} ble_pov_display_s_init_t;

struct ble_pov_display_s_s{
    uint16_t                    service_handle;
    ble_gatts_char_handles_t    set_params_handles;
    ble_gatts_char_handles_t    get_info_handles;  
    ble_gatts_char_handles_t    mode_handles; 
    ble_gatts_char_handles_t    set_text_handles;
    ble_gatts_char_handles_t    set_leds_handles;
	
    uint8_t	uuid_type;                              /**< UUID type for the Service. */
    ble_pov_display_s_set_params_handler_t	        set_params_handler;
    ble_pov_display_s_mode_handler_t				mode_handler;
    ble_pov_display_s_set_text_handler_t			set_text_handler;
    ble_pov_display_s_set_leds_handler_t	        set_leds_handler;
};

uint32_t ble_pov_display_s_init(ble_pov_display_s_t * p_pov_display_s, const ble_pov_display_s_init_t * p_pov_display_s_init);

void ble_pov_display_s_on_ble_evt(ble_evt_t const * p_ble_evt, void * p_context);



#ifdef __cplusplus
}
#endif

#endif // BLE_LBS_H__

/** @} */
