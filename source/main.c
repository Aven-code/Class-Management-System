#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>
#include "mlayout.h"
#include "structure.h"
#include "account.h"

int INDEX=1;				//������±�
int listIndex=2;			//����洢������±�
int X1=10;					//����Ŀ�
int Y1=10;					//����ĸ�
int FLAG=0;					//�����û���¼���
int SIGN=1;					//��ͨ�û���¼���
char USERNAME[USNLEN]="��ʱ�û�";	//��ͨ�û����û���


void sytheside();


int main(void)
{
	
#if 1

	srand((unsigned int)time(NULL)); //�������
	
	sytheside();//��ʼ
#else	
	//studentTable(1,1);
	table(0,5,28,1);

#endif
	return 0;
}



/*
	����:�ۺϺ���
*/

void sytheside()
{
	int index;
	print_check(0);		//����
	cursor_hide();	//���ع��
	printf("\n\n\n\n\t���¡�Enter��������ϵͳ������");
	get_enter();
	initTreeArrays();	//��ʼ��
	index=print_check(1);
	for(;;)	//��ѭ��
	{
		index=print_check(index);
		
	}


};