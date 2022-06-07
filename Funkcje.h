#ifndef Funkcje
#define Funkcje

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>


typedef struct
{
    char Figure;
    bool IsFree;
    bool IsFirst;
    char Kolor;

}Square;

typedef struct
{
    bool byWhite;
    bool byBlack;
}Attacked;

typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    int r;
    int f;
    int x;
    int y;
}Extra;


extern Square *Board[8][8];
extern Square *Board2[8][8];
extern Attacked *WhereBoard[8][8];
extern Position cords[8][8];
extern Position Choice;

//BoardManagment.c
extern void SetBoard();
extern void CopyBoard2To1();
extern void CopyBoard1To2();
extern void ResetAttacked();
extern void Ruch(int t_rank1, int t_file1, int t_rank2, int t_file2);
extern bool CzyPuste(int rank1, int file1, int rank2, int file2);
extern void Promocja(Extra poz, int CzyjRuch);

//FindAttacks.c
extern void FindRook(int rank, int file, char kol);
extern void FindKnight(int rank1, int file1, char kol);
extern void FindBishop(int rank, int file, char kol);
extern void FindKing(int rank, int file, char kol);
extern void FindAttacked();

//CheckMovement.c
extern bool CanPawn(int t_rank1, int t_file1, int t_rank2, int t_file2, int CzyjRuch, bool enPas, int enFile, int enRank);
extern bool CanRook(int rank1, int file1, int rank2, int file2, int CzyjRuch);
extern bool CanBishop(int rank1, int file1, int rank2, int file2, int CzyjRuch);
extern bool CanKnight(int rank1, int file1, int rank2, int file2, int CzyjRuch);
extern bool CanQueen(int rank1, int file1, int rank2, int file2, int CzyjRuch);
extern bool CanKing(int rank1, int file1, int rank2, int file2, int CzyjRuch, int wKR, int wKF, int bKR, int bKF);

//Castle.c
extern bool LongW();
extern bool ShortW();
extern bool LongB();
extern bool ShortB();
extern void MakeCastle(int x1, int x2, int x3, int x4, int y);
extern int DoShortW(int wKF);
extern int DoLongW(int wKF);
extern int DoShortB(int bKF);
extern int DoLongB(int bKF);

//CheckMate.c
extern bool CheckMate(char kto, int prevRank, int prevFile, int wKR, int wKF, int bKR, int bKF, int enRank, int enFile, int CzyjRuch, bool enPas);
extern bool IsCheck(char kto, int wKR, int wKF, int bKR, int bKF);

//GTK.c
extern char *getPiece(char piece);
extern void OknoPromocji(int CzyjRuch, int t_rank2, int t_file2);
extern void GiveImage(char piece, int x, int y);
extern void TakeImage(int x, int y);
extern void placePiece(Position from, Position to);
extern void Show_Communicate(char message[]);
extern void drawMoves(Position pos, char piece);
extern void ResetDraw();
extern void setCheck(int x, int y, bool czy);
extern void setSelected(int x, int y, bool czy);
extern void handleClick(Position pos);
extern void button_clicked(GtkWidget *widget, gpointer data);
extern void button_clicked1(GtkWidget *widget, gpointer data);
extern void MakeBoard();
extern void MakePieces();
extern void StartGame();
extern void myCSS(void);
extern void CreateNew();
#endif
