// Karl Palsson, 2010
// packet format for my sensors.

// header is just for simple sanity.
// note, no node id, we'll use the radio nodes for that.
#ifndef __KPACKET_H
#define __KPACKET_H
#include <stdint.h>

// max max, but you should only declare as many as you need.
#define MAX_SENSORS     4

// A single sensor reading.
typedef struct __attribute__((packed)) _ksensor {
    uint8_t     type;
    uint32_t    value;
} ksensor;

// a collection of sensor readings
typedef struct __attribute__((packed)) _kpacket {
	uint8_t 	header;
        uint8_t         version:4;
        uint8_t         nsensors:4;
        ksensor         ksensors[MAX_SENSORS];
} kpacket;

// a collection of sensor readings
typedef struct __attribute__((packed)) _kpacket2 {
        uint8_t 	header;
        uint8_t         versionCount;
        ksensor         ksensors[MAX_SENSORS];
} kpacket2;

// You need to use "packed" on 32bit processors if you want to maintain 
// compatibility with AVR code using the original (un-annotated) code.
// This is less efficient, but this is not an area where we care much.

#define KPP_VERSION_1 1  // xbee-api.c, reverse endian, whichever it is...
#define KPP_VERSION_2 2  // mrf big endian? (or is that little endian?)

#define VERSION_COUNT(x,y)  (((x) << 4) | ((y) & 0x0f))

#define LM35_VREF256        35
#define TMP36_VREF256       36
#define TMP36_VREF11        37
// HCH1000 with 555, reporting humidity as a frequency
#define FREQ_1SEC           'f'
// internal temperature sensor, for devices that measure against 1.1vref
#define TEMP_INT_VREF11     'i'
// internal temperature sensor, for devices that measure against 2.56vref
#define TEMP_INT_VREF256    'I'
// 10k NTC probe, with 10k resistor divider, measured against 3.3v VCC
#define NTC_10K_3V3         'a'
// flag for binary state sensors (off/on)
#define KPS_RELAY_STATE         'b'
#define KPS_COMMAND         'c'
#define KPS_COMMAND_ARG     'd'
#define KPS_SENSOR_TEST         'z'

// All possible commands
#define KPS_COMMAND_REPORTING_INTERVAL  1
#define KPS_COMMAND_THRESHOLD_TEMP      2
#define KPS_COMMAND_MIN_ON_TIME         3
#define KPS_COMMAND_MIN_OFF_TIME        4
#define KPS_COMMAND_SET_COLLECTOR       5



#endif
	
