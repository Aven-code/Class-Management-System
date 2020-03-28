/*
	此文件写的是：
		关于界面的布局
		每个位所实现的功能函数

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"
#include "mlayout.h"
#include "console.h"
#include "structure.h"
#include "account.h"


extern int X1;
extern int Y1;
extern int FLAG;
extern int SIGN;
extern char USERNAME[USNLEN];

/*
	边框画出来,将x,y轴定死
*/

void border()
{
	int x=0,y=0;
	int i,j;
	//原色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	
	//打印第一行的x轴
	for(i=x;i<=X1+x+1;i++)
	{
		/*
			这里是以格子数目来花边，受于字符串限制，格子只能莫名*2
		*/
		
		if(i==x){
			gotoxy(i,y);	
			printf("┏");
			continue;
		}

		if(i==X1+x+1){
			printf("┓");
			continue;
		}

		printf("━");
		
	}


	/*输出第一列Y轴*/
	for(j=y+1;j<=Y1+y;j++)
	{
		gotoxy(x,j);
		printf("┃");
	
	}


	/*输出第二列的Y轴，与第一列的Y轴一样，所以循环次数一样*/
	for(j=y+1;j<=Y1+y;j++)
	{
		gotoxy(X1*2+2+x,j);
		printf("┃");
	}


	/*输出第第二行的X轴，与第一行的X轴一样，只是y轴变了，但循环次数是一样的*/
	for(i=x;i<=X1+x+1;i++)
	{
		/*
			这里是以格子数目来花边，受于字符串限制，格子只能莫名*2
		*/
		if(i==x){
			gotoxy(i,Y1+y+1);	
			printf("┗");
			continue;
		}
	
		if(i==X1+x+1){
				printf("┛");
				continue;
		}
	
		printf("━");
	}


	//原色
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

}

/*
	定位，清除箭头
*/

void clear(int x,int y)
{	
	
	gotoxy(x,y);
	printf("\040\040");
	
}

/*
	定位，输出箭头
*/
void output(int x,int y)
{
	gotoxy(x,y);
	//青色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("→ ");	
	//原色
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}


/*
	班级管理系统字符画
*/

void home(){

	system("cls");
	
	printf("　　　 　　　 \\\\\\\|/// \n");
	printf("　　       \\\\　.-.-　// \n");
	printf("	  　(　.@.@　) \n");
	printf("+-------oOOo-----(_)-----oOOo---------+ \n|　　　 　　　　　　　　　	      |");
	printf("\n|　   　班  级  管  理  系  统        | \n|　　　　　  　　  　　      　　   　|");
	printf("\n+---------------------Oooo------------+");		
	printf("\n");
	

}

/*
	功能：实现1号位的功能，打印A，返回一个选择了哪一个的下标——班级管理系统
	返回值：返回选择了的下标
*/
int listA(int sub){
	int x=6,y=1;
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;			//最大的度
	int key=0;
	system("cls");
	border();		//打印边框

	
	/*标题提示*/
	warn(3,x-4,y,"班级管理系统");


	gotoxy(x,y+=2);
	printf("注册管理");

	gotoxy(x,y+=2);
	printf("登录管理");
	
	gotoxy(x,y+=2);
	printf("退出系统");

	
	output(arrowsX,arrowsY);//箭头指向第一个度

		
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{
		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}



		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}
		
	gotoxy(0,20);
	printf("当前pos:%d",pos);

	gotoxy(0,21);
	printf("当前第一个度的下标:%d",Tree[sub].firstChild->index);
	
	gotoxy(0,22);
	printf("当前Maxchild:%d",maxChild);


	}

	return pos;

}


/*
	功能：实现2号位的功能，打印B，返回一个选择了哪一个的下标——注册管理
	返回值：返回选择了的下标
*/
int listB(int sub)
{
	
	int x=6,y=1;						 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;		//最大的度
	int key=0;
	system("cls");
	
	border();		//打印边框

	
	/*标题提示*/
	warn(3,x-4,y,"管理员权限");


	
	gotoxy(x,y+=2);
	printf("管理员登录入口");

	gotoxy(x,y+=2);
	printf("注册新用户");
	
	gotoxy(x,y+=2);
	printf("删除用户");
	
	
	
	output(arrowsX,arrowsY);//箭头指向第一个度
	
		
		
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{
		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			return pos;
		}







		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}


		gotoxy(0,20);
		printf("当前pos:%d",pos);

		gotoxy(0,21);
		printf("当前第一个度的下标:%d",Tree[sub].firstChild->index);
	
		gotoxy(0,22);
		printf("当前Maxchild:%d",maxChild);


	}

	return pos;
}


/*
	功能：	实现3号位的功能，打印C，返回一个选择了哪一个的下标——登录管理
	返回值：返回选择了的下标
*/
int listC(int sub)
{
	
	int x=6,y=1;							 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;			//最大的度
	int key=1;
	system("cls");
	
	border();		//打印边框

	
	
	/*标题提示*/
	warn(3,x-4,y,"登录管理");


	if(SIGN)
	{
		//绿色高光
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		gotoxy(x,y+=2);
		printf("已登录√");
		//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		
	}else
	{
		gotoxy(x,y+=2);
		printf("登录账号");
		
	}
	gotoxy(x,y+=2);
	printf("修改密码");
	
	if(SIGN)
	{
	
		gotoxy(x,y+=2);
		printf("退出登录");
	}

	if(!SIGN)//如果没登录
	{
		maxChild-=1;	//不显示退出登录选项
	}

	output(arrowsX,arrowsY);//箭头指向第一个度

		
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{


		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			return pos;
		}

	

		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1 )
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}
		

		/*后期可扩展为温馨提示*/
		gotoxy(0,20);
		printf("当前pos:%2d",pos);

		gotoxy(0,21);
		printf("当前第一个度的下标:%2d",Tree[sub].firstChild->index);
	
		gotoxy(0,22);
		printf("当前Maxchild:%2d",maxChild);


	}

	return pos;
}

/*
	实现4号位的功能——退出系统
*/
int quit(){
	int x=6,y=1;						 //x，y 是标题的坐标
	
	int key;
	system("cls");
	X1=18;
	Y1=8;


	border();	

	//红色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
		//打印边框
	gotoxy(x,y);
	printf("\b\b\b\b是否退出系统？\n");
	//原色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	
	gotoxy(x+1,y+3);
	printf("（Enter确认/ESC取消）");
	
	
	gotoxy(x+1,y+4);		//光标下移
	while(1)
	{
		key=get_key();
		
		if(key==ESC)	//收到ESC键返回上一步
		{
			X1=10;
			Y1=10;
			return 1;
		}else if(key==ENTER){
						
			exit(0);	//退出系统
		}

	}

}


/*
	实现8号位的功能——登录用户	，后期再进行判断登录，这里写好登录成功的效果
*/
int listD(int sub)
{
	
	int x=6,y=1;						 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;				//箭头指向的选项
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;		//最大的度
	int key=0;
	system("cls");

	if(SIGN)//表示已登录
	{

		border();		//打印边框
		/*紫色高光*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		gotoxy(x,y);
		printf("\b\b\b\b:-)Hi.%s",USERNAME);
		//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

		gotoxy(x,y+=2);
		printf("班级管理");

		gotoxy(x,y+=2);
		printf("学生管理");

		gotoxy(x,y+=2);
		printf("活动管理");

		gotoxy(x,y+=2);
		printf("考勤管理");

		output(arrowsX,arrowsY);//箭头指向第一个度
	

		
		/*
			判断按键
		*/
		while(key!=ENTER  && key!=RIGHT)
		{
			key=get_key();

			if(key==ESC)		//直接退出到退出系统项
			{
				return 4;
			}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				return pos;
			}

			if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
				++pos;
				clear(arrowsX,arrowsY);
				output(arrowsX,arrowsY+=2);
			
			}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
			{
				pos--;
				clear(arrowsX,arrowsY);
				output(arrowsX,arrowsY-=2);
			
			}

			/*后期可扩展为温馨提示*/
			gotoxy(0,20);
			printf("当前pos:%2d",pos);

			gotoxy(0,21);
			printf("当前第一个度的下标:%2d",Tree[sub].firstChild->index);
	
			gotoxy(0,22);
			printf("当前Maxchild:%2d",maxChild);

		}

	}
	/*
		未登录，需要调用验证函数8#
	*/
	else
	{
		return checkUser(x,y,sub);
	}


	return pos;
}

/*
	实现11号位功能：打印E——班级管理
*/

int listE(int sub)
{
	
	int x=6,y=1;						 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;		//最大的度
	int key=0;
	
	system("cls");
	
	border();		//打印边框

	
	/*标题提示*/
	warn(3,x-4,y,"班级管理");


	
	gotoxy(x,y+=2);
	printf("注册班级");

	gotoxy(x,y+=2);
	printf("修改班级信息");
	
	gotoxy(x,y+=2);
	printf("查询班级信息");

	gotoxy(x,y+=2);
	printf("删除班级");

	output(arrowsX,arrowsY);//箭头指向第一个度
	


		
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{
		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			return pos;
		}




		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}
		

		/*后期可扩展为温馨提示*/
		gotoxy(0,20);
		printf("当前pos:%d",pos);

		gotoxy(0,21);
		printf("当前第一个度的下标:%d",Tree[sub].firstChild->index);
	
		gotoxy(0,22);
		printf("当前Maxchild:%d",maxChild);


	}

	return pos;

}


/*
	实现12号位功能：打印F——学生管理
*/

int listF(int sub)
{
	
	int x=6,y=1;							 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;			//最大的度
	int key=0;
	
	system("cls");
	
	border();		//打印边框

	
	/*标题提示*/
	warn(3,x-4,y,"学生管理");


	
	gotoxy(x,y+=2);
	printf("新增学生");

	gotoxy(x,y+=2);
	printf("修改学生信息");
	
	gotoxy(x,y+=2);
	printf("查询学生信息");

	gotoxy(x,y+=2);
	printf("删除学生");

	output(arrowsX,arrowsY);//箭头指向第一个度
	


		
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{
		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			return pos;
		}



		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}
		

		/*后期可扩展为温馨提示*/
		gotoxy(0,20);
		printf("当前pos:%d",pos);

		gotoxy(0,21);
		printf("当前第一个度的下标:%d",Tree[sub].firstChild->index);
	
		gotoxy(0,22);
		printf("当前Maxchild:%d",maxChild);


	}

	return pos;

}


/*
	实现13号功能：打印G——活动管理
*/

int listG(int sub)
{
	
	
	int x=6,y=1;							 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;			//最大的度
	int key=0;
	
	system("cls");
	
	border();		//打印边框

	/*标题提示*/
	warn(3,x-4,y,"活动管理");

	gotoxy(x,y+=2);
	printf("抽取演讲者");

	gotoxy(x,y+=2);
	printf("预备演讲者");
	
	gotoxy(x,y+=2);
	printf("演讲内容简记");

	gotoxy(x,y+=2);
	printf("演讲情况浏览");

	output(arrowsX,arrowsY);//箭头指向第一个度
	


		
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{
		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			return pos;
		}



		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}
		

		/*后期可扩展为温馨提示*/
		gotoxy(0,20);
		printf("当前pos:%d",pos);

		gotoxy(0,21);
		printf("当前第一个度的下标:%d",Tree[sub].firstChild->index);
	
		gotoxy(0,22);
		printf("当前Maxchild:%d",maxChild);


	}

	return pos;

}


/*
	实现14号功能：打印H——考勤管理
*/
int listH(int sub)
{
	
	
	int x=6,y=1;							 //x，y 是标题的坐标
	int arrowsX=3,arrowsY=3;
	int pos=Tree[sub].firstChild->index;	//获得首个度的下标
	int maxChild=Tree[sub].number;			//最大的度
	int key=0;
	
	system("cls");
	
	border();		//打印边框

	/*标题提示*/
	warn(3,x-4,y,"考勤管理");


	
	gotoxy(x,y+=2);
	printf("记录考勤");

	gotoxy(x,y+=2);
	printf("更改考勤");
	
	gotoxy(x,y+=2);
	printf("查询考勤");

	gotoxy(x,y+=2);
	printf("考勤记录删除");

	output(arrowsX,arrowsY);//箭头指向第一个度
	

	
	/*
		判断按键
	*/
	while(key!=ENTER  && key!=RIGHT)
	{
		key=get_key();

		if(key==ESC)		//直接退出到退出系统项
		{
			return 4;
		}else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			return pos;
		}



		if(key==DOWN && pos < Tree[sub].firstChild->index+maxChild-1){
			++pos;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY+=2);
			
		}else if(key==UP && pos>=Tree[sub].firstChild->index+1)
		{
			pos--;
			clear(arrowsX,arrowsY);
			output(arrowsX,arrowsY-=2);
			
		}
		

		/*后期可扩展为温馨提示*/
		gotoxy(0,20);
		printf("当前pos:%d",pos);

		gotoxy(0,21);
		printf("当前第一个度的下标:%d",Tree[sub].firstChild->index);
	
		gotoxy(0,22);
		printf("当前Maxchild:%d",maxChild);


	}

	return pos;

}


/*登录错误字符画*/

void errorLogin(int x,int y)
{
	//红色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	gotoxy(x,y);
	printf("    _    _");
	gotoxy(x,y++);
	printf("   (o)--(o)");
	gotoxy(x,y++);
	printf("  /.______.\\");
	gotoxy(x,y++);
	printf("  \\________/");
	gotoxy(x,y++);
	printf(" ./登录失败\.");
	gotoxy(x,y++);
	printf("( .(");
	//绿色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("Enter");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf(") . )");
	gotoxy(x,y++);
	printf(" \\ \\_\\\\//_/ /");
	gotoxy(x,y++);
	printf("  ~~  ~~  ~~");
		
	//原色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

/*登录成功字符画*/

void succeedLogin(int x,int y)
{
	//绿色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	gotoxy(x,y);
	printf("    _    _");
	gotoxy(x,y++);
	printf("   (0)--(0)");
	gotoxy(x,y++);
	printf("  /°    °\\");
	gotoxy(x,y++);
	printf("  \\___□___/");
	gotoxy(x,y++);
	printf(" ./登录成功\\.");
	gotoxy(x,y++);
	printf("( .(");
	//红色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("Enter");
	//绿色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf(") . )");
	gotoxy(x,y++);
	printf(" \\ \\_\\\\//_/ /");
	gotoxy(x,y++);
	printf("  ~~  ~~  ~~");
	//原色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}


/*	
	功能：温馨提示
	参数：输入xy轴坐标，方便打印,i表示那部分功能的温馨提示。 1：表示注册、2：删除,3:修改密码
	返回：返回当前y轴坐标的值
*/
int prompt(int x,int y,int i)
{
	/*紫色高光*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	
	if(i==1)
	{
		gotoxy(x,y++);
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		gotoxy(x,y++);
		printf("提示：");
		gotoxy(x,y++);
		printf("Enter键输入，返回“BACKSPACE”、“←”.");
		gotoxy(x,y++);
		printf("用户名最多14个字符（一个中文字符算两个），密码最多8位.");
		gotoxy(x,y++);
		printf("注册时用户名不得相同，注册（成功/失败）使用F5刷新.");
	}
	else if(i==2)
	{
		gotoxy(x,y++);
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		gotoxy(x,y++);
		printf("提示：");
		gotoxy(x,y++);
		printf("删除完成，回车进行下一个账户的注销，取消注销.");
		gotoxy(x,y++);
		printf("Enter键输入，返回“BACKSPACE”、“←”.");
		gotoxy(x,y++);
		printf("当没有用户时将不能进行注销；注意注销账号的格式.");
	
	}else if(i==3)
	{
		gotoxy(x,y++);
		printf("━━━━━━━━━━━━━━━━");
		gotoxy(x,y++);
		printf("提示：");
		gotoxy(x,y++);
		printf("旧密码不得和新密码相同.");
		gotoxy(x,y++);
		printf("新密码不得出现空字符.");
		gotoxy(x,y++);
		printf("Enter键输入，返回“BACKSPACE”、“←”.");
	
	}

	//原色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

	return y;
}



/*
	功能：打印表格
	参数：x轴与y轴，高度与宽度
	返回：无返回
*/

void table(int x,int y,int width_max,int heigh_max)
{	
	
	int i;//保存一个 x，y 初始值
	int x1,y1;
	x1=x;
	for(i=1;i<width_max;i++,x1+=2) //打印宽度，顶部x轴上的移动
	{
		gotoxy(x1,y);
		if(i==1)
		{
			printf("┌");
		}
		printf("─");
	}
	printf("┐");
	

	y1=++y;

	for(i=0;i<heigh_max;i++,y1++) //打印高度，左边y轴上的移动
	{
		gotoxy(x,y1);
		printf("│");
	}
	
	
	for(i=0;i<heigh_max;y++,i++)//打印高度，右边y轴上的移动
	{
		gotoxy(x1,y);
		printf("│");
	}
	
	for(i=1;i<width_max;x+=2,i++) //打印宽度，底部x轴上的移动
	{
		gotoxy(x,y);
		if(i==1)
		{
			printf("└");
		}
		printf("─");
	}
	printf("┘");
	
}


/*
	功能：打印内容待开发
	参数：传入本级别坐标
	返回：返回当前上级

*/
int waitExploit(int sub)
{
	int key;
	system("cls");
	table(1,1,15,10);
	warn(2,7,5,"功能待开发...");
	warn(3,4,7,"(“←”or“BACKSPACE”)");
	while(1)
	{
		key=get_key();
		if(key==ENTER || key==LEFT || key==ESC)
		{
			return Tree[sub].parent;
		}
	}
}


/*
	功能： 打印学生列表的格式(相当于封装一遍table函数，以学生格式)
	参数：x,y 从xy轴哪个点开始画
	返回：无返回
*/
void studentTable(int x,int y)
{	

	int x1=3+x,y1=1+y;
	int width=5,height=1;
	
	table(x,y,width,height);
	gotoxy(x1,y1);
	printf("学号");

	table(x,y,width+=4,height);
	gotoxy(x1+=7+1,y1);
	printf("姓名");

	table(x,y,width+=4,height);
	gotoxy(x1+=7+1,y1);
	printf("性别");

	table(x,y,width+=4,height);
	gotoxy(x1+=7+1,y1);
	printf("籍贯");
	
	table(x,y,width+=6,height);
	gotoxy(x1+=7+1,y1);
	printf("出生年月");
	
	table(x,y,width+=5,height);
	gotoxy(x1+=7+5,y1);
	printf("咨询师");

	
}