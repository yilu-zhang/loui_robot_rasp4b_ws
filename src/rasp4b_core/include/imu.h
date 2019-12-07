//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:imu.h
//        description:
//
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#ifndef __IMU_H
#define __IMU_H

#include  <wiringPiI2C.h>
#include  <math.h>
#include <stdio.h>

void imu_init(int &fd);
int read_word_2c(int addr,int &fd);


#endif
