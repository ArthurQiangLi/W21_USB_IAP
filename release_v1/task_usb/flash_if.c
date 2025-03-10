/**
  ******************************************************************************
  * @file    flash_if.c
  * @author  SeanLi
  * @version 
  * @date    25-July-2017
  * @brief   
  *
  *                      
  ******************************************************************************
  * @attention
  *				
  *
  ******************************************************************************
  */

/*******************************************************************************
************************************ Includes **********************************
*******************************************************************************/

#include "flash_if.h"


/*******************************************************************************
******************************** Private typedef *******************************
*******************************************************************************/


/*******************************************************************************
******************************** Private define ********************************
*******************************************************************************/

/*******************************************************************************
********************************* Private macro ********************************
*******************************************************************************/


/*******************************************************************************
******************************* Private variables ******************************
*******************************************************************************/


/*******************************************************************************
************************** Private function prototypes *************************
*******************************************************************************/


/*******************************************************************************
******************************* Private functions ******************************
*******************************************************************************/




/*******************************************************************************
  * @brief  Gets the sector of a given address
  *
  * @param  Address: Flash address
  *
  * @retval The sector of a given address
  *****************************************************************************/
static bsp_u32 GetSector(bsp_u32 Address)
{
	bsp_u32 sector = 0;

#if defined STM32F407xx

	if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0)){
		sector = FLASH_SECTOR_0;
		
	}else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1)){
		sector = FLASH_SECTOR_1;
		
	}else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2)){
		sector = FLASH_SECTOR_2;
		
	}else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3)){
		sector = FLASH_SECTOR_3;
		
	}else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4)){
		sector = FLASH_SECTOR_4;
		
	}else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5)){
		sector = FLASH_SECTOR_5;
		
	}else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6)){
		sector = FLASH_SECTOR_6;
		
	}else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7)){
		sector = FLASH_SECTOR_7;
		
	}else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8)){
		sector = FLASH_SECTOR_8;
		
	}else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9)){
		sector = FLASH_SECTOR_9;
		
	}else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10)){
		sector = FLASH_SECTOR_10;
		
	}else{
		sector = FLASH_SECTOR_11;  
	}

#elif defined STM32F429xx

	if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0)){
		sector = FLASH_SECTOR_0;
		
	}else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1)){
		sector = FLASH_SECTOR_1;
		
	}else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2)){
		sector = FLASH_SECTOR_2;
		
	}else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3)){
		sector = FLASH_SECTOR_3;
		
	}else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4)){
		sector = FLASH_SECTOR_4;
		
	}else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5)){
		sector = FLASH_SECTOR_5;
		
	}else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6)){
		sector = FLASH_SECTOR_6;
		
	}else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7)){
		sector = FLASH_SECTOR_7;
		
	}else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8)){
		sector = FLASH_SECTOR_8;
		
	}else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9)){
		sector = FLASH_SECTOR_9;
		
	}else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10)){
		sector = FLASH_SECTOR_10;
		
	}else if((Address < ADDR_FLASH_SECTOR_12) && (Address >= ADDR_FLASH_SECTOR_11)){
		sector = FLASH_SECTOR_11;
		
	}else if((Address < ADDR_FLASH_SECTOR_13) && (Address >= ADDR_FLASH_SECTOR_12)){
		sector = FLASH_SECTOR_12;
		
	}else if((Address < ADDR_FLASH_SECTOR_14) && (Address >= ADDR_FLASH_SECTOR_13)){
		sector = FLASH_SECTOR_13;
		
	}else if((Address < ADDR_FLASH_SECTOR_15) && (Address >= ADDR_FLASH_SECTOR_14)){
		sector = FLASH_SECTOR_14;
		
	}else if((Address < ADDR_FLASH_SECTOR_16) && (Address >= ADDR_FLASH_SECTOR_15)){
		sector = FLASH_SECTOR_15;
		
	}else if((Address < ADDR_FLASH_SECTOR_17) && (Address >= ADDR_FLASH_SECTOR_16)){
		sector = FLASH_SECTOR_16;
		
	}else if((Address < ADDR_FLASH_SECTOR_18) && (Address >= ADDR_FLASH_SECTOR_17)){
		sector = FLASH_SECTOR_17;
		
	}else if((Address < ADDR_FLASH_SECTOR_19) && (Address >= ADDR_FLASH_SECTOR_18)){
		sector = FLASH_SECTOR_18;
		
	}else if((Address < ADDR_FLASH_SECTOR_20) && (Address >= ADDR_FLASH_SECTOR_19)){
		sector = FLASH_SECTOR_19;
		
	}else if((Address < ADDR_FLASH_SECTOR_21) && (Address >= ADDR_FLASH_SECTOR_20)){
		sector = FLASH_SECTOR_20;
		
	}else if((Address < ADDR_FLASH_SECTOR_22) && (Address >= ADDR_FLASH_SECTOR_21)){
		sector = FLASH_SECTOR_21;
		
	}else if((Address < ADDR_FLASH_SECTOR_23) && (Address >= ADDR_FLASH_SECTOR_22)){
		sector = FLASH_SECTOR_22;
		
	/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_23))*/
	}else{
		sector = FLASH_SECTOR_23;  
	}

#else 

#error "STM32F407xx or STM32F429xx has been not defined !"
	
#endif
	
	return sector;
}

/*******************************************************************************
  * @brief  Unlocks Flash for write access
  *
  * @param  None
  *
  * @retval None
  *****************************************************************************/
void flash_if_init(void)
{ 
	HAL_FLASH_Unlock(); 

	// Clear pending flags (if any) 
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
						FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
}


/*******************************************************************************
  * @brief  Lock Flash
  *
  * @param  None
  *
  * @retval None
  *****************************************************************************/
void flash_if_end(void)
{ 
	HAL_FLASH_Lock(); 
}


/*******************************************************************************
  * @brief  扇区擦除
  *
  * @param  add_start
  * @param  size
  *
  * @retval 1 表示成功
  *****************************************************************************/
bsp_u32 flash_if_erase(bsp_u32 add_start, bsp_u32 size)
{
	bsp_u32 FirstSector = 0;
	bsp_u32 NbOfSectors = 0;
	bsp_u32 SectorError = 0;
	FLASH_EraseInitTypeDef EraseInitStruct;
	
	FirstSector = GetSector(add_start);
	NbOfSectors = GetSector(add_start + size) - FirstSector + 1;
	
	EraseInitStruct.TypeErase = 	FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange = 	FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector = 		FirstSector;
	EraseInitStruct.NbSectors = 	NbOfSectors;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK){
		return 0;	// Error occurred while page erase
	}else{
		return 1;
	}
}


/*******************************************************************************
  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
  *         After writing data buffer, the flash content is checked.
  *
  * @param  addr_flash: start address for writing data buffer (8-bit)
  * @param  data: pointer on data buffer
  * @param  size: length of data buffer (unit is 32-bit word)   
  * 
  * @retval 0: data successfully written to Flash memory
  *         1: Error occurred while writing data in Flash memory
  *         2: Written data in flash memory is different from expected one
  *****************************************************************************/
bsp_u32 flash_if_wr(bsp_u32 addr_flash, bsp_u32* data ,bsp_u32 size)
{
	bsp_u32 i = 0;

	for (i = 0; (i < size) && (addr_flash <= (USER_FLASH_END_ADDRESS-4)); i++)
	{
		__disable_irq();
		
		/* Device voltage range supposed to be [2.7V to 3.6V], the operation will
		be done by word */ 
		if (HAL_FLASH_Program(TYPEPROGRAM_WORD, addr_flash, *(uint32_t*)(data+i)) == HAL_OK)      
		{
			__enable_irq();
			/* Check the written value */
			if (*(uint32_t*)addr_flash != *(uint32_t*)(data+i))
			{
				/* Flash content doesn't match SRAM content */
				return(FLASH_IF_WRITINGCTRL_ERROR);
			}
			/* Increment FLASH destination address */
			addr_flash += 4;
			
		}else{
			__enable_irq();
			/* Error occurred while writing data in Flash memory */
			return (FLASH_IF_WRITING_ERROR);
		}
	}

	return (FLASH_IF_OK);
}


/********************************* end of file ********************************/




