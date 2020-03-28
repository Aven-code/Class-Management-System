/*

	���ļ��������й��ڰ༶�Ĳ���������
	�Լ��༶������������ӿ�

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"
#include "mlayout.h"

/*
	����������
*/


//��ʼ��

void InitList_class(list_pclass list)
{
	list->head.next=NULL;
	list->len=0;
}

/*
	���ܣ��ж������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾΪ��,����0��Ϊ��
*/

int isEmpty_class(list_pclass list)
{
	if(list->len==0)
		return 1;
	return 0;
}

//���ӽڵ�
int  addNode_class(list_pclass list,class_elem e)
{
	node_pcla pnode,pnext;		//�ڵ�ָ��
	pnode = (node_pcla)malloc(sizeof(class_elem));

	if(!pnode)
	{
		printf("�����ڴ�ʧ��!");
		return 0;
	}

	/*
		��Ԫ�ش��ڽڵ���
	*/
	
	memcpy(&pnode->elem,&e,sizeof(class_elem));
	pnext=&list->head;
	pnode->next=pnext->next;
	pnext->next=pnode;

	list->len++;
	return 1;
}




/*
	���ܣ����ݴ���Ĳ�����ƥ�����������������򣬳ɹ���ɾ��
	����������ͷָ�룬������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int delNode_class(list_pclass list,char * str )
{
	node_pcla pnode,pnext;
	pnode=&list->head;
	pnext=pnode->next;

	/*
		�������Ϊ�գ����޷�ɾ��
	*/
	if(isEmpty_class(list))
	{
		return 0;
	}

	while(pnext)
	{
		if(compare_class(pnext->elem,str))//�жϰ༶���Ƿ���ͬ
		{
			//ɾ���ڵ�
			pnode->next=pnext->next;
			free(pnext);
			pnext=NULL;
			list->len--;
			return 1;//�ҵ���ͬ���� ����ɾ��
			
		}
		pnode=pnode->next;
		pnext=pnext->next;
	}

	return 0;	//δ�ҵ���ͬ����

}


/*
	���ܣ�ƥ��༶������
	������class_elem ���ͺ� �����û�������ַ���
	���أ�ƥ��ɹ�����1��ƥ��ʧ�ܷ���0

*/
int compare_class(class_elem e,char *str)
{
	if(strcmp(e.class_name,str)==0)
		return 1;
	return 0;

}


/*
	����:����������
	����������ָ��
	���أ���
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
	�����ǿγ�����ĺ���
*/

/*
	���ӽڵ�
*/