#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#define USNLEN 15	//定义用户名长度
#define	PSWORD 9	//密码最长为八位

/*
	基础数据域类型
*/
typedef struct acc
{
	char username [USNLEN]; 	
	char password [PSWORD];
}account;



/*
	节点类型
*/
typedef struct node_a
{
	account data;
	struct node_a * next;
}node_acc;



/*
	单链表链表类型
*/ 
typedef struct 
{
	node_acc head;	//节点类型 哑节点
	unsigned int len;		//长度
}list_acc;

typedef account  * account_p;
typedef list_acc * list_pacc;
typedef node_acc * node_pacc;	//指针




/*函数原型---------------------------------------------*/


/*
	功能：判断链表是否为空
	参数：链表指针
	返回：返回1表示为空,返回0不为空
*/

int isEmpty(list_pacc list);


/*
	功能：初始化链表
	参数：链表指针
	返回：无返回
*/
void InitList(list_pacc list);


/*
	功能：（头插入）传入数据，创建节点
	参数：链表指针，数据域指针
	返回：成功返回1，失败返回0
*/
int  addNode(list_pacc list,account_p acc);



/*
	功能：打印链表内容
	参数：链表指针
	返回：无返回
*/
void printNode(list_pacc list);



/*
	功能：比较数据域类型中的username 是否一样
	参数：数据域值，传入用户名字符串
	返回：相同返回1，不同返回0
	
*/

int compare(account e1,char * str);

/*
	功能：比较数据域类型中的password 是否一样
	参数：数据域值，传入用户名字符串
	返回：相同返回1，不同返回0
*/
int compare2(account e1,char * str);

/*
	功能：根据传入的参数，匹配链表中已有数据域，成功则删除
	参数：传入头指针，数据域指针
	返回：成功返回1，失败返回0
*/
int delNode(list_pacc list,char *str);


/*
	功能：判断用户名不得重复 
	参数：链表指针 和 比较函数指针
	返回：如果相同返回1，不同为0
*/

int equalUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str);



/*
	功能：查询用户名是否存在
	参数：链表指针 和 比较函数指针，查找字符串
	返回：如果存在，返回存在的那个节点。不存在返回null
*/

node_pacc findUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str);


/*
	功能：通过用户名查找密码
	参数：链表中的某个节点，匹配密码的函数指针
	返回：如果找到返回1，未发现为0

*/
int userToPassword(node_pacc pnode,int (*pfun)(account e1,char * str),char * str);

/*
	功能：销毁链表函数
	参数：链表指针
	返回：无
*/
void destroy(list_pacc list);


#endif