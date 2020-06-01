//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:rasp4b_core.cpp
//        description:
//          1.reading imu,motor encoder,velocity and current,then,sending
//            them to laptop.
//          2.controlling the motor according to topic /loui_robot1/cmd_vel
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#include "ros/ros.h"
//#include "std_msgs.h"
#include "geometry_msgs/Twist.h"
#include "rasp4b_core/SensorState.h"
//#include "sensor_msgs/Imu.h"

#include "usbcan.h"
#include "driver.h"

#define G 9.81007 //vins euroc
#define REDUCE_RATIO 14
#define QC 2000
#define D 0.205
#define MI_PI 3.141592654


void cmd_vel_callback(const geometry_msgs::Twist::ConstPtr& msg)
{
	float linear_vel,angular_vel;
	linear_vel = msg->linear.x;
	angular_vel = msg->angular.z;
	printf("setting liner vel:%f,setting ang vel:%f\n",linear_vel,angular_vel);
	robot_movement(linear_vel, angular_vel);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "action_encoder");
	printf("this is action_encoder node!\r\n");//指示程序已运行

	ros::NodeHandle n;

	ros::Subscriber control_sub = n.subscribe("/loui_robot1/cmd_vel", 1000,cmd_vel_callback);
	ros::Publisher motor_pub = n.advertise<rasp4b_core::SensorState>("/loui_robot1/sensor_state", 10);
	
	driver_init();
	
	int reclen=0,ind=0,i=0;
	VCI_CAN_OBJ rec[3000];//接收缓存，设为3000为佳。
	
	printf("Robot init success!\n");
	
	rasp4b_core::SensorState motor_real;
	double camera_T_start_t,error_time;
	int wrong_cnt=0;
	int len;
		
	len=VCI_Receive(VCI_USBCAN2,0,ind,rec,3000,100);
	//printf("len:%d\n",len);
	double imu_T = 0.01;
	double expected_t = ros::Time::now().toSec() + 0.032;
	
	for(int i = 0;i<10;i++)
	{
		while(ros::Time::now().toSec() < expected_t);
		len=VCI_Receive(VCI_USBCAN2,0,ind,rec,3000,100);
		printf("len:%d\n",len);
		expected_t = expected_t + 0.04;
	}
		
	while(ros::ok())
	{
		while(ros::Time::now().toSec() < expected_t);
		double start_t = ros::Time::now().toSec();		
		bool r_read_flag=true,l_read_flag=true;
		int r_rec_cnt=9,l_rec_cnt=9,pub_cnt=0;
		int r_pos,r_vel,r_cur,l_pos,l_vel,l_cur;
		
		if((reclen=VCI_Receive(VCI_USBCAN2,0,ind,rec,3000,100))>0)//调用接收函数，如果有数据，进行数据处理显示。
         {
			//printf("Receive encoder data length:%d\n",reclen);
			camera_T_start_t = ros::Time::now().toSec();
			if(reclen > 82 || reclen < 78)
			{
				wrong_cnt++;
				printf("Wrong encoder receive count:%d,len:%d\n",wrong_cnt,reclen);
			}
			for(int i = reclen-1;i<reclen;i--)
			{
				//printf("the time:%d %f\n",rec[i].TimeFlag,rec[i].TimeStamp);
				if(i<0)
				{
					printf("array index out\n");
					break;
				}
				if(rec[i].ID == 27)
				{
					r_rec_cnt++;
					if(r_rec_cnt == 10)
					{
						r_cur=(rec[i].Data[0]<<8)|rec[i].Data[1];
						r_vel=(rec[i].Data[2]<<8)|rec[i].Data[3];
						r_pos=(rec[i].Data[4]<<24)|(rec[i].Data[3]<<16)|(rec[i].Data[2]<<8)|rec[i].Data[1];
						r_read_flag!=r_read_flag;			
					}
				}
				else if(rec[i].ID == 43)
				{
					l_rec_cnt++;
					if(l_rec_cnt == 10)
					{
						l_cur=(rec[i].Data[0]<<8)|rec[i].Data[1];
						l_vel=(rec[i].Data[2]<<8)|rec[i].Data[3];
						l_pos=(rec[i].Data[4]<<24)|(rec[i].Data[3]<<16)|(rec[i].Data[2]<<8)|rec[i].Data[1];
						l_read_flag!=l_read_flag;			
					}
				}
				
				if(r_rec_cnt>=10 && l_rec_cnt >= 10)
				{
					if(r_read_flag != l_read_flag)
					{
						//printf("Right and left encoder syn error\n");
						return -1;
					}
										
					motor_real.header.stamp = ros::Time().fromSec(camera_T_start_t-pub_cnt*0.01);
					motor_real.r_current = r_cur/10.0;
					motor_real.r_velocity = r_vel*M_PI*D/(60*REDUCE_RATIO);
					motor_real.r_position = r_pos*M_PI*D/(QC*REDUCE_RATIO);
					motor_real.l_current = l_cur/10.0;
					motor_real.l_velocity = l_vel*M_PI*D/(60*REDUCE_RATIO);
					motor_real.l_position = l_pos*M_PI*D/(QC*REDUCE_RATIO);	
					motor_pub.publish(motor_real);
					
					pub_cnt++;
					if(pub_cnt == 4)break;
					else
					{
						r_rec_cnt = r_rec_cnt%10;
						l_rec_cnt = l_rec_cnt%10;
					}
				}				
				
			}
		}

	    else
        {
                printf("receive2 fail!\n");
       	}
		 
		 ros::spinOnce();
		 expected_t = expected_t + 0.04;
		 if(ros::Time::now().toSec() > expected_t)
		 {
			printf("timeout in 2,error time:%f %f\n",ros::Time::now().toSec()-expected_t,ros::Time::now().toSec()-start_t);
		 }		 		
	}
	
        return 0;
}

