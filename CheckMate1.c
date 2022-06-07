#include "Funkcje.h"

bool CheckMate(char kto, int prevRank, int prevFile, int wKR, int wKF, int bKR, int bKF, int enRank, int enFile, int CzyjRuch, bool enPas)
{
    ResetAttacked();
    if(kto == 'B')
    {
        for(int rank = 0; rank < 8; rank++)
        {
            for(int file = 0; file < 8; file++)
            {

                    if(Board[rank][file]->Figure == 'P')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanPawn(rank, file, i, j, CzyjRuch, enPas, enFile, enRank))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'R')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanRook(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'N')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanKnight(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'B')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanBishop(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'Q')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanQueen(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'K')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanKing(rank, file, i, j, CzyjRuch, wKR, wKF, bKR, bKF))
                                {
                                    int trank, tfile;
                                    Ruch(rank, file, i, j);
                                    if(CzyjRuch%2 == 1)
                                    {
                                        trank = wKR;
                                        tfile = wKF;
                                        wKR = i;
                                        wKF = j;
                                    }
                                    else
                                    {
                                        trank = bKR;
                                        tfile = bKF;
                                        bKR = i;
                                        bKF = j;
                                    }
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    if(CzyjRuch%2 == 1)
                                    {
                                        wKR = trank;
                                        wKF = tfile;
                                    }
                                    else
                                    {
                                        bKR = trank;
                                        bKF = tfile;
                                    }
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }

                }
            }

    }
    else if(kto == 'W')
    {
        for(int rank = 0; rank < 8; rank++)
        {
            for(int file = 0; file < 8; file++)
            {

                    if(Board[rank][file]->Figure == 'p')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanPawn(rank, file, i, j, CzyjRuch, enPas, enFile, enRank))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'r')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanRook(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'n')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanKnight(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'b')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanBishop(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'q')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanQueen(rank, file, i, j, CzyjRuch))
                                {
                                    Ruch(rank, file, i, j);
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }
                    if(Board[rank][file]->Figure == 'k')
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            for(int j = 0; j < 8; j++)
                            {
                                if(CanKing(rank, file, i, j, CzyjRuch, wKR, wKF, bKR, bKF))
                                {
                                    int trank, tfile;
                                    Ruch(rank, file, i, j);
                                    if(CzyjRuch%2 == 1)
                                    {
                                        trank = wKR;
                                        tfile = wKF;
                                        wKR = i;
                                        wKF = j;
                                    }
                                    else
                                    {
                                        trank = bKR;
                                        tfile = bKF;
                                        bKR = i;
                                        bKF = j;
                                    }
                                    FindAttacked();
                                    if((!IsCheck(kto, wKR, wKF, bKR, bKF))) return false;
                                    if(CzyjRuch%2 == 1)
                                    {
                                        wKR = trank;
                                        wKF = tfile;
                                    }
                                    else
                                    {
                                        bKR = trank;
                                        bKF = tfile;
                                    }
                                    ResetAttacked();
                                    CopyBoard1To2();
                                }
                            }
                        }
                    }

                }
            }
		 }
return true;
}
bool IsCheck(char kto, int wKR, int wKF, int bKR, int bKF)
{
    if(kto == 'B')
        if(WhereBoard[wKR][wKF]->byBlack) return true;
    if(kto == 'W')
        if(WhereBoard[bKR][bKF]->byWhite) return true;
    return false;
}
