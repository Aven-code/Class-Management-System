
/*
	���ļ��������й���ѧ���Ĳ���������
	�Լ�ѧ��������������ӿ�

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "console.h"

/*
	���ܣ���ʼ��ѧ������
	������
	���أ��޷���
*/

void initList_stu(list_pstu list)
{
	list->head.next=NULL;
	list->len=0;
}


/*
	���ܣ��ж�ѧ�������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾ�գ�����Ϊ0
*/
int isEmpty_stu(list_pstu list)
{
	if(list->len==0)
		return 1;
	return 0;
}


/*
	���ܣ�ѧ���������
	����������ָ�룬������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int addNode_stu(list_pstu list,data_pstu data)
{
	node_pstu pnode,pnext;
	pnode=(node_pstu)malloc(sizeof(node_stu));

	if(!pnode)
	{
		//fprintf(stderr,"�����ڴ�ʧ��");
		return 0;
	}

	//��Ԫ�ش��뵽�ڵ���
	memcpy(&pnode->basic,data,sizeof(data_stu));
	//ָ��ͷ��㣬�������β�ڵ�
	pnext=&list->head;
	
	pnode->next=pnext->next;
	pnext->next=pnode;

	list->len++;
	return 1;

}

/*
	���ܣ�	ɾ���ڵ�
	������	pnode Ҫɾ���Ľڵ��ǰһ���ڵ�
	����ֵ���ɹ�����0��ʧ�ܷ���-1
*/
int delNode_stu(node_pstu pnode)
{
	pnode->next=pnode->next->next;
}


/*
	���ܣ�	����ѧ��ɾ���ڵ�
	������	list	����ָ��
			sno		��Ҫɾ���ڵ��ѧ��
	���أ�	�ɹ�����0��ʧ��-1(δ�ҵ�֮���)
*/
int delNode_stu_sno(list_pstu list,int sno)
{
	node_pstu pnode=NULL,prev=NULL;
	pnode=snoCheck(list,sno);	//��������ڵ�
	if(!pnode || !list->head.next)
		return -1;

	//�ҵ�Ҫ��ɾ�Ľڵ��ǰһ���ڵ�
	prev=&list->head;
	while(prev->next!=pnode)
	{
		prev=prev->next;
	}
	//��������ժ����Ҫ���Ƴ��Ľڵ�
	delNode_stu(prev);
	free(pnode);
	pnode=NULL;

}




/*
	���ܣ�����ѧ������
	����������ָ��
	���أ���
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
	��ӡ��������
*/
void printNode_stu(list_pstu list)
{
	int i=1;
	node_pstu pnext=list->head.next;
	/*
		�������Ϊ�գ���ʾ�û�
	*/
	if(isEmpty_stu(list)){
		printf("����Ϊ��");
		return ;
	}

	while(pnext)
	{
		printf("%d :ѧ�ţ�%d, ������%s ,�Ա�%s,�������£�%s,���᣺%s ,��ѯʦ��%s", pnext->basic.sno,pnext->basic.name,pnext->basic.sex,pnext->basic.brith,pnext->basic.naPlace,pnext->basic.consult);
		pnext=pnext->next;
		i++;
	}


}



/*
	���ܣ� ����ѧ�ţ�����ѧ��

*/

node_pstu snoCheck(list_pstu list,int sno)
{
	node_pstu pnode,ret_val=NULL;
	pnode=list->head.next;

	while(pnode)
	{
		//�����ͬ
		if(sno_equal(pnode->basic.sno,sno))
		{
			return pnode;
		}
		pnode=pnode->next;
	}
	return ret_val;
}

/*
	���ܣ�	ѧ��ѧ�ŵ�ƥ����
	������	ѧ��1��ѧ��2
	����ֵ����ͬ����1����ͬ����0
*/
int sno_equal(int sno1,int sno2)
{
	if(sno1==sno2)
		return 1;
	return 0;

}


/*
	���ܣ�	��ӡѧ����Ϣ(��stuTable ������Ӧ)
	������	data ѧ���ṹ��	//����Ӧ���õ�ַ��
	����ֵ����
*/
void print_stu(data_stu data,int x,int y)
{
	gotoxy(x,y);
	printf("%4d\040\040\040%6s\040%6s\040\040\040\040%6s\040\040%10s\040%8s",data.sno,data.name,data.sex,data.naPlace,data.brith,data.consult);
}