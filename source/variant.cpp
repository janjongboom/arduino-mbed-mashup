#include "Arduino.h"
#include "PinNames.h"

PinDescription g_APinDescription[] = {
  // D0 - D7
  D0,  NULL, NULL,     // D0/TX
  D1, NULL, NULL,     // D1/RX
  D2, NULL, NULL,     // D2
  D3, NULL, NULL,     // D3
  D4, NULL, NULL,     // D4
  D5, NULL, NULL,     // D5
  D6, NULL, NULL,     // D6
  D7,  NULL, NULL,     // D7

  // D8 - D13
  D8, NULL, NULL,     // D8
  D9, NULL, NULL,     // D9
  D10,  NULL, NULL,     // D10
  D11,  NULL, NULL,     // D11/MOSI
  D12,  NULL, NULL,     // D12/MISO
  D13, NULL, NULL,     // D13/SCK/LED

  // A0 - A7
  A0,  NULL, NULL,     // A0
  A1,  NULL, NULL,     // A1
  A2, NULL, NULL,     // A2
  A3, NULL, NULL,     // A3
  A4, NULL, NULL,     // A4/SDA
  A5,  NULL, NULL,     // A5/SCL
  NC, NULL, NULL,     // A6
  NC,  NULL, NULL,     // A7

  // LEDs
  LED1, NULL, NULL,     // LED R
  LED2, NULL, NULL,     // LED G
  LED3,  NULL, NULL,     // LED B
  LED4,  NULL, NULL,     // LED PWR

  NC, NULL, NULL,     // INT APDS

  // PDM
  NC, NULL, NULL,     // PDM PWR
  NC, NULL, NULL,     // PDM CLK
  NC, NULL, NULL,     // PDM DIN

  // Internal I2C
  I2C_SDA, NULL, NULL,     // SDA2
  I2C_SCL, NULL, NULL,     // SCL2

  // Internal I2C
  NC,  NULL, NULL,     // I2C_PULL
  NC, NULL, NULL,     // VDD_ENV_ENABLE
};

extern "C" {
  unsigned int PINCOUNT_fn() {
    return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
  }
}

void initVariant() {
  // noop
}

uint8_t getUniqueSerialNumber(uint8_t* name) {
  // noop
  return 32;
}

void _ontouch1200bps_() {
  NVIC_SystemReset();
}
