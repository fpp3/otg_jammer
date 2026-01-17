#ifndef JAM_H
#define JAM_H

#include "Arduino.h"
#include "SPI.h"
#include "RF24.h"

typedef enum {
  JAM_TX_SIMULTANEOUS = 0, // All radios jam together the same channels
  JAM_TX_STANDALONE = 1  // Each radio jams separate channel, rotating if the channels to jam are more than the number of radios
} jam_tx_mode_e;

typedef struct {
  uint8_t ce_pin;
  uint8_t csn_pin;
  rf24_pa_dbm_e pa_level;
} radio_config_s;


bool load_radios(radio_config_s *pins_array, uint8_t count);
void set_jam_tx_mode(jam_tx_mode_e mode);
void jam_start();
void jam_stop();
void bluetooth_jam(uint8_t method);
void drone_jam(uint8_t method);
void ble_jam();
void wifi_jam(int8_t channel = -1);
void zigbee_jam();
void misc_jam(uint8_t channel1, uint8_t channel2);

#endif