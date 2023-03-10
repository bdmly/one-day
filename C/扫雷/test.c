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
	//创建两个数组
	char arr1[ROWS][COLS];//后台
	char arr2[ROWS][COLS];

	//初始化棋盘
	Initboard(arr1, ROWS, COLS,'0');// 0
	Initboard(arr2, ROWS, COLS,'*');// *

	//打印为9*9
	Displayboard(arr2, ROW, COL);

	//布置雷
	Setmine(arr1, ROW, COL);
	Displayboard(arr1, ROW, COL);

	//排查雷
	Findmine(arr1,arr2,ROW,COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入选项：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏已退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}