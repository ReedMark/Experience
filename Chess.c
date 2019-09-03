#include <stdio.h>
#include <stdlib.h>
#include "Chess.h"

int ChessBoard[N + 1][N + 1] = { 0 };
int WhoseTurn = 0;

void PrintChessBoard()
{
	int i, j;
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			if (i == 0)
				printf("%3d", j);
			else if (j == 0)
				printf("%3d", i);
			else if (1 == ChessBoard[i][j])
				printf(" ●");
			else if (2 == ChessBoard[i][j])
				printf(" ○");
			else
				printf("  *");
		}
	}
}
void InitGame(void)
{
	char c;
	printf("欢迎您，按Y进入游戏\n");
	c = getchar();
	if ('y' != c && 'Y' != c)
		exit(0);

	system("cls");

	PrintChessBoard();
}
void ClrBoard()
{
	int i, j;
	for(i=0;i<=N;i++)
		for (j = 0; j <= N; j++)
		{
			ChessBoard[i][j] = 0;
		}

}
int Judge(int x, int y, int WhoseTurn)
{
	int i, j;
	int t = 2 - WhoseTurn % 2;
	for (i = x - 4, j = y; i <= x; i++)
	{
		if (i >= 1 && i <= N - 4 && t == ChessBoard[i][j] && t == ChessBoard[i + 1][j] && t == ChessBoard[i + 2][j] && t == ChessBoard[i + 3][j] && t == ChessBoard[i + 4][j])
			return 1;
	}
	for (i = x, j = y - 4; j <= y; j++)
	{
		if (j >= 1 && j <= N - 4 && t == ChessBoard[i][j] && t == ChessBoard[i][j + 1] && t == ChessBoard[i][j + 2] && t == ChessBoard[i][j + 3] && t == ChessBoard[i][j + 4])
			return 1;
	}
	for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
	{
		if (i >= 1 && j >= 1 && i <= N - 4 && j <= N - 4 && t == ChessBoard[i][j] && t == ChessBoard[i + 1][j + 1] && t == ChessBoard[i + 2][j + 2] && t == ChessBoard[i + 3][j + 3] && t == ChessBoard[i + 4][j + 4])
			return 1;
	}
	for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
	{
		if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == ChessBoard[i][j] && t == ChessBoard[i - 1][j + 1] && t == ChessBoard[i - 2][j + 2] && t == ChessBoard[i - 3][j + 3] && t == ChessBoard[i - 4][j + 4])
			return 1;
	}
	return 0;
}

void PlayChess(void)
{
	int i, j, winner;
	char Choice;

	if (1 == WhoseTurn % 2)
	{
		printf("玩家1，请输入棋子位置，格式为行号+空格+列号");
		scanf_s("%d %d", &i, &j);
		while (ChessBoard[i][j] != 0)
		{
			printf("位置已经被占用，请重新输入");
			scanf_s("%d %d", &i, &j);
		}
		ChessBoard[i][j] = 1;
	}
	else
	{
		printf("玩家2，请输入棋子位置，格式为行号+空格+列号");
		scanf_s("%d %d", &i, &j);
		while (ChessBoard[i][j] != 0)
		{
			printf("位置已经被占用，请重新输入");
			scanf_s("%d %d", &i, &j);
		}
		ChessBoard[i][j] = 2;
	}
	system("cls");
	PrintChessBoard();
	if (Judge(i, j, WhoseTurn))
	{
	
		if (1 == WhoseTurn % 2)
		{
			printf("玩家1获胜\n 按任意键退出");
			scanf_s("%d", &Choice);
				exit(0);

		}
		else
		{
			printf("玩家2获胜\n 按任意键退出");
			scanf_s("%d", &Choice);
				exit(0);

		}
	}
}
void BeginGame()
{
	while (1)
	{
		WhoseTurn++;
		PlayChess();
	}
}
int main(void)
{
	InitGame();
	BeginGame();
	
}