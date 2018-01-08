#include <reg52.h>


/*************************************************************************
- Function    : �������ʵ��
- Description : ���¾������key1-key15 �������ʾ0-F
- Hardware    : λѡ - P2.7  ��ѡ - P2.6
- Author      : Y.
- Date        : 2017.12
 *************************************************************************/
 
 
/* ���峣�ñ������� */
typedef unsigned char u8;
typedef unsigned int u16;

/* ����λ���� */
sbit dula = P2^6;                // ����U2����������� ����ܶ�ѡ
sbit wela = P2^7;                // ����U3����������� �����λѡ

/* ����ȫ�ֱ��� */
u8 num;

u8 code table[] = {0x3f,0x06,0x5b,0x4f,      // ��������� ���
                   0x66,0x6d,0x7d,0x07,
                   0x7f,0x6f,0x77,0x7c,
                   0x39,0x5e,0x79,0x71};

/* �����Ӻ��� */		
void init();									   // ��ʼ������
void delay(u16);                 // ��ʱ����
void desplay(u8);                // �������ʾ����
void keyscan();                  // ����ɨ�躯��
				   
/*************************************************************************
 Function    : ������
 Description : None 
**************************************************************************/							 
void main()
{
	init();
	while (1)               
	{
		keyscan();              // ��ͣ���ü���ɨ�����
	}
}


/*************************************************************************
 Function    : ��ʱ�ӳ���
 Description : ��ʱX����ms
**************************************************************************/
void delay(u16 xms)
{
	u16 x,y;
	for (x = xms; x > 0; x--)
	{
		for (y = 125; y > 0; y--);
	}
}


/*************************************************************************
 Function    : ��ʼ������
 Description : None
**************************************************************************/
void init()
{
	dula = 1;
	P0 = 0x00;                     // ��ʼ�� �ر����ж�ѡ
	dula = 0;
	
	wela = 1;
	P0 = 0x00;                     // λѡ8�������
	wela = 0;
}


/*************************************************************************
 Function    : ��ʾ����
 Description : None
**************************************************************************/
void display(u8 num)
{
	dula = 1;
	P0 = table[num];               // ��ʾ����ֻ�Ͷ�ѡ����
	dula = 0;
}

/*************************************************************************
 Function    : �������ɨ�躯��
 Description : ��ɨ��
**************************************************************************/
void keyscan()
{
	u8 temp,key;
	
	/* ɨ����̵�һ�� */
	P3 = 0xfe;
	temp = P3;
	temp = temp & 0xf0;
	
	if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp & 0xf0;
			
		if(temp != 0xf0)
		{
			temp = P3;
					
			switch(temp)
			{
				case 0xee: key = 0; break;
				case 0xde: key = 1; break;
				case 0xbe: key = 2; break;
				case 0x7e: key = 3; break;
			}
						
			while(temp != 0xf0)                     // �ȴ���ť�ͷ�
			{
				temp = P3;
				temp = temp & 0xf0;
			}
						
			display(key);                          // ��ʾ����
	
		}
	}
		
	/* ɨ����̵ڶ��� */  
	P3 = 0xfd;
	temp = P3;
	temp = temp & 0xf0;
		
	if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp & 0xf0;
			
		if(temp != 0xf0)
		{
		temp = P3;
					
			switch(temp)
			{
				case 0xed: key = 4; break;
				case 0xdd: key = 5; break;
				case 0xbd: key = 6; break;
				case 0x7d: key = 7; break;
			}
						
			while(temp != 0xf0)                  
			{
				temp = P3;
				temp = temp & 0xf0;
			}
						
			display(key);
		}
	}		

	
	/* ɨ����̵����� */		
    P3 = 0xfb;
    temp = P3;
    temp = temp & 0xf0;
		
    if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp & 0xf0;
			
		if(temp != 0xf0)
		{
			temp = P3;
					
			switch(temp)
			{
				case 0xeb: key = 8; break;
				case 0xdb: key = 9; break;
				case 0xbb: key = 10; break;
				case 0x7b: key = 11; break;
			}
						
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
						
			display(key);
			}
	}	

	/* ɨ����̵����� */		
    P3 = 0xf7;
    temp = P3;
    temp = temp & 0xf0;
		
    if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp & 0xf0;
			
		if(temp != 0xf0)
		{
			temp = P3;
					
			switch(temp)
			{
				case 0xe7: key = 12; break;
				case 0xd7: key = 13; break;
				case 0xb7: key = 14; break;
				case 0x77: key = 15; break;
			}
						
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
						
			display(key);
		}
	}		
		
}