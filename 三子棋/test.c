#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"game.h"

void menu() 
{
	printf("******************\n");
	printf("****  1.play  ****\n");
	printf("****  2.exit  ****\n");
	printf("******************\n");

}
void game()
{
	char Board[ROW][COL];
	
  	InitBoard(Board,ROW,COL);//��ʼ������

	DisplayBoard(Board, ROW, COL); //��ӡ����

	while (1)
	{
		//�����
		playermove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//�ж���Ӯ
		//*���Ӯ
		//#����Ӯ
		//p ƽ��
		//0 ����
		char rel=Iswin(Board, ROW, COL);
		if (rel == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		else if (rel == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (rel == 'p')
		{
			printf("ƽ��\n");
			break;
		}

		//������
		Computermove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//�ж���Ӯ
		 rel = Iswin(Board, ROW, COL);
		if (rel == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		else if (rel == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (rel == 'p')
		{
			printf("ƽ��\n");
			break;
		}
	}
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("������>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);

	return 0;
}