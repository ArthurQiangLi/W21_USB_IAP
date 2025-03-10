/**
  ******************************************************************************
  * @file    flash_if.h
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
********************* Define to prevent recursive inclusion ********************
*******************************************************************************/

#ifndef _FLASH_IF_H
#define _FLASH_IF_H

/*******************************************************************************
************************************ Includes **********************************
*******************************************************************************/

#include "bsp_int.h"

/*******************************************************************************
********************************* Exported macro *******************************
*******************************************************************************/

/* Error code */
enum 
{
  FLASH_IF_OK = 0,
  FLASH_IF_ERASEKO,
  FLASH_IF_WRITINGCTRL_ERROR,
  FLASH_IF_WRITING_ERROR
};
  
enum{
  FLASH_IF_PROTECTION_NONE         = 0,
  FLASH_IF_PROTECTION_PCROPENABLED = 0x1,
  FLASH_IF_PROTECTION_WRPENABLED   = 0x2,
  FLASH_IF_PROTECTION_RDPENABLED   = 0x4,
};


/* End of the Flash address */
#define USER_FLASH_END_ADDRESS        0x081FFFFF


/* Base address of the Flash sectors */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbyte */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbyte */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbyte */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbyte */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbyte */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbyte */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbyte */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbyte */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbyte */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbyte */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbyte */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbyte */
#define ADDR_FLASH_SECTOR_12    ((uint32_t)0x08100000) /* Base @ of Sector 12, 16 Kbyte */                                            
#define ADDR_FLASH_SECTOR_13    ((uint32_t)0x08104000) /* Base @ of Sector 13, 16 Kbyte */
#define ADDR_FLASH_SECTOR_14    ((uint32_t)0x08108000) /* Base @ of Sector 14, 16 Kbyte */
#define ADDR_FLASH_SECTOR_15    ((uint32_t)0x0810C000) /* Base @ of Sector 15, 16 Kbyte */
#define ADDR_FLASH_SECTOR_16    ((uint32_t)0x08110000) /* Base @ of Sector 16, 64 Kbyte */
#define ADDR_FLASH_SECTOR_17    ((uint32_t)0x08120000) /* Base @ of Sector 17, 128 Kbyte */
#define ADDR_FLASH_SECTOR_18    ((uint32_t)0x08140000) /* Base @ of Sector 18, 128 Kbyte */
#define ADDR_FLASH_SECTOR_19    ((uint32_t)0x08160000) /* Base @ of Sector 19, 128 Kbyte */
#define ADDR_FLASH_SECTOR_20    ((uint32_t)0x08180000) /* Base @ of Sector 20, 128 Kbyte */
#define ADDR_FLASH_SECTOR_21    ((uint32_t)0x081A0000) /* Base @ of Sector 21, 128 Kbyte */
#define ADDR_FLASH_SECTOR_22    ((uint32_t)0x081C0000) /* Base @ of Sector 22, 128 Kbyte */
#define ADDR_FLASH_SECTOR_23    ((uint32_t)0x081E0000) /* Base @ of Sector 23, 128 Kbyte */

/*******************************************************************************
********************************* Exported types *******************************
*******************************************************************************/



/*******************************************************************************
******************************* Exported constants *****************************
*******************************************************************************/


/*******************************************************************************
******************************* Exported functions *****************************
*******************************************************************************/

void 	flash_if_init(void);
void 	flash_if_end(void);
bsp_u32 flash_if_erase(bsp_u32 add_start, bsp_u32 size);
bsp_u32 flash_if_wr(bsp_u32 addr_flash, bsp_u32* data, bsp_u32 size);


#endif /* _FLASH_IF_H */

/********************************* end of file ********************************/


