#ifndef _LIST_H_
#define _LIST_H_



#define USLEN 13	//�����û��������ʮ����
#define	PSWORD 8	//�����Ϊ��λ
/*
	����������
*/
typedef struct elem_
{
	char username [USLEN]; 	
	char password [PSWORD];
}elem_t;


/*
	�ڵ�����
*/
typedef struct _node
{
	elem_t data;
	struct _node * next;
}node_t;



/*
	��������������
*/
typedef struct 
{
	node_t head;	//�ڵ����� �ƽڵ�
	unsigned int len;		//����
}list_t;



typedef list_t * List;
typedef node_t * Node;	//����ָ��





/*����ԭ��*/
	


/*
	���ܣ��ж������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾΪ��,����0��Ϊ��
*/

int isEmpty(List list);

/*
	��ʼ������
*/
void InitList(List list);



/*
	���ܣ���ͷ���룩�������ݣ������ڵ�
	������ͷָ�룬�ڵ�ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int  addNode(List list,elem_t * e);

/*
	��ӡ��������
*/

void printNode(List list);

/*
	�ȽϺ������Ƚ������������е�username �Ƿ�һ��
	��ͬ����1����ͬ����0
	
*/

int compare(elem_t e1,char * str);


/*
	���ܣ����ݴ���Ĳ�����ƥ�����������������򣬳ɹ���ɾ��
	����������ͷָ�룬������ָ��
	���أ�һ�����������ͣ����㷵��
*/

elem_t delNode(List list,char *str);



/*
	���ܣ��ж��û��������ظ� 
	����������ָ�� �� �ȽϺ���ָ��
	���أ������ͬ����1����ͬΪ0
*/

int equalUsername(List list,int (*pfun)(elem_t e1,char * str),char * str);



#endif 