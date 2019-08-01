#pragma once
#include "PinNames.h"
#include <stdint.h>
#include <macros.h>

#ifndef __PINS_ARDUINO__
#define __PINS_ARDUINO__

// // Frequency of the board main oscillator
// #define VARIANT_MAINOSC (32768ul)

// // Master clock frequency
// #define VARIANT_MCK     (64000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (21u)
#define NUM_ANALOG_INPUTS    (7u)
#define NUM_ANALOG_OUTPUTS   (0u)

// LEDs
// ----
#define PIN_LED     LED1
#define LED_BUILTIN PIN_LED

// Analog pins
// -----------
#define PIN_A0 A0
#define PIN_A1 A1
#define PIN_A2 A2
#define PIN_A3 A3
#define PIN_A4 A4
#define PIN_A5 A5
#define ADC_RESOLUTION 12

/*
 * Serial interfaces
 */
// Serial (EDBG)
#define PIN_SERIAL_RX SERIAL_RX
#define PIN_SERIAL_TX SERIAL_TX

// SPI
#define PIN_SPI_MISO  SPI_MISO
#define PIN_SPI_MOSI  SPI_MOSI
#define PIN_SPI_SCK   SPI_SCK
#define PIN_SPI_SS    SPI_CS

static const uint8_t SS   = PIN_SPI_SS;   // SPI Slave SS not used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

// Wire
#define PIN_WIRE_SDA        I2C_SDA
#define PIN_WIRE_SCL        I2C_SCL

// #define PIN_WIRE_SDA1       (30u)
// #define PIN_WIRE_SCL1       (31u)

#define PIN_ENABLE_SENSORS_3V3     NC
#define PIN_ENABLE_I2C_PULLUP      NC

#define PIN_INT_APDS (26u)

// PDM Interfaces
// ---------------
// #define PIN_PDM_PWR	 (27)
// #define PIN_PDM_CLK	 (28)
// #define PIN_PDM_DIN	 (29)

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1


// Mbed specific defines
#define SERIAL_HOWMANY		1
#define SERIAL1_TX			PIN_SERIAL_TX
#define SERIAL1_RX			PIN_SERIAL_RX

#define BOARD_NAME			"GENERIC-MBED-OS"

#define DFU_MAGIC_SERIAL_ONLY_RESET   0xb0

#define digitalPinToPort(P)		(digitalPinToPinName(P)/32)

uint8_t getUniqueSerialNumber(uint8_t* name);
void _ontouch1200bps_();

#endif //__PINS_ARDUINO__
