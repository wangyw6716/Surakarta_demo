#include"Hfolder.h"
#pragma comment(lib,"winmm.lib")//���ؿ�---����


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
		zouzi(1);  //�������Ӻ���
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


/*



int chi = 0;
void Grc(int x, int y, int flag) {//�ж��Ƿ�����Բ��
	//int x = msgmove.x;
	//int y = msgmove.y;
	if (chi)return;
	printf("x:%d,y:%d",x,y);
	if ((msgmove.x == 0 && msgmove.y == 0) || (msgmove.x == 0 && msgmove.y == 5) || (msgmove.x == 5 && msgmove.y == 0) || (msgmove.x == 5 && msgmove.y == 5)) {
		MessageBox(NULL, "������,�����찡", "��ʾ", MB_OK);
		msgmove.n++;
		return;
	}

	if ((map[x][y].name == 0 || map[x][y].name == msgmove.name) && flag)
	{
		printf("flag:%d",flag);
		//MessageBox(NULL, "���ܷ����߻��߳��Լ���Ŷ", "��ʾ", MB_OK);
		msgmove.n++;
		return;
	}

	// ����ǵз������Ҿ���Բ��
	if (map[x][y].name != msgmove.name && flag == 1) {
		msgmove.n++;
		msgmove.nhb++;
		printf("����");
		map[msgmove.x][msgmove.y].name = 0;
		map[msg.x][msg.y].name = msgmove.name;
		chi = 1;
		return;

	}else if (map[x][y].name != msgmove.name) {
		return;
	}


	if (msg.x == x && msg.y == y && flag == 1) {
		msgmove.n++;
		msgmove.nhb++;
		printf("����");
		map[msgmove.x][msgmove.y].name = 0;
		map[msg.x][msg.y].name = msgmove.name;
	}

	printf("\n�ݹ鿪ʼ");

	// ������е�����
	if (x == 0 && y == 1) {
		Grc(1, 0,1);
	}
	else if (x == 0 && y == 2) {
		Grc(2, 0, 1);
	}
	else if (x == 0 && y == 3) {
		Grc(2, 5,1);
	}
	else if (x == 0 && y == 4) {
		Grc(1, 5, 1);
	}
	else if (x == 1 && y == 0) {
		Grc(0, 1, 1);
	}
	else if (x == 2 && y == 0) {
		Grc(0, 2, 1);
	}
	else if (x == 3 && y == 0) {
		Grc(5, 2, 1);
	}
	else if (x == 4 && y == 0) {
		Grc(5, 1, 1);
	}
	else if (x == 1 && y == 5) {
		Grc(0, 4, 1);
	}
	else if (x == 2 && y == 5) {
		Grc(0, 3, 1);
	}
	else if (x == 3 && y == 5) {
		Grc(5, 3, 1);
	}
	else if (x == 4 && y == 5) {
		Grc(5, 4, 1);
	}
	else if (x == 5 && y == 1) {
		Grc(4, 0, 1);
	}
	else if (x == 5 && y == 2) {
		Grc(3, 0, 1);
	}
	else if (x == 5 && y == 3) {
		Grc(3, 5, 1);
	}
	else if (x == 5 && y == 4) {
		Grc(4, 5, 1);
	}

	//// ��
	if (x - 1 >= 0) {
		Grc(x - 1, y, flag);
	}


	//// ��
	if (x + 1 <= 5) {
		Grc(x + 1, y,  flag);
	}

	//// ��
	if (y - 1 >= 0) {
		Grc(x, y - 1, flag);
	}

	//// ��
	if (y + 1 <= 5) {
		Grc(x, y + 1, flag);
	}


	//MessageBox(NULL, "���Ӳ����Ϲ���223", "��ʾ", MB_OK);
	return;
}
*/


// ��Ѱ��ѡ���ӵķ��г�����λ��������ȣ�
// directionΪ����·�߷���0�ĸ�����1�ϣ�2�£�3��4�ң�typeΪ��������(����):1���\2����

void fly_dfs(int x, int y, int direction, int type, int flag) {
	printf("\nx:%d,y:%d", x, y);
	// �ĸ���
	if ((x == 0 && y == 0) || (x == 0 && y == 5) || (x == 5 && y == 0) || (x == 5 && y == 5)) {
		return;
	}

	// ����ǵз������Ҿ���Բ��
	if (map[x][y].name != msgmove.name && flag == 1) {
		msgmove.n++;
		msgmove.nhb++;
		printf("\n����\n");
		map[msgmove.x][msgmove.y].name = 0;
		map[msg.x][msg.y].name = msgmove.name;
		return;
	}
	else if (map[x][y].name != msgmove.name) {
		return;
	}

	// ����Ǽ�������
	if (map[x][y].name == msgmove.name && direction != 0) {
		return;
	}

	// ��ʼ��
	if (direction == 0) {

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
	else {

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
				fly_dfs(x - 1, y, direction, type, flag);
			}
		}

		// ��
		if (direction == 2) {
			if (x + 1 <= 5) {
				fly_dfs(x + 1, y, direction, type, flag);
			}
		}

		// ��
		if (direction == 3) {
			if (y - 1 >= 0) {
				fly_dfs(x, y - 1, direction, type, flag);
			}
		}

		// ��
		if (direction == 4) {
			if (y + 1 <= 5) {
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
				else if (map[msg.x][msg.y].name != he)
				{
					//MessageBox(NULL, "������Ļغ�", "��ʾ", MB_OK);
					printf("\n������Ļغ�");

				}
					break;
	 	case 0:
			fly_dfs(msgmove.x, msgmove.y, 0, 0, 0); 
			if (msg.x - msgmove.x<2 && msg.y - msgmove.y<2 && msg.x - msgmove.x>-2 && msg.y - msgmove.y>-2)
			{
				if (map[msg.x][msg.y].name == 0)//�жϸ������Ƿ������ӻ���� || map[msg.x][msg.y].name != msgmove.name  �жϸõ��Ƿ�������,û���Ӿ���������
				{
					msgmove.n++;
					msgmove.nhb++;
					printf("\n����\n");
					map[msgmove.x][msgmove.y].name = 0;
					map[msg.x][msg.y].name = msgmove.name;
				}
				else {
					printf("\n���Ӳ����Ϲ���");
					//MessageBox(NULL, "���Ӳ����Ϲ���", "��ʾ", MB_OK);
					msgmove.n++;
				}
			}
			//else {
			//	chi = 0;
			//	fly_dfs(msgmove.x, msgmove.y, 0,0,0);
			//	//Grc(msgmove.x, msgmove.y,0);
			//	

			//}
			break;
	
	}
}



//����ƶ�����
void GameControl2()
{
	if (MouseHit())//����������Ϣ
	{
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