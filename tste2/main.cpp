#include<iostream>
#include<graphics.h>	//图形库 需要额外安装
#include<mmsystem.h>//包含多媒体接口头文件
#include<conio.h> //
#pragma comment(lib,"winmm.lib")
#define HIGH 600 //高
#define WIDTH 600 //宽
int date[6][6] = {
	2, 2, 2, 2, 2, 2,//2为
	2, 2, 2, 2, 2, 2,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1

};
//黑棋在上，白棋在下
void setwindowstyle()
{
	system("title 苏卡塔尔棋");
	system("color f0");//设置颜色
	system("mode con cols=40 lines=8");//设置窗口大小
}
struct gameRole
{
	int pattern;//模式1or2//先手手1表示先走2表示后走
	int colour;//1表示走白棋，2表示走黑棋
	bool huihe;//回合1为玩家，0为电脑
}role;
struct Blackchess
{
	int number;//黑棋数量

}Bchess;
struct Whitechess
{
	int number;//白棋数量
}Wchess;
//走棋结构体
struct Chess
{
	int x;//你想走的棋子的坐标x
	int y;//你想走的棋子的坐标y
	int c;//你要走的棋子到达的坐标x
	int d;//你要走的棋子到达的坐标y
}Go;
//输入信息（初始化）
void inputinformation()
{
	setwindowstyle();
	printf("  * 开始游戏 *\n");
	printf("输入1选择白棋，输入2选择黑棋\n");
	scanf("%d", &role.colour);
	if (role.colour == 1)
	{
		printf("您选择了白棋：\n");
	}
	else if (role.colour == 2)
	{
		printf("您选择了黑棋：\n");
	}
	printf(" 输入 1 人类先手\n");
	printf(" 输入 2 电脑先手\n");
	scanf("%d", &role.colour);
	if (role.colour == 1)
	{
		printf("请先手下棋：\n");
	}
	else if (role.colour == 2)
	{
		printf("请后手下棋：\n");
	}
	else printf("请重新选择：\n");
	
	
	
	
	
	

	
	
}

//键盘控制
int keyboard()
{
	int ch;
	while (1)
	{

		ch = _getch();//获取键盘

		
			switch (ch)
			{
				//左
			case 'a':	
				
				break;
			case 'd':	
				
				break;
			case 'w':
			
				break;
			case 's':	
			
				break;
			default:
				printf("ch:%d\n", ch);
				break;
			}
		}
}
//主程序
int main()
{
	inputinformation();
	
	while (1)
	{
		
	}
}
