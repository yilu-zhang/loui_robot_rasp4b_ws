//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:imu.cpp
//        description:
//
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#include "imu.h"

void imu_init(int &fd)
{
	fd = wiringPiI2CSetup (0x68);
	wiringPiI2CWriteReg8 (fd,0x6B,0x00);//disable sleep mode 
	printf("set 0x6B=%X\n",wiringPiI2CReadReg8 (fd,0x6B));
}

int read_word_2c(int addr,int &fd)
{
   int val;
  val = wiringPiI2CReadReg8(fd, addr);
  val = val << 8;
  val += wiringPiI2CReadReg8(fd, addr+1);
  if (val >= 0x8000)
    val = -(65536 - val);

  return val;
}

