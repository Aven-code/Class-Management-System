/*
	���ļ���¼ÿ��ѡ���
	����Ľṹ��ʵ��
*/
#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "methods.h"
#include "mlayout.h"	//���ý��溯�� 
#include "structure.h"

 extern int INDEX; 
 extern int listIndex; 
/*
	��ʼ������
	������
*/
void  initTreeArrays()
{

	Node a=addList(3);	//������һ�Žڵ�
	/*������8��С����*/
	Node b,c,d,e,f,g,h;
	int i=1,x=11;

	ptree stem={
		0,				//���ڵ�
		3,				//�ȵĸ���
		a				//������
	};
	Tree[INDEX++]=stem;	//�༶����ϵͳ ���ڵ�


	/*��2��С�������Žڵ㣬����С�����ͬʱ������������Ԫ�أ������뵽������*/

	b=addList(3);			//����ڵ�Ķ�
	stem.parent=1;	
	stem.number=3;			//�ýڵ��µĶ�
	stem.firstChild=b;
	Tree[INDEX++]=stem;		//ע�����


	/*��3��С�������Žڵ�*/
	c=addList(3);
	stem.parent=1;	
	stem.number=3;
	stem.firstChild=c;
	Tree[INDEX++]=stem;		//ϵͳ����


	/*4�Žڵ�*/ 
	stem.parent=1;	
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//�˳�ϵͳ

	/*5�Žڵ�*/ 
	stem.parent=2;	
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//�����û���¼

	/*6�Žڵ� */
	stem.parent=2;	
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//ע���½�ɫ

	/*#7�Žڵ�*/
	stem.parent=2;		
	stem.number=0;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//ɾ���û�


	/*8�Žڵ� */
	d=addList(4);
	stem.parent=3;	
	stem.number=4;
	stem.firstChild=d;
	Tree[INDEX++]=stem;		//��¼�ɹ�

	/*9�Žڵ� */
	stem.parent=3;	
	stem.number=0                                                                    ;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//�޸�����

	/*10�Žڵ� */
	stem.parent=3;	
	stem.number=0                                                                    ;
	stem.firstChild=NULL;
	Tree[INDEX++]=stem;		//�˳���¼


	/*11�Žڵ� */
	e=addList(4);
	stem.parent=8;	
	stem.number=4;
	stem.firstChild=e;
	Tree[INDEX++]=stem;		//�༶����

	/*12�Žڵ� */
	f=addList(4);
	stem.firstChild=f;
	Tree[INDEX++]=stem;		//ѧ������


	/*13�Žڵ� */
	g=addList(4);
	stem.firstChild=g;
	Tree[INDEX++]=stem;		//�༶����

	/*14�Žڵ� */
	h=addList(4);
	stem.firstChild=h;
	Tree[INDEX++]=stem;		//���ڹ���




	//ѭ�������ڵ㣬i=1
	while(i<=16){
		switch(i)
		{
		case 5:
			x++;
			break;
		case 9:
			x++;
			break;
		case 13:
			x++;
			break;
		}
		stem.parent=x;			//15-30��С�ڵ�ĸ��ڵ�
		stem.number=0;			//����0���ӽڵ�
		stem.firstChild=NULL;	//ÿ���ڵ㶼��һ����ʵ���ܺ���
		Tree[INDEX++]=stem;		//������뵽������
		i++;
	}

}

/*
	���ܣ�������Ӻ���
	������total�Ǹ��ڵ�Ķ�
	����ֵ����
*/
Node addList(int total)
{
	int i;
	Node stemp,stemp2,np;;
	
	
	//�ȿ���һ��
	stemp=(Node)malloc(sizeof(node));
	stemp->next=NULL;
	stemp->index=listIndex++;
	np=stemp2=stemp;
	
	//����ʣ�µ�
	for(i=1;i<total;i++)
	{
		stemp=(Node)malloc(sizeof(node));
		stemp->next=NULL;
		stemp->index=listIndex++;
		stemp2->next=stemp;
		stemp2=stemp;
	}
	
	return np;
}




/*
	ͨ�����ص��±���ú���
*/
int print_check(int index)
{
	int ret_val=0;
	switch(index)
	{
	case 0:	
		home();						//���ý��溯��
		break;
	case 1:
		ret_val=listA(index);		//�����溯�� ��ʾ��a����
		break;
	case 2:
		ret_val=listB(index);		//ע������� ��ʾ��b����
		break;
	case 3:
		ret_val=listC(index);		//��¼������ ��ʾ��c����
		break;
	case 4:	
		ret_val=quit();				//�˳�ϵͳ����
		break;
	case 5:
		ret_val=superUser(index);	//�����û���¼
		break;
	case 6:
		ret_val=addUser(index);		//ע�����û�
		break;
	case 7:
		ret_val=delUser(index);		//ɾ���û�
		break;
	case 8:
		ret_val=listD(index);		//��ʾ��d���� �༶����ѧ��������������ڹ���
		break;
	case 9:
		ret_val=changePsd(index);	//�޸����� 
		break;
	case 10:
		ret_val=logOut(index);		//�˳���¼
		break;
	case 11:
		ret_val=listE(index);		//��ʾ��e���� ע��༶���޸İ༶��Ϣ����ѯ�༶��Ϣ��ɾ���༶
		break;
	case 12:
		ret_val=listF(index);		//��ʾ�� f���� ����ѧ�����޸�ѧ����Ϣ����ѯѧ����Ϣ��ɾ��ѧ��
		break;
	case 13:
		ret_val=listG(index);		//��ʾ�� g���� �ݽ��˹����ݽ����ݼ�ǣ��ݽ������޸ģ�
		break;
	case 14:
		ret_val=listH(index);		//��ʾ�� h���� ��¼����,���Ŀ���,��ѯ���ڣ����ڼ�¼ɾ�� 
		break;
	case 15:						//ע��༶
		ret_val=waitExploit(index);
		break;
	case 16:						//�޸İ༶��Ϣ
		ret_val=waitExploit(index);
		break;
	case 17:						//��ѯ�༶��Ϣ
		ret_val=waitExploit(index);
		break;	
	case 18:						//ɾ���༶
		ret_val=waitExploit(index);
		break;
	case 19:						//����ѧ��
		ret_val=addStudents(index);
		break;
	case 20:						//�޸�ѧ����Ϣ
		ret_val=changeStudnets(index);
		break;
	case 21:						//��ѯѧ����Ϣ
		ret_val=waitExploit(index);
		break;
	case 22:						//ɾ��ѧ��
		ret_val=waitExploit(index);
		break;
	case 23:						//�ݽ��˳�ȡ
		ret_val=drawingLecture(index);
		break;
	case 24:						//Ԥ���ݽ���
		ret_val=readyLecture(index);
		break;
	case 25:						//���ݼ��
		ret_val=waitExploit(index);
		break;
	case 26:						//�ݽ�������
		ret_val=waitExploit(index);
		break;
	case 27:						//��¼����
		ret_val=waitExploit(index);
		break;
	case 28:						//���Ŀ���
		ret_val=waitExploit(index);
		break;
	case 29:						//��ѯ����
		ret_val=waitExploit(index);
		break;
	}

	return ret_val;

}





