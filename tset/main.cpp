#include"Hfolder.h"
#pragma comment(lib,"winmm.lib")//加载库---音乐

void setStep1(int x, int y, int type);
void AI();
void search1(int x, int y);
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
		//zouzi(1);  //调用走子函数
		//AI(1);
		AI();
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




// 搜寻所选棋子的飞行吃子走位（深度优先）
// direction为搜索路线方向，0四个方向，1上，2下，3左，4右，type为棋子类型(废弃,没有用)
int chi = 0;
void fly_dfs(int x, int y, int direction, int type, int flag) {
	printf("\nx:%d,y:%d,direction:%d,flag:%d", x, y, direction, flag);
	if (chi)return;
	// 四个角
	if ((x == 0 && y == 0) || (x == 0 && y == 5) || (x == 5 && y == 0) || (x == 5 && y == 5)) {
		return;
	}

	// 如果是敌方棋子且经过圆弧
	if (map[x][y].name != msgmove.name && flag == 1 && (map[x][y].name != 0) && msg.x == x && msg.y == y) {
		msgmove.n++;
		msgmove.nhb++;
		printf("落子点:x:%d,y:%d", msg.x, msg.y);
		printf("\n吃子");
		printf("\nx:%d,y:%d,direction:%d,flag:%d\n", x, y, direction, flag);
		chi = 1;
		map[msgmove.x][msgmove.y].name = 0;
		map[msg.x][msg.y].name = msgmove.name;
		hihe();   //调用回合函数
		return;
	}
	else if (map[x][y].name != msgmove.name && (map[x][y].name != 0)) {
		return;
	}

	// 如果是己方棋子
	if (map[x][y].name == msgmove.name && direction != 0) {
		return;
	}

	// 起始点
	if (!direction) {
		printf("\ndirection=%d", direction);
		// 如果是切点的情况
		if (x == 0 && y == 1) {
			fly_dfs(1, 0, 4, type, 1);
		}
		else if (x == 0 && y == 2) {
			fly_dfs(2, 0, 4, type, 1);
		}
		else if (x == 0 && y == 3) {
			fly_dfs(2, 5, 3, type, 1);
		}
		else if (x == 0 && y == 4) {
			fly_dfs(1, 5, 3, type, 1);
		}
		else if (x == 1 && y == 0) {
			fly_dfs(0, 1, 2, type, 1);
		}
		else if (x == 2 && y == 0) {
			fly_dfs(0, 2, 2, type, 1);
		}
		else if (x == 3 && y == 0) {
			fly_dfs(5, 2, 1, type, 1);
		}
		else if (x == 4 && y == 0) {
			fly_dfs(5, 1, 1, type, 1);
		}
		else if (x == 1 && y == 5) {
			fly_dfs(0, 4, 2, type, 1);
		}
		else if (x == 2 && y == 5) {
			fly_dfs(0, 3, 2, type, 1);
		}
		else if (x == 3 && y == 5) {
			fly_dfs(5, 3, 1, type, 1);
		}
		else if (x == 4 && y == 5) {
			fly_dfs(5, 4, 1, type, 1);
		}
		else if (x == 5 && y == 1) {
			fly_dfs(4, 0, 4, type, 1);
		}
		else if (x == 5 && y == 2) {
			fly_dfs(3, 0, 4, type, 1);
		}
		else if (x == 5 && y == 3) {
			fly_dfs(3, 5, 3, type, 1);
		}
		else if (x == 5 && y == 4) {
			fly_dfs(4, 5, 3, type, 1);
		}

		// 上
		if (x - 1 >= 0) {
			printf("x-1执行了");
			fly_dfs(x - 1, y, 1, type, flag);
		}

		// 下
		if (x + 1 <= 5) {
			fly_dfs(x + 1, y, 2, type, flag);
		}

		// 左
		if (y - 1 >= 0) {
			fly_dfs(x, y - 1, 3, type, flag);
		}

		// 右
		if (y + 1 <= 5) {
			fly_dfs(x, y + 1, 4, type, flag);
		}
	}
	else 
	{
		//printf("\nx:%d,y:%d,direction:%d,flag:%d", x, y, direction, flag);
		// 如果是切点
		if (x == 0 && y == 1 && direction == 1) {
			fly_dfs(1, 0, 4, type, 1);
		}
		else if (x == 0 && y == 2 && direction == 1) {
			fly_dfs(2, 0, 4, type, 1);
		}
		else if (x == 0 && y == 3 && direction == 1) {
			fly_dfs(2, 5, 3, type, 1);
		}
		else if (x == 0 && y == 4 && direction == 1) {
			fly_dfs(1, 5, 3, type, 1);
		}
		else if (x == 1 && y == 0 && direction == 3) {
			fly_dfs(0, 1, 2, type, 1);
		}
		else if (x == 2 && y == 0 && direction == 3) {
			fly_dfs(0, 2, 2, type, 1);
		}
		else if (x == 3 && y == 0 && direction == 3) {
			fly_dfs(5, 2, 1, type, 1);
		}
		else if (x == 4 && y == 0 && direction == 3) {
			fly_dfs(5, 1, 1, type, 1);
		}
		else if (x == 1 && y == 5 && direction == 4) {
			fly_dfs(0, 4, 2, type, 1);
		}
		else if (x == 2 && y == 5 && direction == 4) {
			fly_dfs(0, 3, 2, type, 1);
		}
		else if (x == 3 && y == 5 && direction == 4) {
			fly_dfs(5, 3, 1, type, 1);
		}
		else if (x == 4 && y == 5 && direction == 4) {
			fly_dfs(5, 4, 1, type, 1);
		}
		else if (x == 5 && y == 1 && direction == 2) {
			fly_dfs(4, 0, 4, type, 1);
		}
		else if (x == 5 && y == 2 && direction == 2) {
			fly_dfs(3, 0, 4, type, 1);
		}
		else if (x == 5 && y == 3 && direction == 2) {
			fly_dfs(3, 5, 3, type, 1);
		}
		else if (x == 5 && y == 4 && direction == 2) {
			fly_dfs(4, 5, 3, type, 1);
		}

		// 上
		if (direction == 1) {
			if (x - 1 >= 0) {
				printf("向上走了");
				fly_dfs(x - 1, y, direction, type, flag);
			}
		}

		// 下
		if (direction == 2) {
			if (x + 1 <= 5) {
				printf("向下走了");
				fly_dfs(x + 1, y, direction, type, flag);
			}
		}

		// 左
		if (direction == 3) {
			if (y - 1 >= 0) {
				printf("向左走了");
				fly_dfs(x, y - 1, direction, type, flag);
			}
		}

		// 右
		if (direction == 4) {
			if (y + 1 <= 5) {
				printf("向右走了");
				fly_dfs(x, y + 1, direction, type, flag);
			}
		}
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
				if (map[msg.x][msg.y].name ==he)//判断该坐标是否有棋子  拿子必须有棋子
				{
					msgmove.n++;
					printf("\n拿子");
					msgmove.x = msg.x;
					msgmove.y = msg.y;
					msgmove.name = map[msgmove.x][msgmove.y].name;
				//	tishi();
				}
				else if (map[msg.x][msg.y].name == 0)
				{
					//MessageBox(NULL, "不是你的回合", "提示", MB_OK);
					printf("\n此处没有棋子");

				}
				else if (map[msg.x][msg.y].name != he)
				{
					//MessageBox(NULL, "不是你的回合", "提示", MB_OK);
					printf("\n不是你的回合");

				}
					break;
	 	case 0:
			if (map[msg.x][msg.y].name == map[msgmove.x][msgmove.y].name) {//重新拿子
				//msgmove.n++;
				if (map[msg.x][msg.y].name == he)//判断该坐标是否有棋子  拿子必须有棋子
				{
					//msgmove.n++;
					printf("\n拿子");
					msgmove.x = msg.x;
					msgmove.y = msg.y;
					msgmove.name = map[msgmove.x][msgmove.y].name;
					//	tishi();
				}
				else if (map[msg.x][msg.y].name == 0)
				{
					//MessageBox(NULL, "不是你的回合", "提示", MB_OK);
					printf("\n此处没有棋子");

				}
				else if (map[msg.x][msg.y].name != he)
				{
					//MessageBox(NULL, "不是你的回合", "提示", MB_OK);
					printf("\n不是你的回合");

				}
			}else{
				chi = 0;
				fly_dfs(msgmove.x, msgmove.y, 0, 0, 0); 
				if (msg.x - msgmove.x<2 && msg.y - msgmove.y<2 && msg.x - msgmove.x>-2 && msg.y - msgmove.y>-2 && !chi)
				{
					if (map[msg.x][msg.y].name == 0)//判断该坐标是否有棋子或吃子 || map[msg.x][msg.y].name != msgmove.name  判断该点是否有棋子,没棋子就允许落子
					{
						msgmove.n++;
						msgmove.nhb++;
						printf("\n落子\n");
						chi = 0;
						map[msgmove.x][msgmove.y].name = 0;
						map[msg.x][msg.y].name = msgmove.name;
						hihe();   //调用回合函数
					}
					else {
						printf("\n落子不符合规则");
						//MessageBox(NULL, "落子不符合规则", "提示", MB_OK);
						msgmove.n++;
						chi = 0;
						printf("\n请重新拿子");
					}
				}
				else if (!chi) {
					printf("\n落子不符合规则");
					//MessageBox(NULL, "落子不符合规则", "提示", MB_OK);
					msgmove.n++;
					chi = 0;
					printf("\n请重新拿子");
				}
			}
			break;
	
	}
}


//==================================================================================

struct startPoints startPoints[50000]; // 用于存储每个遍历的点
struct points_list points_list[50000]; // 用来存储最优选择点
int score_list[50000]; // 用来存储每个电脑棋子的最优选择点的预估分
int state_temp[6][6]={ { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0 }, { 2, 2, 2, 2, 2, 2 }, {  2, 2, 2, 2, 2, 2 } };
int step_temp[6][6] = { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } };
int flag2 = 0;
// 搜寻所选棋子的飞行吃子走位（深度优先）
// direction为搜索路线方向，0四个方向，1上，2下，3左，4右，type为棋子类型:1玩家\2电脑

void fly_dfs2(int x, int y, int direction, int type, int flag2) {

	// 四个角
	if ((x == 0 && y == 0) || (x == 0 && y == 5) || (x == 5 && y == 0) || (x == 5 && y == 5)) {
		return;
	}

	// 如果是敌方棋子且经过圆弧
	if (state_temp[x][y] == 2 && flag2 == 1) {
		step_temp[x][y] = 2;
		return;

	}
	else if (state_temp[x][y] == 2) {
		return;
	}

	// 如果是己方棋子
	if (state_temp[x][y] == type && direction != 0) {
		return;
	}

	// 起始点
	if (direction == 0) {

		// 如果是切点的情况
		if (x == 0 && y == 1) {
			fly_dfs2(1, 0, 4, type, 1);
		}
		else if (x == 0 && y == 2) {
			fly_dfs2(2, 0, 4, type, 1);
		}
		else if (x == 0 && y == 3) {
			fly_dfs2(2, 5, 3, type, 1);
		}
		else if (x == 0 && y == 4) {
			fly_dfs2(1, 5, 3, type, 1);
		}
		else if (x == 1 && y == 0) {
			fly_dfs2(0, 1, 2, type, 1);
		}
		else if (x == 2 && y == 0) {
			fly_dfs2(0, 2, 2, type, 1);
		}
		else if (x == 3 && y == 0) {
			fly_dfs2(5, 2, 1, type, 1);
		}
		else if (x == 4 && y == 0) {
			fly_dfs2(5, 1, 1, type, 1);
		}
		else if (x == 1 && y == 5) {
			fly_dfs2(0, 4, 2, type, 1);
		}
		else if (x == 2 && y == 5) {
			fly_dfs2(0, 3, 2, type, 1);
		}
		else if (x == 3 && y == 5) {
			fly_dfs2(5, 3, 1, type, 1);
		}
		else if (x == 4 && y == 5) {
			fly_dfs2(5, 4, 1, type, 1);
		}
		else if (x == 5 && y == 1) {
			fly_dfs2(4, 0, 4, type, 1);
		}
		else if (x == 5 && y == 2) {
			fly_dfs2(3, 0, 4, type, 1);
		}
		else if (x == 5 && y == 3) {
			fly_dfs2(3, 5, 3, type, 1);
		}
		else if (x == 5 && y == 4) {
			fly_dfs2(4, 5, 3, type, 1);
		}

		// 上
		if (x - 1 >= 0) {
			fly_dfs2(x - 1, y, 1, type, flag2);
		}

		// 下
		if (x + 1 <= 5) {
			fly_dfs2(x + 1, y, 2, type, flag2);
		}

		// 左
		if (y - 1 >= 0) {
			fly_dfs2(x, y - 1, 3, type, flag2);
		}

		// 右
		if (y + 1 <= 5) {
			fly_dfs2(x, y + 1, 4, type, flag2);
		}
	}
	else {

		// 如果是切点
		if (x == 0 && y == 1 && direction == 1) {
			fly_dfs2(1, 0, 4, type, 1);
		}
		else if (x == 0 && y == 2 && direction == 1) {
			fly_dfs2(2, 0, 4, type, 1);
		}
		else if (x == 0 && y == 3 && direction == 1) {
			fly_dfs2(2, 5, 3, type, 1);
		}
		else if (x == 0 && y == 4 && direction == 1) {
			fly_dfs2(1, 5, 3, type, 1);
		}
		else if (x == 1 && y == 0 && direction == 3) {
			fly_dfs2(0, 1, 2, type, 1);
		}
		else if (x == 2 && y == 0 && direction == 3) {
			fly_dfs2(0, 2, 2, type, 1);
		}
		else if (x == 3 && y == 0 && direction == 3) {
			fly_dfs2(5, 2, 1, type, 1);
		}
		else if (x == 4 && y == 0 && direction == 3) {
			fly_dfs2(5, 1, 1, type, 1);
		}
		else if (x == 1 && y == 5 && direction == 4) {
			fly_dfs2(0, 4, 2, type, 1);
		}
		else if (x == 2 && y == 5 && direction == 4) {
			fly_dfs2(0, 3, 2, type, 1);
		}
		else if (x == 3 && y == 5 && direction == 4) {
			fly_dfs2(5, 3, 1, type, 1);
		}
		else if (x == 4 && y == 5 && direction == 4) {
			fly_dfs2(5, 4, 1, type, 1);
		}
		else if (x == 5 && y == 1 && direction == 2) {
			fly_dfs2(4, 0, 4, type, 1);
		}
		else if (x == 5 && y == 2 && direction == 2) {
			fly_dfs2(3, 0, 4, type, 1);
		}
		else if (x == 5 && y == 3 && direction == 2) {
			fly_dfs2(3, 5, 3, type, 1);
		}
		else if (x == 5 && y == 4 && direction == 2) {
			fly_dfs2(4, 5, 3, type, 1);
		}

		// 上
		if (direction == 1) {
			if (x - 1 >= 0) {
				fly_dfs2(x - 1, y, direction, type, flag2);
			}
		}

		// 下
		if (direction == 2) {
			if (x + 1 <= 5) {
				fly_dfs2(x + 1, y, direction, type, flag2);
			}
		}

		// 左
		if (direction == 3) {
			if (y - 1 >= 0) {
				fly_dfs2(x, y - 1, direction, type, flag2);
			}
		}

		// 右
		if (direction == 4) {
			if (y + 1 <= 5) {
				fly_dfs2(x, y + 1, direction, type, flag2);
			}
		}
	}
}



 //机器AI
void AI() {
	memset(startPoints,0,sizeof(startPoints));
	//startPoints.clear();
	// points_list.clear();
	// score_list.clear();

	int x = 0;
	int y = 0;

	int maxs = -127;
	int f = 0;
	int score = 0;

	// 遍历所有的电脑棋子
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {


			if (map[i][j].name == 1) {
				for (int m = 0; m < 6; m++) {
					for (int n = 0; n < 6; n++) {
						state_temp[m][n] = map[m][n].name;
					}
				}

				for (int m = 0; m < 6; m++) {
					for (int n = 0; n < 6; n++)
						step_temp[m][n] = 0;
				}

				search1(i, j);
			}
		}
	}

	for (int i = 0; i < sizeof(score_list) / sizeof(score_list[0]); i++) {
		//System.out.println(score_list.get(i));
		//System.out.println(startPoints.get(i).x + " " + startPoints.get(i).y);
		//System.out.println(points_list.get(i).x + " " + points_list.get(i).y);
		if (score_list[i] > maxs) {
			maxs = score_list[i];
			f = i;
		}
	}

	map[points_list[f].x][points_list[f].y].name = 1;
	map[startPoints[f].x][startPoints[f].y].name = 0;
	printf("\n points_list x:%d,y:%d", points_list[f].x, points_list[f].y);
	printf("  startPoints x:%d,y:%d", startPoints[f].x, startPoints[f].y); 
	msgmove.nhb++;

	//		System.out.println(points_list.get(f).x + " " + points_list.get(f).y);
	//		System.out.println(startPoints.get(f).x + " " + startPoints.get(f).y);
	//		for(int i = 0; i < 6; i++) {
	//			for(int j = 0; j < 6; j++) {
	//				System.out.print(myPanel.state[i][j]+" ");
	//			}
	//			System.out.print("\n");
	//		}
}

// 电脑玩家对弈走法模拟，返回（X，Y）棋子的最佳着棋
void search1(int x, int y) {

	int maxs = -65536;
	int score = 0;
	int xx = 0, yy = 0;
	// 回合模拟
	setStep1(x, y, 1);


	int s1[6][6];
	int s2[6][6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			s1[i][j] = map[i][j].name;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			s2[i][j] = step_temp[i][j];
		}
	}
	//		
	//		for(int i = 0;i < 6; i++) {
	//			for(int j = 0; j < 6; j++) {
	//				System.out.print(step_temp[i][j]+" ");
	//			}
	//			System.out.print("\n");
	//		}

			//遍历可落子点
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {

			for (int a1 = 0; a1 < 6; a1++) {
				for (int a2 = 0; a2 < 6; a2++) {
					state_temp[a1][a2] = s1[a1][a2];
					
				}
			}
			for (int a1 = 0; a1 < 6; a1++) {
				for (int a2 = 0; a2 < 6; a2++) {
					step_temp[a1][a2] = s2[a1][a2];
				}
			}

			if (step_temp[i][j] == 1) {

				score = 0;
				if (state_temp[i][j] == 2) { //吃子

					score += 2;
					state_temp[i][j] = 1;
					state_temp[x][y] = 0;
				}
				else { //不吃子
					score++;
					state_temp[i][j] = 1;
					state_temp[x][y] = 0;
				}

				//int[][] a = state_temp.clone();
				int a[6][6];
				for (int a1 = 0; a1 < 6; a1++) {
					for (int a2 = 0; a2 < 6; a2++) {
						a[a1][a2] = state_temp[a1][a2];
						
					}
				}

				//模拟玩家
				for (int m = 0; m < 6; m++) {
					for (int n = 0; n < 6; n++) {

						//state_temp = a.clone();
						for (int a1 = 0; a1 < 6; a1++) {
							for (int a2 = 0; a2 < 6; a2++) {
								state_temp[a1][a2] = a[a1][a2];
								

							}
						}

						if (state_temp[m][n] == 1) {

							for (int x1 = 0; x1 < 6; x1++) {
								for (int y1 = 0; y1 < 6; y1++) {
									step_temp[x1][y1] = 0;
								}
							}

							int score1 = score;
							setStep1(m, n, 2);

							//								int[][] s3 = state_temp.clone();
							//								int[][] s4 = step_temp.clone();
							int s3[6][6];
							int s4[6][6];
							for (int a1 = 0; a1 < 6; a1++) {
								for (int a2 = 0; a2 < 6; a2++) {
									s3[a1][a2] = state_temp[a1][a2];
								}
							}
							for (int a1 = 0; a1 < 6; a1++) {
								for (int a2 = 0; a2 < 6; a2++) {
									s4[a1][a2] = step_temp[a1][a2];
								}
							}

							for (int o = 0; o < 6; o++) {
								for (int p = 0; p < 6; p++) {

									//										state_temp = s3.clone();
									//										step_temp = s4.clone();
									for (int a1 = 0; a1 < 6; a1++) {
										for (int a2 = 0; a2 < 6; a2++) {
											state_temp[a1][a2] = s3[a1][a2];
										}
									}
									for (int a1 = 0; a1 < 6; a1++) {
										for (int a2 = 0; a2 < 6; a2++) {
											step_temp[a1][a2] = s4[a1][a2];
										}
									}

									if (step_temp[o][p] == 1) {
										//吃子
										if (state_temp[o][p] == 2) {
											score1 -= 2;
										}
										else {
											score1++;
										}
									}
								}
							}
							if (score1 > score1) {
								score = score1;
							}
						}

					}
				}
				if (score > maxs) {
					xx = i;
					yy = j;
					maxs = score;
				}
			}
		}
	}

	int lenstartPoints = sizeof(startPoints) / sizeof(startPoints[0]);
	int lenpoints_list = sizeof(points_list) / sizeof(points_list[0]);
	int lenscore_list = sizeof(score_list) / sizeof(score_list[0]);

	//startPoints.add(new Point(x, y));
	startPoints[lenstartPoints] = {x,y};
	startPoints[lenpoints_list] = {xx,yy};
	//points_list.add(new Point(xx, yy));
	score_list[lenscore_list] = maxs;
	printf("lenstartPoints:%d", lenstartPoints);
	printf("maxs:%d",maxs);
}

// ai 将某个棋子可走的点标注出来
void setStep1(int x, int y, int type) {

	if (x - 1 >= 0) {
		if (state_temp[x - 1][y] != type)
			step_temp[x - 1][y] = 2;
	}
	if (x + 1 <= 5) {
		if (state_temp[x + 1][y] != type)
			step_temp[x + 1][y] = 2;
	}
	if (y - 1 >= 0) {
		if (state_temp[x][y - 1] != type)
			step_temp[x][y - 1] = 2;
	}
	if (y + 1 <= 5) {
		if (state_temp[x][y + 1] != type)
			step_temp[x][y + 1] = 2;
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (state_temp[x - 1][y - 1] != type)
			step_temp[x - 1][y - 1] = 2;
	}
	if (x + 1 <= 5 && y - 1 >= 0) {
		if (state_temp[x + 1][y - 1] != type)
			step_temp[x + 1][y - 1] = 2;
	}
	if (x - 1 >= 0 && y + 1 <= 5) {
		if (state_temp[x - 1][y + 1] != type)
			step_temp[x - 1][y + 1] = 2;
	}
	if (x + 1 <= 5 && y + 1 <= 5) {
		if (state_temp[x + 1][y + 1] != type)
			step_temp[x + 1][y + 1] = 2;
	}

	fly_dfs2(x, y, 0, type, 0);

}



//鼠标移动棋子
void GameControl2()
{
	if (MouseHit())//如果有鼠标消息
	{
		msg = GetMouseMsg();//获取鼠标消息
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