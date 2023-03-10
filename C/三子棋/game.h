#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void InitBoard(char Board[ROW][COL], int row, int col);

void DisplayBoard(char Board[ROW][COL], int row, int col);

void playermove(char Board[ROW][COL], int row, int col);

void Computermove(char Board[ROW][COL], int row, int col);

char Iswin(char Board[ROW][COL], int row, int col);