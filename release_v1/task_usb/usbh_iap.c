/**
  ******************************************************************************
  * @file    usbh_iap.c
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

#include "usbh_iap.h"
#include "usbh_if.h"

#include "bsp_io.h"
#include "flash_if.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "ff_gen_drv.h"
#include "usbh_diskio.h"


/*******************************************************************************
******************************** Private typedef *******************************
*******************************************************************************/

typedef  void (*pFunction)(void);

/*******************************************************************************
******************************** Private define ********************************
*******************************************************************************/


#define IAP_Delay(x)		osDelay(x)

//APP启动地址，需要和应用程序中的设置相同
#define USBH_IAP_APP1_ADDR	(uint32_t)0x08040000
#define USBH_IAP_APP1_NAME 	"fw_tm01.bin"


/*******************************************************************************
********************************* Private macro ********************************
*******************************************************************************/


/*******************************************************************************
******************************* Private variables ******************************
*******************************************************************************/

extern char 			USBHPath[4];          /* USB Host logical drive path */
												//USBH_Path >> USBHPath 
usbh_iap_state_t		s_iap_fsm;
FIL 					s_IAP_File; 
FATFS 					s_IAP_FatFs;

bsp_u32					s_iap_buffer1[256];



/*******************************************************************************
************************** Private function prototypes *************************
*******************************************************************************/


/*******************************************************************************
******************************* Private functions ******************************
*******************************************************************************/



/*******************************************************************************
  * @brief  iap_app1_file_match
  *
  * @param  none
  *
  * @retval 0 error
  * 		1 ok
  *****************************************************************************/
static bsp_u16 iap_app1_file_match(void)
{
	FRESULT res1,res2;
	char str[48];
	
	memcpy(str, USBHPath, 4);
	strcat(str, USBH_IAP_APP1_NAME);
	
	res1 = f_mount(&s_IAP_FatFs, (TCHAR const*)USBHPath, 0);

	if( res1 == FR_OK){
		res2 = f_open(&s_IAP_File, str, FA_OPEN_EXISTING | FA_READ);
		if( res2 == FR_OK){

			usbh_iap_usr_log("App1 file Size = %ld.", f_size(&s_IAP_File));
			usbh_iap_usr_log("App1 file is programming.");

			return 1;
		}
	}
	
	usbh_iap_err_log("App1 file is not found.");
	return 0;
}


/*******************************************************************************
  * @brief  iap_app_file_rd
  *
  * @param  rd_addr8 相对于文件首地址(8-bit数据的地址)
  * @param  rd_size  读取数量(32-bit)
  * @param  *buffer  读取缓冲区(32-bit)
  *
  * @retval 0 error
  * 		1 ok
  *****************************************************************************/
static bsp_u16 iap_app_file_rd(bsp_u32 rd_addr8, bsp_u32 rd_size, bsp_u32 *buffer)
{
	bsp_u32	sread;
	
	if(FR_OK != f_lseek(&s_IAP_File, rd_addr8)){
		return 0;
	}
	if(FR_OK != f_read(&s_IAP_File, (void *)buffer, rd_size * 4, (void *)&sread)){
		return 0;
	}

    return 1;
}


/*******************************************************************************
  * @brief  iap_app1_file_wr
  *
  * @param  *buffer  读取缓冲区(32-bit)
  *
  * @retval 0 error
  * 		1 ok
  *****************************************************************************/
static bsp_u32 iap_app1_file_wr(bsp_u32 *buffer)
{
	bsp_u32 i;
	bsp_u32 file_size;
	bsp_u32 block_num;
	
	//调用 IAP_App_FileMatch 后，文件已经处于打开状态
	file_size = f_size(&s_IAP_File);
	//文件为空
	if(file_size == 0){
		return 0;
	}
	block_num = file_size / (128 * 4);
	if((file_size % (128 * 4)) > 0){
		block_num++;
	}
	
	flash_if_init();
	
	if(0 == flash_if_erase(USBH_IAP_APP1_ADDR, file_size)){
		usbh_iap_err_log("App1 erase error.");
		
		flash_if_end();
		f_close(&s_IAP_File);
		return 0;
	}
	
	for(i=0; i<block_num; i++){

		if(0 == iap_app_file_rd(i * 128 * 4, 128, buffer)){
			usbh_iap_usr_log("App1 read error : block [ %d ].", i);

			flash_if_end();
			f_close(&s_IAP_File);
			return 0;
		}
		if(0 != flash_if_wr(USBH_IAP_APP1_ADDR + i * 128 * 4, buffer ,128)){
			usbh_iap_usr_log("App1 Write error : block [ %d ].", i);

			flash_if_end();
			f_close(&s_IAP_File);
			return 0;
		}
	}
	
	usbh_iap_usr_log("App1 programming is complete.");

	flash_if_end();
	f_close(&s_IAP_File);
	
    return 1;
}


/*******************************************************************************
  * @brief  iap_app_run
  *
  * @param  none
  *
  * @retval 0 error
  * 		1 ok
  *****************************************************************************/
static bsp_u16 iap_app_run(bsp_u32 app_addr)
{
	bsp_u32 	AddressStart;
	bsp_u32 	AddressJump;
	pFunction 	Jump_To_Application;
	
	/* Jump to user application */
	AddressStart = *(__IO uint32_t*) app_addr;
	AddressJump  = *(__IO uint32_t*) (app_addr + 4);	  	
	Jump_To_Application = (pFunction) AddressJump;

	// Test if user code is programmed starting from address "app_addr"
	// stm32f429 ram1 and ram2
	if (((AddressStart & 0x2FFE0000 ) == 0x20000000)
	||  ((AddressStart & 0x1FFE0000 ) == 0x10000000))
    {
		usbh_iap_usr_log("IAP_AppRun:app_addr = %x.\r\n", app_addr);

		__disable_fault_irq();

		// Initialize user application's Stack Pointer
		__set_MSP(*(__IO uint32_t*) app_addr);
		Jump_To_Application();
		
	}else{
		usbh_iap_err_log("IAP_AppRun: No application.\r\n");
    }
	return 0;
}

/*******************************************************************************
  * @brief  usbh_iap_boot
  *
  * @param  state
  *
  * @retval 0 检测到U盘
  *         1 未检测到U盘，未检测到APP
  *         2 未检测到U盘，检测到APP  无法返回
  *****************************************************************************/
bsp_u16 usbh_iap_boot(void)
{
	bsp_u8 err;
	
	if(USBH_IF_CLASS_ACTIVE == usbh_if_state_rd()){
		s_iap_fsm = USBH_IAP_APP1_MATCH;
		return 0;
		
	}else{
		err = iap_app_run(USBH_IAP_APP1_ADDR);

		if(0 == err){
			return 1;
		}
	}
	return 2;
}

/*******************************************************************************
  * @brief  usbh_iap_polling
  *
  * @param  state
  *
  * @retval s_iap_fsm
  *****************************************************************************/
usbh_iap_state_t usbh_iap_polling(void)
{
	switch(s_iap_fsm){
		case USBH_IAP_APP1_MATCH:
			if(0 != iap_app1_file_match()){
				s_iap_fsm = USBH_IAP_APP1_PROGRAM;
			}else{
				s_iap_fsm = USBH_IAP_ERROR;
			}
			break;
			
		case USBH_IAP_APP1_PROGRAM:
			if(0 != iap_app1_file_wr(s_iap_buffer1)){
				s_iap_fsm = USBH_IAP_END;
			}else{
				s_iap_fsm = USBH_IAP_ERROR;
			}
			break;

		case USBH_IAP_END:
		case USBH_IAP_ERROR:
		default:
			break;
	}
	
	return s_iap_fsm;
}

/********************************* end of file ********************************/




