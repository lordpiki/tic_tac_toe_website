#include "Minimax.h"

int* getEmptySpots(int* board)
{
	int i = 0, count = 1;
	int* emptySpots = (int*)malloc(sizeof(int*) * count);
	emptySpots[0] = 0;
	
	for (i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		if (board[i] == 0)
		{
			emptySpots[0]++;
			increase(&emptySpots, count + 1);
			emptySpots[count] = i;
			count++;
		}
	}
	if (count == 1)
	{
		return NULL;
	}

	return emptySpots + 1;
}


void increase(int** arr, int count)
{
	*arr = (int*)realloc(*arr, sizeof(int) * count);
}


int getMove(int* board, int turn, int playerTurn, bool isMain)
{
	int chosenScore = 999, tempScore = 0, bestMove = 0, winner = 0, i = 0, j = 0;
	int tempBoard[9] = { 0 };
	int* emptySpots = getEmptySpots(board);
	if (!(emptySpots))
	{
		return 0;
	}
	int emptySpotsAmount = emptySpots[-1];
	bestMove = emptySpots[0];
	

	for (i = 0; i < emptySpotsAmount; i++)
	{
		copy_boards(board, tempBoard);
		tempBoard[emptySpots[i]] = turn;

		winner = checkForWin(tempBoard);
		if (winner == NO_WIN)
		{
			tempScore = getMove(tempBoard, switchTurns(turn), playerTurn, false);
			if (chosenScore == 999)
			{
				chosenScore = tempScore;
			}
			else if (turn == playerTurn)
			{
				if (tempScore > chosenScore)
				{

					bestMove = emptySpots[i];
					chosenScore = tempScore;
				}
			}
			else
			{
				if (tempScore < chosenScore)
				{

					bestMove = emptySpots[i];
					chosenScore = tempScore;
				}
			}
		}
		else
		{
			bestMove = emptySpots[i];
			free(emptySpots - 1);
			if (isMain)
			{
				return bestMove;
			}
			return giveScore(emptySpotsAmount, playerTurn, winner);
		}
	}
	if (isMain)
	{
		free(emptySpots - 1);
		return bestMove;
	}
	return chosenScore;
}

int giveScore(int emptySlots, int playerTurn, int winner)
{
	if (winner == playerTurn)
	{
		return emptySlots;
	}
	else if (winner == switchTurns(playerTurn))
	{
		return -(emptySlots);
	}
	return 0;
}

int copy_boards(int* boardToCopyFrom, int* boardToCopyInto)
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		boardToCopyInto[i] = boardToCopyFrom[i];
	}
	return 0;
}

