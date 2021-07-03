#include<iostream>
#include<graphics.h>	//图形库 需要额外安装
#include<mmsystem.h>//包含多媒体接口头文件
#include<conio.h> //
#include<stdio.h>
#include<math.h>//数学头文件
#include<string.h> 
#pragma comment(lib,"winmm.lib")

//函数申明
void movechess1(int x, int y, int angle, int flag);
void zouzi(int he);
void hihe();
void yidong(int x, int y, int endx, int endy);

int fraction;//定义分数
using namespace std;
MOUSEMSG msg;//定义鼠标存储数据
int n = 1, name = 0;//n鼠标点击次数 ,name存储拿起棋子的颜色
int x = 0, y = 0;//移动棋子时暂存的坐标（x,y）
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
//结构体定义
struct  Chess//棋子属性
{
	char name;//1黑棋 2白棋，0无
	int x;
	int y;
	char type; //棋子属于白棋还是黑棋
	bool flag;//是否过了弧线
}map[ROW][COL];


//* 初始化数据
void  GameInit()
{
	//遍历二维数据
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j].name = 0;
			char mcolor = 'B';//黑色
			if (i<2)
			{
				map[i][j].name = 1;
			}
			else
			{

				if (i >= 4)
				{
					char mcolor = 'W';//白色
					map[i][j].name = 2;
				}
			}
			map[i][j].type = mcolor;
			map[i][j].flag = false;
			map[i][j].x = 150 + j*QP_WIDTH;
			map[i][j].y = 150 + i*QP_HIGH;
		}
	}

}




void draw()
{
	BeginBatchDraw();//双缓冲绘图防止闪屏不美观
	COLORREF color = WHITE;//设置画线颜色
	setbkcolor(RGB(252, 215, 162));//设置背景颜色 
	setlinecolor(BLACK);//设置颜色
	setlinestyle(PS_SOLID, 3);//设置线条颜色，粗细

	cleardevice();//清屏
	//左上角圆
	circle(150, 150, 50);//画园
	circle(150, 150, 100);
	//右上角
	circle(400, 150, 50);
	circle(400, 150, 100);
	//左下
	circle(150, 400, 50);
	circle(150, 400, 100);
	//右下
	circle(400, 400, 50);
	circle(400, 400, 100);
	setfillcolor(RGB(252, 215, 162));
	//左上圆填充
	solidrectangle(150, 150, 250, 250);
	//右上圆填充
	solidrectangle(300, 150, 400, 250);
	//右下圆填充
	solidrectangle(300, 300, 400, 400);
	//左下圆填充
	solidrectangle(150, 300, 250, 400);

	setlinecolor(BLACK);//设置画线颜色
	setlinestyle(PS_SOLID, 3);//设置画线宽度 3
	//绘制横竖交替的棋盘
	for (int i = 0; i < 6; i++)
	{
		line(150 + QP_HIGH * i, 150, 150 + QP_HIGH * i, 400);
		for (int j = 0; j < 6; j++)
		{
			line(150, 150 + QP_WIDTH * j, 400, 150 + QP_WIDTH * j);
		}
	}
//绘制对话框

	
	setlinestyle(PS_SOLID, 1);//设置线条颜色，粗细
	setfillcolor(WHITE);
	settextcolor(BLACK);
	fillrectangle(0, 550, 599, 699);
	line(0, 552,600,552);
	outtextxy(260,560,"开始游戏");//显示




	//特殊功能
	//输出分数等
	setbkmode(TRANSPARENT);//设置背景透明
	settextstyle(20, 0, "黑体");//设置字体
	char coin[20] = "";
	sprintf(coin, "分数：%d", fraction);//存入字体
	outtextxy(500, 50, coin);//显示

	//画棋子
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j].name != 0)
			{
				if (map[i][j].name == 1)
				{
					setfillcolor(BLACK);
					setbkcolor(BLACK);
					settextcolor(BLACK);
					setlinecolor(BLACK);
					fillcircle(map[i][j].x, map[i][j].y, 20);
				}
				else if (map[i][j].name == 2)
				{
					setfillcolor(WHITE);
					setbkcolor(WHITE);
					settextcolor(WHITE);
					setlinecolor(WHITE);
					fillcircle(map[i][j].x, map[i][j].y, 20);
				}

			}
			
		}
	}
	EndBatchDraw();//防止闪屏不美观

}
struct button
{
	int x;
	int y;
	int width;
	int height;
	COLORREF color;
	char* pText;
};
/****************************************************************
*  初始化按钮
*
*********************************************************/
struct button* createButton(int x, int y, int width, int height, COLORREF color, char* pText)
{
	struct button* pB = (struct button*)malloc(sizeof(struct button));//动态内存申请
		pB ->x = x;
	    pB->y = y;
	    pB->width = width;
	    pB->height = height;
		pB->color = color;
		pB->pText = (char*)malloc(strlen(pText)+1);
		strcpy(pB->pText,pText);
		
		
		return pB;
}
/********************************************************************************
*画按钮
*********************************************************************************/
void drawButton(struct button* pB)
{
	/*setfillcolor(pB->color);
	settextstyle(35,0,"楷体");
	fillrectangle(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height);
	outtextxy(pB->x+20,pB->y+30,*pB->pText);
*/

}


struct chess
{
	int x=150;
	int y=150;
	int endx;
	int endy;
	int flag = 0;
	double angle=10;
}chess;
struct msgmove
{
	int n = 1;
	int name = 0;//n鼠标点击次数 ,name存储拿起棋子的颜色
	int x = 0;
	int y = 0;//移动棋子时暂存的坐标（x,y）
	int nhb = 1;

}msgmove;


//回合函数
void hihe()
{
	int ixd = 0;//记录次数标志
	ixd = msgmove.nhb % 2;
	if (ixd == 1)
	{
		zouzi(1);  //调用走子函数
	}
	else if (ixd == 0)
	{
		zouzi(2);
	}

}


//走子函数  he值为1时黑子回合，为2时白子回合
void zouzi(int he)
{
	int ixd;
	ixd = msgmove.n % 2;
	switch (ixd)
	{
	case 1:
		if (map[msg.x][msg.y].name == he)//判断该坐标是否有棋子  拿子必须有棋子
		{
			msgmove.n++;
			printf("拿子");
			msgmove.x = msg.x;
			msgmove.y = msg.y;
			msgmove.name = map[msgmove.x][msgmove.y].name;
			//	tishi();
		}
		else if (map[msg.x][msg.y].name != he)
		{
			MessageBox(NULL, "不是你的回合", "提示", MB_OK);

		}
		break;
	case 0:
		if (msg.x - msgmove.x<2 && msg.y - msgmove.y<2 && msg.x - msgmove.x>-2 && msg.y - msgmove.y>-2)
		{
			if (map[msg.x][msg.y].name == 0 || map[msg.x][msg.y].name != msgmove.name)//判断该坐标是否有棋子或吃子
			{
				msgmove.n++;
				msgmove.nhb++;
				printf("落子");
				yidong(msgmove.x, msgmove.y, msg.x, msg.y);
				map[msgmove.x][msgmove.y].name = 0;
				map[msg.x][msg.y].name = msgmove.name;
			}
		}
		else MessageBox(NULL, "落子不符合规则", "提示", MB_OK);
		break;

	}
}



//鼠标移动棋子
void GameControl2()
{
	if (MouseHit())//如果有鼠标消息
	{
		msg = GetMouseMsg();//获取鼠标消息
		if (msg.uMsg == WM_LBUTTONDOWN)//当左键按下时
		{

			if (msg.x > 130 && msg.x < 420 && msg.y > 130 && msg.y < 420)//边界
			{
				int temp = msg.y;
				msg.y = (msg.x - 130) / QP_HIGH;
				msg.x = (temp - 130) / QP_WIDTH;
				hihe();   //调用回合函数
			}
		}
	}

}












/************************************************ 
*---圆弧移动 
*---int(x,y)圆心
*---dauble angle 需要移动的角度
*---int speed 运动速度最好1到10之间，5最完美
*************************************************/
void movechess(int x,int y,double angle,int speed)
{ 
	chess.x = x;
	chess.y = y;
	chess.angle = angle;
	speed = 10 * speed;
	//初始化数据
	setbkcolor(BLACK);
	settextcolor(YELLOW);
	setlinecolor(YELLOW);

		circle(150, 150, 50);//画园
	
		BeginBatchDraw();//双缓冲绘图
		while (angle)
		{
			chess.angle++;
			cleardevice();
			Sleep(speed);
			//	circle(150, 150, 50);//画园
			chess.endx = chess.x + (int)(sin(PI / 180 * chess.angle) * 50);
			chess.endy = chess.y + (int)(cos(PI / 180 * chess.angle) * 50);
			fillcircle(chess.endx, chess.endy, 10);
		}
		
		EndBatchDraw();//防止闪屏不美观
	
}
	
/****************************************************************************
明天任务实现上，左，下，右，左上，左下，右上，右下的移动（新增格数变量，实现移动几格）
*可以和圆弧的代码整理一起，但可能会增加负担，拖慢速度。
*
*当前位置x,y
*目标位置endx,endy
*速度
******************************************************************************/

void startgame()
{
	MessageBox(NULL, "请开始游戏", "提示",MB_OK);
}
void Zmovchess(int x, int y,int endx, int endy)
{
	int flag,flagx,flagy,i=0;
	chess.x = x;
	chess.y = y;
	chess.endx = endx;
	chess.endy = endy;
	flagx = endx - x;
	flagy = endy - y;
	if (flagx < 0 && flagy == 0)//向正左移动
	{
		flag = 0;
		//flagx = ~flagx;
		flagx += 2 * flagx;

	}else if(flagx > 0 && flagy == 0)//向正右移动
	{
		flag = 1;
	}
	else  if (flagx == 0 && flagy > 0)//向正下移动
	{
		flag = 2;
	}
	else if (flagx == 0 && flagy < 0)//向上
	{
		flag = 3;
	}
	switch (flag)
	{
	case 0:  if (i<=flagx)
	          {
				 i++;
	          }
		   cleardevice();
		   //Sleep	(speed); 
		   chess.endx = chess.x - i;
		   chess.endy = chess.y - i;
		   fillcircle(chess.x, chess.y, 10);
		break;
	case 1:  if (i <= flagx)
	{
				 i++;
	}
			 cleardevice();
			 //Sleep	(speed); 
			 chess.endx = chess.x + i;
			 chess.endy = chess.y + i;
			 fillcircle(chess.x, chess.y, 10);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}

}

void yidong(int x, int y, int endx, int endy)
{
	int   i = 0;
	chess.x = x;
	chess.y = y;
	chess.endx = endx;
	chess.endy = endy;
	printf("(%d%d)\n",chess.x,chess.y);
	
	printf("(%d%d)", chess.endx, chess.endy);
	////flagx = endx - x;
	////flagy = endy - y;
	chess.flag = x - endx;
	BeginBatchDraw();//双缓冲绘图

	if (chess.endx<chess.x)
	{	
		chess.flag--;
	}
	chess.endx = chess.x + chess.flag;
	Sleep(100);
	//cleardevice();
	fillcircle(chess.endx, chess.y, 20);

	EndBatchDraw();//防止闪屏不美观
}



/************************************************
*---终极无极圆弧移动改良
*---int(x,y)圆心
*---dauble angle 需要移动的角度
*---int speed 运动速度最好1到10之间，5最完美
*---flag 标志 1代表顺时针走  2代表逆时针走     可以将直接移动移植过来：在switch加上
*************************************************/
void movechess1(int x,int y,int angle,int flag)
{

	//初始化数据
	setbkcolor(BLACK);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	
	chess.x = x;
	chess.y = y;

	cleardevice();
	BeginBatchDraw();//双缓冲绘图
	 switch (flag)
	{
	 case 1:
		 	if(chess.angle <= angle)
                {
				chess.angle++;
                
			}
			// circle(150, 150, 50);//画园
			chess.endx = chess.x + (int)(sin(PI / 180 * chess.angle) * 50);
			chess.endy = chess.y + (int)(cos(PI / 180 * chess.angle) * 50);
			fillcircle(chess.endx, chess.endy, 20);

		
	
			
			 break;
		case 2:
			if (chess.angle + 360 >= 360-angle)
				  {
				   chess.angle--;
          		  }
				Sleep(10);
				//circle(150, 150, 50);//画园
		
		

				chess.endx = chess.x + (int)(sin(PI / 180 * chess.angle) * 50);
				chess.endy = chess.y + (int)(cos(PI / 180 * chess.angle) * 50);
				fillcircle(chess.endx, chess.endy, 20);
			
				break;
		default:
			break;
	}
	
	 EndBatchDraw();//防止闪屏不美观
}
int main()
{
	
	initgraph(WIDTH, HIGH, SHOWCONSOLE);//新建窗口
	GameInit();
//	circle(400, 150, 50);//画园
	//movechess(150, 150, 270, 5);
	//struct button* pB = createButton(300,200,200,50,YELLOW,"开始");
	//drawButton(pB);
	//startgame();
	while (1)
	{
		//draw();
		//GameControl2();
		movechess1(150, 150, 270,1);
	//	yidong(200, 150, 150, 150);
		//Zmovchess(150,150,200,150);
		
		//movechess2(180);
	}



	while (1);
	closegraph();
	return 0;
}