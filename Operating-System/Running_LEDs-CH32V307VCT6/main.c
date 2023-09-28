#include"debug.h"
#define LED_Rev(GPIO_Pin) GPIO_WriteBit(GPIOE, GPIO_Pin, 1-GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin))
#define Initialize() GPIO_InitTypeDef GPIO_InitStructure; RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE); GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12; GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; GPIO_Init(GPIOE, &GPIO_InitStructure); Delay_Init()



int main(){
    Initialize();
    while(1){
        LED_Rev(GPIO_Pin_11);
        Delay_Ms(64);
        LED_Rev(GPIO_Pin_12);
    }
}
