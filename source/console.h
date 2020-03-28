#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <Windows.h>
#include "structure.h"

// ����Ƶ�ָ��λ��
void gotoxy(int x, int y);

//��ȡ���λ��
void getxy(int *x, int *y);

//���ع��
 void cursor_hide(void);


 // ��ȡ����
int get_key(void);

// �������õ��İ���ö��ֵ
enum key
{
	NONE		= 0x0000,  // û�м�����
	ESC			= 0x001b,	//���ؼ�
	UP			= 0xE048,  // �ϼ�ͷ
	DOWN		= 0xE050,  // �¼�ͷ
	LEFT		= 0xE04B,  // ���ͷ
	RIGHT		= 0xE04D,  // �Ҽ�ͷ
	SPACE		= 0x0020,   //�ո��
	ENTER		= 0x00d,
	F5			= 0x03F,	//�س�
	BACKSPACE	= 0x008		//�˸�
};


/*
	���ܣ�����ָ����Χ�������
	���������ֵ����Сֵ
	���أ�һ�������
*/
int random(int min,int max);

/*
	���ܣ�����1-49֮��������
	��������
	���أ� int�͵������
*/
int random2();



/*
	���ܣ����Enter��
*/
int get_enter();



/*
	���ܣ���ʾ���
	��������
	���أ���
*/
void cursor_show(void);


/*	
	���ܣ���ȡʱ��
	��������
	����: ��
*/
Date get_Time();



/*
	���ܣ���ӡ����
*/
void printTime();




#endif