
/*��Ҫ��ͷ�ļ�
*/
#include<iostream>
#include<graphics.h>	//ͼ�ο� ��Ҫ���ⰲװ
#include<mmsystem.h>//������ý��ӿ�ͷ�ļ�
#include<conio.h> //
#include<math.h>//��ѧͷ�ļ�


/*��Ҫ�ĺ궨��
*/
using namespace std;
MOUSEMSG msg;//�������洢����


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
//���̴ӣ�150��150����400��150����150��400����400��400��
IMAGE bk, cat, img;	//׼��ͼƬ

//�ṹ�嶨��
struct  Chess//��������
{
	char name;//1���� 2���壬0��
	int x;
	int y;
	char type; //�������ڰ��廹�Ǻ���
	bool flag;//�Ƿ���˻���
}map[ROW][COL];
struct chess //Բ��������
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
	int name = 0;//n��������� ,name�洢�������ӵ���ɫ
	int x = 0;
	int y = 0;//�ƶ�����ʱ�ݴ�����꣨x,y��
	int nhb=1;
	
}msgmove;

//��������
void show();
void zouzi(int he);

int Bnumber;//�������
int Wnumber;//�������
