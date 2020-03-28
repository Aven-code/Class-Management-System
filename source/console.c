#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "structure.h"




/*
	系统函数的源代码
*/
 
/*光标定位*/
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
	SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), pos);
}

/*获取光标*/
void getxy(int *x, int *y)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);
	*x = screen_buffer_info.dwCursorPosition.X;
	*y = screen_buffer_info.dwCursorPosition.Y;
}


/*光标隐藏*/
 void cursor_hide(void)
{
	CONSOLE_CURSOR_INFO cci;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}



// 获取按键
int get_key(void)
{
	if(_kbhit())	//如果有键按下
	{
		int ch=_getch();//保存一个值
		if(ch ==0x0 || ch==0xe0)//是否为两个值
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
		}else	//只有一个键值
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
	功能：产生指定范围的随机数
	参数：最大值和最小值
	返回：一个随机数
*/
int random(int min,int max)
{
	int val;
	//srand((unsigned int)time(NULL));main函数中需要调用的
	val=rand()%(max-min+1)+min;
	return val;
}



/*
	功能：产生1-49之间的随机数
	参数：无
	返回： int型的随机数
*/
int random2()
{
	return random(1,49);
}







/*
	功能：获得Enter 键
	参数：无
	返回：如果键值为1 return 1
		
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
	功能：显示光标
	参数：无
	返回：无

*/

void cursor_show(void)
{
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


/*	
	功能：获取日期
	参数：无
	返回: 无
*/
Date get_Time()
{
	time_t timep;		
	struct tm * p;
	Date val_t;

	time (&timep);
	p=gmtime(&timep);

	val_t.year=p->tm_year+1900;		//当前年
	val_t.month=p->tm_mon+1;		//当前月
	val_t.day=p->tm_mday;			//当前月份日数

	return val_t;

}

/*
	功能：打印日期
*/
void printTime()
{	
	Date d=get_Time();
	printf("当前日期为：%2d-%2d-%2d\n",d.year,d.month,d.day);
}