#ifndef __USER_SENSOR_H__
#define __USER_SENSOR_H__

#include <LPC17xx.h>
#include "stdint.h"


//ˮ�õ�״̬����
#define Pump_Normal     0 
#define Pipe_Blockage   1
#define Air_In_The_Pipe 2
#define Sensor_Failure  3

#define Press_Sensor_0 0
#define Press_Sensor_1 1

#define Data_Exists_Flag 0x55

#define State_Normal  0
#define State_Warning 1
#define State_Err     2



#define Temperature_Warning  110
#define Temperature_Err      130


//typedef __packed struct {
//	uint8_t save_flag; // 0x55 ��ʾ�в���, �����ʾ����û�в��� 
//	__packed struct {
//	uint8_t  need_cali_flag;// 0:��ʾ������������ҪУ׼; 1 ��ʾ�����쳣������У׼ 
//	uint16_t throttle_value_min; // ��С����ѹ����Ӧ������ֵ
//	uint16_t throttle_value_default;
//	uint16_t throttle_value_max;
//	uint16_t pressure_user; // �û��趨�Ĺ���ѹ��
//	}pressure_sensor0;
//	
//	__packed struct {
//	uint8_t  need_cali_flag;// 0:��ʾ������������ҪУ׼; 1 ��ʾ�����쳣������У׼ 
//	uint16_t throttle_value_min; // ��С����ѹ����Ӧ������ֵ
//	uint16_t throttle_value_default;
//	uint16_t throttle_value_max;
//	uint16_t pressure_user; // �û��趨�Ĺ���ѹ��
//	}pressure_sensor1;	
//}spray_system_pressure_cali_para_t;

/** ��Ҫ������ ���ײ��� **/
typedef __packed struct {
	uint8_t save_flag; // 0x55 ��ʾ�в���, �����ʾ����û�в��� 
	uint8_t  need_cali_flag;// 0:��ʾ������������ҪУ׼; 1 ��ʾ�����쳣������У׼ 
	uint16_t throttle_value_min; // ��С����ѹ����Ӧ������ֵ
	uint16_t throttle_value_default;
	uint16_t throttle_value_max;
	uint16_t pressure_user; // �û��趨�Ĺ���ѹ��
}spray_system_pressure_cali_para_t;



typedef __packed struct {
	uint8_t   save_flag; // 0x55 ��ʾ�в���, �����ʾ����û�в��� 
	uint8_t   cali_freq; // �궨��ʵʱ������
	uint16_t  capacity;// ����궨��ҩ�����
	uint32_t  cali_pulses; // �궨����������
	uint32_t  cali_time; // �궨����ʱ��

}spray_system_flow_cali_para_t;



#define WORKING_PRESSURE_MIN    		1260// ˮ�ù�������Сѹǿ 0.20MP ��Ӧ�� sensor  adc value 1450mv ����
#define WORKING_PRESSURE_MAX    		1750// ˮ�ù��������ѹǿ 0.33MP ��Ӧ�� sensor  adc value 1750mv ����
#define WORKING_PRESSURE_DEFAULT    1630// ˮ�ù����Ľ��鹤��ѹǿ 0.30MP ��Ӧ�� sensor  adc value 1660mv ����
//#define SLOPE_DEFAULT 71.45

#define MAX_SPRAY_ID 1
#define MIN_SPRAY_ID 2
#define DEBUG_FLOW_LEVEL

#define flow_cali_idle 0 
#define flow_cali_complted 1 
#define flow_cali_failed   2 
#define flow_cali_working  3

uint16_t get_buf_min_value(uint16_t buf[],uint16_t data_num);
uint16_t get_capacity_by_level_sensor(uint8_t liquid_level);
float get_temperature(uint16_t tempe_sensor_value);
//uint16_t get_capacity_by_potentiometer(uint16_t potentiometer_value);
void capacity_by_flow_sensor(void);
uint16_t get_press_value(uint8_t id);
float get_flow_value(uint16_t freq);
void press_sensor_handle(void);
uint16_t Set_FOC2_Value_By_Pressure1(uint16_t start_foc_value ,uint16_t target_pressure_value);
uint16_t Set_FOC1_Value_By_Pressure0(uint16_t start_foc_value ,uint16_t target_pressure_value);
void spray_system_press_para_init_check(void);
void spray_sysem_flow_para_init_check(void);
void flow2_calibration_process(void);

//uint8_t pressure_check_process(uint8_t sensor_id);// 10hz ����
void pressure1_calibration_process(void);// ѹ����У׼����
void pressure2_calibration_process(void);// ѹ����У׼����
//uint16_t flow_sensor_test(uint8_t run_flag); // 10hz
void level_sensor_init(void);
void level_data_process(void);
uint8_t get_capacity_flag_1L(void);
void set_flow_cali_flag(uint8_t state);
void Set_Spary_Limit_Value(uint8_t foc_id,uint8_t value_id ,uint16_t value );
uint16_t Get_Spary_Limit_Value(uint8_t foc_id,uint8_t value_id);
void set_cali_capaciy(uint16_t value);
uint16_t get_current_capacity_d(void);
uint8_t get_flow_value_total(void);
void Set_Volume_Each_Pulse(float value);
void flow1_calibration_process(void);
void flow2_calibration_process(void);
uint8_t Get_XT100_State(void);
uint8_t Get_XT90_State(void);
void temperature_sensor_handle(void);
void spray_residual_volume_init_check(void);
void set_MedeRunoutFlag(uint8_t state);
uint8_t get_pump1_state(void);
uint8_t get_pump2_state(void);
#define User_Max_Throttle 1700
//extern uint8_t pipe_status;
#endif
