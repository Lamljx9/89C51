#ifndef __LCD12864_H
#define __LCD12864_H
#include <reg52.h>

/* �궨�� */
#define LcdDataPort P2          // ���ݶ˿� P2

/* ���峣�ñ������� */
#ifndef __UCHAR_DEF
#define __UCHAR_DEF
typedef unsigned char u8;
typedef unsigned int u16;
#endif


/* λ�������� */
sbit Busy = P2^7;               // æ��־ BF λ -> BF=H���ڲ�����ִ�в���;BF=L������״̬
sbit Reset = P3^0;              // ��λ

sbit RS = P3^1;                 // ����\����ѡ��� -> �ߵ�ƽ������D0-D7��������ʾRAM���͵�ƽ������D0-D7������ָ��Ĵ���ִ��
sbit E = P3^2;                  // ��дʹ�ܣ��ߵ�ƽ��Ч���½�����������
sbit RW = P3^3;                 // ��\дѡ��� -> �ߵ�ƽ����ȡ���ݣ��͵�ƽ��д������

sbit CS1 = P3^4;                // Ƭѡ���ź�: �͵�ƽʱѡ��ǰ64�� ����Ļ
sbit CS2 = P3^5;                // Ƭѡ���ź�: �͵�ƽʱѡ���64�� ����Ļ



/* ����*/
void delay_ms(u16 xms);                                // ��ʱ����
void Check_Busy();                                     // LCD״̬���
void Write_Command(u8 command);                        // д����
void Write_Data(u8 dat);                               // д��ʾ����
void Select_Screen(u8 screen);                         // ѡ����Ļ
void Set_Line(u8 line);                                // ������ʾ��
void Set_Columm(u8 columm);                            // ������ʾ��
void Set_StartLine(u8 startline);                      // ������ʾ��ʼ��
void Clear_Screen(u8 screen);                          // ����
void On_Off(u8 onoff);                                 // ������ʾ����
void Lcd_Reset();                                      // ��λ

void Show_6464(u8 line,u8 columm,u8 *address);         // ��ʾһ��64*64ͼ��


void Lcd_Init();                                       // ��ʼ��

#endif




