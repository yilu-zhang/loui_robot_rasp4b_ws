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
#include "sensor_msgs/Imu.h"

#include "imu.h"

#define G 9.81007 //vins euroc
#define PI_PER_DEGREE 0.017453292  //PI/180
#define IMU_T 0.01

int fd;
int acclX, acclY, acclZ;
int gyroX, gyroY, gyroZ;


int main(int argc, char **argv)
{
	ros::init(argc, argv, "imu_node");
	printf("this is imu node!\r\n");//指示程序已运行

	ros::NodeHandle n;

	ros::Publisher imu_pub = n.advertise<sensor_msgs::Imu>("/loui_robot1/imu", 1000);
	
	imu_init(fd);
	
	sensor_msgs::Imu imu;
	double error_time;
	int wrong_cnt=0;
	double expected_t = ros::Time::now().toSec()+IMU_T;	
	
	for(int i = 0;i<20;i++)
	{
		while(ros::Time::now().toSec() < expected_t);
		//printf("len:%d\n",len);
		read_word_2c(0x3B,fd);
		read_word_2c(0x3D,fd);
		read_word_2c(0x3F,fd);
		read_word_2c(0x43,fd);
		read_word_2c(0x45,fd);
		read_word_2c(0x47,fd);
		expected_t = expected_t + IMU_T;
	}
		
	while(ros::ok())
	{			
			while(ros::Time::now().toSec() < expected_t);
			double start_t_1 = ros::Time::now().toSec(),start_t_2;
			
			/*error_time = ros::Time::now().toSec() - expected_t;
			if(error_time>0.002||error_time<-0.002){
				wrong_cnt++;
				printf("The time error:%d %f\n",wrong_cnt,error_time);
			}*/
			
			start_t_2 = ros::Time::now().toSec();
			
			acclY = read_word_2c(0x3D,fd);
			acclZ = read_word_2c(0x3F,fd);
			acclX = read_word_2c(0x3B,fd);
			gyroZ = read_word_2c(0x47,fd);
			gyroX = read_word_2c(0x43,fd);
			gyroY = read_word_2c(0x45,fd);
			
			imu.header.stamp = ros::Time().fromSec((ros::Time::now().toSec()+start_t_2)/2);
			//printf("Reading imu time:%f\n",ros::Time::now().toSec()-start_t_2);
			
			imu.linear_acceleration.x = acclX*G/16384.0;
			imu.linear_acceleration.y = acclY*G/16384.0;
			imu.linear_acceleration.z = acclZ*G/16384.0;
						
			imu.angular_velocity.x = gyroX*PI_PER_DEGREE/131.072;
			imu.angular_velocity.y = gyroY*PI_PER_DEGREE/131.072;
			imu.angular_velocity.z = gyroZ*PI_PER_DEGREE/131.072;
			imu_pub.publish(imu);
						
			//printf("Process imu time:%f\n",ros::Time::now().toSec()-start_t_1);
			expected_t = expected_t + IMU_T;
			if(ros::Time::now().toSec() > expected_t)
			{
				//printf("timeout in 1,time:%f\n",ros::Time::now().toSec()-start_t_1);
			}
						 
		 if(ros::Time::now().toSec() > expected_t)
		 {
			printf("timeout in 2,error time:%f %f\n",ros::Time::now().toSec()-expected_t,ros::Time::now().toSec()-start_t_1);
		 }
		 //printf("Process encoder time:%f\n",ros::Time::now().toSec()-start_t);		
	}
	
        return 0;
}

