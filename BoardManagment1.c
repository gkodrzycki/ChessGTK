#include "Funkcje.h"

char BeginingFen[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 1";

Square *Board[8][8];
Square *Board2[8][8];
Attacked *WhereBoard[8][8];

void SetBoard()
{
    int i = 0, rank = 0, file = 0, temp;



    while(BeginingFen[i] != ' ')
    {
        temp = (int)BeginingFen[i] - 48;
        if(BeginingFen[i] == '/')
        {
            rank++;
            file = 0;
        }
        else
        {
            if(temp <= 8)
            {
                while(temp--)
                {
                    Square *P1 = malloc(sizeof(Square));
                    P1->Figure = '.';
                    P1->IsFree = true;
                    P1->IsFirst = true;
                    P1->Kolor = 'N';
                    Board[rank][file] = P1;
                    Board2[rank][file] = P1;

                    Attacked *P2 = malloc(sizeof(Attacked));
                    P2->byBlack = false;
                    P2->byWhite = false;
                    WhereBoard[rank][file] = P2;

                    file++;
                }
            }
            else
            {
                Square *P1 = malloc(sizeof(Square));
                P1->Figure = BeginingFen[i];
                P1->IsFree = false;
                P1->IsFirst = true;
                     if(rank == 0 || rank == 1)     P1->Kolor = 'B';
                else if(rank == 6 || rank == 7)     P1->Kolor = 'W';
                Board[rank][file] = P1;
                Board2[rank][file] = P1;

                Attacked *P2 = malloc(sizeof(Attacked));
                P2->byBlack = false;
                P2->byWhite = false;
                WhereBoard[rank][file] = P2;
            }
            file++;
        }
        i++;
    }
}
void CopyBoard2To1()
{
    for(int rank = 0; rank < 8; rank++)
    {
        for(int file = 0; file < 8; file++)
        {
            Board[rank][file]->Figure  = Board2[rank][file]->Figure;
            Board[rank][file]->IsFirst = Board2[rank][file]->IsFirst;
            Board[rank][file]->IsFree  = Board2[rank][file]->IsFree;
            Board[rank][file]->Kolor   = Board2[rank][file]->Kolor;
        }
    }
}
void CopyBoard1To2()
{
    for(int rank = 0; rank < 8; rank++)
    {
        for(int file = 0; file < 8; file++)
        {
            Board2[rank][file]->Figure  = Board[rank][file]->Figure;
            Board2[rank][file]->IsFirst = Board[rank][file]->IsFirst;
            Board2[rank][file]->IsFree  = Board[rank][file]->IsFree;
            Board2[rank][file]->Kolor   = Board[rank][file]->Kolor;
        }
    }
}
void ResetAttacked()
{
    for(int rank = 0; rank < 8; rank++)
    {
        for(int file = 0; file < 8; file++)
        {
            WhereBoard[rank][file]->byBlack = false;
            WhereBoard[rank][file]->byWhite = false;
        }
    }
}
void Ruch(int t_rank1, int t_file1, int t_rank2, int t_file2)
{
    	Square *P1 = malloc(sizeof(Square));
	P1->IsFree = false;
	P1->Figure = Board2[t_rank1][t_file1]->Figure;
	P1->IsFirst = false;
	P1->Kolor = Board2[t_rank1][t_file1]->Kolor;
	Board2[t_rank2][t_file2] = P1;

	Square *P2 = malloc(sizeof(Square));
	P2->IsFree = true;
	P2->Figure = '.';
	P2->IsFirst = false;
	P2->Kolor = 'N';
	Board2[t_rank1][t_file1] = P2;
}
bool CzyPuste(int rank1, int file1, int rank2, int file2)
{
     if(Board[rank2][file2]->IsFree)    return true;
     if(Board[rank1][file1]->Kolor != Board[rank2][file2]->Kolor && !Board[rank2][file2]->IsFree) return true;

	return false;
}
void Promocja(Extra poz, int CzyjRuch)
{
    int t_rank2 = poz.r, t_file2 = poz.f;
    Square *P1 = malloc(sizeof(Square));
	P1->IsFree = false;
	if(CzyjRuch%2 == 1)
    {
        if(poz.y == 3) P1->Figure = 'Q';
        if(poz.y == 2) P1->Figure = 'B';
        if(poz.y == 1) P1->Figure = 'N';
        if(poz.y == 0) P1->Figure = 'R';
    }
	else
    {
        if(poz.y == 3) P1->Figure = 'q';
        if(poz.y == 2) P1->Figure = 'b';
        if(poz.y == 1) P1->Figure = 'n';
        if(poz.y == 0) P1->Figure = 'r';
    }
	P1->IsFirst = false;
	P1->Kolor = Board2[t_rank2][t_file2]->Kolor;
	Board2[t_rank2][t_file2] = P1;

	CopyBoard2To1();
    TakeImage(t_rank2, t_file2);
	GiveImage(Board[t_rank2][t_file2]->Figure, t_file2, t_rank2);
}
