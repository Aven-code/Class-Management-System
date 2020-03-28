#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>
#include "mlayout.h"
#include "structure.h"
#include "account.h"

int INDEX=1;				//数组的下标
int listIndex=2;			//链表存储数组的下标
int X1=10;					//界面的宽
int Y1=10;					//界面的高
int FLAG=0;					//超级用户登录标记
int SIGN=1;					//普通用户登录标记
char USERNAME[USNLEN]="临时用户";	//普通用户的用户名


void sytheside();


int main(void)
{
	
#if 1

	srand((unsigned int)time(NULL)); //随机函数
	
	sytheside();//开始
#else	
	//studentTable(1,1);
	table(0,5,28,1);

#endif
	return 0;
}



/*
	功能:综合函数
*/

void sytheside()
{
	int index;
	print_check(0);		//界面
	cursor_hide();	//隐藏光标
	printf("\n\n\n\n\t按下“Enter”键进入系统···");
	get_enter();
	initTreeArrays();	//初始化
	index=print_check(1);
	for(;;)	//死循环
	{
		index=print_check(index);
		
	}


};