/*
* File: config.cpp
* Author: Aditya Om
* Description: Defines the firmware config parameters
*/

#include "config.h"
#include "debug.h"
#include "relay.h"

#include "EEPROM.h"

#define BITMASK_RELAY_1 1
#define BITMASK_RELAY_2 2
#define BITMASK_RELAY_3 4 //binary representation

#define EEPROM_RELAY_STATES_SIZE    1 //1 byte

#define EEPROM_SIZE     512 //512 bytes

#define EEPROM_RELAY_STATES_START   0
#define EEPROM_RELAY_STATES_END (EEPROM_RELAY_STATES_START + EEPROM_RELAY_STATES_SIZE)

#define EEPROM_CONFIG_END EEPROM_RELAY_STATES_END

#if EEPROM_CONFIG_END > EEPROM_RELAY_STATES_SIZE
    #error EEPROM_SIZE too small
#endif

//load the cofig 
void config_load_settings(){

    EEPROM.begin(EEPROM_SIZE);

    if(relay_latch_enabled){
        config_load_relay_states();
    }

    EEPROM.end();

}

void config_save_relay_states(){

    //Save the config relay states
}

void config_load_relay_states(){

   //load the saved config relay states
}