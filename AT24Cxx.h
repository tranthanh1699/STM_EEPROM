#ifndef _AT24XX_H_
#define _AT24XX_H_

#include "stm32f1xx_hal.h"

// Must be config before using code
#define AT24_ADDRESS 0x57
#define AT24_PAGESIZE 4096 

void AT24_Init(I2C_HandleTypeDef * hi2c); 
void AT24_Write(uint16_t address, void * data, uint16_t len); 
void AT24_Read(uint16_t address, void * data, uint16_t len); 

#endif
