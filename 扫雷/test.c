#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("****** 1.play *******\n");
	printf("****** 0.exit *******\n");
	printf("*********************\n");

}

void game()
{
	//������������
	char arr1[ROWS][COLS];//��̨
	char arr2[ROWS][COLS];

	//��ʼ������
	Initboard(arr1, ROWS, COLS,'0');// 0
	Initboard(arr2, ROWS, COLS,'*');// *

	//��ӡΪ9*9
	Displayboard(arr2, ROW, COL);

	//������
	Setmine(arr1, ROW, COL);
	Displayboard(arr1, ROW, COL);

	//�Ų���
	Findmine(arr1,arr2,ROW,COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������ѡ�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ���˳�\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
	return 0;
}