//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:driver.h
//        description:
//
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#ifndef __DRIVER_H
#define __DRIVER_H

#include "usbcan.h"

#define WHELL_BASE 0.4 //unit:m
#define WHELL_PERIMETER 0.659734457  //unit:m
#define REDUCTION_RATIO 14 //14:1
#define MAX_CURRENT_0 0x0B //3A
#define MAX_CURRENT_1 0xB8 


void driver_init(void);
void robot_movement(float linear_vel,float angular_vel);

#endif
