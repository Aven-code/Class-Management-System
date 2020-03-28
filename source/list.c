/*
	该文件是
	链表接口实现文件
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/*

	功能6注册用户和功能7删除用户的相关结构和函数

*/


/*
	功能：判断链表是否为空
	参数：链表指针
	返回：返回1表示为空,返回0不为空
*/

int isEmpty(List list)
{
	if(list->len==0)
		return 1;
	return 0;
}

/*
	初始化链表
*/
void InitList(List list)
{
	list->head.next=NULL;
	list->len=0;
}



/*
	功能：（头插入）传入数据，创建节点
	参数：头指针，节点指针
	返回：成功返回1，失败返回0
*/
int  addNode(List list,elem_t * e)
{
	Node pnode,pnext;
	pnode=(Node)malloc(sizeof(node_t));

	if(!pnode)
	{
		printf("开辟内存失败");
		return 0;
	}


	//将元素存入到节点里
	memcpy( &pnode->data, e , sizeof(elem_t));
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
	返回：一个数据域类型，方便返回
*/

elem_t delNode(List list,char *str)
{
	elem_t ret_val={NULL,NULL};					//返回值
	//strcpy(ret_val.username,NULL);	
	//strcpy(ret_val.password,NULL);

	Node pnode,pnext;	
	pnext=&list->head;
	pnode=list->head.next;
	/*
		如果链表为空则无法删除
	*/
	if(isEmpty(list))
	{
		
		return ret_val;
	}



	while(pnode)
	{
		
		if(compare(pnode->data,str))//判断数据是否相同
		{
			
			pnext->next=pnode->next;

			strcpy(ret_val.username,pnode->data.username);	
			strcpy(ret_val.password,pnode->data.password);
			free(pnode);	//释放内存
			pnode=NULL;

			list->len--;
			return ret_val;	//找到相同数据
		}

			pnext=pnext->next;
			pnode=pnode->next;
	}

	return ret_val;	//未找到相同数据

}






/*
	打印链表内容
*/

void printNode(List list)
{
	int i=1;
	Node pnode=list->head.next;
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

int compare(elem_t e1,char * str)
{
	if(strcmp(e1.username,str)!=0)	//只判断用户名
		return 0;
	return 1;
}


/*
	功能：判断用户名不得重复 
	参数：链表指针 和 比较函数指针
	返回：如果相同返回1，不同为0
*/

int equalUsername(List list,int (*pfun)(elem_t e1,char * str),char * str)
{
	Node pnode=list->head.next;

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