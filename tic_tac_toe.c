#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the move is valid
int isValidMove(const int board[9], int move) {
printf("move is %d", move);
    return move >= 0 && move < 9 && board[move] == -1; // -1 indicates an empty cell
}

// Function to check if the game is over
int isGameOver(const int board[9]) {
    // Implement your logic to check for a win or draw condition
    // Return 1 if the game is over, 0 otherwise
}

// Function to make the bot's move
int makeBotMove(const int board[9]) {
    // Implement your logic to determine the bot's move
    // For demonstration purposes, you can make a random move in this example
    int move;
    do {
        move = rand() % 9;
    } while (!isValidMove(board, move));
    return move;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [current_board] [player_move]\n", argv[0]);
        return 1;
    }

    int board[9]; // 0-8 represent the cells, -1 indicates an empty cell
    const char* board_str = argv[1];

    printf("argc: %d\n", argc);
    printf("%s\n", argv[1]);
    for (int i = 0; i < argc; i++)
    {
        printf(" %s", argv[i]);
    }

    printf("\nboard: \n");
    for (int i = 0; i < 9; i++)
    {
        board[i] = argv[1][i * 2] - '0';
        printf(" %d %d\n", board[i], argv[1][i * 2]);
    }



    return 0;
}
