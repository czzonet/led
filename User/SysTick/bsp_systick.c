#include "./SysTick/bsp_systick.h"

u32 ntime = 0;
__IO u32 temp = 0;
__IO u32 temp2 = 0;
int flag = 0;//方向
void reset_timer(void){
    temp = ntime;
    
    //变暗-变亮-变暗-变亮阶段循环
    if(flag){
        //变暗阶段，增大temp2
        temp2+=1;
        //最暗时刻反转
        if(temp2>ntime-11){
            flag = 0;
            led_color_next();  //最暗的时刻改变颜色
        }

    }else{
        //变亮阶段
        temp2-=1;
        if(temp2<11){flag = 1;}
    }
}

void systick_config(u32 n){
    if(n<100){
        n=100;
    }
    ntime = n;
    temp2 = ntime;
    reset_timer();
    //10us init
    if(SysTick_Config(SystemCoreClock / 100000)){
        while(1);
    }
    
}







