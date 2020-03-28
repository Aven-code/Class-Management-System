int drawingLecture(int sub)
{
	int key,pos=0;					//��ü�����ǰλ��
	FILE * fstu, *fpass;			//�ļ���ָ��
	node_pstu pnode,ppass,pcheck;	//�ڵ�ָ������
	list_stu list1,list2;			//����ָ��
	data_stu data,data_pass;		//����������
	int size=sizeof(data_stu);		//�ṹ���С
	int x=22,y=4;
	int rndnumber;					//���������
	
	
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

	if((fpass=fopen("stpass.dat","a+b"))==NULL)			//��ȡ�ļ���	
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
		rndnumber=random(1,data.sno);		//1-ѧ��ĩβ�������������ѧ��
		
		pcheck=snoCheck(&list1,rndnumber);	//�����ȥѧ��������

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
			break;
		}else if(list1.len==list2.len)	//����ȡ��ʱ
		{
			gotoxy(22,6);	
			printf("���ֽ�����");	
			break;
		}
	}

	//�������������ѧ��д�뵽fpass�ļ����У���֤�´β��ᱻ�����
	fwrite(&pcheck->basic,size,1,fpass);

	while(1)
	{
		key=get_key();
		if(key==LEFT)	//�˸���������������һ��
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);//�ر���
			fclose(fpass);
			//destroy_stu(&list1);//��������
			//destroy_stu(&list2);
			return pos;
		}
	}	
}

/*----------------------------------------------------------------------*/
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
		print_stu(data,x1,y1)	//��ӡѧ������
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