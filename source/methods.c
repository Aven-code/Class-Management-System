#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"
#include "mlayout.h"
#include "console.h"

/*
	该文件写的是一些
	实现实质功能的函数（而不是打印界面）
*/


#include "structure.h"
#include "account.h"	//关于登陆用户
#include "student.h"	//关于学生


#define SLEN 10	//管理员名和密码的长度
#define VERIFY 3 //验证码答案长度

extern int X1;
extern int Y1;
extern int FLAG;
extern int SIGN;
extern char USERNAME[USNLEN];


/*
	测试链表长度
*/
int countLength(Node np)
{
	int count=0;
	Node stemp=np;
	while(stemp)
	{
		count++;
		stemp=stemp->next;
	}
	return count;
}

/*
	打印链表的值
*/
void printVal(Node np)
{
	int i=1;
	Node stemp=np;
	while(stemp)
	{
		
		printf("N o.%d:%d\n",i,stemp->index);
		stemp=stemp->next;
		i++;
	}
}



/*
	功能：获取字符串
*/
char * sget_s(char * str,int n)
{
	char * ret_val,* find;
	if(ret_val=fgets(str,n,stdin))
	{
		if(find=strchr(str,'\n'))
			*find='\0';
		else 
			while(getchar()!='\n')
				continue;
	}

	return ret_val;
}


/*
	实现5号位的功能——超级用户登录
*/
int superUser(int sub)
{
	int key;
	int x=6,y=1;
	char username[SLEN];
	char password[SLEN];
	system("cls");
	X1=30;		//只改变界面的宽度

	border();	
	/*如果已登录*/
	if(FLAG){	

		//标题提示
		warn(3,x-4,y,"当前账户已登录√");
		
		gotoxy(x+14,y+3);
		printf("是否退出当前管理员账户");
		gotoxy(x+14,y+5);
		printf("（Enter确认/ESC取消）");
		/*判断是否退出*/
		while(1)
			{
				key=get_key();
				if(key==ESC)	//收到ESC键返回上一步
				{
					X1=10;
					return Tree[sub].parent;
				}else if(key==ENTER){
					FLAG=0;		//标记清零
					return sub;	//刷新当前页（重新调用一遍当前函数）
				}
			}

		}

	/*未登录*/
	else
	{			
		/*标题提示*/
		warn(3,x-4,y,"登录管理员用户（取消ESC,Enter显示）");
	
		
		/*判断用户是否取消*/
		for(;;){
			key=get_key();
			if(key==ESC)	//收到ESC键返回上一步
				{
					X1=10;
					return Tree[sub].parent;
				}
			else if(key==ENTER)
				break;
		}

		cursor_show();	//光标显示

		/*打印管理员账户*/
		gotoxy(x+14,y+3);
		printf("账	户：");
		sget_s(username,SLEN);
		
		/*打印管理员密码*/
		gotoxy(x+14,y+5);
		printf("密	码：");
		sget_s(password,SLEN);
		cursor_hide();		//光标隐藏
		
		
		
		

		if(strcmp(username,"Admin")!=0 || strcmp(password,"123456")!=0 )//输入错误
		{
			system("cls");
			border();	
			
			/*标题提示*/
			warn(3,x-4,y,"登录管理员用户");
			
			/*失败青蛙字符*/
			errorLogin(x+16,y+2);
			while(!get_enter())//获得Enter建
				continue;

			return sub;	//直接退出重来
		}
		else															//输入正确
		{
			FLAG=1;
			system("cls");
			border();	

			/*标题提示*/
			warn(3,x-4,y,"登录管理员用户");
	
			/*成功青蛙字符*/
			succeedLogin(x+16,y+2);
			while(!get_enter())//获得Enter建
				continue;
			X1=10;
			return Tree[sub].parent;//返回上一级
						
		}

	}

}


/*
	实现6号位的功能——注册新用户
*/
int addUser(int sub)
{
	/*与注册相关变量*/
	int i,count,length;	//临时变量
	account e;			//暂存元素
	list_acc list;		//声明链表类型变量
	node_pacc pnode;	//节点指针
	FILE * puser;		//文件指针
	int size;			//结构体大小

	
/*end----------------------*/


	int key,pos=0;
	int x=6,y=1;
	system("cls");
	
	if(!FLAG)
	{	/*如果未登录管理员*/
		gotoxy(x+4,y+2);

		printf("注册新账号需要管理员权限，请登录管理员账号！");
		X1=30;
		Y1=5;
		border();
		while(1)
		{
			key=get_key();
			 if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
	
		}
	}
	/*已登录管理员，实现注册功能*/
	else
	{
		i=count=length=0;	//count 定义序号的变量,也等同与链表的len
		X1=34;				//i为每次新增账户
		Y1=10;
		x=6;
		size=sizeof(account);
	

		/*	打开文件	*/
		if((puser=fopen("user.dat","a+b"))==NULL)
		{
			gotoxy(x+2,y);
			printf("ERROR: 不能打开文件(文件名更改或丢失)!!");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					return pos;
				}
			}
		}
		rewind(puser);//定位到文件开始
		InitList(&list);//初始化链表
		
		/*标题提示*/
		warn(3,x,y+1,"+添加新账号");
		warn(3,x,y+2,"以下为读取到的账号信息:");
		
		y=4;
		x+=2; //左右留旁白
		
		while(fread(&e,size,1,puser)==1)
		{
			addNode(&list,&e);	//每读一个结构体，就把值放进链表中去		
			gotoxy(x,y++);
			printf("No.%d: 用户名:%s | 密码：%s\n",count+1,e.username,e.password);
			count++;
		}
		
		/*如果y>border，则需要扩展*/
		if(count)Y1+=count;
		border();
		x-=2; //左右留旁白
	

		/*判断文件内容是否为空*/
		if(count==0)
		{
			y=3;
			gotoxy(x+20,y++);
			printf("--无账号记录--");
		}

	
		/*温馨提示：*/
		y=prompt(x,y,1);
		
		//获取Enter键是否继续，或返回上一级
		while(1)
		{
			key=get_key();
			if(key==ENTER)
				break;
			else if(key==LEFT || key==BACKSPACE)
			{
				X1=10;
				Y1=10;
				fclose(puser);
				destroy(&list);
				return Tree[sub].parent;
			}
		}

		cursor_show();	//光标显示
		/*	
			开始注册
			这里应该使用判断长度，使用户不会误操作
		*/
		gotoxy(x,++y);
		printf("输入用户名：");
		sget_s(e.username,USNLEN);
		gotoxy(x+28,y);
		printf("输入密码：");
		sget_s(e.password,PSWORD);

		cursor_hide();		//光标隐藏


		/* 扩展边框，高度增加4 */
		extensionHigh(4);

		/*判断用户信息是否符合条件*/
		if(equalUsername(&list,compare,e.username))
			warn(2,x,y+3,"用户名已存在，此账户不能被注册.");			//失败提示
		else if(e.username[0]=='\0' || e.password[0]=='\0')
			warn(2,x,y+3,"用户名和密码不得为空.");						//失败提示
		else if(strcmp(e.username,"Admin")==0 || strcmp(e.username,"admin")==0 )
			warn(2,x,y+3,"普通用户名不得于管理员用户名相同.");			//失败提示
		else if(incluSpecial(e.username) || incluSpecial(e.password))
			warn(2,x,y+3,"用户名和密码不得含有空格符或制表符.");		//失败提示
			
		else
		{
			/*成功提示*/
			warn(1,x,y+3,"账号注册成功.");
			addNode(&list,&e);				//添加到链表中
			length=1;
		}




		/*将链表数据写进文件中*/
		if(length--){
			pnode=list.head.next;
			fwrite(&pnode->data,size,1,puser);
		}


		/*获得键*/
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				destroy(&list);
				fclose(puser);
				return pos;
			}else if(key==F5 || key==ENTER)
			{
				destroy(&list);
				fclose(puser);
				return sub;
			}
		}
		
		


	}
	
}


/*
	实现7号功能位——删除用户
*/
int delUser(int sub)
{
	/*与删除用户相关变量*/
	int i,count,length;		//临时变量
	account e;				//暂存变量
	char username[USNLEN];	//被删除的用户名
	list_acc list;			//声明链表类型变量
	node_pacc pnode;		//节点指针
	FILE * puser;			//文件指针
	int size;				//结构体大小
		
/*end----------------------*/
	
	int key,pos=0;
	int x=6,y=1;
	system("cls");
	/*如果未登录管理员*/
	if(!FLAG)
	{	
		gotoxy(x+4,y+2);

		printf("注销用户需要管理员权限，请登录管理员账号！");
		X1=30;
		Y1=5;
		border();
		while(1)
		{
			key=get_key();
			 if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
	
		}	
	}
	/*已登录管理员，实现注册功能*/
	else
	{
		
	
		i=count=length=0;//count 定义序号的变量,也等同与链表的len
		X1=34;			//i为每次新增账户
		Y1=10;
		x=6;
		size=sizeof(account);

		
		/*	打开文件	*/
		if((puser=fopen("user.dat","r+b"))==NULL)
		{
			gotoxy(x+2,y);
			puts("ERROR: 不能打开文件(文件名更改或丢失)!!");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					return pos;
				}
			}
		}

		rewind(puser);//定位到文件开始
		InitList(&list);//初始化链表

		
		/*标题提示*/
		warn(3,x,y+1,"-注销账号");
		warn(3,x,y+2,"以下为读取到的账号信息：");

		y=4;	//与顶部拉开距离
		x+=2;	//左右留旁白

		while(fread(&e,size,1,puser)==1)
		{
			addNode(&list,&e);	//每读一个结构体，就把值放进链表中去		
			gotoxy(x,y++);
			printf("No.%d: 用户名:%s | 密码：%s\n",count+1,e.username,e.password);
			count++;
		}


		/*如果y>border，则需要扩展*/
		if(count)Y1+=count;
		border();
		 x-=2;	//左右留旁白


		/*判断文件内容是否为空*/
		if(count==0)
		{
			gotoxy(x+20,y++);
			printf("--无账号记录--");
		}


		/*读取完记录应该及时关闭文件流*/
		fclose(puser);


		
		y=prompt(x,y,2);//温馨提示：
		

		//获取Enter键是否继续，或返回上一级
		while(1)
		{
			key=get_key();
			if(key==ENTER)
				break;
			else if(key==LEFT || key==BACKSPACE)
			{
				X1=10;
				Y1=10;
				destroy(&list);
				return Tree[sub].parent;
			}
		}


		/*文件为空时不能注销账户*/
		if(count==0)
		{
			gotoxy(x+4,y+3);
			printf("不存在账户，“ENTER” 键返回上一步");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT || key==ENTER)	//退格键、左方向键、回车 返回上一级
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					destroy(&list);
					return pos;
				}
	
			}
		}


		cursor_show();	//光标显示
		
		/*这里应该使用判断长度，使用户不会误操作*/
		gotoxy(x+=4,++y);
		printf("输入注销的用户名：");
		sget_s(username,USNLEN);

		cursor_hide();		//光标隐藏

		/*拉长边框，相当于一个底部出现小边框*/
		Y1+=4;	
		border();

		/*判断用户信息是否符合条件*/
		if(!equalUsername(&list,compare,username))//未在链表中找到数据
		{
		
		
			/*如果字符串包含了空白符*/
			if(incluSpecial(username) || strchr(username,'\0'))
			{
				warn(2,x,y+3,"用户名不得为空白符!");
			}else{
				warn(2,x,y+3,"用户名未知.请检查!");
			}
			
			

			while(1)
			{
				key=get_key();
				 if(key==ENTER || key==F5)	//刷新
				{
					destroy(&list);
					return sub;
				}else if(key==LEFT || key==BACKSPACE)
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					destroy(&list);
					return pos;
				}

			}
		}

		/*
			找到数据，将在链表中移除
		*/
		if(delNode(&list,username))
		{
			warn(1,x,y+3,"账号已被成功注销.");//成功提示
			length=list.len;
		}



		/*
			使用w+b再次打开文件,将链表中的文件写进去
		*/
		if((puser=fopen("user.dat","w+b"))==NULL)
		{
			gotoxy(x,y+7);
			puts("ERROR: 不能打开文件(文件名更改或丢失)!!");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					destroy(&list);
					return pos;
				}
			}
		}
		
		/*将链表数据写进文件中*/
		pnode=list.head.next;
		while(pnode)
		{
			fwrite(&pnode->data,size,1,puser);
			pnode=pnode->next;
		}

		/*获得键*/
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				fclose(puser);
				destroy(&list);
				return pos;
			}else if(key==F5 || key==ENTER)
			{
				fclose(puser);
				destroy(&list);
				return sub;
			}
		}

	}




}


/*
	功能：实现8#号位的功能——判断用户登录
*/

int checkUser(int x,int y,int sub)
{
	int key,size,pos=Tree[sub].parent;
	int r1=random2(),r2=random2();		//获得2个随机数
	int sum1=r1+r2,sum2=0;				//sum1位随机数相加，sum2是用户输入的
	account login,e;					//用户输入的用户名和密码，以及用于fread的e
	FILE * puser;						//文件指针
	list_acc list;						//链表指针
	node_pacc pnode;					//节点指针
	char stemp[VERIFY];					//输入的验证码
	size=sizeof(account);

	system("cls");	
	X1=25;
	border();
	
	warn(3,x-4,y,"登录账号（取消ESC，显示ENTER）");//标题提示

	/*判断用户是否取消*/
	for(;;)
	{
		key=get_key();
		if(key==ESC)	//收到ESC键返回上一步
		{
			X1=10;
			return Tree[sub].parent;
		}
		else if(key==ENTER)
			break;
	}


	cursor_show();	//光标显示
	
	/*打印管理员账户*/
	gotoxy(x+=14,y+=2);
	printf("账  号:");
	sget_s(login.username,USNLEN);
	
	/*打印管理员密码*/
	gotoxy(x,y+=2);
	printf("密  码:");
	sget_s(login.password,PSWORD);
	
	/*黄色高光*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
	gotoxy(x,y+=2);	//验证码题目
	printf("%d + %d = ？",r1,r2);
	/*原色*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);


	/*打印验证码*/
	gotoxy(x,y+2);
	printf("验证码:");
	sget_s(stemp,VERIFY);	//获取字符串,放验证码
	sum2=atoi(stemp);

	

	cursor_hide();		//光标隐藏



	/*	打开文件	*/
	if((puser=fopen("user.dat","a+b"))==NULL)
	{
		gotoxy(x+2,y);
		puts("ERROR: 不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				X1=10;
				Y1=10;
				return sub;
			}
		}
	}

	rewind(puser);//定位到文件开始
	InitList(&list);//初始化链表
		
	/*读取到链表中*/
	while(fread(&e,size,1,puser)==1)
		addNode(&list,&e);	//每读一个结构体，就把值放进链表中去		
	
	fclose(puser);//关闭流

	/* 扩展边框，高度增加4 */
	extensionHigh(4);
	
	if(sum1!=sum2)//验证码错误
	{
		warn(2,x-4,y+6,"验证码错误(Enter)");//失败提示
	}
	else if((pnode=findUsername(&list,compare,login.username))==NULL )//在链表中未找到用户名
	{
		warn(2,x-4,y+6,"用户名错误(Enter)");//失败提示

	}else //用户名正确，说明pnode现在是具有节点地址的
	{
		if(!userToPassword(pnode,compare2,login.password))//如果密码错误
		{
			
			
			warn(2,x-4,y+6,"密码错误(Enter)");//失败提示

		}
		else//用户名和密码都正确了
		{
			
			warn(1,x-4,y+6,"登录成功(Enter)");//成功提示

			SIGN=1;//用户登录标记为1
			strcpy(USERNAME,login.username);
			while(1)
			{
				key=get_key();
				if(key==ENTER)	//回车刷新本界面
				{
					X1=10;
					Y1=10;
					destroy(&list);
					return sub;
				}
			}


		}
	
	}

	/*执行到这里表示没成功，需要重试*/
	while(1)
	{
		key=get_key();
		if(key==ENTER)	//回车刷新本界面
		{
			X1=10;
			Y1=10;
			destroy(&list);
			return sub;
		}
		else if(key==LEFT || key== BACKSPACE)	//左键和退格返回上页
		{
			X1=10;
			Y1=10;
			destroy(&list);
			return pos;
		}
	}

}


/*
	实现9号位的功能——修改密码
*/
int changePsd(int sub)
{
	int x,y;
	int key,size,flag=1;	//flag是检查输入项是否合法，默认不合法
	
	char newpsw[PSWORD];	//用户输入的新密码
	FILE * puser;			//文件流
	account user,e;			//用户输入的用户名和密码，以及用于fread的e


	list_acc list;			//创建链表类型
	node_pacc pnode;		//节点指针

	size=sizeof(account);
	x=2;
	y=1;					//定义坐标

	system("cls");
	X1=22;
	Y1=14;
	border();

	//紫色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	gotoxy(x,y);
	printf("¤修改密码");
	//原色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

	/* 显示温馨提示	*/
	y=prompt(x,y+1,3);
	x+=8;


	//获取Enter键是否继续，或返回
	while(1)
	{
		key=get_key();
		if(key==ENTER)
			break;
		else if(key==LEFT || key==BACKSPACE)
		{
			X1=10;
			Y1=10;
			return Tree[sub].parent;
		}
	}

	cursor_show();		//光标显示
		
	/*	录入数据  */
	gotoxy(x+=4,y+=2);
	printf("用 户 名：");
	sget_s(user.username,USNLEN);

	gotoxy(x,y+=2);
	printf("旧 密 码：");
	sget_s(user.password,PSWORD);

	gotoxy(x,y+=2);
	printf("新 密 码：");
	sget_s(newpsw,PSWORD);

	cursor_hide();		//光标隐藏

	/*打开文件流 a+b*/
	if((puser=fopen("user.dat","a+b"))==NULL)
	{
		gotoxy(x+2,y);
		printf("ERROR: 不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				X1=10;
				Y1=10;
				return Tree[sub].parent;
			}
		}
	}

	/* 指针指向头部 */
	rewind(puser);
	/*	初始化链表	*/
	InitList(&list);

	/*读取流入链表*/
	while(fread(&e,size,1,puser)==1)
		addNode(&list,&e);	//每读一个结构体，就把值放进链表中去	

	/*关闭流*/
	fclose(puser);


	/*扩展边框*/
	extensionHigh(4);

	
	/*
		if检查用户，else检查密码
	*/
	if((pnode=findUsername(&list,compare,user.username))==NULL )//在链表中未找到用户名
	{
		//红色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
		gotoxy(x-4,y+=4);
		printf("×失败：用户名错误");
		//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

	}
	else //用户名正确，说明pnode现在是具有节点地址的
	{
		if(!userToPassword(pnode,compare2,user.password))//如果密码错误
		{
			//红色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("×失败：密码错误");
			//原色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}else if(incluSpecial(newpsw))//新密码不合法
		{
			//红色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("×失败：新密码不合法");
			//原色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}else if(strcmp(user.password,newpsw)==0)//新密码和旧密码相同
		{
			//红色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("×失败：新密码不得与旧密码相同");
			//原色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}else	//旧密码符合
		{
			flag=0;	//标记改为合法标记
			//绿色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("√成功：修改成功(Enter)");
			//原色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		
		}
	}

	//用户错误键入
	while(1 && flag)
	{
		key=get_key();
		if(key==ENTER)
		{
			return sub; 
		}
		else if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			X1=10;
			Y1=10;
			return Tree[sub].parent;
		}
	}



	/*
		执行到这里说明用户输入合法
	*/
	//删除节点
	delNode(&list,user.username);
	strcpy(user.password,newpsw);//将新密码赋给就密码
	//增加节点
	addNode(&list,&user);

	


	/*再次打开文件流 w+b*/
	if((puser=fopen("user.dat","w+b"))==NULL)
	{
		gotoxy(x+2,y);
		printf("ERROR: 不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				X1=10;
				Y1=10;
				return Tree[sub].parent;
			}
		}
	}


	/*将链表数据写进文件中*/
	pnode=list.head.next;
	while(pnode)
	{
		fwrite(&pnode->data,size,1,puser);
		pnode=pnode->next;
	}

	//关闭流
	fclose(puser);
	
	/*
		如果修改密码的账户和 已登录的用户相等，则退出当前登录
	*/
	if(strcmp(user.username,USERNAME)==0)
	{
		SIGN=0;
	}

	//继续修改 or 返回上一步
	while(1)
	{
		key=get_key();
		
		 if(key==ENTER)	//退格键和左方向键返回上一级
		{
			X1=10;
			Y1=10;
			return Tree[sub].parent;
		}
	}


}


/* 
	实现10号位功能——退出登录
*/
int logOut(int sub)
{
	
	int key;
	int x=2,y=1;
	system("cls");
	X1=20;		//只改变界面的宽度
	border();	
	
	//绿色高光
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	gotoxy(x,y);
	printf("当前账户:%s 已登录√",USERNAME);
	//原色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);		
		
	
	gotoxy(x+=10,y+3);
	printf("是否退出当前账户");
	gotoxy(x,y+5);
	printf("（Enter确认/ESC取消）");
	/*判断是否退出*/
	while(1)
	{
		key=get_key();
		if(key==ESC)	//收到ESC键返回上一步
		{
			X1=10;
			return Tree[sub].parent;
		}
		else if(key==ENTER)
		{	
			X1=10;
			SIGN=0;						//标记清零
			return Tree[sub].parent;	//也返回上一步
		}
	}






}


/*
	实现19号位的功能——新增学生
*/
int addStudents(int sub)
{
	/*与注册相关变量*/
	int i,count,length;			//临时变量
	data_stu data;				//用于用户临时输入的数据
	list_stu list;				//链表指针
	node_pstu pnode;			//节点指针
	FILE * fstu;				//文件流指针
	int size=sizeof(data_stu);	//结构体大小
	/*end----------------------*/

	int x1,y1;//学生记录的xy
	/**/
	int key,pos=0,snumber;
	int x=16,y=0;	//这里的x，y是打印文字的

	system("cls");
	warn(3,x,y,"新增学生");

	if((fstu=fopen("students.dat","a+b"))==NULL)	
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"error 1129:不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}
	x=0,y=1;	//表格的xy
	
	studentTable(x,y);	//打印出标题
	
	
	rewind(fstu);//定位到文件开始
	initList_stu(&list);//初始化链表

	x1=2,y1=4;	//学生记录的xy
	while(fread(&data,size,1,fstu)==1)//将数据写进链表
	{
		table(x,y+=2,28,1);
		addNode_stu(&list,&data);//每读一个结构体，就把值放进链表中去
		print_stu(data,x1,y1);	//打印学生函数
		/*gotoxy(x1,y1);
		printf("%4d\040\040\040%6s\040%6s\040\040\040\040%6s\040\040%10s\040%8s",data.sno,data.name,data.sex,data.naPlace,data.brith,data.consult);
		*/
		y1+=2;
	}
	

	//判断文件内容是否为空
	if(y1==4)
	{
		gotoxy(x1,y1++);
		snumber=1;		//如果没有记录，后面所提供的记录的学号以snumer开始
		printf("--无学生记录--");
	}else
	{
		snumber=data.sno+1;	//学号自动生成且加一
		
	}

	
	//获取Enter键是否继续，或返回上一级
	while(1)
	{
		key=get_key();
		if(key==ENTER)
			break;
		else if(key==LEFT || key==BACKSPACE)
		{
			X1=10;
			Y1=10;
			fclose(fstu);
		    destroy_stu(&list);	//当链表有数据时会报错
			return Tree[sub].parent;
		}
	}

	//录入数据
	cursor_show();	//光标显示
	/*	
	开始注册
	这里应该使用判断长度，使用户不会误操作
	*/
	x=58;y=3;

	gotoxy(x,y);
	printf("\b输入学生姓名：");
	sget_s(data.name,STUDNAME);
	
	gotoxy(x,y+=2);
	printf("\t性别：");
	sget_s(data.sex,SEX);
	
	gotoxy(x,y+=2);
	printf("\t籍贯：");
	sget_s(data.naPlace,NATPLACE);

	gotoxy(x,y+=2);
	printf("\040\040出生年月：");
	sget_s(data.brith,BRITHDAT);

	gotoxy(x,y+=2);
	printf("\040\040\040\040咨询师：");
	sget_s(data.consult,CONTEACHER);


	cursor_hide();		//光标隐藏

	/*---------------------------------------------*/
	//！！！！这里需要判断用户信息是否符合条件

	data.sno=snumber;
	addNode_stu(&list,&data);
	
	/*---------------------------------------------*/
	/*将链表数据写进文件中*/
	
	pnode=list.head.next;
	fwrite(&pnode->basic,size,1,fstu);
	warn(1,20,23,"创建成功.");
	
	/*获得键*/
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);
			destroy_stu(&list);
			return pos;
		}else if(key==F5 || key==ENTER)
		{
			fclose(fstu);
			destroy_stu(&list);
			return sub;
		}
	}

}


/*
	实现20号位的功能——修改学生信息
*/
int changeStudnets(int sub)
{
	int key,pos;
	list_stu list;					//链表类型
	node_pstu pnode;					//节点类型
	data_stu data;					//data数据域变量
	FILE * fstu;					//文件指针
	int size=sizeof(data_stu);		//结构体大小
	int sno;						//学号
	int x=2,y=1;


	system("cls");
	
	if((fstu=fopen("students.dat","r+b"))==NULL)		//读取文件流
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}
	//边框
	X1=30;

	Y1=23;
	border();
	warn(3,x,y,"修改学生信息");

	//初始化链表
	initList_stu(&list);
	rewind(fstu);
	
	//这里给个阻塞
	while(1)
	{
		key=get_key();
		if(key==LEFT || key==BACKSPACE)
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);
			destroy_stu(&list);
			return pos;

		}else if(key==ENTER) 
		{
			break;
		}

	}
	//读取文件中的所有数据进链表
	while(1==fread(&data,size,1,fstu))
	{
		//将数据添加进链表
		addNode_stu(&list,&data);
	}
	

	/*判断，如果这里的链表为空说明没有数据，则无法修改*/
	if(isEmpty_stu(&list))
	{
		gotoxy(x,y+3);
		printf("链表为空，则不能修改数据");
		while(1)
		{
			key=get_key();
			if(key==LEFT || key==BACKSPACE ||key==ENTER)
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				fclose(fstu);
				destroy_stu(&list);
				return pos;
			}
		}
	}

	//提醒用户输入学号
	gotoxy(x+=2,y+=3);
	printf("请输入学号：");
	myscanf(&sno);
	studentTable(x,y);	//打印出标题

	//根据学号查找，打印出这位学生信息
	if(pnode=snoCheck(&list,sno))
	{
		print_stu(pnode->basic,x,y+3);
	}
	else
	{
		warn(2,x,y,"未发现该学号学生.");
		while(1)
		{	
			key=get_key();
			if(key==ENTER)
			{
				fclose(fstu);
				destroy_stu(&list);
				return sub;
			}
		}	
	}

	//提醒用户输出新的学生信息
	//pnode是已经找到的节点，只需要在这上面修改就可以
	
	//录入数据
	cursor_show();	//光标显示
	x=7;y=9;

	gotoxy(x,y);
	printf("\b修改一下信息.");
	
	gotoxy(x,y+=2);
	printf("\b输入学生姓名：");
	sget_s(data.name,STUDNAME);
	
	gotoxy(x,y+=2);
	printf("\t性别：");
	sget_s(data.sex,SEX);
	
	gotoxy(x,y+=2);
	printf("\t籍贯：");
	sget_s(data.naPlace,NATPLACE);

	gotoxy(x,y+=2);
	printf("\040\040出生年月：");
	sget_s(data.brith,BRITHDAT);

	gotoxy(x,y+=2);
	printf("\040\040\040\040咨询师：");
	sget_s(data.consult,CONTEACHER);

	data.sno=sno;		//学号不能被修改，由传进来的sno赋值
	cursor_hide();		//光标隐藏
	
	pnode->basic=data;

	/*---------------------------------------------*/
	/*将链表数据写进文件中*/
	//将流写回去,先将流定位到文件头，将原先的覆盖
	rewind(fstu);
	//将链表全部回写
	/*将链表数据写进文件中*/
	pnode=list.head.next;
	while(pnode)
	{
		fwrite(&pnode->basic,size,1,fstu);
		pnode=pnode->next;
	}
	//fwrite(&pnode->basic,size,1,fstu)
	warn(1,x,y+=3,"修改成功.");

	
	/*获得键*/
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);
			destroy_stu(&list);
			return pos;
		}else if(key==F5 || key==ENTER)
		{
			fclose(fstu);
			destroy_stu(&list);
			return sub;
		}
	}
}

/*
	实现21号位的功能——查询学生信息
*/

/*
	实现22号位的功能——删除学生信息
*/


/*
	实现23号位的功能——抽取演讲人
*/
int drawingLecture(int sub)
{
	int key,pos=0;
	FILE * fstu, *fpass;
	node_pstu pcheck;
	list_stu list1,list2;		//链表指针
	data_stu data,data_pass;
	int size=sizeof(data_stu);	//结构体大小
	int x=22,y=4;
	int rndnumber;				//随机数
	int rest_flag=1;			//重新抽取


	system("cls");
	warn(3,x,y,"随机抽取（Enter）");	
	if((fstu=fopen("students.dat","a+b"))==NULL)		//读取文件流
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	if((fpass=fopen("stpass.dat","a+b"))==NULL)				//读取文件流	
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	rewind(fpass);	//将指针指向文件开始
	rewind(fstu);	//	
	initList_stu(&list1);
	initList_stu(&list2);

	X1=30;		//只改变界面的宽度

	border();	
	
	while(1)
	{
		key=get_key();
		if(key==LEFT || key==BACKSPACE)
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fpass);
			fclose(fstu);
			destroy_stu(&list1);
			destroy_stu(&list2);
			return pos;

		}else if(key==ENTER) 
		{
			break;
		}

	}

	
	while(fread(&data,size,1,fstu)==1)//原文件
	{
		addNode_stu(&list1,&data);	//每读一个结构体，就把值放进去
	}

	while(fread(&data_pass,size,1,fpass)==1)//已读文件
	{
		addNode_stu(&list2,&data_pass);	
	}




	while(1)
	{
		rest_flag=1;
		rndnumber=random(1,data.sno);		//1-学生末尾，随机数产生的学号	//这里需要判断一遍14个学生
		
		pcheck=snoCheck(&list1,rndnumber);	//随机数为学号去学生表中找

		//通过随机数查找链表
		if(pcheck && !snoCheck(&list2,rndnumber))	//此学号在学生表中能够找到，但在pass表中不能找到
		{

			gotoxy(6,6);	
			printf("抽取的演讲人是:");
			gotoxy(23,6);	
			//黄色高光
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

			printf("〈 %s 〉",pcheck->basic.name);

			//原色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

			gotoxy(22,8);
			printf("(ENTER确认 / ESC重抽)");
			while(1)
			{
				key=get_key();
				if(key==ESC)
				{
					rest_flag=0;
					break;
				}
				else if(key==ENTER)
				{
					gotoxy(22,8);
					printf("\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40");
					gotoxy(22,8);
					printf("确认这位了~（|←）");
					break;
				}
			}

			if(rest_flag)//如果用户敲入回车，则重新抽取
				break;
		}else if(list1.len==list2.len)	//当读取完时
		{
			gotoxy(22,6);	
			printf("本轮结束！进行下一轮(Enter)");
			/*
				结束之后需要关闭流,使用w+b重新读取，变相的清空pass文件
				本轮结束，也以为着后面操作
			*/
			fclose(fpass);		//关闭文件
			
			if((fpass=fopen("stpass.dat","wb"))==NULL)	//打开流
			{
				system("cls");
				printf("ERROR 1403：文件打开失败");
			}

			while(1)
			{
				key=get_key();
				if(key==ENTER)	//回车之后，刷新本页
				{

					fclose(fstu);//关闭流
					fclose(fpass);
					destroy_stu(&list1);//销毁链表
					destroy_stu(&list2);
					return sub;
				}
				else if(key==LEFT)	//退格键和左方向键返回上一级
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					fclose(fstu);//关闭流
					fclose(fpass);
					destroy_stu(&list1);//销毁链表
					destroy_stu(&list2);
					return pos;
				}
			}
			break;
		}
	}

	//将本次随机到的学生写入到fpass文件流中，保证下次不会被随机到
	fwrite(&pcheck->basic,size,1,fpass);
	
	while(1)
	{
		key=get_key();
		if(key==LEFT || key==ENTER)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);//关闭流
			fclose(fpass);
			destroy_stu(&list1);//销毁链表
			destroy_stu(&list2);
			return pos;
		}
		/*else if(key==ENTER)//敲下回车，刷新本页
		{
			fclose(fstu);//关闭流
			fclose(fpass);
			destroy_stu(&list1);//销毁链表
			destroy_stu(&list2);
			return sub;
		}*/
	}





	
	
}


/*
	实现24号位的功能——预备演讲人
*/
int readyLecture(int sub)
{
	int key,pos=0;
	int size=sizeof(data_stu);
	FILE * fpass;
	list_stu list2;
	data_stu data_pass;
	int x=8,y=1;
	
	
	system("cls");
	warn(3,x-1,y,"下一个演讲人准备");

	
	if((fpass=fopen("stpass.dat","a+b"))==NULL)		//读取已随机过的文件流
	{
		system("cls");
		X1=20;
		Y1=5;
		border();
		warn(2,x,y+3,"不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	rewind(fpass);
	initList_stu(&list2);
	X1=16;		//只改变界面的宽度
	Y1=6;
	border();	//边框

	while(fread(&data_pass,size,1,fpass)==1)
	{
		addNode_stu(&list2,&data_pass);	//增加节点

	}
	
	if(0==list2.len)
	{
		gotoxy(x-3,y+=2);
		printf("当前还未抽取预备演讲者.");
		gotoxy(x-3,++y);
		printf("请返回抽取演讲者.");

	}else{
		//黄色高光
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
		gotoxy(x+3,y+=2);
		printf("< %s >",data_pass.name);
		//原色高光
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		gotoxy(x-1,y+=2);
		printf("请演讲者做好准备.");
			//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}
	
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fpass);
			destroy_stu(&list2);
			return pos;
		}
	}

}

/*
	实现25位的功能——演讲内容简记
*/

/*
	实现26位的功能——演讲情况浏览
*/


/*
	实现27位的功能——记录考勤
*/


/*
	实现28位的功能——更改考勤
*/

/*
	实现29位的功能——查询考勤
*/

/*
	实现30位的功能——考勤记录删除
*/







/*
	功能：字符串不得包含空字符和制表符
*/
int	incluSpecial(char *str)
{
	char * find;
	if(find=strchr(str,32))
		return 1;
	else if(find=strchr(str,'\t'))
		return 1;
	return 0;
}


/*
	功能：扩展边框
*/
void extensionHigh(int value){
	Y1+=value;	
	border();
}


/*
	功能：打印带颜色的提示or警示
*/
void warn(int flag,int x,int y,char *str)
{
	gotoxy(x,y);
	if(flag==1)//如果是1表示成功
	{
		//绿色高光
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		printf("√成功：%s",str);
		//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}else if(flag==2)//如果是2表示失败
	{
		//红色高光
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("×失败：%s",str);
		//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}else if(flag==3)//如果是3表示标题提示
	{
		/*紫色高光*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		printf("%s",str);
		//原色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	
	}
}

/*
	输入数字
*/
void myscanf(int *p)
{
	scanf("%d",p);
	while(getchar()!='\n')
		continue;
	
	
}