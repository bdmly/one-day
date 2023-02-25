#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void Initboard(char arr[ROWS][COLS], int rows, int cols, int set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void Displayboard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("***********扫雷游戏*********\n");
	//显示标识行列数
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("***********扫雷游戏*********\n");
}

void Setmine(char arr[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}
int Get(char arr1[ROWS][COLS], int x, int y)
{
	return arr1[x - 1][y - 1] + arr1[x - 1][y] + arr1[x - 1][y + 1] +
		arr1[x][y - 1] + arr1[x][y + 1] +
		arr1[x + 1][y - 1] + arr1[x + 1][y] + arr1[x + 1][y + 1] - 8 * '0';
}
void Findmine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - COUNT)
	{
		printf("请输入坐标:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr1[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				break;
			}
			else
			{
				int get = Get(arr1, x, y);
				arr2[x][y] = get+'0';
				Displayboard(arr2, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("恭喜胜利\n");
	}
}