/*
	���ļ������ݣ�
		����ṹ��
		����㣬�û���ѧ�����༶.....
		���ʱ��Ľṹ��
		��ʼ����������ת�ڵ㺯����ԭ��

*/

#ifndef _STRUCTURE_H_
#define	_STRUCTURE_H_



#define MAX 100	//�������ֵ


//ʱ��Ľṹ��
typedef struct date{
	int year;
	int month;
	int day;
}Date;



//�������ڵ�ṹ��С����
typedef struct nod
{
	int index;
	struct nod * next;
}node;
typedef node * Node;

/*�ڵ�����������Ԫ��*/
typedef struct
{
	int parent;				//���ڵ�
	int number;				//�ȵĸ�����
	Node  firstChild;		//������
}ptree;


/*����ṹ����*/
ptree Tree[MAX];


/*����ԭ�͡�������������������������������������������*/

/*
	���ܣ������±���֮��Ӧ�ĺ���
	����������һ�����β���
*/
int print_check(int index);

/*
	��ʼ������
	������
*/
void  initTreeArrays();

/*
	���ܣ�������ӽڵ�
	������total�Ǹ��ڵ�Ķ�
	����ֵ����
*/
Node addList(int total);


#endif 