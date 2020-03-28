/*
	���ļ�������ڰ༶���ܵ���غ����ͽṹ
*/

#ifndef _CLASS_H_
#define _CLASS_H_
#include "structure.h"


#define CNAME		31			//�γ����Ƴ���
#define CMAJOR		31			//�γ�רҵ���Ƴ���
#define TEARNAME	11			//����������
#define CLASSNAME   21			//�༶����



/*
	����γ�����
*/

typedef struct course
{
	char curriculum[CNAME];		//�γ�����
	struct course * next;		//��һ������

}node_course;


/*
	����ʦΪ�������;Ϳ����γ�һ���γ��б�
*/

/*
	������ʦ�ṹ
*/
typedef struct teacher
{
	
	char tc_name[TEARNAME];	//��ʦ����
	node_course * next;			//��ʦ�ṹ�����˿γ�����

}list_teach;



/*
	����༶�ṹ
*/
typedef struct 
{

	char class_name[CLASSNAME];		//�༶����
	char major [CMAJOR];			//רҵ����
	Date reg_time;					//ע������
	Date open_class;				//��������
	Date graduation;				//��ҵ����
	int amount;						//����
	float len_learn;				//ѧϰʱ��
	char major_teach[TEARNAME];		//����������
	list_teach t;						//��ʦ����

}class_elem;



/*
	����ṹ
*/
//�ڵ�����
typedef struct node_tcla
{
	class_elem elem;	//Ԫ�ؽṹ
	struct node_tcla * next;	//ָ����һ��

}node_cla;


//����������
typedef struct list_cla
{	
	node_cla head;			//ͷ�ڵ�
	int  len;				//�ڵ㳤��
}list_class;



typedef list_class * list_pclass;	//����ָ��
typedef node_cla  *  node_pcla;		//�ڵ�ָ��



//��ʼ��

void InitList_class(list_pclass list);


/*
	���ܣ��ж������Ƿ�Ϊ��
	����������ָ��
	���أ�����1��ʾΪ��,����0��Ϊ��
*/

int isEmpty_class(list_pclass list);



//���ӽڵ�
int  addNode_class(list_pclass list,class_elem e);

/*
	���ܣ����ݴ���Ĳ�����ƥ�����������������򣬳ɹ���ɾ��
	����������ͷָ�룬������ָ��
	���أ��ɹ�����1��ʧ�ܷ���0
*/
int delNode_class(list_pclass list,char * str );

/*
	���ܣ�ƥ��༶������
	������class_elem ���ͺ� �����û�������ַ���
	���أ�ƥ��ɹ�����1��ƥ��ʧ�ܷ���0

*/
int compare_class(class_elem e,char *str);



/*
	����:����������
	����������ָ��
	���أ���
*/
void destroy_class(list_pclass list);


#endif