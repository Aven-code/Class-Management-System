/*
	实现接口，关于账户信息的操作相关函数

	功能6：注册用户
	功能7：删除用户
	的相关结构和函数


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
	
//类型： list_acc	指针	list_pacc
//类型： node_acc	指针	node_pacc
//类型： account	指针	account_p
	

/*
	功能：判断链表是否为空
	参数：链表指针
	返回：返回1表示为空,返回0不为空
*/

int isEmpty(list_pacc list)
{
	if(list->len==0)
		return 1;
	return 0;
}



/*
	初始化链表
*/
void InitList(list_pacc list)
{
	list->head.next=NULL;
	list->len=0;
}



/*
	功能：（头插入）传入数据，创建节点
	参数：头指针，数据域类型指针
	返回：成功返回1，失败返回0
*/
int  addNode(list_pacc list,account_p  e)
{
	node_pacc pnode,pnext;
	pnode=(node_pacc)malloc(sizeof(node_acc));

	if(!pnode)
	{
	//	printf("开辟内存失败");
		return 0;
	}

	
	//将元素存入到节点里
	memcpy( &pnode->data, e , sizeof(account));
	pnext=&list->head;	//指向头结点，方便查找尾节点
	pnode->next=pnext->next;
	pnext->next=pnode;

/*
	
	pnext=&list->head;	//指向头结点，方便查找尾节点

	pnode->next=NULL
	while(pnext->next)	//循环到尾部
	{
		pnext=pnext->next;
	}

	pnext->next=pnode;


*/




	list->len++;


	return 1;
}


/*
	功能：根据传入的参数，匹配链表中已有数据域，成功则删除
	参数：传入头指针，数据域指针
	返回：成功返回1，失败返回0
*/

int delNode(list_pacc list,char *str)
{
	
	node_pacc pnode,pnext;	
	pnode=&list->head;
	pnext=list->head.next;
	/*
		如果链表为空则无法删除
	*/
	if(isEmpty(list))
	{
		return 0;
	
	}

	while(pnext)
	{
		if(compare(pnext->data,str))//判断数据是否相同
		{
			
			pnode->next=pnext->next;
			free(pnext);	//释放内存
			pnext=NULL;
			list->len--;
			return 1;	//找到相同数据
		}

			pnode=pnode->next;
			pnext=pnext->next;
	}

	return 0;	//未找到相同数据

}


/*
	功能：销毁链表函数
	参数：链表指针
	返回：无
*/
void destroy(list_pacc list)
{
	node_pacc pnode,pnext;
	pnode=&list->head;
	pnext=list->head.next;

	
	while(pnext)
	{
		pnode=pnext;
		pnext=pnext->next;
		free(pnode);
	}
	
	list->head.next=NULL;
	list->len=0;
	         
}



/*
	打印链表内容
*/

void printNode(list_pacc list)
{
	int i=1;
	node_pacc pnode=list->head.next;
	/*如果链表为空，打印空值*/
	if(isEmpty(list))
	{
		printf("链表为空");
		return ;
	}

	while(pnode){
		
		printf("%d:用户名：%s,密码：%s\n",i,pnode->data.username,pnode->data.password);
		pnode=pnode->next;
		i++;
	}

}




/*
	比较函数：比较数据域类型中的username 是否一样
	相同返回1，不同返回0
	
*/

int compare(account e1,char * str)
{
	if(strcmp(e1.username,str)!=0)	//只判断用户名
		return 0;
	return 1;
}


/*
	比较函数：比较数据域类型中的password 是否一样
	相同返回1，不同返回0
*/
int compare2(account e1,char * str)
{
	if(strcmp(e1.password,str)!=0)	//只判断用户名
		return 0;
	return 1;
}

/*
	功能：判断用户名不得重复 
	参数：链表指针 和 比较函数指针，比较字符串
	返回：如果相同返回1，不同为0
*/

int equalUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str)
{
	node_pacc pnode=list->head.next;

	while(pnode)
	{
		/*如果相同*/
		if(pfun(pnode->data,str))
		{
			return 1;
		
		}
		pnode=pnode->next;
	}
	return 0;
}

/*
	功能：查询用户名是否存在
	参数：链表指针 和 比较函数指针，查找字符串
	返回：如果存在，返回存在的那个节点。不存在返回null
*/

node_pacc findUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str)
{
	node_pacc pnode=list->head.next;

	while(pnode)
	{
		/*如果相同*/
		if(pfun(pnode->data,str))
		{
			return pnode;
		
		}
		pnode=pnode->next;
	}
	return NULL;//没找到
}

/*
	功能：通过用户名查找密码
	参数：链表中的某个节点，匹配密码的函数指针
	返回：如果找到返回1，未发现为0

*/
int userToPassword(node_pacc pnode,int (*pfun)(account e1,char * str),char * str)
{

	return pfun(pnode->data,str);

}