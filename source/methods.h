#ifndef _METHODS_H_
#define _METHODS_H_
#include "structure.h"
#include <stdio.h>
/*
	���ܣ���ȡ�ַ���
	�������ַ���������
*/
char * sget_s(char * str,int n);




/*
	ʵ��5��λ�Ĺ��ܡ�������Ա��¼
*/
int superUser(int sub);



/*
	ʵ��6��λ�Ĺ��ܡ���ע�����û�
*/
int addUser(int sub);


/*
	ʵ��7�Ź���λ����ɾ���û�
*/
int delUser(int sub);


/*
	���ܣ�ʵ��8#��λ�Ĺ��ܡ����ж��û���¼
	������x,y��� �±�
	���أ��ɹ�����1��ʧ��0
*/
int checkUser(int x,int y,int sub);


/*
	ʵ��9��λ�Ĺ��ܡ����޸�����
*/
int changePsd(int sub);

/*
	ʵ��10��λ���ܡ����˳���¼
*/
int logOut(int sub);



/*
	ʵ��19��λ�Ĺ��ܡ�������ѧ��
*/
int addStudents(int sub);


/*
	ʵ��23��λ�Ĺ��ܡ�����ȡ�ݽ���
*/
int drawingLecture(int sub);



/*
	ʵ��24��λ�Ĺ��ܡ���Ԥ���ݽ���
*/
int readyLecture(int sub);


/*
	����������
*/
int countLength(Node np);



/*	��ӡ�����ֵ*/
void printVal(Node np);

/*
	���ܣ��ַ������ð������ַ����Ʊ��
	����: �����ַ���
	���أ���������1��δ��������0
*/
int	incluSpecial(char *str);


/*
	���ܣ���չ�߿�
	���������߿�߶���չ����
	���أ��޷���
*/
void extensionHigh(int value);

/*
	���ܣ���ӡ����ɫ����ʾor��ʾ
	������flagֵΪ1�ǳɹ���ǣ�Ϊ2��ʧ�ܣ�Ϊ3�ǹ��ܱ�����ʾ��xy��Ӧxy�����꣬str�û�������ʾ��Ϣ
	���أ���
*/
void warn(int flag,int x,int y,char *str);


/*
	��������
*/
void myscanf(int *p);
#endif