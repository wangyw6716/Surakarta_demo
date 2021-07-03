#include"Hfolder.h"
#pragma comment(lib,"winmm.lib")//加载库---音乐


//遍历棋子个数
void number()
{
	Bnumber = 0;
	Wnumber = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j].name == 1)
			{
				Bnumber++;
			}
			else if(map[i][j].name==2)
			{
				Wnumber++;
			}
		}
	
	}
}


//胜负判定
void shuying()
{
	if (Bnumber == 0)
	{
		printf("黑棋失败，白棋胜利");
		MessageBox(NULL, "黑棋失败，白棋胜利", "提示", MB_OK);
		
	}
	else if (Wnumber==0)
	{
		printf("白棋失败，黑棋胜利");
		MessageBox(NULL, "白棋失败，黑棋胜利", "提示", MB_OK);
	
		
	}
}


//调整窗口函数
void setwindowstyle()
{
	system("title 苏卡塔尔棋");
	system("color f0");//设置颜色
	system("mode con cols=40 lines=8");//设置窗口大小
}


//回合函数
void hihe()
{
	int ixd=0;//记录次数标志
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


//提示
//void tishi()
//{
//	for (int i = msg.x-1; i < msg.x+1; i++)
//	{
//		if (map[msg.x][msg.y].name == 0)
//		{
//			map[msg.x][msg.y].name = 3;
//		}
//	}
//
//}

void Grc() {
	if ((msgmove.x == 0 && msgmove.y == 0) || (msgmove.x == 0 && msgmove.y == 5) || (msgmove.x == 5 && msgmove.y == 0) || (msgmove.x == 5 && msgmove.y == 5)) {
		return;
	}
	cout << msgmove.x;
	return;
}

//走子函数  he值为1时黑子回合，为2时白子回合
void zouzi(int he)
{
	int ixd;
	ixd = msgmove.n % 2;
	switch (ixd)
	{
	    case 1:
				if (map[msg.x][msg.y].name ==he)//判断该坐标是否有棋子  拿子必须有棋子
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
				if (map[msg.x][msg.y].name == 0)//判断该坐标是否有棋子或吃子 || map[msg.x][msg.y].name != msgmove.name  判断该点是否有棋子,没棋子就允许落子
				{
					msgmove.n++;
					msgmove.nhb++;
					printf("落子");
					map[msgmove.x][msgmove.y].name = 0;
					map[msg.x][msg.y].name = msgmove.name;
				}
				else {
					MessageBox(NULL, "落子不符合规则", "提示", MB_OK);
				}
			}
			else {

				Grc();
				MessageBox(NULL, "落子不符合规则", "提示", MB_OK);

			}
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
	

//* 初始化数据
void  GameInit()
{
	//遍历二维数据
	for (int i = 0 ; i < ROW; i++)
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
				
				if (i >=4)
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


//*测试函数，打印二维数组的值
void show()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("( %d %d )%d ", (map[i][j].y - 130) / 50, (map[i][j].x- 130) / 50, map[i][j].name);
		}
		printf("\n");
	}
}

//*背景音乐
void  PlayBGM()
{
    //1打开音乐想多媒体设备接口发送一个字符串,代表指令    alias 取别名	
	mciSendString("oprn 123.mp3",0,0,0);
    //2,播放音乐
	mciSendString("piay 123.mp3", 0, 0, 0);
	//3关闭音乐
	Sleep(3000);   //延时3s
	mciSendString("close 123.mp3", 0, 0, 0);
}


//绘制对话框文字档
void duihuakuang()
{
	//绘制对话框
	setlinestyle(PS_SOLID, 1);//设置线条颜色，粗细
	setfillcolor(WHITE);
	settextcolor(BLACK);
	fillrectangle(0, 550, 599, 699);//对话框背景
	line(0, 552, 600, 552);
	outtextxy(260, 560, "开始游戏");//显示
	//输出坐标1 2 3 4 5 6 
	for (int j = 0; j < 6; ++j)
	{
		settextcolor(RED);
		char temp[20] = { '0', '1', '2', '3', '4', '5' };
		outtextxy(140, 150 + 50 * j, temp[j]);
	}
	for (int i = 0; i < 6; i++)
	{
		settextcolor(RED);
		char temp[20] = { '0', '1', '2', '3', '4', '5' };
		outtextxy(153 + 50 * i, 140, temp[i]);
	}
	int c = 0;
	//特殊功能
	//输出分数等
	setbkmode(TRANSPARENT);//设置背景透明
	settextstyle(15, 0, "黑体");//设置字体
	char coin[20] = "";
	char coin1[20] = "";
	sprintf_s(coin, "黑子数量：%d", Bnumber);//存入字体
	sprintf_s(coin1, "白子数量：%d", Wnumber);//存入字体
	outtextxy(500, 600, coin);//显示
	outtextxy(500, 630, coin1);//显示
	c = msgmove.nhb % 2;
	if (c == 1)
	{
		outtextxy(500, 570, "回合：黑子");
	}
	else if (c == 0)
	{ 
		outtextxy(500, 570, "回合：白子");
	}
}


//*绘制棋盘
void draw()
{
	BeginBatchDraw();//双缓冲绘图防止闪屏不美观
	COLORREF color = WHITE;//设置画线颜色
	setbkcolor(RGB(204,204,204));//设置背景颜色 
	setlinecolor(BLACK);//设置颜色
	setlinestyle(PS_SOLID, 3);//设置线条颜色，粗细
	
	cleardevice();//清屏
	//左上角圆
	circle(150, 150, 50);          //画园
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
	setfillcolor(RGB(204, 204, 204));
	//左上圆填充
	solidrectangle(150, 150, 250, 250);
	//右上圆填充
	solidrectangle(300, 150, 400, 250);
	//右下圆填充
	solidrectangle(300, 300, 400, 400);
	//左下圆填充
	solidrectangle(150,300,250,400);


	setlinecolor(BLACK);//设置画线颜色
	setlinestyle(PS_SOLID,3);//设置画线宽度 3
	//绘制横竖交替的棋盘
	for (int i = 0; i < 6; i++)
	{
		line(150 + QP_HIGH * i, 150, 150 + QP_HIGH * i, 400);
		for (int j = 0; j < 6;j++)
		{
			line(150, 150 + QP_WIDTH * j, 400, 150 + QP_WIDTH * j);
		}
	}

	duihuakuang();
	//画棋子
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j].name != 0)
			{
				if (map[i][j].name==1)
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
				//else if (map[i][j].name == 3)
				//{
				//	setbkcolor(YELLOW);
				//	settextcolor(YELLOW);
				//	setlinecolor(YELLOW);
				//	//setbkcolor(RGB(204, 204, 204));//设置背景颜色 
				//	fillcircle(map[i][j].x, map[i][j].y, 20);

				//}
			}
		}
	}
	EndBatchDraw();//防止闪屏不美观

}


int main()
{
    GameInit();
	show();
	//setwindowstyle();
	initgraph(WIDTH, HIGH, SHOWCONSOLE);//新建窗口
	while (1)
	{
		number();
		draw();
		//GameControl();
		GameControl2();
		shuying();
	}
	while (1);
	return 0;
}