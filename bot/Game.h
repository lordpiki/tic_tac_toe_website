#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "Minimax.h"

#define X_TURN 1
#define O_TURN -1

#define TIE 0
#define NO_WIN 2
#define WIN 3

#define BOARD_SIZE 3

int checkForWin(int board[]);
bool checkWinForPlayer(int board[], int turn);
int switchTurns(int turn);
int checkPos(int board[]);
