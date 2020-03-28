/*
	���ļ���
	����ӿ�ʵ���ļ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/*

	����6ע���û��͹���7ɾ���û�����ؽṹ�ͺ���

*/


/*
	���ܣ��ж������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾΪ��,����0��Ϊ��
*/

int isEmpty(List list)
{
	if(list->len==0)
		return 1;
	return 0;
}

/*
	��ʼ������
*/
void InitList(List list)
{
	list->head.next=NULL;
	list->len=0;
}



/*
	���ܣ���ͷ���룩�������ݣ������ڵ�
	������ͷָ�룬�ڵ�ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int  addNode(List list,elem_t * e)
{
	Node pnode,pnext;
	pnode=(Node)malloc(sizeof(node_t));

	if(!pnode)
	{
		printf("�����ڴ�ʧ��");
		return 0;
	}


	//��Ԫ�ش��뵽�ڵ���
	memcpy( &pnode->data, e , sizeof(elem_t));
	pnext=&list->head;	//ָ��ͷ��㣬�������β�ڵ�
	pnode->next=pnext->next;
	pnext->next=pnode;

/*
	
	pnext=&list->head;	//ָ��ͷ��㣬�������β�ڵ�

	pnode->next=NULL
	while(pnext->next)	//ѭ����β��
	{
		pnext=pnext->next;
	}

	pnext->next=pnode;


*/




	list->len++;


	return 1;
}


/*
	���ܣ����ݴ���Ĳ�����ƥ�����������������򣬳ɹ���ɾ��
	����������ͷָ�룬������ָ��
	���أ�һ�����������ͣ����㷵��
*/

elem_t delNode(List list,char *str)
{
	elem_t ret_val={NULL,NULL};					//����ֵ
	//strcpy(ret_val.username,NULL);	
	//strcpy(ret_val.password,NULL);

	Node pnode,pnext;	
	pnext=&list->head;
	pnode=list->head.next;
	/*
		�������Ϊ�����޷�ɾ��
	*/
	if(isEmpty(list))
	{
		
		return ret_val;
	}



	while(pnode)
	{
		
		if(compare(pnode->data,str))//�ж������Ƿ���ͬ
		{
			
			pnext->next=pnode->next;

			strcpy(ret_val.username,pnode->data.username);	
			strcpy(ret_val.password,pnode->data.password);
			free(pnode);	//�ͷ��ڴ�
			pnode=NULL;

			list->len--;
			return ret_val;	//�ҵ���ͬ����
		}

			pnext=pnext->next;
			pnode=pnode->next;
	}

	return ret_val;	//δ�ҵ���ͬ����

}






/*
	��ӡ��������
*/

void printNode(List list)
{
	int i=1;
	Node pnode=list->head.next;
	/*�������Ϊ�գ���ӡ��ֵ*/
	if(isEmpty(list))
	{
		printf("����Ϊ��");
		return ;
	}

	while(pnode){
		
		printf("%d:�û�����%s,���룺%s\n",i,pnode->data.username,pnode->data.password);
		pnode=pnode->next;
		i++;
	}

}




/*
	�ȽϺ������Ƚ������������е�username �Ƿ�һ��
	��ͬ����1����ͬ����0
	
*/

int compare(elem_t e1,char * str)
{
	if(strcmp(e1.username,str)!=0)	//ֻ�ж��û���
		return 0;
	return 1;
}


/*
	���ܣ��ж��û��������ظ� 
	����������ָ�� �� �ȽϺ���ָ��
	���أ������ͬ����1����ͬΪ0
*/

int equalUsername(List list,int (*pfun)(elem_t e1,char * str),char * str)
{
	Node pnode=list->head.next;

	while(pnode)
	{
		/*�����ͬ*/
		if(pfun(pnode->data,str))
		{
			return 1;
		
		}
		pnode=pnode->next;
	}
	return 0;
}