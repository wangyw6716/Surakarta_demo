#include<iostream>
#include<graphics.h>	//ͼ�ο� ��Ҫ���ⰲװ
#include<mmsystem.h>//������ý��ӿ�ͷ�ļ�
#include<conio.h> //
#pragma comment(lib,"winmm.lib")
#define HIGH 600 //��
#define WIDTH 600 //��
int date[6][6] = {
	2, 2, 2, 2, 2, 2,//2Ϊ
	2, 2, 2, 2, 2, 2,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1

};
//�������ϣ���������
void setwindowstyle()
{
	system("title �տ�������");
	system("color f0");//������ɫ
	system("mode con cols=40 lines=8");//���ô��ڴ�С
}
struct gameRole
{
	int pattern;//ģʽ1or2//������1��ʾ����2��ʾ����
	int colour;//1��ʾ�߰��壬2��ʾ�ߺ���
	bool huihe;//�غ�1Ϊ��ң�0Ϊ����
}role;
struct Blackchess
{
	int number;//��������

}Bchess;
struct Whitechess
{
	int number;//��������
}Wchess;
//����ṹ��
struct Chess
{
	int x;//�����ߵ����ӵ�����x
	int y;//�����ߵ����ӵ�����y
	int c;//��Ҫ�ߵ����ӵ��������x
	int d;//��Ҫ�ߵ����ӵ��������y
}Go;
//������Ϣ����ʼ����
void inputinformation()
{
	setwindowstyle();
	printf("  * ��ʼ��Ϸ *\n");
	printf("����1ѡ����壬����2ѡ�����\n");
	scanf("%d", &role.colour);
	if (role.colour == 1)
	{
		printf("��ѡ���˰��壺\n");
	}
	else if (role.colour == 2)
	{
		printf("��ѡ���˺��壺\n");
	}
	printf(" ���� 1 ��������\n");
	printf(" ���� 2 ��������\n");
	scanf("%d", &role.colour);
	if (role.colour == 1)
	{
		printf("���������壺\n");
	}
	else if (role.colour == 2)
	{
		printf("��������壺\n");
	}
	else printf("������ѡ��\n");
	
	
	
	
	
	

	
	
}

//���̿���
int keyboard()
{
	int ch;
	while (1)
	{

		ch = _getch();//��ȡ����

		
			switch (ch)
			{
				//��
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
//������
int main()
{
	inputinformation();
	
	while (1)
	{
		
	}
}
