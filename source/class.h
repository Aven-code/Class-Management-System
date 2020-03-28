/*
	该文件保存关于班级功能的相关函数和结构
*/

#ifndef _CLASS_H_
#define _CLASS_H_
#include "structure.h"


#define CNAME		31			//课程名称长度
#define CMAJOR		31			//课程专业名称长度
#define TEARNAME	11			//班主任名称
#define CLASSNAME   21			//班级名称



/*
	定义课程链表
*/

typedef struct course
{
	char curriculum[CNAME];		//课程名称
	struct course * next;		//下一个名称

}node_course;


/*
	以老师为链表类型就可用形成一个课程列表；
*/

/*
	定义老师结构
*/
typedef struct teacher
{
	
	char tc_name[TEARNAME];	//老师名称
	node_course * next;			//老师结构包含了课程名称

}list_teach;



/*
	定义班级结构
*/
typedef struct 
{

	char class_name[CLASSNAME];		//班级名称
	char major [CMAJOR];			//专业名称
	Date reg_time;					//注册日期
	Date open_class;				//开班日期
	Date graduation;				//毕业日期
	int amount;						//人数
	float len_learn;				//学习时长
	char major_teach[TEARNAME];		//班主任名称
	list_teach t;						//老师名称

}class_elem;



/*
	链表结构
*/
//节点类型
typedef struct node_tcla
{
	class_elem elem;	//元素结构
	struct node_tcla * next;	//指向下一个

}node_cla;


//大链表类型
typedef struct list_cla
{	
	node_cla head;			//头节点
	int  len;				//节点长度
}list_class;



typedef list_class * list_pclass;	//链表指针
typedef node_cla  *  node_pcla;		//节点指针



//初始化

void InitList_class(list_pclass list);


/*
	功能：判断链表是否为空
	参数：链表指针
	返回：返回1表示为空,返回0不为空
*/

int isEmpty_class(list_pclass list);



//增加节点
int  addNode_class(list_pclass list,class_elem e);

/*
	功能：根据传入的参数，匹配链表中已有数据域，成功则删除
	参数：传入头指针，数据域指针
	返回：成功返回1，失败返回0
*/
int delNode_class(list_pclass list,char * str );

/*
	功能：匹配班级的名字
	参数：class_elem 类型和 传入用户输入的字符串
	返回：匹配成功返回1，匹配失败返回0

*/
int compare_class(class_elem e,char *str);



/*
	功能:销毁链表函数
	参数：链表指针
	返回：无
*/
void destroy_class(list_pclass list);


#endif