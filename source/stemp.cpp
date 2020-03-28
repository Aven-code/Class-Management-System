int drawingLecture(int sub)
{
	int key,pos=0;					//获得键，当前位置
	FILE * fstu, *fpass;			//文件流指针
	node_pstu pnode,ppass,pcheck;	//节点指针类型
	list_stu list1,list2;			//链表指针
	data_stu data,data_pass;		//数据域类型
	int size=sizeof(data_stu);		//结构体大小
	int x=22,y=4;
	int rndnumber;					//随机数变量
	
	
	system("cls");
	warn(3,x,y,"随机抽取（Enter）");
	if((fstu=fopen("students.dat","a+b"))==NULL)		//读取文件流
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	if((fpass=fopen("stpass.dat","a+b"))==NULL)			//读取文件流	
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}

	rewind(fpass);	//将指针指向文件开始
	rewind(fstu);	//	
	initList_stu(&list1);
	initList_stu(&list2);


	X1=30;		//只改变界面的宽度

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

	
	while(fread(&data,size,1,fstu)==1)//原文件
	{
		addNode_stu(&list1,&data);	//每读一个结构体，就把值放进去
	}

	while(fread(&data_pass,size,1,fpass)==1)//已读文件
	{
		addNode_stu(&list2,&data_pass);	
	}




	while(1)
	{
		rndnumber=random(1,data.sno);		//1-学生末尾，随机数产生的学号
		
		pcheck=snoCheck(&list1,rndnumber);	//随机数去学生表中找

		//通过随机数查找链表
		if(pcheck && !snoCheck(&list2,rndnumber))	//此学号在学生表中能够找到，但在pass表中不能找到
		{

			gotoxy(6,6);	
			printf("抽取的演讲人是:");
			gotoxy(23,6);	
			//黄色高光
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

			printf("〈 %s 〉",pcheck->basic.name);

			//原色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			break;
		}else if(list1.len==list2.len)	//当读取完时
		{
			gotoxy(22,6);	
			printf("本轮结束！");	
			break;
		}
	}

	//将本次随机到的学生写入到fpass文件流中，保证下次不会被随机到
	fwrite(&pcheck->basic,size,1,fpass);

	while(1)
	{
		key=get_key();
		if(key==LEFT)	//退格键和左方向键返回上一级
		{
			pos=Tree[sub].parent;
			X1=10;
			Y1=10;
			fclose(fstu);//关闭流
			fclose(fpass);
			//destroy_stu(&list1);//销毁链表
			//destroy_stu(&list2);
			return pos;
		}
	}	
}

/*----------------------------------------------------------------------*/
int addStudents(int sub)
{
	/*与注册相关变量*/
	int i,count,length;			//临时变量
	data_stu data;				//用于用户临时输入的数据
	list_stu list;				//链表指针
	node_pstu pnode;			//节点指针
	FILE * fstu;				//文件流指针
	int size=sizeof(data_stu);	//结构体大小
	/*end----------------------*/

	int x1,y1;//学生记录的xy
	/**/
	int key,pos=0,snumber;
	int x=16,y=0;	//这里的x，y是打印文字的

	system("cls");
	warn(3,x,y,"新增学生");

	if((fstu=fopen("students.dat","a+b"))==NULL)	
	{
		system("cls");
		X1=30;
		Y1=5;
		border();
		warn(2,x,y+3,"error 1129:不能打开文件(文件名更改或丢失)!!");
		while(1)
		{
			key=get_key();
			if(key==BACKSPACE || key==LEFT ||key==ENTER)	//退格键和左方向键返回上一级
			{
				pos=Tree[sub].parent;
				X1=10;
				Y1=10;
				return pos;
			}
		}
	}
	x=0,y=1;	//表格的xy
	
	studentTable(x,y);	//打印出标题
	
	
	rewind(fstu);//定位到文件开始
	initList_stu(&list);//初始化链表

	x1=2,y1=4;	//学生记录的xy
	while(fread(&data,size,1,fstu)==1)//将数据写进链表
	{
		table(x,y+=2,28,1);
		addNode_stu(&list,&data);//每读一个结构体，就把值放进链表中去
		print_stu(data,x1,y1)	//打印学生函数
		/*gotoxy(x1,y1);
		printf("%4d\040\040\040%6s\040%6s\040\040\040\040%6s\040\040%10s\040%8s",data.sno,data.name,data.sex,data.naPlace,data.brith,data.consult);
		*/
		y1+=2;
	}
	

	//判断文件内容是否为空
	if(y1==4)
	{
		gotoxy(x1,y1++);
		snumber=1;		//如果没有记录，后面所提供的记录的学号以snumer开始
		printf("--无学生记录--");
	}else
	{
		snumber=data.sno+1;	//学号自动生成且加一
		
	}

	
	//获取Enter键是否继续，或返回上一级
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
		    destroy_stu(&list);	//当链表有数据时会报错
			return Tree[sub].parent;
		}
	}

	//录入数据
	cursor_show();	//光标显示
	/*	
	开始注册
	这里应该使用判断长度，使用户不会误操作
	*/
	x=58;y=3;

	gotoxy(x,y);
	printf("\b输入学生姓名：");
	sget_s(data.name,STUDNAME);
	
	gotoxy(x,y+=2);
	printf("\t性别：");
	sget_s(data.sex,SEX);
	
	gotoxy(x,y+=2);
	printf("\t籍贯：");
	sget_s(data.naPlace,NATPLACE);

	gotoxy(x,y+=2);
	printf("\040\040出生年月：");
	sget_s(data.brith,BRITHDAT);

	gotoxy(x,y+=2);
	printf("\040\040\040\040咨询师：");
	sget_s(data.consult,CONTEACHER);


	cursor_hide();		//光标隐藏

	/*---------------------------------------------*/
	//！！！！这里需要判断用户信息是否符合条件

	data.sno=snumber;
	addNode_stu(&list,&data);
	
	/*---------------------------------------------*/
	/*将链表数据写进文件中*/
	
	pnode=list.head.next;
	fwrite(&pnode->basic,size,1,fstu);
	warn(1,20,23,"创建成功.");
	
	/*获得键*/
	while(1)
	{
		key=get_key();
		if(key==BACKSPACE || key==LEFT)	//退格键和左方向键返回上一级
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