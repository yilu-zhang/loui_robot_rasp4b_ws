//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:usbcan.cpp
//        description:
//
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#include "usbcan.h"

void usbcan_init(void)
{
	if(VCI_OpenDevice(VCI_USBCAN2,0,0)==1)//打开设备
	{
		printf(">>open deivce success!\n");//打开设备成功
	}else
	{
		printf(">>open deivce error!\n");
		exit(1);
	}
}
