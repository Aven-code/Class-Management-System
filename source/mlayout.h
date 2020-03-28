#ifndef _MLAYOUT_H_
#define _MLAYOUT_H_
/*
	定位，清除箭头
*/

void clear(int x,int y);

/*
	定位，输出箭头
*/
void output(int x,int y);



/*
	功能：输出班级管理系统字符画，提醒用户Enter进入
	参数：
	返回：
*/
void home();

/*
	边框画出来
*/
void border();


/*
	实现1号位的功能，打印a，
*/
int listA(int);

/*
	实现2号位的功能,打印b
*/
int listB(int);

/*
	实现3号位的功能,打印b
*/
int listC(int);

/*
	实现4号位的功能
*/
int quit();



/*
	实现7号位的功能——登录用户
*/
int listD(int sub);




/*
	实现9号位功能：打印E——班级管理
*/

int listE(int sub);

/*
	实现10号位功能：打印F——学生管理
*/

int listF(int sub);

/*
	实现11号功能：打印G——活动管理
*/

int listG(int sub);

/*
	实现12号功能：打印H——考勤管理
*/
int listH(int sub);


/*登录错误字符画*/

void errorLogin(int x,int y);


/*登录成功字符画*/

void succeedLogin(int x,int y);



/*	
	功能：温馨提示
	参数：输入xy轴坐标，方便打印,i表示那部分功能的温馨提示。 1：表示注册、2：删除
	返回：返回当前y轴坐标的值
*/
int prompt(int x,int y,int i);




/*
	功能：打印表格
	参数：x轴与y轴，高度与宽度
	返回：无返回
*/

void table(int x,int y,int width_max,int heigh_max);



/*
	功能：打印内容待开发
	参数：
	返回：

*/
int waitExploit(int sub);


/*
	功能： 打印学生列表的格式(相当于封装一遍table函数，以学生格式)
	参数：x,y 从xy轴哪个点开始画
	返回：无返回
*/
void studentTable(int x,int y);
#endif