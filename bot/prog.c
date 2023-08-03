#include "PCH.h"

int main(void)
{
	int board[BOARD_SIZE*BOARD_SIZE] = { 0 };
	int turn = X_TURN, pos = 0, winner = 0, playerTurn = 0;
	do
	{
		if (turn == X_TURN)
		{
			print_board(board);
			printf("Best move is for %c is %d\n", convert(turn), getMove(board, turn, turn, true) + 1); // suggestion for user

			pos = checkPos(board);

			pos--; // making pos - 1 to match board
		}
		else
		{
			pos = getMove(board, turn, turn, true); // getting bot move
			printf("\nO is choosing %d\n", pos + 1);
		}

		board[pos] = turn; // making move
		turn = switchTurns(turn); // switching turns

		winner = checkForWin(board); // getting winner

	} while (winner == NO_WIN); // checking if game ended

	print_board(board);
	if (winner == TIE)
	{
		printf("TIE!");
	}
	else
	{
		printf("%c won!", convert(checkForWin(board)));
	}
	printf("\n\nPress any key to exit.");

	getchar();
	return 0;
}