#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROWS 11
#define COLS 11
#define COUNT 10
#define ROW 9
#define COL 9

//≥ı ºªØ
void Initboard(char arr[ROWS][COLS], int rows, int cols, int set);

void Displayboard(char arr[ROWS][COLS], int row, int col);
void Setmine(char arr[ROWS][COLS], int row, int col);

void Findmine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col);