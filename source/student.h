/*
	students.c�ļ��ĺ���ԭ��
*/

#define STUDNAME	11	//����
#define BRITHDAT	13	//������
#define NATPLACE	15	//���� 
#define CONTEACHER	21	//��ѯʦ
#define SEX			4	//�Ա�

/*������ṹ*/
typedef struct data_student
{
	int	 sno; 				 //ѧ��
	char name[STUDNAME];	 //����
	char sex[SEX];			 //�Ա�
	char brith[BRITHDAT];	 //��������
	char naPlace[NATPLACE];	 //����
	char consult[CONTEACHER];//��ѯʦ

}data_stu;

typedef data_stu * data_pstu;	//������ָ������


/*�ڵ�ṹ*/
typedef struct node_student
{
	data_stu basic;				//���������ͱ���
	struct node_student * next;	//nextָ��
}node_stu;

typedef node_stu * node_pstu;	//�ڵ�ָ������


/*����ṹ*/
typedef struct 
{
	node_stu head;		//�ڵ����ͱ���
	int len;			//���ȱ���
}list_stu;

typedef list_stu * list_pstu;	//����ָ������

/*����ԭ��---------------------------------------------*/


/*
	���ܣ��ж�ѧ�������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾ�գ�����Ϊ0
*/
int isEmpty_stu(list_pstu list);

/*
	���ܣ���ʼ��ѧ������
	������list ����ָ��
	���أ��޷���
*/
void initList_stu(list_pstu list);



/*
	���ܣ�ѧ���������
	����������ָ�룬������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int addNode_stu(list_pstu list,data_pstu data);


/*
	���ܣ�����ѧ������
	����������ָ��
	���أ���
*/
void destroy_stu(list_pstu list);



/*
	��ӡ��������
*/
void printNode_stu(list_pstu list);


/*
	���ܣ�	��list�в���ѧ��
	������	list	����ָ��
			sno		��Ҫ���ѧ��
	����ֵ���ҵ��˷����Ǹ��ڵ㣬δ�ҵ�����NULL
*/

node_pstu snoCheck(list_pstu list,int sno);


/*
	���ܣ�	ѧ��ѧ�ŵ�ƥ����
	������	ѧ��1��ѧ��2
	����ֵ����ͬ����1����ͬ����0
*/
int sno_equal(int sno1,int sno2);



/*
	���ܣ�	��ӡѧ����Ϣ
	������	data ѧ���ṹ��	//����Ӧ���õ�ַ��
	����ֵ����
*/
void print_stu(data_stu data,int x,int y);


/*
	���ܣ�	����ѧ��ɾ���ڵ�
	������	list	����ָ��
			sno		��Ҫɾ���ڵ��ѧ��
	���أ�	�ɹ�����0��ʧ��-1(δ�ҵ�֮���)
*/
int delNode_stu_sno(list_pstu list,int sno);


/*
	���ܣ�	����ѧ��ɾ���ڵ�
	������	list	����ָ��
			sno		��Ҫɾ���ڵ��ѧ��
	���أ�	�ɹ�����0��ʧ��-1(δ�ҵ�֮���)
*/
int delNode_stu_sno(list_pstu list,int sno);