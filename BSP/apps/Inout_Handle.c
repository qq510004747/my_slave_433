/**************(C) COPYRIGHT  DIY嵌入式开发工作室*****************************
 * 文件名   ：LED.C
 * 环境	 	  : MDK4.73-固件库V3.5版本
 * 实验平台 ：STM32F103RBT6-8MHz->72MHz
 * 版本     ：V1.0.0
 * 作者     ：
 * 修改时间 ：2013-12-20
 * 硬件连接 : STM32F10x-STM32开发板
 * 描述     : 系统基本输出配置文件
 * 修改记录     :
 * 版本号       :  日期          作者       说明 
   V1.0.1       :  2014-09-13          
*******************************************************************************/
/* Includes---------------------------------------------*/
#include "Inout_Handle.h"

#define Open_spikelamp_switch 		PBout( 3) = 1
#define Off_spikelamp_switch 		PBout( 3) = 0

#define Open_voice_switch 			PDout( 2) = 1
#define Off_voice_switch 			PDout( 2) = 0

#define Open_led_switch 			PCout(12) = 1
#define Off_led_switch 				PCout(12) = 0

#define Open_reserve1_swtich		PCout(11) = 1
#define Off_reserve1_swtich 		PCout(11) = 0

#define Open_reserve2_switch 		PCout(10) = 1
#define Off_reserve2_switch			PCout(10) = 0

#define Open_reserve3_switch 		PAout(15) = 1
#define Off_reserve3_switch 		PAout(15) = 0
///****************************************************************/
void Current_Inout_Handle(void)
{
	switch(current_node.location2)
	{
		case Location_East1:				 /*	 东	*/
			{
			east1_control_t.trigger_vehicle1	  = current_node.trigger_vehicle1;
			east1_control_t.trigger_video2 	  = current_node.trigger_video2;
			east1_control_t.trigger_microwave3 = current_node.trigger_microwave3;
			east1_control_t.trigger_reserve1  = current_node.trigger_reserve1;
			}
			break;
		
		case Location_South2: 			    /*	南	*/
			{ 
			south2_control_t.trigger_vehicle1   = current_node.trigger_vehicle1;
			south2_control_t.trigger_video2 	   = current_node.trigger_video2;
			south2_control_t.trigger_microwave3 = current_node.trigger_microwave3;
			south2_control_t.trigger_reserve1  = current_node.trigger_reserve1;
			}
			break;
		case Location_West3:			   /*	西	*/
			{
			west3_control_t.trigger_vehicle1	  = current_node.trigger_vehicle1;
			west3_control_t.trigger_video2 	  = current_node.trigger_video2;
			west3_control_t.trigger_microwave3 = current_node.trigger_microwave3;
			west3_control_t.trigger_reserve1  = current_node.trigger_reserve1;
			}
			break;
		case Location_North4: 			    /*	北	*/
			{
			north4_control_t.trigger_vehicle1	  = current_node.trigger_vehicle1;
			north4_control_t.trigger_video2 	 	  = current_node.trigger_video2;
			north4_control_t.trigger_microwave3 	  = current_node.trigger_microwave3;
			north4_control_t.trigger_reserve1     = current_node.trigger_reserve1;
			}
			break;
		default:
			break;
	}
	switch(current_node.location2)
	{
		case Location_East1:				 /*	 东	*/
			{
			current_node.spikelamp_switch1 =  east1_control_t.spikelamp_switch1;
			current_node.voice_switch2	  =  east1_control_t.voice_switch2;
			current_node.led_switch3 	  =  east1_control_t.led_switch3;
			current_node.reserve1_switch  =  east1_control_t.reserve1_switch;
			current_node.reserve2_switch  =  east1_control_t.reserve2_switch;
			current_node.reserve3_switch  =  east1_control_t.reserve3_switch;
			}
			break;
		
		case Location_South2: 			    /*	南	*/
			{
			current_node.spikelamp_switch1  =  south2_control_t.spikelamp_switch1;
		 	current_node.voice_switch2	   =  south2_control_t.voice_switch2;
			current_node.led_switch3 	   =  south2_control_t.led_switch3;
			current_node.reserve1_switch   =  south2_control_t.reserve1_switch ;
			current_node.reserve2_switch   =  south2_control_t.reserve2_switch ;
			current_node.reserve3_switch   =  south2_control_t.reserve3_switch ;
			}
			break;
		case Location_West3:			   /*	西	*/
			{
			 current_node.spikelamp_switch1   =  west3_control_t.spikelamp_switch1;
			 current_node.voice_switch2 		 =  west3_control_t.voice_switch2;
			 current_node.led_switch3  		 =  west3_control_t.led_switch3;
			 current_node.reserve1_switch    =  west3_control_t.reserve1_switch;
			 current_node.reserve2_switch    =  west3_control_t.reserve2_switch ;
			 current_node.reserve3_switch    =  west3_control_t.reserve3_switch;
			}
			break;
		case Location_North4: 			    /*	北	*/
			{
			current_node.spikelamp_switch1  	 =  north4_control_t.spikelamp_switch1;
			current_node.voice_switch2 		 =  north4_control_t.voice_switch2;
			current_node.led_switch3 		 =  north4_control_t.led_switch3;
			current_node.reserve1_switch   	 =  north4_control_t.reserve1_switch;
			current_node.reserve2_switch   	 =  north4_control_t.reserve2_switch;
			current_node.reserve3_switch   	 =  north4_control_t.reserve3_switch;
			}
			break;
		default:
			break;
	}
//	if(current_node.spikelamp_switch1 == 1)
//	{
//		
//	}
//	if(current_node.voice_switch2 == 1)
//	{
//		
//	}
//	if(current_node.led_switch3 == 1)
//	{
//		
//	}
//	if(current_node.reserve1_switch == 1)
//	{
//		
//	}
//	if(current_node.reserve2_switch == 1)
//	{
//		
//	}
//	if(current_node.reserve3_switch == 1)
//	{
//		
//	}
}
void Sys_Inout_Handle()
{
	u8 i = 0;
	for (i = 1; i < NODE_ID_NUM_MAX; i++) 
	{	//! traverse the entire array which saves all the nodes 
		switch(node[i].location2)
		{
			case Location_East1:				 /*	 东	*/
				{

					east1_control_t.trigger_vehicle1   = node[i].trigger_vehicle1;

					east1_control_t.trigger_video2     = node[i].trigger_video2;

					east1_control_t.trigger_microwave3 = node[i].trigger_microwave3;

					east1_control_t.trigger_reserve1   = node[i].trigger_reserve1;
//					memcpy(&gITASMsg.payload.node[i-1], &node[i], sizeof(node_t));
				}
				break;
			
			case Location_South2: 			    /*	南	*/
				{ 

					south2_control_t.trigger_vehicle1   = node[i].trigger_vehicle1;

					south2_control_t.trigger_video2     = node[i].trigger_video2;

					south2_control_t.trigger_microwave3 = node[i].trigger_microwave3;

					south2_control_t.trigger_reserve1   = node[i].trigger_reserve1;
				}
				break;
			case Location_West3:			   /*	西	*/
				{

					west3_control_t.trigger_vehicle1	= node[i].trigger_vehicle1;

					west3_control_t.trigger_video2 = node[i].trigger_video2;

					west3_control_t.trigger_microwave3 = node[i].trigger_microwave3;

					west3_control_t.trigger_reserve1 = node[i].trigger_reserve1;
				}
				break;
			case Location_North4: 			    /*	北	*/
				{

					north4_control_t.trigger_vehicle1 = node[i].trigger_vehicle1;

					north4_control_t.trigger_video2 = node[i].trigger_video2;

					north4_control_t.trigger_microwave3 = node[i].trigger_microwave3;

					north4_control_t.trigger_reserve1 = node[i].trigger_reserve1;
				}
				break;
			default:
				break;
		}
	}
	
	east1_control_t.spikelamp_switch1   =  0;
	east1_control_t.voice_switch2	   =  0;
	east1_control_t.led_switch3 	  	   =  0;
	south2_control_t.spikelamp_switch1  =  0;
	south2_control_t.voice_switch2	   =  0;
	south2_control_t.led_switch3 	   =  0;
	west3_control_t.spikelamp_switch1   =  0;
	west3_control_t.voice_switch2	   =  0;
	west3_control_t.led_switch3 	       =  0;
	north4_control_t.spikelamp_switch1  =  0;
	north4_control_t.voice_switch2	   =  0;
	north4_control_t.led_switch3 	   =  0;

	if((east1_control_t.trigger_vehicle1||east1_control_t.trigger_video2)&&south2_control_t.trigger_microwave3)//AF  ①
	{
		east1_control_t.spikelamp_switch1   =  1;
		east1_control_t.voice_switch2	   =  1;
		east1_control_t.led_switch3 	  	   =  1;
		east1_control_t.reserve1_switch 	  	   =  1;
		
		south2_control_t.spikelamp_switch1  =  1;
		south2_control_t.voice_switch2	   =  1;
		south2_control_t.led_switch3 	   =  1;
		south2_control_t.reserve1_switch 	   =  1;
		
	}
	
	if((east1_control_t.trigger_vehicle1||east1_control_t.trigger_video2)&&north4_control_t.trigger_microwave3)//AH
	{
		east1_control_t.spikelamp_switch1   =  1;
		east1_control_t.voice_switch2	   =  1;
		east1_control_t.led_switch3 	  	   =  1;
		east1_control_t.reserve1_switch 	  	   =  1;
		
		north4_control_t.spikelamp_switch1  =  1;
		north4_control_t.voice_switch2	   =  1;
		north4_control_t.led_switch3 	   =  1;
		north4_control_t.reserve1_switch 	   =  1;
	}
	
	if((south2_control_t.trigger_vehicle1||south2_control_t.trigger_video2)&&east1_control_t.trigger_microwave3)//be
	{
		east1_control_t.spikelamp_switch1   =  1;
		east1_control_t.voice_switch2	   =  1;
		east1_control_t.led_switch3 	  	   =  1;
		east1_control_t.reserve1_switch 	  	   =  1;
		
		south2_control_t.spikelamp_switch1  =  1;
		south2_control_t.voice_switch2	   =  1;
		south2_control_t.led_switch3 	   =  1;
		south2_control_t.reserve1_switch 	   =  1;
	}
	
	if((south2_control_t.trigger_vehicle1||south2_control_t.trigger_video2)&&west3_control_t.trigger_microwave3)//bg
	{
		south2_control_t.spikelamp_switch1  =  1;
		south2_control_t.voice_switch2	   =  1;
		south2_control_t.led_switch3 	   =  1;
		south2_control_t.reserve1_switch 	   =  1;
		
		west3_control_t.spikelamp_switch1   =  1;
		west3_control_t.voice_switch2	   =  1;
		west3_control_t.led_switch3 	       =  1;
		west3_control_t.reserve1_switch 	       =  1;
	}
	
	if((west3_control_t.trigger_vehicle1||west3_control_t.trigger_video2)&&south2_control_t.trigger_microwave3)//cf
	{
		south2_control_t.spikelamp_switch1  =  1;
		south2_control_t.voice_switch2	   =  1;
		south2_control_t.led_switch3 	   =  1;
		south2_control_t.reserve1_switch 	   =  1;
		
		west3_control_t.spikelamp_switch1   =  1;
		west3_control_t.voice_switch2	   =  1;
		west3_control_t.led_switch3 	       =  1;
		west3_control_t.reserve1_switch 	       =  1;
	}
	
	if((west3_control_t.trigger_vehicle1||east1_control_t.trigger_video2)&&north4_control_t.trigger_microwave3)//cH
	{
		west3_control_t.spikelamp_switch1   =  1;
		west3_control_t.voice_switch2	   =  1;
		west3_control_t.led_switch3 	       =  1;
		west3_control_t.reserve1_switch 	       =  1;
		
		north4_control_t.spikelamp_switch1  =  1;
		north4_control_t.voice_switch2	   =  1;
		north4_control_t.led_switch3 	   =  1;
		north4_control_t.reserve1_switch 	   =  1;
	}
	
	if((north4_control_t.trigger_vehicle1||north4_control_t.trigger_video2)&&east1_control_t.trigger_microwave3)//de
	{
		east1_control_t.spikelamp_switch1   =  1;
		east1_control_t.voice_switch2	   =  1;
		east1_control_t.led_switch3 	  	   =  1;
		east1_control_t.reserve1_switch 	  	   =  1;
		
		north4_control_t.spikelamp_switch1  =  1;
		north4_control_t.voice_switch2	   =  1;
		north4_control_t.led_switch3 	   =  1;
		north4_control_t.reserve1_switch 	   =  1;
	}
	
	if((north4_control_t.trigger_vehicle1||north4_control_t.trigger_video2)&&west3_control_t.trigger_microwave3)//dg
	{
		west3_control_t.spikelamp_switch1   =  1;
		west3_control_t.voice_switch2	   =  1;
		west3_control_t.led_switch3 	       =  1;
		west3_control_t.reserve1_switch 	       =  1;
		
		north4_control_t.spikelamp_switch1  =  1;
		north4_control_t.voice_switch2	   =  1;
		north4_control_t.led_switch3 	   =  1;
		north4_control_t.reserve1_switch 	   =  1;
	}
	
//		switch(current_node.location2)
//		{
//		case Location_East1:				 /*	 东	*/
//			{
//			east1_control_t.trigger_vehicle1	  = current_node.trigger_vehicle1;
//			east1_control_t.trigger_video2 	  = current_node.trigger_video2;
//			east1_control_t.trigger_microwave3 = current_node.trigger_microwave3;
//			east1_control_t.trigger_reserve1  = current_node.trigger_reserve1;
//			}
//			break;
//		case Location_South2: 			    /*	南	*/
//			{ 
//			south2_control_t.trigger_vehicle1   = current_node.trigger_vehicle1;
//			south2_control_t.trigger_video2 	   = current_node.trigger_video2;
//			south2_control_t.trigger_microwave3 = current_node.trigger_microwave3;
//			south2_control_t.trigger_reserve1  = current_node.trigger_reserve1;
//			}
//			break;
//		case Location_West3:			   /*	西	*/
//			{
//			west3_control_t.trigger_vehicle1	  = current_node.trigger_vehicle1;
//			west3_control_t.trigger_video2 	  = current_node.trigger_video2;
//			west3_control_t.trigger_microwave3 = current_node.trigger_microwave3;
//			west3_control_t.trigger_reserve1  = current_node.trigger_reserve1;
//			}
//			break;
//		case Location_North4: 			    /*	北	*/
//			{
//			north4_control_t.trigger_vehicle1   = current_node.trigger_vehicle1;
//			north4_control_t.trigger_video2 	   = current_node.trigger_video2;
//			north4_control_t.trigger_microwave3 = current_node.trigger_microwave3;
//			north4_control_t.trigger_reserve1  = current_node.trigger_reserve1;
//			}
//			break;
//		default :
//			break;
//		}
//	east1_control_t.spikelamp_switch1;
//	south2_control_t.spikelamp_switch1;
//	west3_control_t.voice_switch2;
//	north4_control_t.reserve3_switch;
}

