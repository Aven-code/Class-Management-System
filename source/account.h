#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#define USNLEN 15	//�����û�������
#define	PSWORD 9	//�����Ϊ��λ

/*
	��������������
*/
typedef struct acc
{
	char username [USNLEN]; 	
	char password [PSWORD];
}account;



/*
	�ڵ�����
*/
typedef struct node_a
{
	account data;
	struct node_a * next;
}node_acc;



/*
	��������������
*/ 
typedef struct 
{
	node_acc head;	//�ڵ����� �ƽڵ�
	unsigned int len;		//����
}list_acc;

typedef account  * account_p;
typedef list_acc * list_pacc;
typedef node_acc * node_pacc;	//ָ��




/*����ԭ��---------------------------------------------*/


/*
	���ܣ��ж������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾΪ��,����0��Ϊ��
*/

int isEmpty(list_pacc list);


/*
	���ܣ���ʼ������
	����������ָ��
	���أ��޷���
*/
void InitList(list_pacc list);


/*
	���ܣ���ͷ���룩�������ݣ������ڵ�
	����������ָ�룬������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int  addNode(list_pacc list,account_p acc);



/*
	���ܣ���ӡ��������
	����������ָ��
	���أ��޷���
*/
void printNode(list_pacc list);



/*
	���ܣ��Ƚ������������е�username �Ƿ�һ��
	������������ֵ�������û����ַ���
	���أ���ͬ����1����ͬ����0
	
*/

int compare(account e1,char * str);

/*
	���ܣ��Ƚ������������е�password �Ƿ�һ��
	������������ֵ�������û����ַ���
	���أ���ͬ����1����ͬ����0
*/
int compare2(account e1,char * str);

/*
	���ܣ����ݴ���Ĳ�����ƥ�����������������򣬳ɹ���ɾ��
	����������ͷָ�룬������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int delNode(list_pacc list,char *str);


/*
	���ܣ��ж��û��������ظ� 
	����������ָ�� �� �ȽϺ���ָ��
	���أ������ͬ����1����ͬΪ0
*/

int equalUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str);



/*
	���ܣ���ѯ�û����Ƿ����
	����������ָ�� �� �ȽϺ���ָ�룬�����ַ���
	���أ�������ڣ����ش��ڵ��Ǹ��ڵ㡣�����ڷ���null
*/

node_pacc findUsername(list_pacc list,int (*pfun)(account e1,char * str),char * str);


/*
	���ܣ�ͨ���û�����������
	�����������е�ĳ���ڵ㣬ƥ������ĺ���ָ��
	���أ�����ҵ�����1��δ����Ϊ0

*/
int userToPassword(node_pacc pnode,int (*pfun)(account e1,char * str),char * str);

/*
	���ܣ�����������
	����������ָ��
	���أ���
*/
void destroy(list_pacc list);


#endif