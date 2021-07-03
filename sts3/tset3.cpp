#include<iostream>
#include<graphics.h>	//ͼ�ο� ��Ҫ���ⰲװ
#include<mmsystem.h>//������ý��ӿ�ͷ�ļ�
#include<conio.h> //
#include<stdio.h>
#include<math.h>//��ѧͷ�ļ�
#include<string.h> 
#pragma comment(lib,"winmm.lib")

//��������
void movechess1(int x, int y, int angle, int flag);
void zouzi(int he);
void hihe();
void yidong(int x, int y, int endx, int endy);

int fraction;//�������
using namespace std;
MOUSEMSG msg;//�������洢����
int n = 1, name = 0;//n��������� ,name�洢�������ӵ���ɫ
int x = 0, y = 0;//�ƶ�����ʱ�ݴ�����꣨x,y��
#define ROW 6//��
#define COL 6//��
#define HIGH 700 //��
#define WIDTH 600 //��
#define QP_HIGH 50//���Ӹ�
#define QP_WIDTH 50//���ӿ�
#define QP_X1 130 //�������Ͻ�x����            
#define QP_X2 380 //�������Ͻ�y����
#define QP_Y1 130 //�������Ͻ�y����
#define QP_Y2 380 //�����ҽ�y����
#define PI 3.1415
//�ṹ�嶨��
struct  Chess//��������
{
	char name;//1���� 2���壬0��
	int x;
	int y;
	char type; //�������ڰ��廹�Ǻ���
	bool flag;//�Ƿ���˻���
}map[ROW][COL];


//* ��ʼ������
void  GameInit()
{
	//������ά����
	for (int i = 0; i < ROW; i++)
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

				if (i >= 4)
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




void draw()
{
	BeginBatchDraw();//˫�����ͼ��ֹ����������
	COLORREF color = WHITE;//���û�����ɫ
	setbkcolor(RGB(252, 215, 162));//���ñ�����ɫ 
	setlinecolor(BLACK);//������ɫ
	setlinestyle(PS_SOLID, 3);//����������ɫ����ϸ

	cleardevice();//����
	//���Ͻ�Բ
	circle(150, 150, 50);//��԰
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
	setfillcolor(RGB(252, 215, 162));
	//����Բ���
	solidrectangle(150, 150, 250, 250);
	//����Բ���
	solidrectangle(300, 150, 400, 250);
	//����Բ���
	solidrectangle(300, 300, 400, 400);
	//����Բ���
	solidrectangle(150, 300, 250, 400);

	setlinecolor(BLACK);//���û�����ɫ
	setlinestyle(PS_SOLID, 3);//���û��߿�� 3
	//���ƺ������������
	for (int i = 0; i < 6; i++)
	{
		line(150 + QP_HIGH * i, 150, 150 + QP_HIGH * i, 400);
		for (int j = 0; j < 6; j++)
		{
			line(150, 150 + QP_WIDTH * j, 400, 150 + QP_WIDTH * j);
		}
	}
//���ƶԻ���

	
	setlinestyle(PS_SOLID, 1);//����������ɫ����ϸ
	setfillcolor(WHITE);
	settextcolor(BLACK);
	fillrectangle(0, 550, 599, 699);
	line(0, 552,600,552);
	outtextxy(260,560,"��ʼ��Ϸ");//��ʾ




	//���⹦��
	//���������
	setbkmode(TRANSPARENT);//���ñ���͸��
	settextstyle(20, 0, "����");//��������
	char coin[20] = "";
	sprintf(coin, "������%d", fraction);//��������
	outtextxy(500, 50, coin);//��ʾ

	//������
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
	EndBatchDraw();//��ֹ����������

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
*  ��ʼ����ť
*
*********************************************************/
struct button* createButton(int x, int y, int width, int height, COLORREF color, char* pText)
{
	struct button* pB = (struct button*)malloc(sizeof(struct button));//��̬�ڴ�����
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
*����ť
*********************************************************************************/
void drawButton(struct button* pB)
{
	/*setfillcolor(pB->color);
	settextstyle(35,0,"����");
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
	int name = 0;//n��������� ,name�洢�������ӵ���ɫ
	int x = 0;
	int y = 0;//�ƶ�����ʱ�ݴ�����꣨x,y��
	int nhb = 1;

}msgmove;


//�غϺ���
void hihe()
{
	int ixd = 0;//��¼������־
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


//���Ӻ���  heֵΪ1ʱ���ӻغϣ�Ϊ2ʱ���ӻغ�
void zouzi(int he)
{
	int ixd;
	ixd = msgmove.n % 2;
	switch (ixd)
	{
	case 1:
		if (map[msg.x][msg.y].name == he)//�жϸ������Ƿ�������  ���ӱ���������
		{
			msgmove.n++;
			printf("����");
			msgmove.x = msg.x;
			msgmove.y = msg.y;
			msgmove.name = map[msgmove.x][msgmove.y].name;
			//	tishi();
		}
		else if (map[msg.x][msg.y].name != he)
		{
			MessageBox(NULL, "������Ļغ�", "��ʾ", MB_OK);

		}
		break;
	case 0:
		if (msg.x - msgmove.x<2 && msg.y - msgmove.y<2 && msg.x - msgmove.x>-2 && msg.y - msgmove.y>-2)
		{
			if (map[msg.x][msg.y].name == 0 || map[msg.x][msg.y].name != msgmove.name)//�жϸ������Ƿ������ӻ����
			{
				msgmove.n++;
				msgmove.nhb++;
				printf("����");
				yidong(msgmove.x, msgmove.y, msg.x, msg.y);
				map[msgmove.x][msgmove.y].name = 0;
				map[msg.x][msg.y].name = msgmove.name;
			}
		}
		else MessageBox(NULL, "���Ӳ����Ϲ���", "��ʾ", MB_OK);
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












/************************************************ 
*---Բ���ƶ� 
*---int(x,y)Բ��
*---dauble angle ��Ҫ�ƶ��ĽǶ�
*---int speed �˶��ٶ����1��10֮�䣬5������
*************************************************/
void movechess(int x,int y,double angle,int speed)
{ 
	chess.x = x;
	chess.y = y;
	chess.angle = angle;
	speed = 10 * speed;
	//��ʼ������
	setbkcolor(BLACK);
	settextcolor(YELLOW);
	setlinecolor(YELLOW);

		circle(150, 150, 50);//��԰
	
		BeginBatchDraw();//˫�����ͼ
		while (angle)
		{
			chess.angle++;
			cleardevice();
			Sleep(speed);
			//	circle(150, 150, 50);//��԰
			chess.endx = chess.x + (int)(sin(PI / 180 * chess.angle) * 50);
			chess.endy = chess.y + (int)(cos(PI / 180 * chess.angle) * 50);
			fillcircle(chess.endx, chess.endy, 10);
		}
		
		EndBatchDraw();//��ֹ����������
	
}
	
/****************************************************************************
��������ʵ���ϣ����£��ң����ϣ����£����ϣ����µ��ƶ�����������������ʵ���ƶ�����
*���Ժ�Բ���Ĵ�������һ�𣬵����ܻ����Ӹ����������ٶȡ�
*
*��ǰλ��x,y
*Ŀ��λ��endx,endy
*�ٶ�
******************************************************************************/

void startgame()
{
	MessageBox(NULL, "�뿪ʼ��Ϸ", "��ʾ",MB_OK);
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
	if (flagx < 0 && flagy == 0)//�������ƶ�
	{
		flag = 0;
		//flagx = ~flagx;
		flagx += 2 * flagx;

	}else if(flagx > 0 && flagy == 0)//�������ƶ�
	{
		flag = 1;
	}
	else  if (flagx == 0 && flagy > 0)//�������ƶ�
	{
		flag = 2;
	}
	else if (flagx == 0 && flagy < 0)//����
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
	BeginBatchDraw();//˫�����ͼ

	if (chess.endx<chess.x)
	{	
		chess.flag--;
	}
	chess.endx = chess.x + chess.flag;
	Sleep(100);
	//cleardevice();
	fillcircle(chess.endx, chess.y, 20);

	EndBatchDraw();//��ֹ����������
}



/************************************************
*---�ռ��޼�Բ���ƶ�����
*---int(x,y)Բ��
*---dauble angle ��Ҫ�ƶ��ĽǶ�
*---int speed �˶��ٶ����1��10֮�䣬5������
*---flag ��־ 1����˳ʱ����  2������ʱ����     ���Խ�ֱ���ƶ���ֲ��������switch����
*************************************************/
void movechess1(int x,int y,int angle,int flag)
{

	//��ʼ������
	setbkcolor(BLACK);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	
	chess.x = x;
	chess.y = y;

	cleardevice();
	BeginBatchDraw();//˫�����ͼ
	 switch (flag)
	{
	 case 1:
		 	if(chess.angle <= angle)
                {
				chess.angle++;
                
			}
			// circle(150, 150, 50);//��԰
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
				//circle(150, 150, 50);//��԰
		
		

				chess.endx = chess.x + (int)(sin(PI / 180 * chess.angle) * 50);
				chess.endy = chess.y + (int)(cos(PI / 180 * chess.angle) * 50);
				fillcircle(chess.endx, chess.endy, 20);
			
				break;
		default:
			break;
	}
	
	 EndBatchDraw();//��ֹ����������
}
int main()
{
	
	initgraph(WIDTH, HIGH, SHOWCONSOLE);//�½�����
	GameInit();
//	circle(400, 150, 50);//��԰
	//movechess(150, 150, 270, 5);
	//struct button* pB = createButton(300,200,200,50,YELLOW,"��ʼ");
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