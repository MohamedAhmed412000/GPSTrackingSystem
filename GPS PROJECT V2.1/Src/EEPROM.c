/************************************************************************
* 
* Module      : EEPROM
*
* File Nmae   : EEPROM.h
*
* Describtion : Header file for "EEPROM Module" containing the function prototypes for EEPROM driver
*
* Author      : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V01
*
* Date        : 6 June 2021
*
***************************************************************************/


#include "BIT_MATH.h"
#include "EEPROM.h"



void EEPROM_reset(void)
{	
SET_BIT(SYSCTL_SREEPROM_R,0);
while(BIT_IS_SET(EEPROM_EEDONE_R,0));
}


void EEPROM_init(void)
{
SET_BIT(SYSCTL_RCGCEEPROM_R,0);
while(BIT_IS_SET(EEPROM_EEDONE_R,0));
}


void EEPROM_write(uint32_t data, uint32_t address_block, uint8_t address_offset)//, uint32_t address)
{
	EEPROM_EEBLOCK_R = address_block;
	EEPROM_EEOFFSET_R = address_offset;
	
EEPROM_EERDWRINC_R = data;
}
uint32_t EEPROM_read(uint32_t address_block, uint8_t address_offset)//uint32_t address)
{
	EEPROM_EEBLOCK_R = address_block;
	EEPROM_EEOFFSET_R = address_offset;
return EEPROM_EERDWRINC_R;
}

