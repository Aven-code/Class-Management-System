
/*
	此文件包含所有关于学生的操作函数，
	以及学生链表操作函数接口

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "console.h"

/*
	功能：初始化学生链表
	参数：
	返回：无返回
*/

void initList_stu(list_pstu list)
{
	list->head.next=NULL;
	list->len=0;
}


/*
	功能：判断学生链表是否为空
	参数：链表指针
	返回：返回1表示空，不空为0
*/
int isEmpty_stu(list_pstu list)
{
	if(list->len==0)
		return 1;
	return 0;
}


/*
	功能：学生链表添加
	参数：链表指针，数据域指针
	返回：成功返回1，失败返回0
*/
int addNode_stu(list_pstu list,data_pstu data)
{
	node_pstu pnode,pnext;
	pnode=(node_pstu)malloc(sizeof(node_stu));

	if(!pnode)
	{
		//fprintf(stderr,"开辟内存失败");
		return 0;
	}

	//将元素存入到节点里
	memcpy(&pnode->basic,data,sizeof(data_stu));
	//指向头结点，方便查找尾节点
	pnext=&list->head;
	
	pnode->next=pnext->next;
	pnext->next=pnode;

	list->len++;
	return 1;

}

/*
	功能：	删除节点
	参数：	pnode 要删除的节点的前一个节点
	返回值：成功返回0，失败返回-1
*/
int delNode_stu(node_pstu pnode)
{
	pnode->next=pnode->next->next;
}


/*
	功能：	根据学号删除节点
	参数：	list	链表指针
			sno		需要删除节点的学号
	返回：	成功返回0，失败-1(未找到之类的)
*/
int delNode_stu_sno(list_pstu list,int sno)
{
	node_pstu pnode=NULL,prev=NULL;
	pnode=snoCheck(list,sno);	//查找这个节点
	if(!pnode || !list->head.next)
		return -1;

	//找到要被删的节点的前一个节点
	prev=&list->head;
	while(prev->next!=pnode)
	{
		prev=prev->next;
	}
	//从链表上摘下需要被移除的节点
	delNode_stu(prev);
	free(pnode);
	pnode=NULL;

}




/*
	功能：销毁学生链表
	参数：链表指针
	返回：无
*/
void destroy_stu(list_pstu list)
{
	node_pstu pnode,pnext;
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
void printNode_stu(list_pstu list)
{
	int i=1;
	node_pstu pnext=list->head.next;
	/*
		如果链表为空，提示用户
	*/
	if(isEmpty_stu(list)){
		printf("链表为空");
		return ;
	}

	while(pnext)
	{
		printf("%d :学号：%d, 姓名：%s ,性别：%s,出生年月：%s,籍贯：%s ,咨询师：%s", pnext->basic.sno,pnext->basic.name,pnext->basic.sex,pnext->basic.brith,pnext->basic.naPlace,pnext->basic.consult);
		pnext=pnext->next;
		i++;
	}


}



/*
	功能： 输入学号，查找学生

*/

node_pstu snoCheck(list_pstu list,int sno)
{
	node_pstu pnode,ret_val=NULL;
	pnode=list->head.next;

	while(pnode)
	{
		//如果相同
		if(sno_equal(pnode->basic.sno,sno))
		{
			return pnode;
		}
		pnode=pnode->next;
	}
	return ret_val;
}

/*
	功能：	学生学号的匹配器
	参数：	学生1，学生2
	返回值：相同返回1，不同返回0
*/
int sno_equal(int sno1,int sno2)
{
	if(sno1==sno2)
		return 1;
	return 0;

}


/*
	功能：	打印学生信息(与stuTable 函数对应)
	参数：	data 学生结构体	//这里应该用地址的
	返回值：无
*/
void print_stu(data_stu data,int x,int y)
{
	gotoxy(x,y);
	printf("%4d\040\040\040%6s\040%6s\040\040\040\040%6s\040\040%10s\040%8s",data.sno,data.name,data.sex,data.naPlace,data.brith,data.consult);
}