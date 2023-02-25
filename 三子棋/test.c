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
	
  	InitBoard(Board,ROW,COL);//初始化棋盘

	DisplayBoard(Board, ROW, COL); //打印棋盘

	while (1)
	{
		//玩家走
		playermove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//判断输赢
		//*玩家赢
		//#电脑赢
		//p 平局
		//0 继续
		char rel=Iswin(Board, ROW, COL);
		if (rel == '*')
		{
			printf("玩家赢\n");
			break;
		}
		else if (rel == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (rel == 'p')
		{
			printf("平局\n");
			break;
		}

		//电脑走
		Computermove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//判断输赢
		 rel = Iswin(Board, ROW, COL);
		if (rel == '*')
		{
			printf("玩家赢\n");
			break;
		}
		else if (rel == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (rel == 'p')
		{
			printf("平局\n");
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
		printf("请输入>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);

	return 0;
}