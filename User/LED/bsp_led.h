#ifndef __BSP_LED_H__
#define __BSP_LED_H__


/*
1、设计函数输出基本混色，即各灯为0%或100%两种状态，共8种基本颜色。
使用PWM后可以调制更多颜色。
2、少使用宏而多使用函数，c++里面有这样的建议。所以虽然是使用标准库，
但并不意味着我就能只能使用它了，如果不好用，照样舍弃。取优才是正确的思路。
3、避免过度封装，这里使用三个宏定义，是因为每个灯就三个板级相关的参数，端口、时钟、引脚。
当然时钟是和端口是统一的，也可以优化为一个。
这样的确方便了移植。以后电路有改动只需要改部分宏定义即可。
*/
//R 红色
#define LED1_GPIO_PORT GPIOB
#define LED1_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN GPIO_Pin_5


//G 绿色
#define LED2_GPIO_PORT GPIOB
#define LED2_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN GPIO_Pin_0

//B 蓝色
#define LED3_GPIO_PORT GPIOB
#define LED3_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED3_GPIO_PIN GPIO_Pin_1

void led_gpio_config(void);
void led_red(void);
void led_green(void);
void led_blue(void);
void led_yellow(void);
void led_purple(void);
void led_cyan(void);
void led_white(void);
void led_dark(void);

void led_color_next(void);
void led_on(void);
void led_off(void);
void led_roll(void);
#endif

