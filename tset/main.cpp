#include"Hfolder.h"
#pragma comment(lib,"winmm.lib")//���ؿ�---����

void setStep1(int x, int y, int type);
void AI();
void search1(int x, int y);
//�������Ӹ���
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


//ʤ���ж�
void shuying()
{
	if (Bnumber == 0)
	{
		printf("����ʧ�ܣ�����ʤ��");
		MessageBox(NULL, "����ʧ�ܣ�����ʤ��", "��ʾ", MB_OK);
		
	}
	else if (Wnumber==0)
	{
		printf("����ʧ�ܣ�����ʤ��");
		MessageBox(NULL, "����ʧ�ܣ�����ʤ��", "��ʾ", MB_OK);
	
		
	}
}


//�������ں���
void setwindowstyle()
{
	system("title �տ�������");
	system("color f0");//������ɫ
	system("mode con cols=40 lines=8");//���ô��ڴ�С
}


//�غϺ���
void hihe()
{
	int ixd=0;//��¼������־
	ixd = msgmove.nhb % 2;
	if (ixd == 1)
	{
		//zouzi(1);  //�������Ӻ���
		//AI(1);
		AI();
	}
	else if (ixd == 0)
	{
		zouzi(2);   
	}

}


//��ʾ
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




// ��Ѱ��ѡ���ӵķ��г�����λ��������ȣ�
// directionΪ����·�߷���0�ĸ�����1�ϣ�2�£�3��4�ң�typeΪ��������(����,û����)
int chi = 0;
void fly_dfs(int x, int y, int direction, int type, int flag) {
	printf("\nx:%d,y:%d,direction:%d,flag:%d", x, y, direction, flag);
	if (chi)return;
	// �ĸ���
	if ((x == 0 && y == 0) || (x == 0 && y == 5) || (x == 5 && y == 0) || (x == 5 && y == 5)) {
		return;
	}

	// ����ǵз������Ҿ���Բ��
	if (map[x][y].name != msgmove.name && flag == 1 && (map[x][y].name != 0) && msg.x == x && msg.y == y) {
		msgmove.n++;
		msgmove.nhb++;
		printf("���ӵ�:x:%d,y:%d", msg.x, msg.y);
		printf("\n����");
		printf("\nx:%d,y:%d,direction:%d,flag:%d\n", x, y, direction, flag);
		chi = 1;
		map[msgmove.x][msgmove.y].name = 0;
		map[msg.x][msg.y].name = msgmove.name;
		hihe();   //���ûغϺ���
		return;
	}
	else if (map[x][y].name != msgmove.name && (map[x][y].name != 0)) {
		return;
	}

	// ����Ǽ�������
	if (map[x][y].name == msgmove.name && direction != 0) {
		return;
	}

	// ��ʼ��
	if (!direction) {
		printf("\ndirection=%d", direction);
		// ������е�����
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

		// ��
		if (x - 1 >= 0) {
			printf("x-1ִ����");
			fly_dfs(x - 1, y, 1, type, flag);
		}

		// ��
		if (x + 1 <= 5) {
			fly_dfs(x + 1, y, 2, type, flag);
		}

		// ��
		if (y - 1 >= 0) {
			fly_dfs(x, y - 1, 3, type, flag);
		}

		// ��
		if (y + 1 <= 5) {
			fly_dfs(x, y + 1, 4, type, flag);
		}
	}
	else 
	{
		//printf("\nx:%d,y:%d,direction:%d,flag:%d", x, y, direction, flag);
		// ������е�
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

		// ��
		if (direction == 1) {
			if (x - 1 >= 0) {
				printf("��������");
				fly_dfs(x - 1, y, direction, type, flag);
			}
		}

		// ��
		if (direction == 2) {
			if (x + 1 <= 5) {
				printf("��������");
				fly_dfs(x + 1, y, direction, type, flag);
			}
		}

		// ��
		if (direction == 3) {
			if (y - 1 >= 0) {
				printf("��������");
				fly_dfs(x, y - 1, direction, type, flag);
			}
		}

		// ��
		if (direction == 4) {
			if (y + 1 <= 5) {
				printf("��������");
				fly_dfs(x, y + 1, direction, type, flag);
			}
		}
	}
}



//���Ӻ���  heֵΪ1ʱ���ӻغϣ�Ϊ2ʱ���ӻغ�
void zouzi(int he)
{
	int ixd;
	ixd = msgmove.n % 2;
	switch (ixd)
	{
	    case 1:
				if (map[msg.x][msg.y].name ==he)//�жϸ������Ƿ�������  ���ӱ���������
				{
					msgmove.n++;
					printf("\n����");
					msgmove.x = msg.x;
					msgmove.y = msg.y;
					msgmove.name = map[msgmove.x][msgmove.y].name;
				//	tishi();
				}
				else if (map[msg.x][msg.y].name == 0)
				{
					//MessageBox(NULL, "������Ļغ�", "��ʾ", MB_OK);
					printf("\n�˴�û������");

				}
				else if (map[msg.x][msg.y].name != he)
				{
					//MessageBox(NULL, "������Ļغ�", "��ʾ", MB_OK);
					printf("\n������Ļغ�");

				}
					break;
	 	case 0:
			if (map[msg.x][msg.y].name == map[msgmove.x][msgmove.y].name) {//��������
				//msgmove.n++;
				if (map[msg.x][msg.y].name == he)//�жϸ������Ƿ�������  ���ӱ���������
				{
					//msgmove.n++;
					printf("\n����");
					msgmove.x = msg.x;
					msgmove.y = msg.y;
					msgmove.name = map[msgmove.x][msgmove.y].name;
					//	tishi();
				}
				else if (map[msg.x][msg.y].name == 0)
				{
					//MessageBox(NULL, "������Ļغ�", "��ʾ", MB_OK);
					printf("\n�˴�û������");

				}
				else if (map[msg.x][msg.y].name != he)
				{
					//MessageBox(NULL, "������Ļغ�", "��ʾ", MB_OK);
					printf("\n������Ļغ�");

				}
			}else{
				chi = 0;
				fly_dfs(msgmove.x, msgmove.y, 0, 0, 0); 
				if (msg.x - msgmove.x<2 && msg.y - msgmove.y<2 && msg.x - msgmove.x>-2 && msg.y - msgmove.y>-2 && !chi)
				{
					if (map[msg.x][msg.y].name == 0)//�жϸ������Ƿ������ӻ���� || map[msg.x][msg.y].name != msgmove.name  �жϸõ��Ƿ�������,û���Ӿ���������
					{
						msgmove.n++;
						msgmove.nhb++;
						printf("\n����\n");
						chi = 0;
						map[msgmove.x][msgmove.y].name = 0;
						map[msg.x][msg.y].name = msgmove.name;
						hihe();   //���ûغϺ���
					}
					else {
						printf("\n���Ӳ����Ϲ���");
						//MessageBox(NULL, "���Ӳ����Ϲ���", "��ʾ", MB_OK);
						msgmove.n++;
						chi = 0;
						printf("\n����������");
					}
				}
				else if (!chi) {
					printf("\n���Ӳ����Ϲ���");
					//MessageBox(NULL, "���Ӳ����Ϲ���", "��ʾ", MB_OK);
					msgmove.n++;
					chi = 0;
					printf("\n����������");
				}
			}
			break;
	
	}
}


//==================================================================================

struct startPoints startPoints[50000]; // ���ڴ洢ÿ�������ĵ�
struct points_list points_list[50000]; // �����洢����ѡ���
int score_list[50000]; // �����洢ÿ���������ӵ�����ѡ����Ԥ����
int state_temp[6][6]={ { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0 }, { 2, 2, 2, 2, 2, 2 }, {  2, 2, 2, 2, 2, 2 } };
int step_temp[6][6] = { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } };
int flag2 = 0;
// ��Ѱ��ѡ���ӵķ��г�����λ��������ȣ�
// directionΪ����·�߷���0�ĸ�����1�ϣ�2�£�3��4�ң�typeΪ��������:1���\2����

void fly_dfs2(int x, int y, int direction, int type, int flag2) {

	// �ĸ���
	if ((x == 0 && y == 0) || (x == 0 && y == 5) || (x == 5 && y == 0) || (x == 5 && y == 5)) {
		return;
	}

	// ����ǵз������Ҿ���Բ��
	if (state_temp[x][y] == 2 && flag2 == 1) {
		step_temp[x][y] = 2;
		return;

	}
	else if (state_temp[x][y] == 2) {
		return;
	}

	// ����Ǽ�������
	if (state_temp[x][y] == type && direction != 0) {
		return;
	}

	// ��ʼ��
	if (direction == 0) {

		// ������е�����
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

		// ��
		if (x - 1 >= 0) {
			fly_dfs2(x - 1, y, 1, type, flag2);
		}

		// ��
		if (x + 1 <= 5) {
			fly_dfs2(x + 1, y, 2, type, flag2);
		}

		// ��
		if (y - 1 >= 0) {
			fly_dfs2(x, y - 1, 3, type, flag2);
		}

		// ��
		if (y + 1 <= 5) {
			fly_dfs2(x, y + 1, 4, type, flag2);
		}
	}
	else {

		// ������е�
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

		// ��
		if (direction == 1) {
			if (x - 1 >= 0) {
				fly_dfs2(x - 1, y, direction, type, flag2);
			}
		}

		// ��
		if (direction == 2) {
			if (x + 1 <= 5) {
				fly_dfs2(x + 1, y, direction, type, flag2);
			}
		}

		// ��
		if (direction == 3) {
			if (y - 1 >= 0) {
				fly_dfs2(x, y - 1, direction, type, flag2);
			}
		}

		// ��
		if (direction == 4) {
			if (y + 1 <= 5) {
				fly_dfs2(x, y + 1, direction, type, flag2);
			}
		}
	}
}



 //����AI
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

	// �������еĵ�������
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

// ������Ҷ����߷�ģ�⣬���أ�X��Y�����ӵ��������
void search1(int x, int y) {

	int maxs = -65536;
	int score = 0;
	int xx = 0, yy = 0;
	// �غ�ģ��
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

			//���������ӵ�
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
				if (state_temp[i][j] == 2) { //����

					score += 2;
					state_temp[i][j] = 1;
					state_temp[x][y] = 0;
				}
				else { //������
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

				//ģ�����
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
										//����
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

// ai ��ĳ�����ӿ��ߵĵ��ע����
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



//����ƶ�����
void GameControl2()
{
	if (MouseHit())//����������Ϣ
	{
		msg = GetMouseMsg();//��ȡ�����Ϣ
		msg = GetMouseMsg();//��ȡ�����Ϣ
		if (msg.uMsg == WM_LBUTTONDOWN)//���������ʱ
		{

			if (msg.x > 130 && msg.x < 420 && msg.y > 130 && msg.y < 420)//�߽�
			{
				int temp = msg.y;
				msg.y = (msg.x - 130) / QP_HIGH;
				msg.x = (temp - 130) / QP_WIDTH;
				hihe();   //���ûغϺ���
			}
		}
	}
	
}
	

//* ��ʼ������
void  GameInit()
{
	//������ά����
	for (int i = 0 ; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j].name = 0;
			char mcolor = 'B';//��ɫ
			if (i<2)
			{
				map[i][j].name = 1;
			}
			else
			{
				
				if (i >=4)
				{
					char mcolor = 'W';//��ɫ
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


//*���Ժ�������ӡ��ά�����ֵ
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

//*��������
void  PlayBGM()
{
    //1���������ý���豸�ӿڷ���һ���ַ���,����ָ��    alias ȡ����	
	mciSendString("oprn 123.mp3",0,0,0);
    //2,��������
	mciSendString("piay 123.mp3", 0, 0, 0);
	//3�ر�����
	Sleep(3000);   //��ʱ3s
	mciSendString("close 123.mp3", 0, 0, 0);
}


//���ƶԻ������ֵ�
void duihuakuang()
{
	//���ƶԻ���
	setlinestyle(PS_SOLID, 1);//����������ɫ����ϸ
	setfillcolor(WHITE);
	settextcolor(BLACK);
	fillrectangle(0, 550, 599, 699);//�Ի��򱳾�
	line(0, 552, 600, 552);
	outtextxy(260, 560, "��ʼ��Ϸ");//��ʾ
	//�������1 2 3 4 5 6 
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
	//���⹦��
	//���������
	setbkmode(TRANSPARENT);//���ñ���͸��
	settextstyle(15, 0, "����");//��������
	char coin[20] = "";
	char coin1[20] = "";
	sprintf_s(coin, "����������%d", Bnumber);//��������
	sprintf_s(coin1, "����������%d", Wnumber);//��������
	outtextxy(500, 600, coin);//��ʾ
	outtextxy(500, 630, coin1);//��ʾ
	c = msgmove.nhb % 2;
	if (c == 1)
	{
		outtextxy(500, 570, "�غϣ�����");
	}
	else if (c == 0)
	{ 
		outtextxy(500, 570, "�غϣ�����");
	}
}


//*��������
void draw()
{
	BeginBatchDraw();//˫�����ͼ��ֹ����������
	COLORREF color = WHITE;//���û�����ɫ
	setbkcolor(RGB(204,204,204));//���ñ�����ɫ 
	setlinecolor(BLACK);//������ɫ
	setlinestyle(PS_SOLID, 3);//����������ɫ����ϸ
	
	cleardevice();//����
	//���Ͻ�Բ
	circle(150, 150, 50);          //��԰
	circle(150, 150, 100);
	//���Ͻ�
	circle(400, 150, 50);
	circle(400, 150, 100);
	//����
	circle(150, 400, 50);
	circle(150, 400, 100);
	//����
	circle(400, 400, 50);
	circle(400, 400, 100);
	setfillcolor(RGB(204, 204, 204));
	//����Բ���
	solidrectangle(150, 150, 250, 250);
	//����Բ���
	solidrectangle(300, 150, 400, 250);
	//����Բ���
	solidrectangle(300, 300, 400, 400);
	//����Բ���
	solidrectangle(150,300,250,400);


	setlinecolor(BLACK);//���û�����ɫ
	setlinestyle(PS_SOLID,3);//���û��߿�� 3
	//���ƺ������������
	for (int i = 0; i < 6; i++)
	{
		line(150 + QP_HIGH * i, 150, 150 + QP_HIGH * i, 400);
		for (int j = 0; j < 6;j++)
		{
			line(150, 150 + QP_WIDTH * j, 400, 150 + QP_WIDTH * j);
		}
	}

	duihuakuang();
	//������
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
				//	//setbkcolor(RGB(204, 204, 204));//���ñ�����ɫ 
				//	fillcircle(map[i][j].x, map[i][j].y, 20);

				//}
			}
		}
	}
	EndBatchDraw();//��ֹ����������

}


int main()
{
    GameInit();
	show();
	//setwindowstyle();
	initgraph(WIDTH, HIGH, SHOWCONSOLE);//�½�����
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