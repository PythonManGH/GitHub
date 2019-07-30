#pragma once


/** @brief Macro Definition */
#define       PB01_ENDPOINT        "inproc://ps01"      // ��򵥵�����Ӧ��ģʽ
#define       ZP01PS_ENDPOINT      "inproc://zp01ps"    // zmq_poll 
#define       ZP01RR_ENDPOINT      "inproc://zp01rr"    // zmq_poll

#define       PSDEVICE_FRONT       "inproc://pub_sub_front"             // װ�õ�ǰ�˶˵�
#define       PSDEVICE_BACE        "inproc://pub_sub_back"              // װ�õĺ�˶˵� 

#define       PSENVELOPE           "inproc://envelope"                  // �ŷ�



/** @brief Rep-Req ���*/
#define      RR01              "inproc://rr01"                 // �򵥵�����Ӧ��
#define      RR02_FRONT        "inproc://rr02_front"           // ��װ�õ�����Ӧ��
#define      RR02_BACK         "inproc://rr02_back"            // ��װ�õ�����Ӧ��



/** @brief Global variable */
extern void*  gContext;