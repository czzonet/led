#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__


#include "stm32f10x.h"
#include "core_cm3.h"
#include "./LED/bsp_led.h"    //为了控制颜色变化

void systick_config(u32 n);
void reset_timer(void);


#endif
