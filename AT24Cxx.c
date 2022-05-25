#include "AT24Cxx.h" 

I2C_HandleTypeDef * eeprom_hi2c; 

static uint8_t eeprom_address = AT24_ADDRESS << 1; 
//static uint16_t page_address_mask = AT24_PAGESIZE - 1; 


void AT24_Init(I2C_HandleTypeDef * hi2c)
{
	eeprom_hi2c = 	hi2c; 
}	
void AT24_Write(uint16_t address, void * data, uint16_t len)
{
	uint8_t * pdata = (uint8_t *) data; 
	HAL_I2C_Mem_Write(eeprom_hi2c, eeprom_address, address, 2, pdata, len, 1000); 
	HAL_Delay(10); 
}
void AT24_Read(uint16_t address, void * data, uint16_t len)
{
	uint8_t * pdata = (uint8_t *)data; 
	HAL_I2C_Mem_Read(eeprom_hi2c, eeprom_address, address, 2, pdata, len, 1000); 
	HAL_Delay(5);
}
