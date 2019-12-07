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

#include "usbcan.h"
#include "driver.h"
#include "imu.h"

int fd;
int acclX, acclY, acclZ;
int gyroX, gyroY, gyroZ;
//double acclX_scaled, acclY_scaled, acclZ_scaled;
//double gyroX_scaled, gyroY_scaled, gyroZ_scaled;

void cmd_vel_callback(const geometry_msgs::Twist::ConstPtr& msg)
{
	float linear_vel,angular_vel;
	linear_vel = msg->linear.x;
	angular_vel = msg->angular.z;
	robot_movement(linear_vel, angular_vel);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "rasp4b_core");
	printf(">>this is first control node!\r\n");//指示程序已运行

	ros::NodeHandle n;

	ros::Subscriber sub= n.subscribe("/loui_robot1/cmd_vel", 100,cmd_vel_callback);
	ros::Publisher motor_pub = n.advertise<rasp4b_core::SensorState>\
		("sensor_state", 10);
	
	driver_init();
	imu_init(fd);
	
	int reclen=0,ind=0,i=0;
	VCI_CAN_OBJ rec[3000];//接收缓存，设为3000为佳。
	
	ros::Rate loop_rate(10);
	printf("ready!\n");
	while(ros::ok())
	{
		ros::spinOnce();
		//TODO:need to optimize
		if((reclen=VCI_Receive(VCI_USBCAN2,0,ind,rec,3000,100))>0)//调用接收函数，如果有数据，进行数据处理显示。
         	{
			//printf("publish success!");
                	i=reclen-1;
			rasp4b_core::SensorState motor_real;
			motor_real.motor_id=rec[i].ID;//&0xFFF0;
			motor_real.current=(rec[i].Data[0]<<8)|rec[i].Data[1];
			motor_real.velocity=(rec[i].Data[2]<<8)|rec[i].Data[3];
			motor_real.position=(rec[i].Data[4]<<24)|(rec[i].Data[3]<<16)|(rec[i].Data[2]<<8)|rec[i].Data[1];
			
			acclX = read_word_2c(0x3B,fd);
			acclY = read_word_2c(0x3D,fd);
			acclZ = read_word_2c(0x3F,fd);
			motor_real.acclX_scaled = acclX *100000/ 16384.0;
			motor_real.acclY_scaled = acclY *100000/ 16384.0;
			motor_real.acclZ_scaled = acclZ *100000/ 16384.0;
			
			gyroX = read_word_2c(0x43,fd);
			gyroY = read_word_2c(0x45,fd);
			gyroZ = read_word_2c(0x47,fd);
			motor_real.gyroX_scaled = gyroX *100000/ 131.0;
			motor_real.gyroY_scaled = gyroY *100000/ 131.0;
			motor_real.gyroZ_scaled = gyroZ *100000/ 131.0;
			
			motor_pub.publish(motor_real);
                  }

	        else
       		 {
               		 printf("receive2 fail!\n");
       		 }
		 loop_rate.sleep();
	}	

        return 0;
}

