#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<time.h>
#include"game.h"
#include<easyx.h>
#include<Windows.h>
#define GAI 58
int EASY_COUNT = 5;
IMAGE img_ohno;
IMAGE img_cool;
IMAGE img_num[20];
IMAGE img_leinum[20];
IMAGE img_leinum1[20];
IMAGE img_gai;
IMAGE img_lei;
IMAGE img_redlei;
IMAGE img_qi;
IMAGE img_kj1;
IMAGE img_start;
IMAGE img_quit;
int count_qi = EASY_COUNT;
int count_two = EASY_COUNT / 10;
int count_one = EASY_COUNT % 10;
char mine[ROWS][COLS];
char show[ROWS][COLS];
char show_qi[ROWS][COLS];
int leicount = EASY_COUNT;
int win = ROW * COL - leicount;


void menu()
{
    leicount = EASY_COUNT;
	count_qi = EASY_COUNT;
    win = ROW * COL - leicount;
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	initgraph(545, 610,EX_NOCLOSE);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(&img_kj1, "assets/kj1.png");
	loadimage(&img_start, "assets/start.png");
	loadimage(&img_quit, "assets/quit.png");
	putimage(0, 0, &img_kj1);
	putimage((545 - 345) / 2, (610 - 100) / 2 - 100 + 40, &img_start);
	putimage((545 - 345) / 2, (610 - 100) / 2 + 25 + 40, &img_quit);
	spreadmouse();
	getchar();

}
void game()
{
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '0');
	InitBoard(show_qi, ROWS, COLS, '0');
	SetMine(mine, ROW, COL);
	IMAGE img_kj;
	IMAGE img_smile;
	count_qi = EASY_COUNT;
	cleardevice();
	loadimage(&img_cool, "assets/cool.png", 45, 45);
	loadimage(&img_lei, "assets/lei.png", GAI, GAI);
	loadimage(&img_ohno, "assets/ohno.png", 45, 45);
	loadimage(&img_redlei, "assets/redlei.png", GAI, GAI, true);
	loadimage(&img_qi, "assets/qi.png", GAI, GAI);
	loadimage(&img_kj, "assets/kj.png");
	loadimage(&img_smile, "assets/smile.png",45,45);
	loadimage(&img_gai, "assets/gai.png",GAI,GAI);
	loadimage(&img_num[0], "assets/0.png");
	loadimage(&img_num[1], "assets/1.png");
	loadimage(&img_num[2], "assets/2.png");
	loadimage(&img_num[3], "assets/3.png");
	loadimage(&img_num[4], "assets/4.png");
	loadimage(&img_num[5], "assets/5.png");
	loadimage(&img_num[6], "assets/6.png");
	loadimage(&img_num[7], "assets/7.png");
	loadimage(&img_num[8], "assets/8.png");
	loadimage(&img_leinum1[0], "assets/lei(0)1.png");
	loadimage(&img_leinum1[1], "assets/lei(1)1.png");
	loadimage(&img_leinum1[2], "assets/lei(2)1.png");
	loadimage(&img_leinum1[3], "assets/lei(3)1.png");
	loadimage(&img_leinum1[4], "assets/lei(4)1.png");
	loadimage(&img_leinum1[5], "assets/lei(5)1.png");
	loadimage(&img_leinum1[6], "assets/lei(6)1.png");
	loadimage(&img_leinum1[7], "assets/lei(7)1.png");
	loadimage(&img_leinum1[8], "assets/lei(8)1.png");
	loadimage(&img_leinum1[9], "assets/lei(9)1.png");
	putimage(0, 0, &img_kj);
	count_two = count_qi / 10;
	count_one = count_qi % 10;
	putimage(13, 13, &img_leinum1[count_two]);
	putimage(13 + 13, 13, &img_leinum1[count_one]);
	putimage((545 - 60) / 2, 13, &img_smile);
	//putq(mine, ROW, COL);
	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			putimage(14+j*GAI, 74+i*GAI, &img_gai);
		}
	}
	mouse(mine);

	
	getchar();
}



void spreadmouse()
{
	ExMessage msg = { 0 };
	int i = 0;
	while (i == 0)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			int x = msg.x;
			int y = msg.y;
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (x >= (545 - 345) / 2 && x <= (545 - 345) / 2 + 345)
				{
					if (y >= (610 - 100) / 2 - 100 + 40 && y <= (610 - 100) / 2 - 100 + 40 + 100)
					{
						selects();
					}
					else if (y >= (610 - 100) / 2 + 25 + 40 && y <= (610 - 100) / 2 + 25 + 40 + 100)
					{
						exit(0);
					}
				}
			}
		}
	}
}

//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}


//设置地雷
void  SetMine(char board[ROWS][COLS], int row, int col)
{
	srand((unsigned int)time(NULL));
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

////布置棋盘
//void putq(char mine[ROWS][COLS], int row, int col)
//{
//	IMAGE img_empty;
//	IMAGE img_lei;
//	int i = 0;
//	int j = 0;
//	for (j = 1;j <= row;j++)
//	{
//		for (i = 1;i <= col;i++)
//		{
//			if (mine[i][j] =='0')
//			{
//				loadimage(&img_empty, "assets/empty.png",GAI,GAI);
//				putimage(12 + (i-1) * GAI, 74 +(j-1) * GAI, &img_empty);
//			}
//			else if (mine[i][j] == '1')
//			{
//				loadimage(&img_lei, "assets/lei.png",GAI,GAI);
//				putimage(12 + (i - 1) * GAI, 74 + (j - 1) * GAI, &img_lei);
//			}
//		}
//	}
//}

//void mouse(char mine[ROWS][COLS])
//{
//		ExMessage msg = { 0 };
//		while (true)
//		{
//			if (peekmessage(&msg, EX_MOUSE))
//			{
//				int x = msg.x;
//				int y = msg.y;
//				char path[100] = { 0 };
//				if (x >= 13 && x <= 533 && y >= 73 && y <= 599)
//				{
//					switch (msg.message)
//					{
//					case WM_LBUTTONDOWN:
//						int i = (x - 12) / GAI + 1;
//						int j = (y - 74) / GAI + 1;
//						if (mine[i][j] == '1'&&show[i][j]=='0')
//						{
//							show[i][j] = '1';
//							loadimage(&img_lei, "assets/lei.png", GAI, GAI, true);
//							loadimage(&img_redlei, "assets/redlei.png", GAI, GAI, true);
//							putimage(12 + (i - 1) * GAI, 74 + (j - 1) * GAI, &img_redlei);
//							loadimage(&img_ohno, "assets/ohno.png",45,45);
//							putimage((545 - 60) / 2, 13, &img_ohno);
//							for (int i = 0;i < ROW;i++)
//							{
//								for (int j = 0;j < COL;j++)
//								{
//									if (mine[i][j] == '1')
//									{
//										putimage(14 + j * GAI, 74 + i * GAI, &img_lei);
//									}
//									
//								}
//							}
//							Sleep(2000);
//							menu();
//						}
//						else if (mine[i][j] == '0'&& show[i][j]=='0')
//						{
//							show[i][j] = '1';
//							loadimage(&img_num[0], "assets/0.png", GAI, GAI, true);
//							int count = GetMineCount(mine,i,j);
//							putimage(12 + (i - 1) * GAI, 74 + (j - 1) * GAI,&img_num[count]);
//							ls(i, j,mine, show);
//						}
//						if (win == 0)
//						{
//							loadimage(&img_cool, "assets/cool.png",45,45);
//							putimage((545 - 60) / 2, 13, &img_cool);
//							Sleep(1145);
//							menu();
//						}
//					}
//					
//				}
//				
//			}
//		}
//		
//			
//}



int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int cnt = 0;
	if (mine[x - 1][y - 1] == '1') cnt++;
	if (mine[x - 1][y] == '1') cnt++;
	if (mine[x - 1][y + 1] == '1') cnt++;
	if (mine[x][y - 1] == '1') cnt++;
	if (mine[x][y + 1] == '1') cnt++;
	if (mine[x + 1][y - 1] == '1') cnt++;
	if (mine[x + 1][y] == '1') cnt++;
	if (mine[x + 1][y + 1] == '1') cnt++;
	return cnt;
}


//
//void ls(int i, int j, char mine[ROWS][COLS], char show[ROWS][COLS])
//{
//	if (i < 1 || i > ROW || j < 1 || j > COL )
//	{
//		return;
//	}
//	else if (show[i][j] == '1')
//	{
//		return;
//	}
//	if (mine[i][j] == '1')
//	{
//		return;
//	}
//	show[i][j] = '1';
//	int count = GetMineCount(mine, i, j);
//	putimage(12 + (i - 1) * GAI, 74 + (j - 1) * GAI, &img_num[count]);
//	win--;
//	if (count == 0)
//	{
//		ls(i - 1, j - 1, mine, show);
//		ls(i - 1, j,     mine, show);
//		ls(i - 1, j + 1, mine, show);
//		ls(i,     j - 1, mine, show);
//		ls(i,     j + 1, mine, show);
//		ls(i + 1, j - 1, mine, show);
//		ls(i + 1, j,     mine, show);
//		ls(i + 1, j + 1, mine, show);
//	}
//}

void mouse(char mine[ROWS][COLS])
{
	ExMessage msg = { 0 };
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			int x = msg.x;
			int y = msg.y;
			if (x >= 13 && x <= 533 && y >= 73 && y <= 599)
			{
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
				{
					int col = (x - 12) / GAI + 1;
					int row = (y - 74) / GAI + 1;
			    if (show[row][col] == '0' && show_qi[row][col] == '1')
			{
				show_qi[row][col] = '0';
				putimage(12 + (col - 1) * GAI, 74 + (row - 1) * GAI, &img_gai);
				count_qi++;
				count_two = count_qi / 10;
				count_one = count_qi % 10;
				putimage(13, 13, &img_leinum1[count_two]);
				putimage(13 + 13, 13, &img_leinum1[count_one]);
			}
					else if (mine[row][col] == '1' && show[row][col] == '0')
					{
						show[row][col] = '1';
						putimage(12 + (col - 1) * GAI, 74 + (row - 1) * GAI, &img_redlei);
						putimage((545 - 60) / 2, 13, &img_ohno);
						for (int r = 0; r <= ROW; r++)
						{
							for (int c = 0; c <= COL; c++)
							{
								if (r == row && c == col)
								{
								}
								else if (mine[r][c] == '1')
								{
									putimage(14 + (c - 1) * GAI, 74 + (r - 1) * GAI, &img_lei);
								}
							}
						}
						Sleep(2000);
						menu();
					}
					else if (mine[row][col] == '0' && show[row][col] == '0')
					{
						ls(row, col, mine, show);
					}
					if (win == 0)
					{
						putimage((545 - 60) / 2, 13, &img_cool);
						Sleep(1145);
						menu();
					}
				}
					break;
				case WM_RBUTTONDOWN:
				{
					int col1 = (x - 12) / GAI + 1;
					int row1 = (y - 74) / GAI + 1;
					if (show[row1][col1] == '0'&&show_qi[row1][col1] == '0'&&count_qi>0)
					{
						show_qi[row1][col1] = '1';
						putimage(12 + (col1 - 1) * GAI, 74 + (row1 - 1) * GAI, &img_qi);
						count_qi--;
						count_two = count_qi / 10;
						count_one = count_qi % 10;
						putimage(13, 13, &img_leinum1[count_two]);
						putimage(13 + 13, 13, &img_leinum1[count_one]);
					}
					else if (show[row1][col1] == '0' && show_qi[row1][col1] == '1')
					{
						show_qi[row1][col1] = '0';
						putimage(12 + (col1 - 1) * GAI, 74 + (row1 - 1) * GAI, &img_gai);
						count_qi++;
						count_two = count_qi / 10;
						count_one = count_qi % 10;
						putimage(13, 13, &img_leinum1[count_two]);
						putimage(13 + 13, 13, &img_leinum1[count_one]);
					}
				}
					break;
				}
			}
		}
	}
}

void ls(int row, int col, char mine[ROWS][COLS], char show[ROWS][COLS])
{
	if (row < 1 || row > ROW || col < 1 || col > COL)
	{
		return;
	}
	if (show[row][col] != '0')
	{
		return;
	}
	int count = GetMineCount(mine, row, col);

	show[row][col] = '1';
	putimage(12 + (col - 1) * GAI, 74 + (row - 1) * GAI, &img_num[count]);
	win--;
	if (show_qi[row][col] == '1')
	{
		show_qi[row][col] = '0';
		count_qi++;
		count_two = count_qi / 10;
		count_one = count_qi % 10;
		putimage(13, 13, &img_leinum1[count_two]);
		putimage(13 + 13, 13, &img_leinum1[count_one]);
	}
	if (count == 0)
	{
		ls(row - 1, col - 1, mine, show);
		ls(row - 1, col, mine, show);
		ls(row - 1, col + 1, mine, show);
		ls(row, col - 1, mine, show);
		ls(row, col + 1, mine, show);
		ls(row + 1, col - 1, mine, show);
		ls(row + 1, col, mine, show);
		ls(row + 1, col + 1, mine, show);
	}
}


void selects()
{
	cleardevice();
	loadimage(&img_leinum[0], "assets/lei(0).png", 60, 60);
	loadimage(&img_leinum[1], "assets/lei(1).png", 60, 60);
	loadimage(&img_leinum[2], "assets/lei(2).png", 60, 60);
	loadimage(&img_leinum[3], "assets/lei(3).png", 60, 60);
	loadimage(&img_leinum[4], "assets/lei(4).png", 60, 60);
	loadimage(&img_leinum[5], "assets/lei(5).png", 60, 60);
	loadimage(&img_leinum[6], "assets/lei(6).png", 60, 60);
	loadimage(&img_leinum[7], "assets/lei(7).png", 60, 60);
	loadimage(&img_leinum[8], "assets/lei(8).png", 60, 60);
	loadimage(&img_leinum[9], "assets/lei(9).png", 60, 60);
	putimage(0, 0, &img_kj1);
	settextstyle(48, 0, "微软雅黑");
	settextcolor(BLACK);
	outtextxy((545 - 60) / 2 - 30, (610 - 60) / 2 - 100, "count\n");
	putimage((545 - 60) / 2 - 30, (610 - 60) / 2 - 100 + 40 - 40, &img_leinum[0]);
	putimage((545 - 60) / 2 + 30, (610 - 60) / 2 - 100 + 40 - 40, &img_leinum[5]);
	putimage((545 - 60) / 2 - 30, (610 - 60) / 2 - 100 + 100, &img_leinum[1]);
	putimage((545 - 60) / 2 + 30, (610 - 60) / 2 - 100 + 100, &img_leinum[0]);
	putimage((545 - 60) / 2 - 30, (610 - 60) / 2 - 100 + 160 + 40, &img_leinum[2]);
	putimage((545 - 60) / 2 + 30, (610 - 60) / 2 - 100 + 160 + 40, &img_leinum[0]);
	ExMessage msg = { 0 };
	int i = 0;
	while (i == 0)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			int i = msg.x;
			int j = msg.y;
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if (i >= (545 - 60) / 2 - 30 && i <= (545 - 60) / 2 + 30 + 60 && j >= (610 - 60) / 2 - 100 + 40 - 40 && j <= (610 - 60) / 2 - 100 + 40 - 40 + 60)
				{
					EASY_COUNT = 5;
					game();
				}
				else if (i >= (545 - 60) / 2 - 30 && i <= (545 - 60) / 2 + 30 + 60 && j >= (610 - 60) / 2 - 100 + 100 && j <= (610 - 60) / 2 - 100 + 100 + 60)
				{
					EASY_COUNT = 10;
					game();
				}
				else if (i >= (545 - 60) / 2 - 30 && i <= (545 - 60) / 2 + 30 + 60 && j >= (610 - 60) / 2 - 100 + 160 + 40 && j <= (610 - 60) / 2 - 100 + 160 + 60)
				{
					EASY_COUNT = 20;
					game();
				}
				break;
			}
			}


		}
	}
}