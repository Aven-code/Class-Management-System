/*
	ʵ�ֽӿڣ������˻���Ϣ�Ĳ�����غ���

	����6��ע���û�
	����7��ɾ���û�
	����ؽṹ�ͺ���


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
	
//���ͣ� list_acc	ָ��	list_pacc
//���ͣ� node_acc	ָ��	node_pacc
//���ͣ� account	ָ��	account_p
	

/*
	���ܣ��ж������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾΪ��,����0��Ϊ��
*/

int isEmpty(list_pacc list)
{
	if(list->len==0)
		return 1;
	return 0;
}



/*
	��ʼ������
*/
void InitList(list_pacc list)
{
	list->head.next=NULL;
	list->len=0;
}



/*
	���ܣ���ͷ���룩�������ݣ������ڵ�
	������ͷָ�룬����������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int  addNode(list_pacc list,account_p  e)
{
	node_pacc pnode,pnext;
	pnode=(node_pacc)malloc(sizeof(node_acc));

	if(!pnode)
	{
	//	printf("�����ڴ�ʧ��");
		return 0;
	}

	
	//��Ԫ�ش��뵽�ڵ���
	memcpy( &pnode->data, e , sizeof(account));
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
	���أ��ɹ�����1��ʧ�ܷ���0
*/

int delNode(list_pacc list,char *str)
{
	
	node_pacc pnode,pnext;	
	pnode=&list->head;
	pnext=list->head.next;
	/*
		�������Ϊ�����޷�ɾ��
	*/
	if(isEmpty(list))
	{
		return 0;
	
	}

	while(pnext)
	{
		if(compare(pnext->data,str))//�ж������Ƿ���ͬ
		{
			
			pnode->next=pnext->next;
			free(pnext);	//�ͷ��ڴ�
			pnext=NULL;
			list->len--;
			return 1;	//�ҵ���ͬ����
		}

			pnode=pnode->next;
			pnext=pnext->next;
	}

	return 0;	//δ�ҵ���ͬ����

}


/*
	���ܣ�����������
	����������ָ��
	���أ���
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
	��ӡ��������
*/

void printNode(list_pacc list)
{
	int i=1;
	node_pacc pnode=list->head.next;
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

int compare(account e1,char * str)
{
	if(strcmp(e1.username,str)!=0)	//ֻ�ж��û���
		return 0;
	return 1;
}


/*
	�ȽϺ������Ƚ������������е�password �Ƿ�һ��
	��ͬ����1����ͬ����0
*/
int compare2(account e1,char * str)
{
	if(strcmp(e1.password,str)!=0)	//ֻ�ж��û���
		return 0;
	return 1;
}

/*
	���ܣ��ж��û��������ظ� 
	����������ָ�� �� �ȽϺ���ָ�룬�Ƚ��ַ���
	���أ������ͬ����1����ͬΪ0
*/

int equalUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str)
{
	node_pacc pnode=list->head.next;

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

/*
	���ܣ���ѯ�û����Ƿ����
	����������ָ�� �� �ȽϺ���ָ�룬�����ַ���
	���أ�������ڣ����ش��ڵ��Ǹ��ڵ㡣�����ڷ���null
*/

node_pacc findUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str)
{
	node_pacc pnode=list->head.next;

	while(pnode)
	{
		/*�����ͬ*/
		if(pfun(pnode->data,str))
		{
			return pnode;
		
		}
		pnode=pnode->next;
	}
	return NULL;//û�ҵ�
}

/*
	���ܣ�ͨ���û�����������
	�����������е�ĳ���ڵ㣬ƥ������ĺ���ָ��
	���أ�����ҵ�����1��δ����Ϊ0

*/
int userToPassword(node_pacc pnode,int (*pfun)(account e1,char * str),char * str)
{

	return pfun(pnode->data,str);

}