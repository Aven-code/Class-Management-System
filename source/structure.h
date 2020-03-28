/*
	该文件的内容：
		定义结构：
		界面点，用户，学生，班级.....
		获得时间的结构体
		初始化函数和跳转节点函数的原型

*/

#ifndef _STRUCTURE_H_
#define	_STRUCTURE_H_



#define MAX 100	//数组最大值


//时间的结构体
typedef struct date{
	int year;
	int month;
	int day;
}Date;



//定义界面节点结构（小链表）
typedef struct nod
{
	int index;
	struct nod * next;
}node;
typedef node * Node;

/*节点类型素数组元素*/
typedef struct
{
	int parent;				//父节点
	int number;				//度的个数。
	Node  firstChild;		//子链表
}ptree;


/*定义结构数组*/
ptree Tree[MAX];


/*函数原型——————————————————————*/

/*
	功能：调用下标与之对应的函数
	参数：传入一个整形参数
*/
int print_check(int index);

/*
	初始化数组
	和链表
*/
void  initTreeArrays();

/*
	功能：链表添加节点
	参数：total是父节点的度
	返回值：无
*/
Node addList(int total);


#endif 