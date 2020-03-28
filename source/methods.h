#ifndef _METHODS_H_
#define _METHODS_H_
#include "structure.h"
#include <stdio.h>
/*
	功能：获取字符串
	参数：字符串，长度
*/
char * sget_s(char * str,int n);




/*
	实现5号位的功能——管理员登录
*/
int superUser(int sub);



/*
	实现6号位的功能——注册新用户
*/
int addUser(int sub);


/*
	实现7号功能位——删除用户
*/
int delUser(int sub);


/*
	功能：实现8#号位的功能——判断用户登录
	参数：x,y轴和 下标
	返回：成功返回1，失败0
*/
int checkUser(int x,int y,int sub);


/*
	实现9号位的功能——修改密码
*/
int changePsd(int sub);

/*
	实现10号位功能——退出登录
*/
int logOut(int sub);



/*
	实现19号位的功能——新增学生
*/
int addStudents(int sub);


/*
	实现23号位的功能——抽取演讲人
*/
int drawingLecture(int sub);



/*
	实现24号位的功能——预备演讲人
*/
int readyLecture(int sub);


/*
	测试链表长度
*/
int countLength(Node np);



/*	打印链表的值*/
void printVal(Node np);

/*
	功能：字符串不得包含空字符和制表符
	参数: 传入字符串
	返回：包含返回1，未包含返回0
*/
int	incluSpecial(char *str);


/*
	功能：扩展边框
	参数：将边框高度扩展多少
	返回：无返回
*/
void extensionHigh(int value);

/*
	功能：打印带颜色的提示or警示
	参数：flag值为1是成功标记，为2是失败，为3是功能标题提示；xy对应xy轴坐标，str用户输入提示信息
	返回：无
*/
void warn(int flag,int x,int y,char *str);


/*
	输入数字
*/
void myscanf(int *p);
#endif