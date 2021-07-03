
/*需要的头文件
*/
#include<iostream>
#include<graphics.h>	//图形库 需要额外安装
#include<mmsystem.h>//包含多媒体接口头文件
#include<conio.h> //
#include<math.h>//数学头文件


/*需要的宏定义
*/
using namespace std;
MOUSEMSG msg;//定义鼠标存储数据


#define ROW 6//列
#define COL 6//行
#define HIGH 700 //高
#define WIDTH 600 //宽
#define QP_HIGH 50//棋子高
#define QP_WIDTH 50//棋子宽
#define QP_X1 130 //棋盘左上角x坐标            
#define QP_X2 380 //棋盘右上角y坐标
#define QP_Y1 130 //棋盘左上角y坐标
#define QP_Y2 380 //棋盘右角y坐标
#define PI 3.1415
//棋盘从（150，150）（400，150）（150，400）（400，400）
IMAGE bk, cat, img;	//准备图片

//结构体定义
struct  Chess//棋子属性
{
	char name;//1黑棋 2白棋，0无
	int x;
	int y;
	char type; //棋子属于白棋还是黑棋
	bool flag;//是否过了弧线
}map[ROW][COL];
struct chess //圆弧形行走
{
	int x = 150;
	int y = 150;
	int angle;
	int endx;
	int endy;

}chess;
struct msgmove
{
	int n = 1;
	int name = 0;//n鼠标点击次数 ,name存储拿起棋子的颜色
	int x = 0;
	int y = 0;//移动棋子时暂存的坐标（x,y）
	int nhb=1;
	
}msgmove;

//函数申明
void show();
void zouzi(int he);

int Bnumber;//定义黑子
int Wnumber;//定义白子
