

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "util.h"

//보석찾기 사전정의
#define MAP_HEIGHT	10
#define MAP_WIDTH	10

#define ROAD		0
#define WALL		1
#define GEM			2

#define LEFT		75
#define RIGHT		77
#define UP			72
#define DOWN		80
#define ESC			27

//함수로 분리

int map[MAP_HEIGHT][MAP_WIDTH] = {
		{0,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,2,0,1,1,0,1},
		{1,1,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};

int _select;
int playerX = 0;
int playerY = 0;

void KeyProcess() {
	if (_kbhit())
	{
		_select = _getch();
		if (_select == 224)
		{
			_select = _getch();
		}
	}
}



void GameProcess() {
	switch (_select)
	{
	case LEFT:
		if (playerX - 1 >= 0)
		{
			if (map[playerY][playerX - 1] == ROAD)
			{
				playerX--;
			}
			else if (map[playerY][playerX - 1] == GEM)
			{
				printf("\nCLEAR!\n");
				playerX = 0;
				playerY = 0;
			}
		}
		_select = 0;
		break;
	case RIGHT:
		if (playerX + 1 < MAP_WIDTH)
		{
			if (map[playerY][playerX + 1] == ROAD)
			{
				playerX++;
			}
			else if (map[playerY][playerX + 1] == GEM)
			{
				printf("CLEAR!\n");
				playerX = 0;
				playerY = 0;
			}
		}
		_select = 0;
		break;
	case UP:
		if (playerY - 1 >= 0)
		{
			if (map[playerY - 1][playerX] == ROAD)
			{
				playerY--;
			}
			else if (map[playerY - 1][playerX] == GEM)
			{
				printf("CLEAR!\n");
				playerX = 0;
				playerY = 0;
			}
		}
		_select = 0;
		break;
	case DOWN:
		if (playerY + 1 < MAP_HEIGHT)
		{
			if (map[playerY + 1][playerX] == ROAD)
			{
				playerY++;
			}
			else if (map[playerY + 1][playerX] == GEM)
			{
				printf("CLEAR!\n");
				playerX = 0;
				playerY = 0;
			}
		}
		_select = 0;
		break;
	default:
		if (_select != LEFT && _select != RIGHT && _select != UP && _select != DOWN) {
			printf("\n잘못입력하였습니다.");
		}
		_select = 0;
		break;
	}
}


void DrawGame() {
	setcursortype(NOCURSOR);
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			gotoxy(x, y);
			if (map[y][x] == ROAD)
			{
				if (playerX == x && playerY == y)
				{
					printf("§");
				}
				else
				{
					printf("□");
				}
			}
			else if (map[y][x] == WALL)
			{
				printf("■");
			}
			else if (map[y][x] == GEM)
			{
				printf("★");
			}
		}
		//printf("\n");
	}
}




int main()
{
	//보석찾기게임
	

	
	

	while (true)
	{
		
		KeyProcess();
		GameProcess();
		DrawGame();
		
	}
}

