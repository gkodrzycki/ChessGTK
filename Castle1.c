#include "Funkcje.h"


bool ShortW()
{
    FindAttacked();
    if(Board[7][4]->IsFirst && Board[7][7]->IsFirst && !WhereBoard[7][4]->byBlack && !WhereBoard[7][5]->byBlack && !WhereBoard[7][6]->byBlack && Board[7][5]->IsFree && Board[7][6]->IsFree)
    {
        ResetAttacked();
        return true;
    }
    ResetAttacked();
    return false;
}

bool ShortB()
{
    FindAttacked();
    if(Board[0][4]->IsFirst && Board[0][7]->IsFirst && !WhereBoard[0][4]->byWhite && !WhereBoard[0][5]->byWhite && !WhereBoard[0][6]->byWhite && Board[0][5]->IsFree && Board[0][6]->IsFree)
    {
        ResetAttacked();
        return true;
    }
    ResetAttacked();
    return false;
}

bool LongB()
{
    FindAttacked();
    if(Board[0][4]->IsFirst && Board[7][0]->IsFirst && !WhereBoard[0][4]->byWhite && !WhereBoard[0][3]->byWhite && !WhereBoard[0][2]->byWhite && Board[0][3]->IsFree && Board[0][2]->IsFree && Board[0][1]->IsFree)
    {
        ResetAttacked();
        return true;
    }
    ResetAttacked();
    return false;
}

bool LongW()
{
    FindAttacked();
    if(Board[7][4]->IsFirst && Board[0][0]->IsFirst && !WhereBoard[7][4]->byBlack && !WhereBoard[7][3]->byBlack && !WhereBoard[7][2]->byBlack && Board[7][3]->IsFree && Board[7][2]->IsFree && Board[7][1]->IsFree)
    {
        ResetAttacked();
        return true;
    }
    ResetAttacked();
    return false;
}



void MakeCastle(int x1, int x2, int x3, int x4, int y)
{
    Square *P1 = malloc(sizeof(Square));
    P1->IsFree = false;
    P1->Figure = Board2[y][x1]->Figure;
    P1->IsFirst = false;
    P1->Kolor = Board2[y][x1]->Kolor;
    Board2[y][x3] = P1;

    TakeImage(x3, y);
    GiveImage(Board[y][x1]->Figure, x3, y);
    TakeImage(x1,y);

    Square *P2 = malloc(sizeof(Square));
    P2->IsFree = true;
    P2->Figure = '.';
    P2->IsFirst = false;
    P2->Kolor = 'N';
    Board2[y][x1] = P2;

    CopyBoard2To1();

    Square *P3 = malloc(sizeof(Square));
    P3->IsFree = false;
    P3->Figure = Board2[y][x4]->Figure;
    P3->IsFirst = false;
    P3->Kolor = Board2[y][x4]->Kolor;
    Board2[y][x2] = P3;


    TakeImage(x2, y);
    GiveImage(Board[y][x4]->Figure, x2, y);
    TakeImage(x4,y);

    Square *P4 = malloc(sizeof(Square));
    P4->IsFree = true;
    P4->Figure = '.';
    P4->IsFirst = false;
    P4->Kolor = 'N';
    Board2[y][x4] = P4;
    CopyBoard2To1();
}
int DoShortW(int wKF)
{
    wKF = 6;
    MakeCastle(4, 5, 6, 7, 7);

    return wKF;
}
int DoLongW(int wKF)
{
    wKF = 2;
    MakeCastle(4, 3, 2, 0, 7);

    return wKF;
}
int DoShortB(int bKF)
{
    bKF = 6;
    MakeCastle(4, 5, 6, 7, 0);

    return bKF;
}
int DoLongB(int bKF)
{
    bKF = 2;
    MakeCastle(4, 3, 2, 0, 0);

    return bKF;
}
