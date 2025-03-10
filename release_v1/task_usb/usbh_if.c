/**
  ******************************************************************************
  * @file    usbh_if.c
  * @author  SeanLi
  * @version 
  * @date    25-July-2017
  * @brief   
  *
  *                      
  ******************************************************************************
  * @attention
  *				usb_host.c
  *
  ******************************************************************************
  */

/*******************************************************************************
************************************ Includes **********************************
*******************************************************************************/

#include "usbh_if.h"


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

usbh_if_state_t	s_usbh_if_state;

/*******************************************************************************
************************** Private function prototypes *************************
*******************************************************************************/


/*******************************************************************************
******************************* Private functions ******************************
*******************************************************************************/


/*******************************************************************************
  * @brief  USBH 状态设置回调函数
  *
  * @param  state
  *
  * @retval none
  *****************************************************************************/
void usbh_if_state_wr_cb(usbh_if_state_t state)
{
	s_usbh_if_state = state;
}


/*******************************************************************************
  * @brief  USBH 状态获取
  *
  * @param  state
  *
  * @retval s_usbh_if_state
  *****************************************************************************/
usbh_if_state_t usbh_if_state_rd(void)
{
	return s_usbh_if_state;
}


/********************************* end of file ********************************/




