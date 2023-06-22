#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

/**
 * @brief 
 * 
 */
void    TIM3_init(void);

/**
 * @brief Set the servo angle object
 * 
 * @param angle 
 */
void set_servo_angle(uint8_t angle); //uint8??
#endif