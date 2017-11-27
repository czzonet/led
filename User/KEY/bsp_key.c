#include "bsp_key.h"

void key_gpio_config(void){
    //不喜欢驼峰写法，自己来。
    //依次配置时钟，模式
    GPIO_InitTypeDef gpio;
    
    RCC_APB2PeriphClockCmd( KEY1_GPIO_CLK, ENABLE);
    gpio.GPIO_Pin = KEY1_GPIO_PIN;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
    GPIO_Init(KEY1_GPIO_PORT, &gpio);
    
    RCC_APB2PeriphClockCmd( KEY2_GPIO_CLK, ENABLE);
    gpio.GPIO_Pin = KEY2_GPIO_PIN;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
    GPIO_Init(KEY2_GPIO_PORT, &gpio);
  
}


uint8_t key1_click(void){
    //按下为高电平，读取寄存器变化
    if(GPIO_ReadInputDataBit( KEY1_GPIO_PORT, KEY1_GPIO_PIN) == 1){
        //等待按键松开
        while((GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == 1));
        return 1;
    }else
    return 0;
}

uint8_t key2_click(void){
    if(GPIO_ReadInputDataBit( KEY2_GPIO_PORT, KEY2_GPIO_PIN) == 1){
        //等待按键松开
        while((GPIO_ReadInputDataBit(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == 1));
        return 1;
    }else
    return 0;
}

static void nvic_config(void){
    NVIC_InitTypeDef nvic;
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    //key1
    nvic.NVIC_IRQChannel = KEY1_EXTI_IRQ;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 1;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);
    
    //key2
    nvic.NVIC_IRQChannel = KEY2_EXTI_IRQ;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 1;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);
}

void key_exti_config(void){
    EXTI_InitTypeDef exti;
    key_gpio_config();
    nvic_config();
    
    //key1
    GPIO_EXTILineConfig(KEY1_EXTI_PORTSOURCE, KEY1_EXTI_PINSOURCE);
    exti.EXTI_Line = KEY1_EXTI_LINE;
    exti.EXTI_Mode = EXTI_Mode_Interrupt;
    exti.EXTI_Trigger = EXTI_Trigger_Rising;
    exti.EXTI_LineCmd = ENABLE;
    EXTI_Init(&exti);
    
    //key2
    GPIO_EXTILineConfig(KEY2_EXTI_PORTSOURCE, KEY2_EXTI_PINSOURCE);
    exti.EXTI_Line = KEY2_EXTI_LINE;
    exti.EXTI_Mode = EXTI_Mode_Interrupt;
    exti.EXTI_Trigger = EXTI_Trigger_Rising;
    exti.EXTI_LineCmd = ENABLE;
    EXTI_Init(&exti);
}

