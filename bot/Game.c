#include "Game.h"


int checkForWin(int board[])
{
	if (checkWinForPlayer(board, X_TURN))
	{
		return X_TURN;
	}
	else if (checkWinForPlayer(board, O_TURN))
	{
		return O_TURN;
	}
	else if (!getEmptySpots(board))
	{
		return TIE;
	}
	return NO_WIN;
}


bool checkWinForPlayer(int board[], int turn)
{
	int i = 0, j = 0, count = 0;
	int possible_wins[][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 4, 8}, {2, 4, 6}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8} };
	for (i = 0; i < 8; i++)
	{
		count = 0;
		for (j = 0; j < WIN; j++)
		{
			if (board[possible_wins[i][j]] == turn)
			{
				count++;
			}
		}
		if (count == WIN)
		{
			return true;
		}
	}
	return false;
}


int switchTurns(int turn)
{
	turn = turn == X_TURN ? O_TURN : X_TURN;
}

int checkPos(int board[])
{
	int pos = 0;
	bool isValid = false;
	printf("\nPlease enter your turn (1-9)\n");
	do
	{
		scanf("%d", &pos); // getting position of user
		getchar();

		isValid = !(pos < 0 || pos > 9) && board[pos - 1] == 0;
		if (!isValid)
		{
			printf("Please enter a valid spot!\n");
		}
	} while (!isValid);
	
	return pos;
}
