#include "bsp_led.h"

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

int led_color;
/**
  * @brief  Configure the LED
  * @param  None
  * @retval None
  */
void led_gpio_config(void){
    led_color = 0;
    //依次配置时钟，模式
    GPIO_InitTypeDef gpio;
    
    RCC_APB2PeriphClockCmd( LED1_GPIO_CLK, ENABLE);
    gpio.GPIO_Pin = LED1_GPIO_PIN;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP ;
    gpio.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_Init(LED1_GPIO_PORT, &gpio);
    
    RCC_APB2PeriphClockCmd( LED2_GPIO_CLK, ENABLE);
    gpio.GPIO_Pin = LED2_GPIO_PIN;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP ;
    gpio.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_Init(LED2_GPIO_PORT, &gpio);
    
    RCC_APB2PeriphClockCmd( LED3_GPIO_CLK, ENABLE);
    gpio.GPIO_Pin = LED3_GPIO_PIN;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP ;
    gpio.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_Init(LED3_GPIO_PORT, &gpio);
    
}

//注意是低电平点亮，而初始化即为低电平。
//红色 RGB 高电平对应 100，低电平为 011，对应配置如下
//用库函数也可以用寄存器操作，待补充。
void led_red(void){
    GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);  
    led_color = 0;    
}

//010 101
void led_green(void){
    GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
    led_color = 1;
}

//001 110
void led_blue(void){
    GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
    led_color = 2;
}

//110 001
void led_yellow(void){
    GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
    led_color = 3;
}

//101 010
void led_purple(void){
    GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
    led_color = 4;
}

//011 100
void led_cyan(void){
    GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
    led_color = 5;
}

//111 000
void led_white(void){
    GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
    led_color = 6;
}

/*
****不能算作颜色，所以不分配led_color的值。
*/
//000 111
void led_dark(void){
    GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);    
    GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);    
}

/*
****全局变量 led_color 的值自增，并且在0~6共七种颜色之间循环。
*/
void led_color_next(void){
    led_color++;
    if(led_color == 7){
        led_color = 0;
    }
}

/*
****根据全局变量 led_color 的值打开对应颜色的灯光组合。
*/
void led_on(void){
    switch(led_color){
        case 0:led_red();break;
        case 1:led_green();break;
        case 2:led_blue();break;
        case 3:led_yellow();break;
        case 4:led_purple();break;
        case 5:led_cyan();break;
        case 6:led_white();break;
    }
}

void led_off(void){
    led_dark();
}

/*
****改变颜色并打开灯光。
*/
void led_roll(void){
    led_color_next();
    led_on();
}

void led_red_toggle(void){
    if(led_color != 7){
        led_white();
    }else{
        led_red();
    }

}


