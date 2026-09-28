#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<time.h>
#include<easyx.h>
#include<Windows.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2


//
//char show[ROWS][COLS];


void spreadmouse();

//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//设置地雷
void  SetMine(char board[ROWS][COLS], int row, int col);

//布置棋盘
void putq(char mine[ROWS][COLS], int row, int col);


void mouse(char mine[ROWS][COLS]);

int GetMineCount(char mine[ROWS][COLS], int x, int y);

void game();

void ls(int i, int j, char mine[ROWS][COLS], char show[ROWS][COLS]);

void menu();

void selects();


