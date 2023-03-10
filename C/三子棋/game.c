#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void playermove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:\n");
	while (1)
	{
		printf("����������: ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Board[x-1][y-1] == ' ')
			{
				Board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("��λ��ռ�ã�����������\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}

}

void Computermove(char Board[ROW][COL], int row, int col)
{
	printf("������:\n");
	while (1)
	{
		int x = rand()%row;
		int y = rand()%col;

		if (Board[x][y] == ' ')
		{
			Board[x][y] = '#';
			break;
		}
	}
}

//�ж���Ӯ
char Iswin(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	//��
	for (i = 0; i < row; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ')
		{
			return Board[i][0];
		}
	}
	//��
	for (i = 0; i < col; i++)
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ')
		{
			return Board[0][i];
		}
	}
	//�Խ���
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	 else if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}

	//ƽ��
	while (1)
	{
		for (i = 0; i < row; i++)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				if (Board[i][j] == ' ')
					return 0;                                      
			}

		}
		return 'p';
	}

	return 0;
}