#pragma once

#include "Game.h"
#include "View.h"

int* getEmptySpots(int* board);
void increase(int** arr, int count);
int getMove(int* board, int turn, int playerTurn, bool isMain);
int giveScore(int emptySlots, int playerTurn, int winner);
int copy_boards(int* boardToCopyFrom, int* boardToCopyInto);
