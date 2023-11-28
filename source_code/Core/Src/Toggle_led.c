/*
 * Toggle_led.c
 *
 *  Created on: Nov 28, 2023
 *      Author: ASUS TUF GAMING
 */
#include "Toggle_led.h"

void toggle_led1(){
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}
void toggle_led2(){
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}
void toggle_led3(){
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}
void toggle_led4(){
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
}
void toggle_led5(){
	HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
}

