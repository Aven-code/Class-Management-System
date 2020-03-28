/*
	students.c文件的函数原型
*/

#define STUDNAME	11	//姓名
#define BRITHDAT	13	//出生日
#define NATPLACE	15	//籍贯 
#define CONTEACHER	21	//咨询师
#define SEX			4	//性别

/*数据域结构*/
typedef struct data_student
{
	int	 sno; 				 //学号
	char name[STUDNAME];	 //姓名
	char sex[SEX];			 //性别
	char brith[BRITHDAT];	 //出生年月
	char naPlace[NATPLACE];	 //籍贯
	char consult[CONTEACHER];//咨询师

}data_stu;

typedef data_stu * data_pstu;	//数据域指针类型


/*节点结构*/
typedef struct node_student
{
	data_stu basic;				//数据域类型变量
	struct node_student * next;	//next指针
}node_stu;

typedef node_stu * node_pstu;	//节点指针类型


/*链表结构*/
typedef struct 
{
	node_stu head;		//节点类型变量
	int len;			//长度变量
}list_stu;

typedef list_stu * list_pstu;	//链表指针类型

/*函数原型---------------------------------------------*/


/*
	功能：判断学生链表是否为空
	参数：链表指针
	返回：返回1表示空，不空为0
*/
int isEmpty_stu(list_pstu list);

/*
	功能：初始化学生链表
	参数：list 链表指针
	返回：无返回
*/
void initList_stu(list_pstu list);



/*
	功能：学生链表添加
	参数：链表指针，数据域指针
	返回：成功返回1，失败返回0
*/
int addNode_stu(list_pstu list,data_pstu data);


/*
	功能：销毁学生链表
	参数：链表指针
	返回：无
*/
void destroy_stu(list_pstu list);



/*
	打印链表内容
*/
void printNode_stu(list_pstu list);


/*
	功能：	从list中查找学生
	参数：	list	链表指针
			sno		需要查的学号
	返回值：找到了返回那个节点，未找到返回NULL
*/

node_pstu snoCheck(list_pstu list,int sno);


/*
	功能：	学生学号的匹配器
	参数：	学生1，学生2
	返回值：相同返回1，不同返回0
*/
int sno_equal(int sno1,int sno2);



/*
	功能：	打印学生信息
	参数：	data 学生结构体	//这里应该用地址的
	返回值：无
*/
void print_stu(data_stu data,int x,int y);


/*
	功能：	根据学号删除节点
	参数：	list	链表指针
			sno		需要删除节点的学号
	返回：	成功返回0，失败-1(未找到之类的)
*/
int delNode_stu_sno(list_pstu list,int sno);


/*
	功能：	根据学号删除节点
	参数：	list	链表指针
			sno		需要删除节点的学号
	返回：	成功返回0，失败-1(未找到之类的)
*/
int delNode_stu_sno(list_pstu list,int sno);