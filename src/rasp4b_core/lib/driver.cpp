//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:driver.cpp
//        description:
//
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#include "driver.h"
void driver_init(void)
{
	usbcan_init();
	
	//初始化参数，严格参数二次开发函数库说明书。
	VCI_INIT_CONFIG config;
	config.AccCode=0x80000000;
	config.AccMask=0xFFFFFFFF;
	config.Filter=0;//接收所有帧
	config.Timing0=0x00;/*波特率1000 Kbps  0x00  0x14*/
	config.Timing1=0x14;
	config.Mode=0;//正常模式	

	//需要发送的帧，结构体设置
	VCI_CAN_OBJ send[2];
	send[0].ID=0x00; //broadcast
	send[0].SendType=1;
	send[0].DataLen=8;
	send[0].ExternFlag=0;
	send[0].RemoteFlag=0;
	send[1].ID=0x20; //driver 2
	send[1].SendType=1;
	send[1].DataLen=8;
	send[1].ExternFlag=0;
	send[1].RemoteFlag=0;	

	//init usbcan
	if(VCI_InitCAN(VCI_USBCAN2,0,0,&config)!=1)
	{
		printf(">>Init CAN1 error\n");
		VCI_CloseDevice(VCI_USBCAN2,0);
	}

	//start usbcan
	if(VCI_StartCAN(VCI_USBCAN2,0,0)!=1)
	{
		printf(">>Start CAN1 error\n");
		VCI_CloseDevice(VCI_USBCAN2,0);
	}	
	usleep(100000);

	int i=0;
	//send reset command
	for(i = 0; i < send[0].DataLen; i++)
	{
		send[0].Data[i] = 0x55;
		send[1].Data[i] = 0x55;
	}
	if(VCI_Transmit(VCI_USBCAN2, 0, 0, send, 1) == 1)
	{
		printf("reset succes!\n");
	}
	else
	{
		printf("reset fail!\n");
	        usleep(100000);//延时100ms。
		VCI_CloseDevice(VCI_USBCAN2,0);//关闭设备。
		exit(1);
	}
	usleep(500000);
	
	//select current and velcity model
	send[0].ID=0x01;
	send[1].ID=0x21;
	send[0].Data[0] = 0x06;  //model 6
	send[1].Data[0] = 0x06;
	for(i = 1; i < send[0].DataLen; i++)
	{
		send[0].Data[i] = 0x55;
		send[1].Data[i] = 0x55;
	}

	if(VCI_Transmit(VCI_USBCAN2, 0, 0, send, 1) == 1)
	{
		printf("set mode succes!\n");
	}
	else
	{
		printf("set mode fail!\n");
	        usleep(100000);//延时100ms。
		VCI_CloseDevice(VCI_USBCAN2,0);//关闭设备。
		exit(1);
	}
	usleep(500000);
	
	//setting the period of current,velocity,position and CTL1/CTL2
	send[0].ID=0x1A;
    send[1].ID=0x2A;
	
	//the period of sending current,velocity and position is 1ms
    send[0].Data[0] = 0x01; 
    send[1].Data[0] = 0x01;
	//don't send CTL1/CTL2
    send[0].Data[1] = 0x00;
    send[1].Data[1] = 0x00;

    for(i = 4; i < send[0].DataLen; i++)
    {
        send[0].Data[i] = 0x55;
        send[1].Data[i] = 0x55;
    }
	
	if(VCI_Transmit(VCI_USBCAN2, 0, 0, send, 1) == 1)
	{
		printf("set feedback succes!\n");
	}
	else
	{
		printf("set feedback fail!\n");
	        usleep(100000);//延时100ms。
		VCI_CloseDevice(VCI_USBCAN2,0);//关闭设备。
		exit(1);
	}
	usleep(100000);	
	if(VCI_Transmit(VCI_USBCAN2, 0, 0, &send[1], 1) == 1)
	{
		printf("set feedback succes!\n");
	}
	else
	{
		printf("set feedback fail!\n");
	        usleep(100000);//延时100ms。
		VCI_CloseDevice(VCI_USBCAN2,0);//关闭设备。
		exit(1);
	}
	usleep(100000);
}

//m/s->RPM
u_int16_t velocity_convert_rpm(float vel)
{
	u_int16_t vel_rpm;
	if(vel>=0)
	{
		vel_rpm = vel*60*REDUCTION_RATIO/WHELL_PERIMETER;
	}
	
	else
	{
		vel_rpm = (-vel)*60*REDUCTION_RATIO/WHELL_PERIMETER;
		vel_rpm = ~vel_rpm + 1;
	} 
	return vel_rpm;
}

void left_motor_action(float vel_left)
{
	u_int16_t vel_rpm;
	VCI_CAN_OBJ send;
    send.ID=0x27;
    send.SendType=0;
    send.DataLen=8;
    send.ExternFlag=0;
    send.RemoteFlag=0;
    
    int i;
	for(i = 4; i < send.DataLen; i++)
    {
        send.Data[i] = 0x55;
    }
    
    vel_rpm = velocity_convert_rpm(vel_left);
    //printf("the rpm is:%x\n",vel_rpm);
    
    send.Data[0] = MAX_CURRENT_0;
    send.Data[1] = MAX_CURRENT_1;
    send.Data[2] = (vel_rpm>>8)&0xff;
    send.Data[3] = vel_rpm&0xff;  
    
    VCI_Transmit(VCI_USBCAN2, 0, 0, &send, 1); 
}

void right_motor_action(float vel_right)
{
	u_int16_t vel_rpm;
	VCI_CAN_OBJ send;
    send.ID=0x17;
    send.SendType=0;
    send.DataLen=8;
    send.ExternFlag=0;
    send.RemoteFlag=0;
    
    int i;
	for(i = 4; i < send.DataLen; i++)
    {
        send.Data[i] = 0x55;
    }
    
    vel_rpm = velocity_convert_rpm(vel_right);
    //printf("the rpm is:%x\n",vel_rpm);
    
    send.Data[0] = MAX_CURRENT_0;
    send.Data[1] = MAX_CURRENT_1;
    send.Data[2] = (vel_rpm>>8)&0xff;
    send.Data[3] = vel_rpm&0xff;  
    
    VCI_Transmit(VCI_USBCAN2, 0, 0, &send, 1); 
}

void left_motor_operation(float vel_left)
{
	left_motor_action(vel_left);
}

void right_motor_operation(float vel_right)
{
	right_motor_action(vel_right);
}

void robot_movement(float linear_vel, float angular_vel)
{
	float vel_left,vel_right; //unit:m/s
	
	//printf("action!\n"); 
	 
	//looking from back to front.Counterclockwise is positive
	vel_left = linear_vel - WHELL_BASE*angular_vel*0.5;
	vel_right = linear_vel + WHELL_BASE*angular_vel*0.5;
	
	left_motor_operation(vel_left);
	usleep(10000); //10ms;interval shoud greater than 5ms
	right_motor_operation(vel_right);	
}


