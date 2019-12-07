//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:infrared_control
//        description:
//          input-The signal of infrared remote controller(dm/s).
//          output-Expected velocity /loui_robot1/cmd_vel
//                           (geometry_msgs/Twist.h,m/s). 
//
//        created by yiluzhang at  12/06/2019
//
//======================================================================

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#define uchar unsigned char

#define NORMAL_VEL_X 0.3
#define NORMAL_VEL_Z 0.4

//TODO:1.setting_velocity function;
char const *keymap[21] ={
	" KEY_CHANNELDOWN ",
	" KEY_CHANNEL ",
	" KEY_CHANNELUP ",
	" KEY_PREVIOUS ",
	" KEY_NEXT ",
	" KEY_PLAYPAUSE ",
	" KEY_VOLUMEDOWN ",
	" KEY_VOLUMEUP ",
	" KEY_EQUAL ",
	" KEY_NUMERIC_0 ",
	" BTN_0 ",
	" BTN_1 ",
	" KEY_NUMERIC_1 ",
	" KEY_NUMERIC_2 ",
	" KEY_NUMERIC_3 ",
	" KEY_NUMERIC_4 ",
	" KEY_NUMERIC_5 ",
	" KEY_NUMERIC_6 ",
	" KEY_NUMERIC_7 ",
	" KEY_NUMERIC_8 ",
	" KEY_NUMERIC_9 "};

int key(char *code)
{
	int i;
	int num;
	for (i=0; i<21; i++){
		if (strstr(code, keymap[i])){
			num = i;
		}
	}
	return num + 1;
}
//int twist_setting(int i)

int main(int argc, char **argv)
{
	struct lirc_config *config;
	int buttonTimer = millis();
	char *code;
	//char *c;
	
	ros::init(argc, argv, "infrared_control");
	ros::NodeHandle n;
	ros::Publisher infrared_pub = n.advertise<geometry_msgs::Twist>("/loui_robot1/cmd_vel", 10);
		
	if(wiringPiSetup() == -1)
	{
		ROS_INFO("setup wiringPi failed !");
		return 1; 
	}

	if(lirc_init("lirc",1)==-1)
		exit(EXIT_FAILURE);

	if(lirc_readconfig(NULL,&config,NULL)!=0)
	{
		exit(EXIT_FAILURE);
	}
	ROS_INFO("setup wiringPi success!");
	
	geometry_msgs::Twist msg;
	msg.linear.x=0;
	msg.linear.y=0;
	msg.linear.z=0;
	msg.angular.x=0;
	msg.angular.y=0;
	msg.angular.z=0;
	
	float vel_set=0;
	//bool pub_flag=true;
	bool set_vel_flag=false;
	int input_num = 0;
	
	ros::Rate loop_rate(10);			
	while(ros::ok())
	{
		if(lirc_nextcode(&code)!=0)
		{
			break;
		}
		
		if(code==NULL) continue;

		if (millis() - buttonTimer  > 400)
		{				
			switch(key(code))
			{
				//CH-
				case 1:
					//XXX:if only use fisrt line,the value is too small but 
					//not zero when the value equal to zero.it maybe due
					//to raspberry pi processing.
					msg.linear.x-=0.1;
					if((msg.linear.x>-0.0001)&&(msg.linear.x<0.0001))
					{	msg.linear.x=0;}
					
					break;
				
				//CH	
				case 2: 
					if(input_num==0)
					{
						msg.linear.x=NORMAL_VEL_X;
				    }
				    
				    else 
				    {
						msg.linear.x=vel_set*0.1;
					}
					//pub_flag=true;
					set_vel_flag=false;
					input_num=0;
					vel_set=0; 
					break;
				
				//CH+
				case 3:
					msg.linear.x+=0.1;
					if((msg.linear.x>-0.0001)&&(msg.linear.x<0.0001))
					{	msg.linear.x=0;}
					break;
				
				//|<<	
				case 4: 			
					if(input_num==0)
					{
						msg.angular.z=NORMAL_VEL_Z;
				    }
				    
				    else 
				    {
						msg.angular.z=vel_set*0.1;
					}
					//pub_flag=true;
					set_vel_flag=false;
					input_num=0;
					vel_set=0;  
					break;
				
				//>>|	
				case 5: 
					msg.linear.x=0;
					msg.angular.z=0;
					break;
				
				//>||	
				case 6: 
					if(input_num==0)
					{
						msg.angular.z=-NORMAL_VEL_Z;
				    }
				    
				    else 
				    {
						msg.angular.z=-vel_set*0.1;
					}
					//pub_flag=true;
					set_vel_flag=false;
					input_num=0;
					vel_set=0;  
					break;
				
				//-	
				case 7:
					msg.angular.z-=0.1;
					if((msg.angular.z>-0.0001)&&(msg.angular.z<0.0001))
					{	msg.angular.z=0;}
					break;
				
				//+	
				case 8: 			
					if(input_num==0)
					{
						msg.linear.x=-NORMAL_VEL_X;
				    }
				    
				    else 
				    {
						msg.linear.x=-vel_set*0.1;
					}
					//pub_flag=true;
					set_vel_flag=false;
					input_num=0;
					vel_set=0; 
					break;
				
				//EQ
				case 9:
					msg.angular.z+=0.1;
					if((msg.angular.z>-0.0001)&&(msg.angular.z<0.0001))
					{	msg.angular.z=0;}
					break;
				
				//200+	
				case 12:
					set_vel_flag=true;
					break;
				
				//0
				case 10:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=0;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10;
							input_num++;
						}
					}
					break;
				
				//1
				case 13: 
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=1;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+1;
							input_num++;
						}
					}
					break;
				
				//2	
				case 14:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=2;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+2;
							input_num++;
						}
					} 
					break;
				
				//3
				case 15:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=3;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+3;
							input_num++;
						}
					}
					break;
				
				//4	
				case 16: 
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=4;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+4;
							input_num++;
						}
					}
					break;
				
				//5
				case 17: 
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=5;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+5;
							input_num++;
						}
					}
					break;
				
				//6
				case 18:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=6;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+6;
							input_num++;
						}
					} 
					break;
					
				//7
				case 19:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=7;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+7;
							input_num++;
						}
					}
					break;
				
				//8
				case 20:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=8;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+8;
							input_num++;
						}
					} 
					break;
				
				//9	
				case 21:
					if(set_vel_flag)
					{
						if(input_num==0)
						{
							vel_set=9;
							input_num++;
						}
						
						else if(input_num==1)
						{
							vel_set=vel_set*10+9;
							input_num++;
						}
					}
					break;
					
				default:
					break;
					
			}
			infrared_pub.publish(msg);	
		}

		ros::spinOnce();
		free(code);
		loop_rate.sleep();
	}
	
	ROS_INFO("exit while");
	lirc_freeconfig(config);
	ROS_INFO("1");	
	lirc_deinit();
	ROS_INFO("2");
	exit(EXIT_SUCCESS);
	ROS_INFO("3");
	return 0;
}


