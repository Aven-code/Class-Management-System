#ifndef _MLAYOUT_H_
#define _MLAYOUT_H_
/*
	��λ�������ͷ
*/

void clear(int x,int y);

/*
	��λ�������ͷ
*/
void output(int x,int y);



/*
	���ܣ�����༶����ϵͳ�ַ����������û�Enter����
	������
	���أ�
*/
void home();

/*
	�߿򻭳���
*/
void border();


/*
	ʵ��1��λ�Ĺ��ܣ���ӡa��
*/
int listA(int);

/*
	ʵ��2��λ�Ĺ���,��ӡb
*/
int listB(int);

/*
	ʵ��3��λ�Ĺ���,��ӡb
*/
int listC(int);

/*
	ʵ��4��λ�Ĺ���
*/
int quit();



/*
	ʵ��7��λ�Ĺ��ܡ�����¼�û�
*/
int listD(int sub);




/*
	ʵ��9��λ���ܣ���ӡE�����༶����
*/

int listE(int sub);

/*
	ʵ��10��λ���ܣ���ӡF����ѧ������
*/

int listF(int sub);

/*
	ʵ��11�Ź��ܣ���ӡG���������
*/

int listG(int sub);

/*
	ʵ��12�Ź��ܣ���ӡH�������ڹ���
*/
int listH(int sub);


/*��¼�����ַ���*/

void errorLogin(int x,int y);


/*��¼�ɹ��ַ���*/

void succeedLogin(int x,int y);



/*	
	���ܣ���ܰ��ʾ
	����������xy�����꣬�����ӡ,i��ʾ�ǲ��ֹ��ܵ���ܰ��ʾ�� 1����ʾע�ᡢ2��ɾ��
	���أ����ص�ǰy�������ֵ
*/
int prompt(int x,int y,int i);




/*
	���ܣ���ӡ���
	������x����y�ᣬ�߶�����
	���أ��޷���
*/

void table(int x,int y,int width_max,int heigh_max);



/*
	���ܣ���ӡ���ݴ�����
	������
	���أ�

*/
int waitExploit(int sub);


/*
	���ܣ� ��ӡѧ���б�ĸ�ʽ(�൱�ڷ�װһ��table��������ѧ����ʽ)
	������x,y ��xy���ĸ��㿪ʼ��
	���أ��޷���
*/
void studentTable(int x,int y);
#endif