#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__

//保持模块独立性不能包含led部分，而通过编写返回值函数然后在主函数调用判断来实现逻辑。
//更正：中断服务函数不可靠返回值实现逻辑，改为直接主函数里重写实现。
#include "stm32f10x_gpio.h"

//k1 pa0
#define KEY1_GPIO_PORT GPIOA
//注意端口时钟变化，配置EXTI信号源时需要用到AFIO外部中断寄存器。
#define KEY1_GPIO_CLK (RCC_APB2Periph_GPIOA \
|RCC_APB2Periph_AFIO)
#define KEY1_GPIO_PIN GPIO_Pin_0
//EXIT部分
#define KEY1_EXTI_PORTSOURCE GPIO_PortSourceGPIOA
#define KEY1_EXTI_PINSOURCE GPIO_PinSource0
#define KEY1_EXTI_LINE EXTI_Line0
#define KEY1_EXTI_IRQ EXTI0_IRQn
#define KEY1_IRQHandler EXTI0_IRQHandler



//k2 pc13
#define KEY2_GPIO_PORT GPIOC
#define KEY2_GPIO_CLK RCC_APB2Periph_GPIOC
#define KEY2_GPIO_PIN GPIO_Pin_13
#define KEY2_EXTI_PORTSOURCE GPIO_PortSourceGPIOC
#define KEY2_EXTI_PINSOURCE GPIO_PinSource13
#define KEY2_EXTI_LINE EXTI_Line13
#define KEY2_EXTI_IRQ EXTI15_10_IRQn

void key_gpio_config(void);
uint8_t key1_click(void);
uint8_t key2_click(void);
void key_exti_config(void);


#endif
