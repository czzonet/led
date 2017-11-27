/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
//相对路径是从main.c文件所在位置找起
#include "./LED/bsp_led.h"
#include "./KEY/bsp_key.h"
#include "./SysTick/bsp_systick.h"



int main(void){
    
    led_gpio_config();
    led_green();
    systick_config(500);

    
    #if 0
    //轮询模式
    key_gpio_config();
    //循环监听检测
    while (1){
        if(key1_click() == 1){
            led_roll();
        }
        if(key2_click()){
            led_yellow();
        }
    }
    #else
    //中断模式
    key_exti_config();
    while(1);
    #endif
}

