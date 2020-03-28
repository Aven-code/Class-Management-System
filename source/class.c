/*

	此文件包含所有关于班级的操作函数，
	以及班级链表操作函数接口

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"
#include "mlayout.h"

/*
	相关链表操作
*/


//初始化

void InitList_class(list_pclass list)
{
	list->head.next=NULL;
	list->len=0;
}

/*
	功能：判断链表是否为空
	参数：链表指针
	返回：返回1表示为空,返回0不为空
*/

int isEmpty_class(list_pclass list)
{
	if(list->len==0)
		return 1;
	return 0;
}

//增加节点
int  addNode_class(list_pclass list,class_elem e)
{
	node_pcla pnode,pnext;		//节点指针
	pnode = (node_pcla)malloc(sizeof(class_elem));

	if(!pnode)
	{
		printf("开辟内存失败!");
		return 0;
	}

	/*
		将元素存在节点里
	*/
	
	memcpy(&pnode->elem,&e,sizeof(class_elem));
	pnext=&list->head;
	pnode->next=pnext->next;
	pnext->next=pnode;

	list->len++;
	return 1;
}




/*
	功能：根据传入的参数，匹配链表中已有数据域，成功则删除
	参数：传入头指针，数据域指针
	返回：成功返回1，失败返回0
*/
int delNode_class(list_pclass list,char * str )
{
	node_pcla pnode,pnext;
	pnode=&list->head;
	pnext=pnode->next;

	/*
		如果链表为空，则无法删除
	*/
	if(isEmpty_class(list))
	{
		return 0;
	}

	while(pnext)
	{
		if(compare_class(pnext->elem,str))//判断班级名是否相同
		{
			//删除节点
			pnode->next=pnext->next;
			free(pnext);
			pnext=NULL;
			list->len--;
			return 1;//找到相同数据 并且删除
			
		}
		pnode=pnode->next;
		pnext=pnext->next;
	}

	return 0;	//未找到相同数据

}


/*
	功能：匹配班级的名字
	参数：class_elem 类型和 传入用户输入的字符串
	返回：匹配成功返回1，匹配失败返回0

*/
int compare_class(class_elem e,char *str)
{
	if(strcmp(e.class_name,str)==0)
		return 1;
	return 0;

}


/*
	功能:销毁链表函数
	参数：链表指针
	返回：无
*/
void destroy_class(list_pclass list)
{
	node_pcla pnode,pnext;
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
	以下是课程链表的函数
*/

/*
	增加节点
*/