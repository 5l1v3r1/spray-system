/**
  ******************** (C) COPYRIGHT 2011 DJI **********************************
  *
  * @Project Name       : WKM2_CAN_LOADER.uvproj
  * @File Name          : can_def.h
  * @Environment        : keil mdk4.12/LPC1765/100M cclock
  * @Author&Date        : 2011-10-17
  * @Version            : 1.10
  ******************************************************************************
  * @Description
  *
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAN_DEF_H__
#define __CAN_DEF_H__

#include "../drivers/drivers_def.h"

/* public define -------------------------------------------------------------*/
/* can buffer size */
#define  A2  1
#define  A3  2

#define  FC_TYPE  A2

#define CAN_BUFSIZE	          (512)	      /* ������2��n���� */

/* unpack can package in ISR or task tick */
#define UNPACK_ON_ISR         (0)

/* ������ص�ID�Ŷ��� */
//��̨����ID
//#define CAN1_RX_ID3		  (0x0417)
//�������ID  
//define CAN1_RX_ID		    (0x0417)
#define UPGRADE_RX_FARMING_BOARD_ID	   (0x04fa)
#define UPGRADE_TX_FARMING_BOARD_ID	   (0x05fa)


//����LightBridge(��̨�����)
#define CAN1_RX_ID		  (0x0412)
//����CAN id �������� 
#define CAN1_UPGRADE_ID		(UPGRADE_RX_FARMING_BOARD_ID)

#if FC_TYPE==A2
//�ɿؽ���ID  617
#define CAN1_RX_ID2		  (0x0617) // ��ID   ��һ�� 0x519 

//���ͳ��������ݵ� �ɿ�ID V0   0xA3 radar->MC  0xA2 mc->radar 
#define CAN1_TX_ID2       (0x0095)
#else 
#define CAN1_RX_ID2		  (0x0519)
#define CAN1_TX_ID2     (0x00A3)

#endif

//��OFDM��ID (�ư���Ϣ��
#define CAN1_TX_ID		  (0x0413)  


//����ҩ����Ϣ��//���ɿ�
#define CAN1_TX_ID3       (0x0616) // ��ID

//�����ذ����ư�� CANID
#define CAN1_UPGRADE_ACK_ID  (UPGRADE_TX_FARMING_BOARD_ID )

//���İ��LED֮���CAN ID
#define CAN1_TX_LED_ID      (0xA1)

// ���������״��Һλsensor ����
#define CAN1_RX_RADAR      (0x180)

#define CAN2_RX_ID		    (0x0517)
#define CAN2_TX_ID		    (0x0412)

/*******************  (C) COPYRIGHT 2011 DJI ************END OF FILE***********/
#endif
