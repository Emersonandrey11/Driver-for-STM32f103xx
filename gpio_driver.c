
#include <stdint.h>
#include "gpio_driver.h"


 static void pinMode (GPIO_TypeDef *GPIOx, uint16_t pin_no, uint32_t mode, uint32_t op_type)
{
	
	/**************************************************************************************
	*Configura��o dos clocks
	***************************************************************************************/
	
//	if (GPIOx == GPIOA){
//	 _HAL_RCC_GPIOA_CLOCK_ENABLE();
//	}
//	if (GPIOx == GPIOB){
//		_HAL_RCC_GPIOB_CLOCK_ENABLE();
//	}
//	if (GPIOx == GPIOC){
//	 _HAL_RCC_GPIOC_CLOCK_ENABLE();
//	}
//	if (GPIOx == GPIOD){
//		_HAL_RCC_GPIOD_CLOCK_ENABLE();
//	}
//	if (GPIOx == GPIOE){
//	 _HAL_RCC_GPIOE_CLOCK_ENABLE();
//	}	
//	if (GPIOx == GPIOF){
//		_HAL_RCC_GPIOF_CLOCK_ENABLE();
//	}
//	if (GPIOx == GPIOG){
//	 _HAL_RCC_GPIOG_CLOCK_ENABLE();
//	}	
	
	/**************************************************************************************
	*Configura��o de entrada e sa�da dos pinos
	***************************************************************************************/
	
	if (pin_no > 7) {
		
	uint16_t pin_base = (pin_no - 8)*4;                            // Faz uma opera��o para colocar o modo corretamente no registrador
	GPIOx->CRH |= (mode << (pin_base));                           
		
	if (mode == OUTPUT){		                                       // Sa�da
	GPIOx->CRH |= (op_type << (pin_base + 2));
	}
	
//  if (mode == INPUT){                                            // Entrada
//			if (op_type == PULLDOWN){                                  // PullDown
//	      GPIOx->ODR |=  (LOW << pin_no); 
//	     }
//	    else if (op_type == PULLUP){                               // PullUp
//	      GPIOx->ODR |= (HIGH << pin_no);
//	     }
//	}	
	}
	else {
	
		
	uint16_t pin_base = (pin_no - 8)*4;                            // Faz uma opera��o para colocar o modo corretamente no registrador
	GPIOx->CRL |= (mode << (pin_base));
		
	if (mode == OUTPUT){	                                         //	Configura push pull ou open drain	
	GPIOx->CRL |= (op_type << (pin_base + 2));
	}
	
//  if (mode == INPUT){                                           // Sa�da
//			if (op_type == PULLDOWN){
//	      GPIOx->ODR &= ~(LOW << pin_no);
//	     }
//	    else if (op_type == PULLUP){
//	      GPIOx->ODR |= (HIGH << pin_no);
//	     }
//	}	
	}
}
	
	/**************************************************************************************
	*Cria uma fun��o auxiliar para Delay
	***************************************************************************************/
	
 static void delay (int time)
{
	int i = 0;
	for(i=0;i<time;i++){}
}

 	/**************************************************************************************
	*Cria uma fun��o para leitura de dados digitais
	***************************************************************************************/

static uint8_t digitalRead (GPIO_TypeDef *GPIOx, uint16_t pin_no, uint32_t op_type)
{

	uint8_t value;

  value = ((GPIOx->IDR>> pin_no) & 0x00000001 );

  return value;	

}

 	/**************************************************************************************
	*Cria uma fun��o para escrita de dados digitais
	***************************************************************************************/

static void digitalWrite (GPIO_TypeDef *GPIOx, uint16_t pin_no, uint16_t val)
{
  
	if(val==1){
	 GPIOx->ODR |= (1 << pin_no);
	}
	else{
	 GPIOx->ODR &= ~(1 << pin_no);
	}
	
}
