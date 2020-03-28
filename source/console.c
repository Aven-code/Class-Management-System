#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "structure.h"




/*
	ϵͳ������Դ����
*/
 
/*��궨λ*/
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
	SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), pos);
}

/*��ȡ���*/
void getxy(int *x, int *y)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);
	*x = screen_buffer_info.dwCursorPosition.X;
	*y = screen_buffer_info.dwCursorPosition.Y;
}


/*�������*/
 void cursor_hide(void)
{
	CONSOLE_CURSOR_INFO cci;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}



// ��ȡ����
int get_key(void)
{
	if(_kbhit())	//����м�����
	{
		int ch=_getch();//����һ��ֵ
		if(ch ==0x0 || ch==0xe0)//�Ƿ�Ϊ����ֵ
		{
			ch=_getch();
			switch(ch)
			{
				case 0x48:
					return UP;
				case 0x50:
					return DOWN;
				case 0x4B:
					return LEFT;
				case 0x4D:
					return RIGHT;
				case 0x3F:
					return F5;
				default:
					return NONE;
			}
		}else	//ֻ��һ����ֵ
		{
			switch(ch)
			{
				case 0x8:
					return BACKSPACE;
				case 0x1b:
					return ESC;
				case 0x20:
					return SPACE;
				case 0xd:
					return ENTER;
				default:
					return NONE;
			}
		}
	}
	return NONE;
}


/*
	���ܣ�����ָ����Χ�������
	���������ֵ����Сֵ
	���أ�һ�������
*/
int random(int min,int max)
{
	int val;
	//srand((unsigned int)time(NULL));main��������Ҫ���õ�
	val=rand()%(max-min+1)+min;
	return val;
}



/*
	���ܣ�����1-49֮��������
	��������
	���أ� int�͵������
*/
int random2()
{
	return random(1,49);
}







/*
	���ܣ����Enter ��
	��������
	���أ������ֵΪ1 return 1
		
*/
int get_enter()
{
	int key;
	while(1){
		key=get_key();
		if(key==ENTER)
			break;
	}
	return 1;
}


/*
	���ܣ���ʾ���
	��������
	���أ���

*/

void cursor_show(void)
{
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


/*	
	���ܣ���ȡ����
	��������
	����: ��
*/
Date get_Time()
{
	time_t timep;		
	struct tm * p;
	Date val_t;

	time (&timep);
	p=gmtime(&timep);

	val_t.year=p->tm_year+1900;		//��ǰ��
	val_t.month=p->tm_mon+1;		//��ǰ��
	val_t.day=p->tm_mday;			//��ǰ�·�����

	return val_t;

}

/*
	���ܣ���ӡ����
*/
void printTime()
{	
	Date d=get_Time();
	printf("��ǰ����Ϊ��%2d-%2d-%2d\n",d.year,d.month,d.day);
}