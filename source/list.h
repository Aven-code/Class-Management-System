#ifndef _LIST_H_
#define _LIST_H_



#define USLEN 13	//定义用户名长度最长十二个
#define	PSWORD 8	//密码最长为八位
/*
	数据域类型
*/
typedef struct elem_
{
	char username [USLEN]; 	
	char password [PSWORD];
}elem_t;


/*
	节点类型
*/
typedef struct _node
{
	elem_t data;
	struct _node * next;
}node_t;



/*
	单链表链表类型
*/
typedef struct 
{
	node_t head;	//节点类型 哑节点
	unsigned int len;		//长度
}list_t;



typedef list_t * List;
typedef node_t * Node;	//二级指针





/*函数原型*/
	


/*
	功能：判断链表是否为空
	参数：链表指针
	返回：返回1表示为空,返回0不为空
*/

int isEmpty(List list);

/*
	初始化链表
*/
void InitList(List list);



/*
	功能：（头插入）传入数据，创建节点
	参数：头指针，节点指针
	返回：成功返回1，失败返回0
*/
int  addNode(List list,elem_t * e);

/*
	打印链表内容
*/

void printNode(List list);

/*
	比较函数：比较数据域类型中的username 是否一样
	相同返回1，不同返回0
	
*/

int compare(elem_t e1,char * str);


/*
	功能：根据传入的参数，匹配链表中已有数据域，成功则删除
	参数：传入头指针，数据域指针
	返回：一个数据域类型，方便返回
*/

elem_t delNode(List list,char *str);



/*
	功能：判断用户名不得重复 
	参数：链表指针 和 比较函数指针
	返回：如果相同返回1，不同为0
*/

int equalUsername(List list,int (*pfun)(elem_t e1,char * str),char * str);



#endif 