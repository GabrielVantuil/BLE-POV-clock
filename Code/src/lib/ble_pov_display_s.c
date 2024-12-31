#include "sdk_common.h"
#if NRF_MODULE_ENABLED(BLE_POV_DISPLAY_S)
#include "ble_pov_display_s.h"
#include "ble_srv_common.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "handles.h"

void on_write(ble_pov_display_s_t * p_pov_display_s, ble_evt_t const * p_ble_evt){
    ble_gatts_evt_write_t const * p_evt_write = &p_ble_evt->evt.gatts_evt.params.write;

	if((p_evt_write->handle == p_pov_display_s->mode_handles.value_handle)           	&& (p_pov_display_s->mode_handler != NULL)){
		NRF_LOG_INFO("mode_handler");
        p_pov_display_s->mode_handler(p_ble_evt->evt.gap_evt.conn_handle, p_pov_display_s, p_evt_write->data[0]);
    }
    else if ((p_evt_write->handle == p_pov_display_s->set_text_handles.value_handle)	&& (p_pov_display_s->set_text_handler != NULL)){
		NRF_LOG_INFO("set_text_handler");
        p_pov_display_s->set_text_handler(p_ble_evt->evt.gap_evt.conn_handle, p_pov_display_s, p_evt_write->data, p_evt_write->len);
    }
    else if ((p_evt_write->handle == p_pov_display_s->set_leds_handles.value_handle)	&& (p_pov_display_s->set_leds_handler != NULL)){
		NRF_LOG_INFO("set_leds_handler");
        p_pov_display_s->set_leds_handler(p_ble_evt->evt.gap_evt.conn_handle, p_pov_display_s, p_evt_write->data, p_evt_write->len);
    }
	else {
		NRF_LOG_INFO("write handle not found");
		NRF_LOG_INFO("len:%d | data[0]:%d | %d", p_evt_write->len, p_evt_write->data[0], p_evt_write->handle);
	}
    NRF_LOG_FLUSH();
}

void ble_pov_display_s_on_ble_evt(ble_evt_t const * p_ble_evt, void * p_context){
    ble_pov_display_s_t * p_pov_display_s = (ble_pov_display_s_t *)p_context;
    switch (p_ble_evt->header.evt_id){
        case BLE_GATTS_EVT_WRITE:
            on_write(p_pov_display_s, p_ble_evt);
            break;
        default:	//No implementation needed.
//            NRF_LOG_INFO("Event unhadled: %d", p_ble_evt->header.evt_id);
            break;
    }
}
uint32_t configAndAddChar(ble_pov_display_s_t * p_pov_display_s, uint16_t uuid, uint16_t len, bool isWrite, ble_gatts_char_handles_t * p_char_handle){
    ble_add_char_params_t add_char_params;
    memset(&add_char_params, 0, sizeof(add_char_params));
    add_char_params.uuid              = uuid;
    add_char_params.uuid_type         = p_pov_display_s->uuid_type;
    add_char_params.init_len          = 0;
    add_char_params.max_len           = len;
    add_char_params.char_props.read   = !isWrite;
    add_char_params.char_props.write  = isWrite;
	
    add_char_params.read_access       = SEC_OPEN;
    add_char_params.write_access 	  = SEC_OPEN;
//	if(!isWrite)    add_char_params->p_init_value	  = packet;
    return characteristic_add(p_pov_display_s->service_handle, &add_char_params, p_char_handle);
}

uint32_t ble_pov_display_s_init(ble_pov_display_s_t * p_pov_display_s, const ble_pov_display_s_init_t * p_pov_display_s_init){
    uint32_t              err_code;
    ble_uuid_t            ble_uuid;

    // Initialize service structure.
    p_pov_display_s->mode_handler           = p_pov_display_s_init->mode_handler;
	p_pov_display_s->set_text_handler       = p_pov_display_s_init->set_text_handler;
	p_pov_display_s->set_leds_handler       = p_pov_display_s_init->set_leds_handler;

    // Add service.
    ble_uuid128_t base_uuid = {POV_DISPLAY_S_UUID_BASE};
    err_code = sd_ble_uuid_vs_add(&base_uuid, &p_pov_display_s->uuid_type);
    VERIFY_SUCCESS(err_code);

    ble_uuid.type = p_pov_display_s->uuid_type;
    ble_uuid.uuid = POV_DISPLAY_S_UUID_SERVICE;

    err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY, &ble_uuid, &p_pov_display_s->service_handle);
    VERIFY_SUCCESS(err_code); 
		
    err_code = configAndAddChar(p_pov_display_s, POV_DISPLAY_S_UUID_MODE_CHAR           , 1, 1, &p_pov_display_s->mode_handles);
    if (err_code != NRF_SUCCESS)	return err_code;

    err_code = configAndAddChar(p_pov_display_s, POV_DISPLAY_S_UUID_SET_TEXT_CHAR       , 100, 1, &p_pov_display_s->set_text_handles);
    if (err_code != NRF_SUCCESS)	return err_code;

    err_code = configAndAddChar(p_pov_display_s, POV_DISPLAY_S_UUID_SET_LEDS_CHAR       , 3*LED_COUNT, 1, &p_pov_display_s->set_leds_handles);
    if (err_code != NRF_SUCCESS)	return err_code;

    err_code = configAndAddChar(p_pov_display_s, POV_DISPLAY_S_UUID_GET_LED_AMOUNT_CHAR , 1, 0, &p_pov_display_s->get_led_amount_handles);
    if (err_code != NRF_SUCCESS)	return err_code;
	
    return err_code;
}
#endif // NRF_MODULE_ENABLED(BLE_POV_DISPLAY_S)
