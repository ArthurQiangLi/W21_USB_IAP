/**
  ******************************************************************************
  * @file    msg_start.h
  * @author  SeanLi
  * @version 
  * @date    29-December-2017
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
#ifndef _MSG_START_H
#define _MSG_START_H

/*******************************************************************************
************************************ Includes **********************************
*******************************************************************************/


/*******************************************************************************
********************************* Exported macro *******************************
*******************************************************************************/


/*******************************************************************************
********************************* Exported types *******************************
*******************************************************************************/

/*******************************************************************************
  * @brief  msg_start_led_t
  *         INIT		启动和烧录  红灯快闪 绿灯灭
  *         FINISH		烧录完成    红灯慢闪 绿灯灭
  *         ERROR		出错        红灯慢闪 绿灯亮
  *****************************************************************************/
  
typedef enum {
	MSG_START_LED_INIT			= 0X00,
    MSG_START_LED_FINISH,
	MSG_START_LED_ERROR
	
}msg_start_led_t;


/*******************************************************************************
******************************* Exported constants *****************************
*******************************************************************************/


/*******************************************************************************
******************************* Exported functions *****************************
*******************************************************************************/




#endif /* _MSG_START_H */

/********************************* end of file ********************************/
