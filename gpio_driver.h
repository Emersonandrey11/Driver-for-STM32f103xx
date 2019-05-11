
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f10x.h"


/* Configuração do Modo (I/O) */

#define INPUT                                            ( (uint32_t)0x00 )
#define OUTPUT                                           ( (uint32_t)0x01 )
#define GPIO_PIN_ALT_FUN_MODE                            ( (uint32_t)0x02 )

/* Open-drain ou push-pull */

#define PUSHPULL                                         ( (uint32_t)0x00 )
#define OPENDRAIN                                        ( (uint32_t)0x01 )

/* Velocidade */

#define GPIO_PIN_SPEED_LOW                               ( (uint32_t)0x00 )
#define GPIO_PIN_SPEED_MEDIUM                            ( (uint32_t)0x01 )
#define GPIO_PIN_SPEED_HIGH                              ( (uint32_t)0x02 )

/* PUPD */

//#define GPIO_PIN_NO_PULL_PUSH                            ( (uint32_t)0x00 )
#define PULLUP                                           ( (uint32_t)0x01 )
#define PULLDOWN                                         ( (uint32_t)0x00 )


/* Macros para habilitar o clock */

#define _HAL_RCC_GPIOA_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 2) )
#define _HAL_RCC_GPIOB_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 3) )
#define _HAL_RCC_GPIOC_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 4) )
#define _HAL_RCC_GPIOD_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 5) )
#define _HAL_RCC_GPIOE_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 6) )
#define _HAL_RCC_GPIOF_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 7) )
#define _HAL_RCC_GPIOG_CLOCK_ENABLE()                    (RCC->APB2ENR |= (1 << 8) )

#define HIGH                                             ( (uint16_t)0x01 )
#define LOW                                              ( (uint16_t)0x00 )


//typedef struct
//{
//    uint32_t pin_no;              // main deve dizer qual é o pino
//	
//	  uint32_t mode;             // main deve dizer o modo do pino, input, output ou alt fun
//	
//	  uint32_t op_type;          // main deve dizer se é open-drain ou push pull
//	
// 	  uint32_t pull;             // main deve dizer se tem pull-up,pull-down ou se não tem
//	
//	  uint32_t speed;            // main deve dizer a velocidade do clock para o pino
//	
//	  uint32_t alternate;        // main deve dizer qual é a outra função do pino

//} GPIO_PIN_CONF_T;

#endif
