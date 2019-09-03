#ifndef __Chess_H
#define __Chess_H
#define N 15


void InitGame(void);
void PlayChess();
void PrintChessBoard();
int Judge(int i, int j, int WhoseTurn);
void ClrBoard();
void BeginGame();
#endif __Chess_H
