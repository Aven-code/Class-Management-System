#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <Windows.h>
#include "structure.h"

// 光标移到指定位置
void gotoxy(int x, int y);

//获取光标位置
void getxy(int *x, int *y);

//隐藏光标
 void cursor_hide(void);


 // 获取按键
int get_key(void);

// 程序中用到的按键枚举值
enum key
{
	NONE		= 0x0000,  // 没有键按下
	ESC			= 0x001b,	//返回键
	UP			= 0xE048,  // 上箭头
	DOWN		= 0xE050,  // 下箭头
	LEFT		= 0xE04B,  // 左箭头
	RIGHT		= 0xE04D,  // 右箭头
	SPACE		= 0x0020,   //空格键
	ENTER		= 0x00d,
	F5			= 0x03F,	//回车
	BACKSPACE	= 0x008		//退格
};


/*
	功能：产生指定范围的随机数
	参数：最大值和最小值
	返回：一个随机数
*/
int random(int min,int max);

/*
	功能：产生1-49之间的随机数
	参数：无
	返回： int型的随机数
*/
int random2();



/*
	功能：获得Enter键
*/
int get_enter();



/*
	功能：显示光标
	参数：无
	返回：无
*/
void cursor_show(void);


/*	
	功能：获取时间
	参数：无
	返回: 无
*/
Date get_Time();



/*
	功能：打印日期
*/
void printTime();




#endif