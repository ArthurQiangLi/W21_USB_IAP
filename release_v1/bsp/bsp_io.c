/**
  ******************************************************************************
  * @file    bsp_io.c
  * @author  SeanLi
  * @version 
  * @date    11-January-2018
  * @brief   
  *
  *   
  ******************************************************************************
  * @note
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

#include "bsp_io.h"

/*******************************************************************************
******************************** Private typedef *******************************
*******************************************************************************/

/*******************************************************************************
******************************** Private define ********************************
*******************************************************************************/


/*******************************************************************************
  * @brief  input pins
  *         PIN_READ:       (Port->IDR & Pin)
  *         PIN_READ_HIGH: ((Port->IDR & Pin) == 0)
  *         PIN_READ_LOW:  ((Port->IDR & Pin) != 0)
  *****************************************************************************/

//-----------------------------------------------
//-- IN_KEY
#define IN_KEY_RD	( GPI_KEY_GPIO_Port->IDR & GPI_KEY_Pin)
#define IN_KEY_RDL	((GPI_KEY_GPIO_Port->IDR & GPI_KEY_Pin) == 0)
#define IN_KEY_RDH	((GPI_KEY_GPIO_Port->IDR & GPI_KEY_Pin) != 0)



/*******************************************************************************
  * @brief  output pins
  *         PIN_SET:    (Port->BSRR = Pin)
  *         PIN_RESET:  (Port->BSRR = (Pin << 16U))
  *         PIN_TOGGLE: (Port->ODR ^= Pin)
  *****************************************************************************/

//-----------------------------------------------
//-- OUT_PWR_ALL
#define OUT_PWR_ALL_H		(GPO_PWR_ALL_GPIO_Port->BSRR =  GPO_PWR_ALL_Pin)
#define OUT_PWR_ALL_L		(GPO_PWR_ALL_GPIO_Port->BSRR = (GPO_PWR_ALL_Pin << 16U))
#define OUT_PWR_ALL_TOG		(GPO_PWR_ALL_GPIO_Port->ODR ^=  GPO_PWR_ALL_Pin)



/*******************************************************************************
  * @brief  led pins  Active-Low 
  *         PIN_SET:    (Port->BSRR = Pin)
  *         PIN_RESET:  (Port->BSRR = (Pin << 16U))
  *         PIN_TOGGLE: (Port->ODR ^= Pin)
  *****************************************************************************/

//-----------------------------------------------
//-- LED_RED
#define LED_RED_ON		(GPO_LED_RED_GPIO_Port->BSRR =  GPO_LED_RED_Pin)
#define LED_RED_OFF		(GPO_LED_RED_GPIO_Port->BSRR = (GPO_LED_RED_Pin << 16U))
#define LED_RED_TOG		(GPO_LED_RED_GPIO_Port->ODR ^=  GPO_LED_RED_Pin)
//-----------------------------------------------
//-- LED_GREEN
#define LED_GREEN_ON	(GPO_LED_GREEN_GPIO_Port->BSRR =  GPO_LED_GREEN_Pin)
#define LED_GREEN_OFF	(GPO_LED_GREEN_GPIO_Port->BSRR = (GPO_LED_GREEN_Pin << 16U))
#define LED_GREEN_TOG	(GPO_LED_GREEN_GPIO_Port->ODR ^=  GPO_LED_GREEN_Pin)



/*******************************************************************************
********************************* Private macro ********************************
*******************************************************************************/

/*******************************************************************************
******************************* Private variables ******************************
*******************************************************************************/

//extern ADC_HandleTypeDef hadc1;
//extern DAC_HandleTypeDef hdac;


/*******************************************************************************
************************** Private function prototypes *************************
*******************************************************************************/

/*******************************************************************************
******************************* Private functions ******************************
*******************************************************************************/



/*******************************************************************************
  * @brief  input
  *****************************************************************************/

/*******************************************************************************
  * @brief  读取逻辑输入值
  *
  * @param	num BSP_IN_x
  * 
  * @retval BSP_RESET
  * @retval BSP_SET
  *****************************************************************************/
bsp_bit bsp_io_in_level_rd(bsp_io_in_t num)
{
	bsp_bit level;
	
	switch(num){
	case BSP_IN_KEY:
		level = (bsp_bit)IN_KEY_RD;
		break;
		
	default:
		level = BSP_RESET;
		break;
	}

	return level;
}


/*******************************************************************************
  * @brief  output
  *****************************************************************************/

/*******************************************************************************
  * @brief  bsp_io_out_wr
  *
  * @param	num BSP_OUT_x
  * @param	level 
  * 
  * @retval none
  *****************************************************************************/
void bsp_io_out_wr(bsp_io_out_t num, bsp_bit level)
{
	switch(num){
	case BSP_OUT_PWR_ALL:
		if(level == BSP_RESET) OUT_PWR_ALL_L;
		else                   OUT_PWR_ALL_H;
		break;
		
	default:
		break;
	}
}


/*******************************************************************************
  * @brief  bsp_io_out_led_wr
  *
  * @param	led
  * @param	status
  * 
  * @retval none
  *****************************************************************************/
void bsp_io_led_wr(bsp_io_led_t led, bsp_io_led_status_t status)
{
	switch(led){
	case BSP_LED_RED:
		if(status == BSP_LED_ON)		{LED_RED_ON;}
		else if(status == BSP_LED_TOG)	{LED_RED_TOG;}
		else							{LED_RED_OFF;}
		break;

	case BSP_LED_GREEN:
		if(status == BSP_LED_ON)		{LED_GREEN_ON;}
		else if(status == BSP_LED_TOG)	{LED_GREEN_TOG;}
		else							{LED_GREEN_OFF;}
		break;
		
	default:
		break;
	}
}


/*******************************************************************************
  * @brief  adc
  *****************************************************************************/
  
/*******************************************************************************
  * @brief  读取片内ADC值
  *
  * @param  none
  *
  * @retval value
  *****************************************************************************/
bsp_u16 bsp_io_adc_rd(void)
{
	bsp_u16 				value = 0;
	/*
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 50);	
	value = HAL_ADC_GetValue(&hadc1);
	*/
	return value;
}

/*******************************************************************************
  * @brief  配置ADC通道
  *
  * @param  ch
  *
  * @retval none
  *****************************************************************************/
void bsp_io_adc_cfg(bsp_io_adc_ch_t ch)
{
	/*
	ADC_ChannelConfTypeDef 	sConfig;

	switch(ch){
	case BSP_ADC_CH1:
		sConfig.Channel = ADC_CHANNEL_0;
		break;
		
	case BSP_ADC_CH2:
		sConfig.Channel = ADC_CHANNEL_1;
		break;
	
	default:
		sConfig.Channel = ADC_CHANNEL_0;
		break;
	}
	
	sConfig.Rank         = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_84CYCLES;
	sConfig.Offset       = 0;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	*/
}

/*******************************************************************************
  * @brief  读取片内ADC值
  *
  * @param  *adc
  *
  * @retval none
  *****************************************************************************/
#define ADC_BUFFER_SIZE 8

void bsp_io_adc_poll(bsp_io_adc_t *adc)
{
	bsp_u16 i;
	bsp_u32 tmp_u32;
	
	//切换通道后延时
	adc->channel ++;
	if(adc->channel >= BSP_ADC_NUM){
		adc->channel = BSP_ADC_CH1;
	}
	bsp_io_adc_cfg(adc->channel);
	if(NULL != adc->op_delay){
		adc->op_delay(2);
	}
	
	//多次读取ADC后计算平均值
	tmp_u32 = 0;
	for(i=0; i<ADC_BUFFER_SIZE; i++){
		adc->buffer[i] = bsp_io_adc_rd();
		tmp_u32 += adc->buffer[i];
	}
	tmp_u32 /= ADC_BUFFER_SIZE;
	adc->value_adc[adc->channel] = tmp_u32;
	
	//折算成电压值
	switch(adc->channel){
		case BSP_ADC_CH1:
			tmp_u32 *= 2500;
			tmp_u32 /= 4095;
			break;
		
		default:
			tmp_u32 = 0;
			break;
	}
	adc->value_vol[adc->channel] = tmp_u32;
}


/*******************************************************************************
  * @brief  dac
  *****************************************************************************/
  
/*******************************************************************************
  * @brief  写DAC值
  *
  * @param  ch
  * @param  value 电压值，单位mv，范围0~2500mv
  *
  * @retval none
  *****************************************************************************/
void bsp_io_dac_wr(bsp_io_dac_t ch, bsp_u16 value)
{
	bsp_u32 reg;
	
	if (value > 2500) 
		value = 2500;
	
	reg = value * 4096 / 2500;
	reg = reg;
	
	switch(ch){
	case BSP_DAC_CH1:
		//HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, reg);
		break;
		
	case BSP_DAC_CH2:
		//HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, reg);
		break;
		
	default:
		break;
	}	
}


/*******************************************************************************
  * @brief  bsp_io_init
  *
  * @param	none
  * 
  * @retval none
  *****************************************************************************/
void bsp_io_init(void)
{
	/*
	bsp_io_dac_wr(BSP_DAC_CH1, 0);
	bsp_io_dac_wr(BSP_DAC_CH2, 0);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
	*/
}


/********************************* end of file ********************************/
