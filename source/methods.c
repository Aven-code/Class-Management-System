#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"
#include "mlayout.h"
#include "console.h"

/*
	���ļ�д����һЩ
	ʵ��ʵ�ʹ��ܵĺ����������Ǵ�ӡ���棩
*/


#include "structure.h"
#include "account.h"	//���ڵ�½�û�
#include "student.h"	//����ѧ��


#define SLEN 10	//����Ա��������ĳ���
#define VERIFY 3 //��֤��𰸳���

extern int X1;
extern int Y1;
extern int FLAG;
extern int SIGN;
extern char USERNAME[USNLEN];


/*
	����������
*/
int countLength(Node np)
{
	int count=0;
	Node stemp=np;
	while(stemp)
	{
		count++;
		stemp=stemp->next;
	}
	return count;
}

/*
	��ӡ�����ֵ
*/
void printVal(Node np)
{
	int i=1;
	Node stemp=np;
	while(stemp)
	{
		
		printf("N o.%d:%d\n",i,stemp->index);
		stemp=stemp->next;
		i++;
	}
}



/*
	���ܣ���ȡ�ַ���
*/
char * sget_s(char * str,int n)
{
	char * ret_val,* find;
	if(ret_val=fgets(str,n,stdin))
	{
		if(find=strchr(str,'\n'))
			*find='\0';
		else 
			while(getchar()!='\n')
				continue;
	}

	return ret_val;
}


/*
	ʵ��5��λ�Ĺ��ܡ��������û���¼
*/
int superUser(int sub)
{
	int key;
	int x=6,y=1;
	char username[SLEN];
	char password[SLEN];
	system("cls");
	X1=30;		//ֻ�ı����Ŀ��

	border();	
	/*����ѵ�¼*/
	if(FLAG){	

		//������ʾ
		warn(3,x-4,y,"��ǰ�˻��ѵ�¼��");
		
		gotoxy(x+14,y+3);
		printf("�Ƿ��˳���ǰ����Ա�˻�");
		gotoxy(x+14,y+5);
		printf("��Enterȷ��/ESCȡ����");
		/*�ж��Ƿ��˳�*/
		while(1)
			{
				key=get_key();
				if(key==ESC)	//�յ�ESC��������һ��
				{
					X1=10;
					return Tree[sub].parent;
				}else if(key==ENTER){
					FLAG=0;		//�������
					return sub;	//ˢ�µ�ǰҳ�����µ���һ�鵱ǰ������
				}
			}

		}

	/*δ��¼*/
	else
	{			
		/*������ʾ*/
		warn(3,x-4,y,"��¼����Ա�û���ȡ��ESC,Enter��ʾ��");
	
		
		/*�ж��û��Ƿ�ȡ��*/
		for(;;){
			key=get_key();
			if(key==ESC)	//�յ�ESC��������һ��
				{
					X1=10;
					return Tree[sub].parent;
				}
			else if(key==ENTER)
				break;
		}

		cursor_show();	//�����ʾ

		/*��ӡ����Ա�˻�*/
		gotoxy(x+14,y+3);
		printf("��	����");
		sget_s(username,SLEN);
		
		/*��ӡ����Ա����*/
		gotoxy(x+14,y+5);
		printf("��	�룺");
		sget_s(password,SLEN);
		cursor_hide();		//�������
		
		
		
		

		if(strcmp(username,"Admin")!=0 || strcmp(password,"123456")!=0 )//�������
		{
			system("cls");
			border();	
			
			/*������ʾ*/
			warn(3,x-4,y,"��¼����Ա�û�");
			
			/*ʧ�������ַ�*/
			errorLogin(x+16,y+2);
			while(!get_enter())//���Enter��
				continue;

			return sub;	//ֱ���˳�����
		}
		else															//������ȷ
		{
			FLAG=1;
			system("cls");
			border();	

			/*������ʾ*/
			warn(3,x-4,y,"��¼����Ա�û�");
	
			/*�ɹ������ַ�*/
			succeedLogin(x+16,y+2);
			while(!get_enter())//���Enter��
				continue;
			X1=10;
			return Tree[sub].parent;//������һ��
						
		}

	}

}


/*
	ʵ��6��λ�Ĺ��ܡ���ע�����û�
*/
int addUser(int sub)
{
	/*��ע����ر���*/
	int i,count,length;	//��ʱ����
	account e;			//�ݴ�Ԫ��
	list_acc list;		//�����������ͱ���
	node_pacc pnode;	//�ڵ�ָ��
	FILE * puser;		//�ļ�ָ��
	int size;			//�ṹ���С

	
/*end----------------------*/


	int key,pos=0;
	int x=6,y=1;
	system("cls");
	
	if(!FLAG)
	{	/*���δ��¼����Ա*/
		gotoxy(x+4,y+2);

		printf("ע�����˺���Ҫ����ԱȨ�ޣ����¼����Ա�˺ţ�");
		X1=30;
		Y1=5;
		border();
		while(1)
		{
			key=get_key();
			 if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
	
		}
	}
	/*�ѵ�¼����Ա��ʵ��ע�Ṧ��*/
	else
	{
		i=count=length=0;	//count ������ŵı���,Ҳ��ͬ�������len
		X1=34;				//iΪÿ�������˻�
		Y1=10;
		x=6;
		size=sizeof(account);
	

		/*	���ļ�	*/
		if((puser=fopen("user.dat","a+b"))==NULL)
		{
			gotoxy(x+2,y);
			printf("ERROR: ���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					return pos;
				}
			}
		}
		rewind(puser);//��λ���ļ���ʼ
		InitList(&list);//��ʼ������
		
		/*������ʾ*/
		warn(3,x,y+1,"+������˺�");
		warn(3,x,y+2,"����Ϊ��ȡ�����˺���Ϣ:");
		
		y=4;
		x+=2; //�������԰�
		
		while(fread(&e,size,1,puser)==1)
		{
			addNode(&list,&e);	//ÿ��һ���ṹ�壬�Ͱ�ֵ�Ž�������ȥ		
			gotoxy(x,y++);
			printf("No.%d: �û���:%s | ���룺%s\n",count+1,e.username,e.password);
			count++;
		}
		
		/*���y>border������Ҫ��չ*/
		if(count)Y1+=count;
		border();
		x-=2; //�������԰�
	

		/*�ж��ļ������Ƿ�Ϊ��*/
		if(count==0)
		{
			y=3;
			gotoxy(x+20,y++);
			printf("--���˺ż�¼--");
		}

	
		/*��ܰ��ʾ��*/
		y=prompt(x,y,1);
		
		//��ȡEnter���Ƿ�������򷵻���һ��
		while(1)
		{
			key=get_key();
			if(key==ENTER)
				break;
			else if(key==LEFT || key==BACKSPACE)
			{
				X1=10;
				Y1=10;
				fclose(puser);
				destroy(&list);
				return Tree[sub].parent;
			}
		}

		cursor_show();	//�����ʾ
		/*	
			��ʼע��
			����Ӧ��ʹ���жϳ��ȣ�ʹ�û����������
		*/
		gotoxy(x,++y);
		printf("�����û�����");
		sget_s(e.username,USNLEN);
		gotoxy(x+28,y);
		printf("�������룺");
		sget_s(e.password,PSWORD);

		cursor_hide();		//�������


		/* ��չ�߿򣬸߶�����4 */
		extensionHigh(4);

		/*�ж��û���Ϣ�Ƿ��������*/
		if(equalUsername(&list,compare,e.username))
			warn(2,x,y+3,"�û����Ѵ��ڣ����˻����ܱ�ע��.");			//ʧ����ʾ
		else if(e.username[0]=='\0' || e.password[0]=='\0')
			warn(2,x,y+3,"�û��������벻��Ϊ��.");						//ʧ����ʾ
		else if(strcmp(e.username,"Admin")==0 || strcmp(e.username,"admin")==0 )
			warn(2,x,y+3,"��ͨ�û��������ڹ���Ա�û�����ͬ.");			//ʧ����ʾ
		else if(incluSpecial(e.username) || incluSpecial(e.password))
			warn(2,x,y+3,"�û��������벻�ú��пո�����Ʊ��.");		//ʧ����ʾ
			
		else
		{
			/*�ɹ���ʾ*/
			warn(1,x,y+3,"�˺�ע��ɹ�.");
			addNode(&list,&e);				//��ӵ�������
			length=1;
		}




		/*����������д���ļ���*/
		if(length--){
			pnode=list.head.next;
			fwrite(&pnode->data,size,1,puser);
		}


		/*��ü�*/
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				destroy(&list);
				fclose(puser);
				return pos;
			}else if(key==F5 || key==ENTER)
			{
				destroy(&list);
				fclose(puser);
				return sub;
			}
		}
		
		


	}
	
}


/*
	ʵ��7�Ź���λ����ɾ���û�
*/
int delUser(int sub)
{
	/*��ɾ���û���ر���*/
	int i,count,length;		//��ʱ����
	account e;				//�ݴ����
	char username[USNLEN];	//��ɾ�����û���
	list_acc list;			//�����������ͱ���
	node_pacc pnode;		//�ڵ�ָ��
	FILE * puser;			//�ļ�ָ��
	int size;				//�ṹ���С
		
/*end----------------------*/
	
	int key,pos=0;
	int x=6,y=1;
	system("cls");
	/*���δ��¼����Ա*/
	if(!FLAG)
	{	
		gotoxy(x+4,y+2);

		printf("ע���û���Ҫ����ԱȨ�ޣ����¼����Ա�˺ţ�");
		X1=30;
		Y1=5;
		border();
		while(1)
		{
			key=get_key();
			 if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
	
		}	
	}
	/*�ѵ�¼����Ա��ʵ��ע�Ṧ��*/
	else
	{
		
	
		i=count=length=0;//count ������ŵı���,Ҳ��ͬ�������len
		X1=34;			//iΪÿ�������˻�
		Y1=10;
		x=6;
		size=sizeof(account);

		
		/*	���ļ�	*/
		if((puser=fopen("user.dat","r+b"))==NULL)
		{
			gotoxy(x+2,y);
			puts("ERROR: ���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					return pos;
				}
			}
		}

		rewind(puser);//��λ���ļ���ʼ
		InitList(&list);//��ʼ������

		
		/*������ʾ*/
		warn(3,x,y+1,"-ע���˺�");
		warn(3,x,y+2,"����Ϊ��ȡ�����˺���Ϣ��");

		y=4;	//�붥����������
		x+=2;	//�������԰�

		while(fread(&e,size,1,puser)==1)
		{
			addNode(&list,&e);	//ÿ��һ���ṹ�壬�Ͱ�ֵ�Ž�������ȥ		
			gotoxy(x,y++);
			printf("No.%d: �û���:%s | ���룺%s\n",count+1,e.username,e.password);
			count++;
		}


		/*���y>border������Ҫ��չ*/
		if(count)Y1+=count;
		border();
		 x-=2;	//�������԰�


		/*�ж��ļ������Ƿ�Ϊ��*/
		if(count==0)
		{
			gotoxy(x+20,y++);
			printf("--���˺ż�¼--");
		}


		/*��ȡ���¼Ӧ�ü�ʱ�ر��ļ���*/
		fclose(puser);


		
		y=prompt(x,y,2);//��ܰ��ʾ��
		

		//��ȡEnter���Ƿ�������򷵻���һ��
		while(1)
		{
			key=get_key();
			if(key==ENTER)
				break;
			else if(key==LEFT || key==BACKSPACE)
			{
				X1=10;
				Y1=10;
				destroy(&list);
				return Tree[sub].parent;
			}
		}


		/*�ļ�Ϊ��ʱ����ע���˻�*/
		if(count==0)
		{
			gotoxy(x+4,y+3);
			printf("�������˻�����ENTER�� ��������һ��");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT || key==ENTER)	//�˸������������س� ������һ��
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					destroy(&list);
					return pos;
				}
	
			}
		}


		cursor_show();	//�����ʾ
		
		/*����Ӧ��ʹ���жϳ��ȣ�ʹ�û����������*/
		gotoxy(x+=4,++y);
		printf("����ע�����û�����");
		sget_s(username,USNLEN);

		cursor_hide();		//�������

		/*�����߿��൱��һ���ײ�����С�߿�*/
		Y1+=4;	
		border();

		/*�ж��û���Ϣ�Ƿ��������*/
		if(!equalUsername(&list,compare,username))//δ���������ҵ�����
		{
		
		
			/*����ַ��������˿հ׷�*/
			if(incluSpecial(username) || strchr(username,'\0'))
			{
				warn(2,x,y+3,"�û�������Ϊ�հ׷�!");
			}else{
				warn(2,x,y+3,"�û���δ֪.����!");
			}
			
			

			while(1)
			{
				key=get_key();
				 if(key==ENTER || key==F5)	//ˢ��
				{
					destroy(&list);
					return sub;
				}else if(key==LEFT || key==BACKSPACE)
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					destroy(&list);
					return pos;
				}

			}
		}

		/*
			�ҵ����ݣ������������Ƴ�
		*/
		if(delNode(&list,username))
		{
			warn(1,x,y+3,"�˺��ѱ��ɹ�ע��.");//�ɹ���ʾ
			length=list.len;
		}



		/*
			ʹ��w+b�ٴδ��ļ�,�������е��ļ�д��ȥ
		*/
		if((puser=fopen("user.dat","w+b"))==NULL)
		{
			gotoxy(x,y+7);
			puts("ERROR: ���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
			while(1)
			{
				key=get_key();
				 if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					destroy(&list);
					return pos;
				}
			}
		}
		
		/*����������д���ļ���*/
		pnode=list.head.next;
		while(pnode)
		{
			fwrite(&pnode->data,size,1,puser);
			pnode=pnode->next;
		}

		/*��ü�*/
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				fclose(puser);
				destroy(&list);
				return pos;
			}else if(key==F5 || key==ENTER)
			{
				fclose(puser);
				destroy(&list);
				return sub;
			}
		}

	}




}


/*
	���ܣ�ʵ��8#��λ�Ĺ��ܡ����ж��û���¼
*/

int checkUser(int x,int y,int sub)
{
	int key,size,pos=Tree[sub].parent;
	int r1=random2(),r2=random2();		//���2�������
	int sum1=r1+r2,sum2=0;				//sum1λ�������ӣ�sum2���û������
	account login,e;					//�û�������û��������룬�Լ�����fread��e
	FILE * puser;						//�ļ�ָ��
	list_acc list;						//����ָ��
	node_pacc pnode;					//�ڵ�ָ��
	char stemp[VERIFY];					//�������֤��
	size=sizeof(account);

	system("cls");	
	X1=25;
	border();
	
	warn(3,x-4,y,"��¼�˺ţ�ȡ��ESC����ʾENTER��");//������ʾ

	/*�ж��û��Ƿ�ȡ��*/
	for(;;)
	{
		key=get_key();
		if(key==ESC)	//�յ�ESC��������һ��
		{
			X1=10;
			return Tree[sub].parent;
		}
		else if(key==ENTER)
			break;
	}


	cursor_show();	//�����ʾ
	
	/*��ӡ����Ա�˻�*/
	gotoxy(x+=14,y+=2);
	printf("��  ��:");
	sget_s(login.username,USNLEN);
	
	/*��ӡ����Ա����*/
	gotoxy(x,y+=2);
	printf("��  ��:");
	sget_s(login.password,PSWORD);
	
	/*��ɫ�߹�*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
	gotoxy(x,y+=2);	//��֤����Ŀ
	printf("%d + %d = ��",r1,r2);
	/*ԭɫ*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);


	/*��ӡ��֤��*/
	gotoxy(x,y+2);
	printf("��֤��:");
	sget_s(stemp,VERIFY);	//��ȡ�ַ���,����֤��
	sum2=atoi(stemp);

	

	cursor_hide();		//�������



	/*	���ļ�	*/
	if((puser=fopen("user.dat","a+b"))==NULL)
	{
		gotoxy(x+2,y);
		puts("ERROR: ���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				X1=10;
				Y1=10;
				return sub;
			}
		}
	}

	rewind(puser);//��λ���ļ���ʼ
	InitList(&list);//��ʼ������
		
	/*��ȡ��������*/
	while(fread(&e,size,1,puser)==1)
		addNode(&list,&e);	//ÿ��һ���ṹ�壬�Ͱ�ֵ�Ž�������ȥ		
	
	fclose(puser);//�ر���

	/* ��չ�߿򣬸߶�����4 */
	extensionHigh(4);
	
	if(sum1!=sum2)//��֤�����
	{
		warn(2,x-4,y+6,"��֤�����(Enter)");//ʧ����ʾ
	}
	else if((pnode=findUsername(&list,compare,login.username))==NULL )//��������δ�ҵ��û���
	{
		warn(2,x-4,y+6,"�û�������(Enter)");//ʧ����ʾ

	}else //�û�����ȷ��˵��pnode�����Ǿ��нڵ��ַ��
	{
		if(!userToPassword(pnode,compare2,login.password))//����������
		{
			
			
			warn(2,x-4,y+6,"�������(Enter)");//ʧ����ʾ

		}
		else//�û��������붼��ȷ��
		{
			
			warn(1,x-4,y+6,"��¼�ɹ�(Enter)");//�ɹ���ʾ

			SIGN=1;//�û���¼���Ϊ1
			strcpy(USERNAME,login.username);
			while(1)
			{
				key=get_key();
				if(key==ENTER)	//�س�ˢ�±�����
				{
					X1=10;
					Y1=10;
					destroy(&list);
					return sub;
				}
			}


		}
	
	}

	/*ִ�е������ʾû�ɹ�����Ҫ����*/
	while(1)
	{
		key=get_key();
		if(key==ENTER)	//�س�ˢ�±�����
		{
			X1=10;
			Y1=10;
			destroy(&list);
			return sub;
		}
		else if(key==LEFT || key== BACKSPACE)	//������˸񷵻���ҳ
		{
			X1=10;
			Y1=10;
			destroy(&list);
			return pos;
		}
	}

}


/*
	ʵ��9��λ�Ĺ��ܡ����޸�����
*/
int changePsd(int sub)
{
	int x,y;
	int key,size,flag=1;	//flag�Ǽ���������Ƿ�Ϸ���Ĭ�ϲ��Ϸ�
	
	char newpsw[PSWORD];	//�û������������
	FILE * puser;			//�ļ���
	account user,e;			//�û�������û��������룬�Լ�����fread��e


	list_acc list;			//������������
	node_pacc pnode;		//�ڵ�ָ��

	size=sizeof(account);
	x=2;
	y=1;					//��������

	system("cls");
	X1=22;
	Y1=14;
	border();

	//��ɫ�߹�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	gotoxy(x,y);
	printf("���޸�����");
	//ԭɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

	/* ��ʾ��ܰ��ʾ	*/
	y=prompt(x,y+1,3);
	x+=8;


	//��ȡEnter���Ƿ�������򷵻�
	while(1)
	{
		key=get_key();
		if(key==ENTER)
			break;
		else if(key==LEFT || key==BACKSPACE)
		{
			X1=10;
			Y1=10;
			return Tree[sub].parent;
		}
	}

	cursor_show();		//�����ʾ
		
	/*	¼������  */
	gotoxy(x+=4,y+=2);
	printf("�� �� ����");
	sget_s(user.username,USNLEN);

	gotoxy(x,y+=2);
	printf("�� �� �룺");
	sget_s(user.password,PSWORD);

	gotoxy(x,y+=2);
	printf("�� �� �룺");
	sget_s(newpsw,PSWORD);

	cursor_hide();		//�������

	/*���ļ��� a+b*/
	if((puser=fopen("user.dat","a+b"))==NULL)
	{
		gotoxy(x+2,y);
		printf("ERROR: ���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				X1=10;
				Y1=10;
				return Tree[sub].parent;
			}
		}
	}

	/* ָ��ָ��ͷ�� */
	rewind(puser);
	/*	��ʼ������	*/
	InitList(&list);

	/*��ȡ��������*/
	while(fread(&e,size,1,puser)==1)
		addNode(&list,&e);	//ÿ��һ���ṹ�壬�Ͱ�ֵ�Ž�������ȥ	

	/*�ر���*/
	fclose(puser);


	/*��չ�߿�*/
	extensionHigh(4);

	
	/*
		if����û���else�������
	*/
	if((pnode=findUsername(&list,compare,user.username))==NULL )//��������δ�ҵ��û���
	{
		//��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
		gotoxy(x-4,y+=4);
		printf("��ʧ�ܣ��û�������");
		//ԭɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

	}
	else //�û�����ȷ��˵��pnode�����Ǿ��нڵ��ַ��
	{
		if(!userToPassword(pnode,compare2,user.password))//����������
		{
			//��ɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("��ʧ�ܣ��������");
			//ԭɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}else if(incluSpecial(newpsw))//�����벻�Ϸ�
		{
			//��ɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("��ʧ�ܣ������벻�Ϸ�");
			//ԭɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}else if(strcmp(user.password,newpsw)==0)//������;�������ͬ
		{
			//��ɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("��ʧ�ܣ������벻�����������ͬ");
			//ԭɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}else	//���������
		{
			flag=0;	//��Ǹ�Ϊ�Ϸ����
			//��ɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);	
			gotoxy(x-4,y+=4);
			printf("�̳ɹ����޸ĳɹ�(Enter)");
			//ԭɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		
		}
	}

	//�û��������
	while(1 && flag)
	{
		key=get_key();
		if(key==ENTER)
		{
			return sub; 
		}
		else if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
		{
			X1=10;
			Y1=10;
			return Tree[sub].parent;
		}
	}



	/*
		ִ�е�����˵���û�����Ϸ�
	*/
	//ɾ���ڵ�
	delNode(&list,user.username);
	strcpy(user.password,newpsw);//�������븳��������
	//���ӽڵ�
	addNode(&list,&user);

	


	/*�ٴδ��ļ��� w+b*/
	if((puser=fopen("user.dat","w+b"))==NULL)
	{
		gotoxy(x+2,y);
		printf("ERROR: ���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				X1=10;
				Y1=10;
				return Tree[sub].parent;
			}
		}
	}


	/*����������д���ļ���*/
	pnode=list.head.next;
	while(pnode)
	{
		fwrite(&pnode->data,size,1,puser);
		pnode=pnode->next;
	}

	//�ر���
	fclose(puser);
	
	/*
		����޸�������˻��� �ѵ�¼���û���ȣ����˳���ǰ��¼
	*/
	if(strcmp(user.username,USERNAME)==0)
	{
		SIGN=0;
	}

	//�����޸� or ������һ��
	while(1)
	{
		key=get_key();
		
		 if(key==ENTER)	//�˸���������������һ��
		{
			X1=10;
			Y1=10;
			return Tree[sub].parent;
		}
	}


}


/* 
	ʵ��10��λ���ܡ����˳���¼
*/
int logOut(int sub)
{
	
	int key;
	int x=2,y=1;
	system("cls");
	X1=20;		//ֻ�ı����Ŀ��
	border();	
	
	//��ɫ�߹�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	gotoxy(x,y);
	printf("��ǰ�˻�:%s �ѵ�¼��",USERNAME);
	//ԭɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);		
		
	
	gotoxy(x+=10,y+3);
	printf("�Ƿ��˳���ǰ�˻�");
	gotoxy(x,y+5);
	printf("��Enterȷ��/ESCȡ����");
	/*�ж��Ƿ��˳�*/
	while(1)
	{
		key=get_key();
		if(key==ESC)	//�յ�ESC��������һ��
		{
			X1=10;
			return Tree[sub].parent;
		}
		else if(key==ENTER)
		{	
			X1=10;
			SIGN=0;						//�������
			return Tree[sub].parent;	//Ҳ������һ��
		}
	}






}


/*
	ʵ��19��λ�Ĺ��ܡ�������ѧ��
*/
int addStudents(int sub)
{
	/*��ע����ر���*/
	int i,count,length;			//��ʱ����
	data_stu data;				//�����û���ʱ���������
	list_stu list;				//����ָ��
	node_pstu pnode;			//�ڵ�ָ��
	FILE * fstu;				//�ļ���ָ��
	int size=sizeof(data_stu);	//�ṹ���С
	/*end----------------------*/

	int x1,y1;//ѧ����¼��xy
	/**/
	int key,pos=0,snumber;
	int x=16,y=0;	//�����x��y�Ǵ�ӡ���ֵ�

	system("cls");
	warn(3,x,y,"����ѧ��");

	if((fstu=fopen("students.dat","a+b"))==NULL)	
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"error 1129:���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}
	x=0,y=1;	//����xy
	
	studentTable(x,y);	//��ӡ������
	
	
	rewind(fstu);//��λ���ļ���ʼ
	initList_stu(&list);//��ʼ������

	x1=2,y1=4;	//ѧ����¼��xy
	while(fread(&data,size,1,fstu)==1)//������д������
	{
		table(x,y+=2,28,1);
		addNode_stu(&list,&data);//ÿ��һ���ṹ�壬�Ͱ�ֵ�Ž�������ȥ
		print_stu(data,x1,y1);	//��ӡѧ������
		/*gotoxy(x1,y1);
		printf("%4d\040\040\040%6s\040%6s\040\040\040\040%6s\040\040%10s\040%8s",data.sno,data.name,data.sex,data.naPlace,data.brith,data.consult);
		*/
		y1+=2;
	}
	

	//�ж��ļ������Ƿ�Ϊ��
	if(y1==4)
	{
		gotoxy(x1,y1++);
		snumber=1;		//���û�м�¼���������ṩ�ļ�¼��ѧ����snumer��ʼ
		printf("--��ѧ����¼--");
	}else
	{
		snumber=data.sno+1;	//ѧ���Զ������Ҽ�һ
		
	}

	
	//��ȡEnter���Ƿ�������򷵻���һ��
	while(1)
	{
		key=get_key();
		if(key==ENTER)
			break;
		else if(key==LEFT || key==BACKSPACE)
		{
			X1=10;
			Y1=10;
			fclose(fstu);
		    destroy_stu(&list);	//������������ʱ�ᱨ��
			return Tree[sub].parent;
		}
	}

	//¼������
	cursor_show();	//�����ʾ
	/*	
	��ʼע��
	����Ӧ��ʹ���жϳ��ȣ�ʹ�û����������
	*/
	x=58;y=3;

	gotoxy(x,y);
	printf("\b����ѧ��������");
	sget_s(data.name,STUDNAME);
	
	gotoxy(x,y+=2);
	printf("\t�Ա�");
	sget_s(data.sex,SEX);
	
	gotoxy(x,y+=2);
	printf("\t���᣺");
	sget_s(data.naPlace,NATPLACE);

	gotoxy(x,y+=2);
	printf("\040\040�������£�");
	sget_s(data.brith,BRITHDAT);

	gotoxy(x,y+=2);
	printf("\040\040\040\040��ѯʦ��");
	sget_s(data.consult,CONTEACHER);


	cursor_hide();		//�������

	/*---------------------------------------------*/
	//��������������Ҫ�ж��û���Ϣ�Ƿ��������

	data.sno=snumber;
	addNode_stu(&list,&data);
	
	/*---------------------------------------------*/
	/*����������д���ļ���*/
	
	pnode=list.head.next;
	fwrite(&pnode->basic,size,1,fstu);
	warn(1,20,23,"�����ɹ�.");
	
	/*��ü�*/
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);
			destroy_stu(&list);
			return pos;
		}else if(key==F5 || key==ENTER)
		{
			fclose(fstu);
			destroy_stu(&list);
			return sub;
		}
	}

}


/*
	ʵ��20��λ�Ĺ��ܡ����޸�ѧ����Ϣ
*/
int changeStudnets(int sub)
{
	int key,pos;
	list_stu list;					//��������
	node_pstu pnode;					//�ڵ�����
	data_stu data;					//data���������
	FILE * fstu;					//�ļ�ָ��
	int size=sizeof(data_stu);		//�ṹ���С
	int sno;						//ѧ��
	int x=2,y=1;


	system("cls");
	
	if((fstu=fopen("students.dat","r+b"))==NULL)		//��ȡ�ļ���
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}
	//�߿�
	X1=30;

	Y1=23;
	border();
	warn(3,x,y,"�޸�ѧ����Ϣ");

	//��ʼ������
	initList_stu(&list);
	rewind(fstu);
	
	//�����������
	while(1)
	{
		key=get_key();
		if(key==LEFT || key==BACKSPACE)
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);
			destroy_stu(&list);
			return pos;

		}else if(key==ENTER) 
		{
			break;
		}

	}
	//��ȡ�ļ��е��������ݽ�����
	while(1==fread(&data,size,1,fstu))
	{
		//��������ӽ�����
		addNode_stu(&list,&data);
	}
	

	/*�жϣ�������������Ϊ��˵��û�����ݣ����޷��޸�*/
	if(isEmpty_stu(&list))
	{
		gotoxy(x,y+3);
		printf("����Ϊ�գ������޸�����");
		while(1)
		{
			key=get_key();
			if(key==LEFT || key==BACKSPACE ||key==ENTER)
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				fclose(fstu);
				destroy_stu(&list);
				return pos;
			}
		}
	}

	//�����û�����ѧ��
	gotoxy(x+=2,y+=3);
	printf("������ѧ�ţ�");
	myscanf(&sno);
	studentTable(x,y);	//��ӡ������

	//����ѧ�Ų��ң���ӡ����λѧ����Ϣ
	if(pnode=snoCheck(&list,sno))
	{
		print_stu(pnode->basic,x,y+3);
	}
	else
	{
		warn(2,x,y,"δ���ָ�ѧ��ѧ��.");
		while(1)
		{	
			key=get_key();
			if(key==ENTER)
			{
				fclose(fstu);
				destroy_stu(&list);
				return sub;
			}
		}	
	}

	//�����û�����µ�ѧ����Ϣ
	//pnode���Ѿ��ҵ��Ľڵ㣬ֻ��Ҫ���������޸ľͿ���
	
	//¼������
	cursor_show();	//�����ʾ
	x=7;y=9;

	gotoxy(x,y);
	printf("\b�޸�һ����Ϣ.");
	
	gotoxy(x,y+=2);
	printf("\b����ѧ��������");
	sget_s(data.name,STUDNAME);
	
	gotoxy(x,y+=2);
	printf("\t�Ա�");
	sget_s(data.sex,SEX);
	
	gotoxy(x,y+=2);
	printf("\t���᣺");
	sget_s(data.naPlace,NATPLACE);

	gotoxy(x,y+=2);
	printf("\040\040�������£�");
	sget_s(data.brith,BRITHDAT);

	gotoxy(x,y+=2);
	printf("\040\040\040\040��ѯʦ��");
	sget_s(data.consult,CONTEACHER);

	data.sno=sno;		//ѧ�Ų��ܱ��޸ģ��ɴ�������sno��ֵ
	cursor_hide();		//�������
	
	pnode->basic=data;

	/*---------------------------------------------*/
	/*����������д���ļ���*/
	//����д��ȥ,�Ƚ�����λ���ļ�ͷ����ԭ�ȵĸ���
	rewind(fstu);
	//������ȫ����д
	/*����������д���ļ���*/
	pnode=list.head.next;
	while(pnode)
	{
		fwrite(&pnode->basic,size,1,fstu);
		pnode=pnode->next;
	}
	//fwrite(&pnode->basic,size,1,fstu)
	warn(1,x,y+=3,"�޸ĳɹ�.");

	
	/*��ü�*/
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT)	//�˸���������������һ��
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);
			destroy_stu(&list);
			return pos;
		}else if(key==F5 || key==ENTER)
		{
			fclose(fstu);
			destroy_stu(&list);
			return sub;
		}
	}
}

/*
	ʵ��21��λ�Ĺ��ܡ�����ѯѧ����Ϣ
*/

/*
	ʵ��22��λ�Ĺ��ܡ���ɾ��ѧ����Ϣ
*/


/*
	ʵ��23��λ�Ĺ��ܡ�����ȡ�ݽ���
*/
int drawingLecture(int sub)
{
	int key,pos=0;
	FILE * fstu, *fpass;
	node_pstu pcheck;
	list_stu list1,list2;		//����ָ��
	data_stu data,data_pass;
	int size=sizeof(data_stu);	//�ṹ���С
	int x=22,y=4;
	int rndnumber;				//�����
	int rest_flag=1;			//���³�ȡ


	system("cls");
	warn(3,x,y,"�����ȡ��Enter��");	
	if((fstu=fopen("students.dat","a+b"))==NULL)		//��ȡ�ļ���
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	if((fpass=fopen("stpass.dat","a+b"))==NULL)				//��ȡ�ļ���	
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	rewind(fpass);	//��ָ��ָ���ļ���ʼ
	rewind(fstu);	//	
	initList_stu(&list1);
	initList_stu(&list2);

	X1=30;		//ֻ�ı����Ŀ��

	border();	
	
	while(1)
	{
		key=get_key();
		if(key==LEFT || key==BACKSPACE)
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fpass);
			fclose(fstu);
			destroy_stu(&list1);
			destroy_stu(&list2);
			return pos;

		}else if(key==ENTER) 
		{
			break;
		}

	}

	
	while(fread(&data,size,1,fstu)==1)//ԭ�ļ�
	{
		addNode_stu(&list1,&data);	//ÿ��һ���ṹ�壬�Ͱ�ֵ�Ž�ȥ
	}

	while(fread(&data_pass,size,1,fpass)==1)//�Ѷ��ļ�
	{
		addNode_stu(&list2,&data_pass);	
	}




	while(1)
	{
		rest_flag=1;
		rndnumber=random(1,data.sno);		//1-ѧ��ĩβ�������������ѧ��	//������Ҫ�ж�һ��14��ѧ��
		
		pcheck=snoCheck(&list1,rndnumber);	//�����Ϊѧ��ȥѧ��������

		//ͨ���������������
		if(pcheck && !snoCheck(&list2,rndnumber))	//��ѧ����ѧ�������ܹ��ҵ�������pass���в����ҵ�
		{

			gotoxy(6,6);	
			printf("��ȡ���ݽ�����:");
			gotoxy(23,6);	
			//��ɫ�߹�
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

			printf("�� %s ��",pcheck->basic.name);

			//ԭɫ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

			gotoxy(22,8);
			printf("(ENTERȷ�� / ESC�س�)");
			while(1)
			{
				key=get_key();
				if(key==ESC)
				{
					rest_flag=0;
					break;
				}
				else if(key==ENTER)
				{
					gotoxy(22,8);
					printf("\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40\40");
					gotoxy(22,8);
					printf("ȷ����λ��~��|����");
					break;
				}
			}

			if(rest_flag)//����û�����س��������³�ȡ
				break;
		}else if(list1.len==list2.len)	//����ȡ��ʱ
		{
			gotoxy(22,6);	
			printf("���ֽ�����������һ��(Enter)");
			/*
				����֮����Ҫ�ر���,ʹ��w+b���¶�ȡ����������pass�ļ�
				���ֽ�����Ҳ��Ϊ�ź������
			*/
			fclose(fpass);		//�ر��ļ�
			
			if((fpass=fopen("stpass.dat","wb"))==NULL)	//����
			{
				system("cls");
				printf("ERROR 1403���ļ���ʧ��");
			}

			while(1)
			{
				key=get_key();
				if(key==ENTER)	//�س�֮��ˢ�±�ҳ
				{

					fclose(fstu);//�ر���
					fclose(fpass);
					destroy_stu(&list1);//��������
					destroy_stu(&list2);
					return sub;
				}
				else if(key==LEFT)	//�˸���������������һ��
				{
					pos=Tree[sub].parent;
					X1=10;
					Y1=10;
					fclose(fstu);//�ر���
					fclose(fpass);
					destroy_stu(&list1);//��������
					destroy_stu(&list2);
					return pos;
				}
			}
			break;
		}
	}

	//�������������ѧ��д�뵽fpass�ļ����У���֤�´β��ᱻ�����
	fwrite(&pcheck->basic,size,1,fpass);
	
	while(1)
	{
		key=get_key();
		if(key==LEFT || key==ENTER)	//�˸���������������һ��
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);//�ر���
			fclose(fpass);
			destroy_stu(&list1);//��������
			destroy_stu(&list2);
			return pos;
		}
		/*else if(key==ENTER)//���»س���ˢ�±�ҳ
		{
			fclose(fstu);//�ر���
			fclose(fpass);
			destroy_stu(&list1);//��������
			destroy_stu(&list2);
			return sub;
		}*/
	}





	
	
}


/*
	ʵ��24��λ�Ĺ��ܡ���Ԥ���ݽ���
*/
int readyLecture(int sub)
{
	int key,pos=0;
	int size=sizeof(data_stu);
	FILE * fpass;
	list_stu list2;
	data_stu data_pass;
	int x=8,y=1;
	
	
	system("cls");
	warn(3,x-1,y,"��һ���ݽ���׼��");

	
	if((fpass=fopen("stpass.dat","a+b"))==NULL)		//��ȡ����������ļ���
	{
		system("cls");
		X1=20;
		Y1=5;
		border();
		warn(2,x,y+3,"���ܴ��ļ�(�ļ������Ļ�ʧ)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	rewind(fpass);
	initList_stu(&list2);
	X1=16;		//ֻ�ı����Ŀ��
	Y1=6;
	border();	//�߿�

	while(fread(&data_pass,size,1,fpass)==1)
	{
		addNode_stu(&list2,&data_pass);	//���ӽڵ�

	}
	
	if(0==list2.len)
	{
		gotoxy(x-3,y+=2);
		printf("��ǰ��δ��ȡԤ���ݽ���.");
		gotoxy(x-3,++y);
		printf("�뷵�س�ȡ�ݽ���.");

	}else{
		//��ɫ�߹�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
		gotoxy(x+3,y+=2);
		printf("< %s >",data_pass.name);
		//ԭɫ�߹�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		gotoxy(x-1,y+=2);
		printf("���ݽ�������׼��.");
			//ԭɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}
	
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT ||key==ENTER)	//�˸���������������һ��
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fpass);
			destroy_stu(&list2);
			return pos;
		}
	}

}

/*
	ʵ��25λ�Ĺ��ܡ����ݽ����ݼ��
*/

/*
	ʵ��26λ�Ĺ��ܡ����ݽ�������
*/


/*
	ʵ��27λ�Ĺ��ܡ�����¼����
*/


/*
	ʵ��28λ�Ĺ��ܡ������Ŀ���
*/

/*
	ʵ��29λ�Ĺ��ܡ�����ѯ����
*/

/*
	ʵ��30λ�Ĺ��ܡ������ڼ�¼ɾ��
*/







/*
	���ܣ��ַ������ð������ַ����Ʊ��
*/
int	incluSpecial(char *str)
{
	char * find;
	if(find=strchr(str,32))
		return 1;
	else if(find=strchr(str,'\t'))
		return 1;
	return 0;
}


/*
	���ܣ���չ�߿�
*/
void extensionHigh(int value){
	Y1+=value;	
	border();
}


/*
	���ܣ���ӡ����ɫ����ʾor��ʾ
*/
void warn(int flag,int x,int y,char *str)
{
	gotoxy(x,y);
	if(flag==1)//�����1��ʾ�ɹ�
	{
		//��ɫ�߹�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		printf("�̳ɹ���%s",str);
		//ԭɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}else if(flag==2)//�����2��ʾʧ��
	{
		//��ɫ�߹�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("��ʧ�ܣ�%s",str);
		//ԭɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}else if(flag==3)//�����3��ʾ������ʾ
	{
		/*��ɫ�߹�*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		printf("%s",str);
		//ԭɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	
	}
}

/*
	��������
*/
void myscanf(int *p)
{
	scanf("%d",p);
	while(getchar()!='\n')
		continue;
	
	
}