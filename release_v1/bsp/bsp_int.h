/**
  ******************************************************************************
  * @file    bsp_int.h
  * @author  SeanLi
  * @version 
  * @date    11-January-2018
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
#ifndef _BSP_INT_H
#define _BSP_INT_H

/*******************************************************************************
************************************ Includes **********************************
*******************************************************************************/

//#include "stm8s.h"
//#include <string.h>
//#include "main.h"
#include "stm32f4xx.h"

/*******************************************************************************
********************************* Exported macro *******************************
*******************************************************************************/

/*******************************************************************************
  * @brief  BSP_32BIT_EN: 关联int等数据类型的位宽
  *         1:32 bit MCU
  *         0:8/16 bit MCU
  *****************************************************************************/
#define BSP_32BIT_EN 	1

#if (BSP_32BIT_EN == 0)||(BSP_32BIT_EN == 1)
#else
#error "BSP_32BIT_EN has been not defined !"
#endif

//BSP_32BIT_EN template
#if (BSP_32BIT_EN == 1)

#elif (BSP_32BIT_EN == 0)
	
#endif

/*******************************************************************************
  * @brief  BSP_XXX
  *****************************************************************************/
#define BSP_U8_MAX     (255)
#define BSP_S8_MAX     (127)
#define BSP_S8_MIN     (-128)
#define BSP_U16_MAX    (65535u)
#define BSP_S16_MAX    (32767)
#define BSP_S16_MIN    (-32768)
#define BSP_U32_MAX    (4294967295uL)
#define BSP_S32_MAX    (2147483647)
#define BSP_S32_MIN    (-2147483648uL)

/*******************************************************************************
********************************* Exported types *******************************
*******************************************************************************/

/*******************************************************************************
  * @brief  数据类型
  *****************************************************************************/

//-----------------------------------------------
//- 8 bit data type 
typedef   signed char     bsp_s8;
typedef unsigned char     bsp_u8;
typedef volatile bsp_s8   bsp_vs8;
typedef volatile bsp_u8   bsp_vu8;
typedef const bsp_s8      bsp_cs8;
typedef const bsp_u8      bsp_cu8;
typedef const bsp_vs8     bsp_cvs8;
typedef const bsp_vu8     bsp_cvu8;

//-----------------------------------------------
//- 16 bit data type 
#if (BSP_32BIT_EN == 1)
typedef   signed short    bsp_s16;
typedef unsigned short    bsp_u16;
#elif (BSP_32BIT_EN == 0)
typedef   signed int      bsp_s16;
typedef unsigned int      bsp_u16;
#endif
typedef volatile bsp_s16  bsp_vs16;
typedef volatile bsp_u16  bsp_vu16;
typedef const bsp_s16     bsp_cs16;
typedef const bsp_u16     bsp_cu16;
typedef const bsp_vs16    bsp_cvs16;
typedef const bsp_vu16    bsp_cvu16;

//-----------------------------------------------
//- 32 bit data type 
#if (BSP_32BIT_EN == 1)
typedef   signed int      bsp_s32;
typedef unsigned int      bsp_u32;
#elif (BSP_32BIT_EN == 0)
typedef   signed long     bsp_s32;
typedef unsigned long     bsp_u32;
#endif
typedef volatile bsp_s32  bsp_vs32;
typedef volatile bsp_u32  bsp_vu32;
typedef const bsp_s32     bsp_cs32;
typedef const bsp_u32     bsp_cu32;
typedef const bsp_vs32    bsp_cvs32;
typedef const bsp_vu32    bsp_cvu32;

//-----------------------------------------------
//- 64 bit data type 
#if (BSP_32BIT_EN == 1)
typedef   signed long      bsp_s64;
typedef unsigned long      bsp_u64;
#elif (BSP_32BIT_EN == 0)
typedef   signed long long bsp_s64;
typedef unsigned long long bsp_u64;
#endif
typedef volatile bsp_s64  bsp_vs64;
typedef volatile bsp_u64  bsp_vu64;
typedef const bsp_s64     bsp_cs64;
typedef const bsp_u64     bsp_cu64;
typedef const bsp_vs64    bsp_cvs64;
typedef const bsp_vu64    bsp_cvu64;

//-----------------------------------------------
//- bit 
typedef enum 
{
	BSP_RESET 	= 0, 
	BSP_SET 	= 1 //!BSP_RESET
} bsp_bit;

typedef enum 
{ 
	BSP_FALSE 	= 0, 
	BSP_TRUE 	= 1 //!BSP_FALSE
} bsp_bool;

/*******************************************************************************
  * @brief  错误类型
  *****************************************************************************/
typedef enum
{
	//-----------------------------------------------
	//- OK 
	BSP_OK = 0,
	BSP_OK_1,
	BSP_OK_2,
	BSP_OK_3,
	BSP_OK_4,
	
	//-----------------------------------------------
	//- ERROR 
	BSP_ERR,
	BSP_ERR_1,
	BSP_ERR_2,
	BSP_ERR_3,
	BSP_ERR_4,
	
	BSP_ERR_INVALID_ARG,	//argument
	BSP_ERR_INVALID_STATE,
	BSP_ERR_INVALID_SIZE,
	BSP_ERR_NOT_FOUND,
	BSP_ERR_TIMEOUT,
	BSP_ERR_BUSY,
	
	BSP_ERR_OPEN,
	BSP_ERR_CLOSE,
	BSP_ERR_WR,
	BSP_ERR_RD,

}bsp_err_t;

/*******************************************************************************
******************************* Exported constants *****************************
*******************************************************************************/

/*******************************************************************************
******************************* Exported functions *****************************
*******************************************************************************/

#endif /* _BSP_INT_H */

/********************************* end of file ********************************/
