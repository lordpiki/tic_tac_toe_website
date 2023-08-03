#include "View.h"

void print_board(int board[])
{

	printf("\n");
	printf(" %c | %c | %c \n", convert(board[0]), convert(board[1]), convert(board[2]));
	printf(" %c | %c | %c \n", convert(board[3]), convert(board[4]), convert(board[5]));
	printf(" %c | %c | %c \n", convert(board[6]), convert(board[7]), convert(board[8]));

}

char convert(int turn)
{
	return turn == X_TURN ? 'X' : turn == O_TURN ? 'O' : ' ';
}
