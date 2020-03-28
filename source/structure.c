/*
	该文件记录每层选择项，
	即项的结构体实现
*/
#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "methods.h"
#include "mlayout.h"	//调用界面函数 
#include "structure.h"

 extern int INDEX; 
 extern int listIndex; 
/*
	初始化数组
	和链表
*/
void  initTreeArrays()
{

	Node a=addList(3);	//隶属于一号节点
	/*链表共有8个小链表*/
	Node b,c,d,e,f,g,h;
	int i=1,x=11;

	ptree stem={
		0,				//父节点
		3,				//度的个数
		a				//子链表
	};
	Tree[INDEX++]=stem;	//班级管理系统 根节点


	/*第2个小链表，二号节点，创建小链表的同时，创建了数组元素，并加入到数组中*/

	b=addList(3);			//传入节点的度
	stem.parent=1;	
	stem.number=3;			//该节点下的度
	stem.firstChild=b;
	Tree[INDEX++]=stem;		//注册管理


	/*第3个小链表，三号节点*/
	c=addList(3);
	stem.parent=1;	
	stem.number=3;
	stem.firstChild=c;
	Tree[INDEX++]=stem;		//系统管理


	/*4号节点*/ 
	stem.parent=1;	
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//退出系统

	/*5号节点*/ 
	stem.parent=2;	
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//超级用户登录

	/*6号节点 */
	stem.parent=2;	
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//注册新角色

	/*#7号节点*/
	stem.parent=2;		
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//删除用户


	/*8号节点 */
	d=addList(4);
	stem.parent=3;	
	stem.number=4;
	stem.firstChild=d;
	Tree[INDEX++]=stem;		//登录成功

	/*9号节点 */
	stem.parent=3;	
	stem.number=0                                                                    ;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//修改密码

	/*10号节点 */
	stem.parent=3;	
	stem.number=0                                                                    ;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//退出登录


	/*11号节点 */
	e=addList(4);
	stem.parent=8;	
	stem.number=4;
	stem.firstChild=e;
	Tree[INDEX++]=stem;		//班级管理

	/*12号节点 */
	f=addList(4);
	stem.firstChild=f;
	Tree[INDEX++]=stem;		//学生管理


	/*13号节点 */
	g=addList(4);
	stem.firstChild=g;
	Tree[INDEX++]=stem;		//班级管理

	/*14号节点 */
	h=addList(4);
	stem.firstChild=h;
	Tree[INDEX++]=stem;		//考勤管理




	//循环创建节点，i=1
	while(i<=16){
		switch(i)
		{
		case 5:
			x++;
			break;
		case 9:
			x++;
			break;
		case 13:
			x++;
			break;
		}
		stem.parent=x;			//15-30各小节点的父节点
		stem.number=0;			//都是0个子节点
		stem.firstChild=NULL;	//每个节点都是一个事实功能函数
		Tree[INDEX++]=stem;		//将其加入到数组中
		i++;
	}

}

/*
	功能：链表添加函数
	参数：total是父节点的度
	返回值：无
*/
Node addList(int total)
{
	int i;
	Node stemp,stemp2,np;;
	
	
	//先开辟一个
	stemp=(Node)malloc(sizeof(node));
	stemp->next=NULL;
	stemp->index=listIndex++;
	np=stemp2=stemp;
	
	//开辟剩下的
	for(i=1;i<total;i++)
	{
		stemp=(Node)malloc(sizeof(node));
		stemp->next=NULL;
		stemp->index=listIndex++;
		stemp2->next=stemp;
		stemp2=stemp;
	}
	
	return np;
}




/*
	通过返回的下标调用函数
*/
int print_check(int index)
{
	int ret_val=0;
	switch(index)
	{
	case 0:	
		home();						//调用界面函数
		break;
	case 1:
		ret_val=listA(index);		//主界面函数 显示：a链表
		break;
	case 2:
		ret_val=listB(index);		//注册管理函数 显示：b链表
		break;
	case 3:
		ret_val=listC(index);		//登录管理函数 显示：c链表
		break;
	case 4:	
		ret_val=quit();				//退出系统函数
		break;
	case 5:
		ret_val=superUser(index);	//超级用户登录
		break;
	case 6:
		ret_val=addUser(index);		//注册新用户
		break;
	case 7:
		ret_val=delUser(index);		//删除用户
		break;
	case 8:
		ret_val=listD(index);		//显示：d链表 班级管理，学生管理，活动管理，考勤管理
		break;
	case 9:
		ret_val=changePsd(index);	//修改密码 
		break;
	case 10:
		ret_val=logOut(index);		//退出登录
		break;
	case 11:
		ret_val=listE(index);		//显示：e链表 注册班级，修改班级信息，查询班级信息，删除班级
		break;
	case 12:
		ret_val=listF(index);		//显示： f链表 新增学生，修改学生信息，查询学生信息，删除学生
		break;
	case 13:
		ret_val=listG(index);		//显示： g链表 演讲人管理，演讲内容简记，演讲内容修改，
		break;
	case 14:
		ret_val=listH(index);		//显示： h链表 记录考勤,更改考勤,查询考勤，考勤记录删除 
		break;
	case 15:						//注册班级
		ret_val=waitExploit(index);
		break;
	case 16:						//修改班级信息
		ret_val=waitExploit(index);
		break;
	case 17:						//查询班级信息
		ret_val=waitExploit(index);
		break;	
	case 18:						//删除班级
		ret_val=waitExploit(index);
		break;
	case 19:						//新增学生
		ret_val=addStudents(index);
		break;
	case 20:						//修改学生信息
		ret_val=changeStudnets(index);
		break;
	case 21:						//查询学生信息
		ret_val=waitExploit(index);
		break;
	case 22:						//删除学生
		ret_val=waitExploit(index);
		break;
	case 23:						//演讲人抽取
		ret_val=drawingLecture(index);
		break;
	case 24:						//预备演讲人
		ret_val=readyLecture(index);
		break;
	case 25:						//内容简记
		ret_val=waitExploit(index);
		break;
	case 26:						//演讲情况浏览
		ret_val=waitExploit(index);
		break;
	case 27:						//记录考勤
		ret_val=waitExploit(index);
		break;
	case 28:						//更改考勤
		ret_val=waitExploit(index);
		break;
	case 29:						//查询考勤
		ret_val=waitExploit(index);
		break;
	}

	return ret_val;

}





