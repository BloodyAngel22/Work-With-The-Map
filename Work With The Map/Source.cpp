#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int width = 50, height = 32;
bool gameover;
int x, y, gold=0;
int xe, ye;
int counter = 0;
enum Movement { Stop = 0, UP, DOWN, LEFT, RIGHT };
Movement move;

void Setup() {
	gameover = false;
	move = Stop;
	x = width / 2 - 1, y = height / 2 - 1;
	xe = rand() % width, ye = rand() % height;
}

void Draw() {
		system("cls");

		for (int i = 0; i < width + 1; i++)
			printf("#");
		printf("\n");
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0 or j == width - 1)
					printf("#");
				if (i == y and j == x)
					printf("o");
				else if (i == ye and j == xe)
					printf("*");
				else
					printf(" ");
			}

			printf("\n");
		}

		for (int i = 0; i < width + 1; i++)
			printf("#");
		printf("\n"); printf("Gold: %d", gold);
}

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 72:
			move = UP;
			break;
		case 80:
			move = DOWN;
			break;
		case 75:
			move = LEFT;
			break;
		case 77:
			move = RIGHT;
			break;
		case 'q':
			move = Stop;
			break;
		case 'z':
			gameover = true;
		}
	}
}

void Logic() {
	switch (move)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}
	if (x > width - 2)
		x--;
	if (x < 0)
		x++;
	if (y < 0)
		y++;
	if (y > height-1)
		y--;
	if (x == xe and y == ye) {
		xe = rand() % width, ye = rand() % height;
		gold++;
	}
}

int main() {
	Setup();
	while (!gameover) {
		Input();
		Logic();
		Draw();
	}
}