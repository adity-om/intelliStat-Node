/*
 * @Author: aditya om
 * @Date: 2022-02-04 14:47:33
 * @Last Modified by:   aditya om
 * @Last Modified time: 2022-02-04 14:47:33
 */

#ifndef _CONFIG_H
	#define _CONFIG_H

	#include <Arduino.h>

	//------------------------------------------------------------------------------
	// Load and save the WiFi relay config
	//
	// This initial Implementation saves the config to the EEPROM area of Flash
	//------------------------------------------------------------------------------

	extern void config_load_settings();
	extern void config_save_relay_states();
	extern void config_load_relay_states();

#endif // _CONFIG_H
