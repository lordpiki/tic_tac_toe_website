const boardCells = document.querySelectorAll('.cell');
const currentBoard = Array(9).fill(0); // Initialize the board state with -1 (empty cells)

function resetBoard() {
    // Get all the cells by their id


    // Clear the content of each cell and remove the 'occupied' class
    boardCells.forEach(cell => {
        cell.textContent = '';
        cell.classList.remove('occupied');

    });

    currentBoard.fill(0);
}


document.addEventListener('DOMContentLoaded', function() {

    let turn = 1;

    boardCells.forEach((cell, index) => {
        cell.addEventListener('click', function() {
            if (!cell.classList.contains('occupied')) {
                const move = index;

                if (turn === 1)
                {
                    currentBoard[move] = 1; // Update the board state for player's move
                    cell.textContent = 'X';
                }
                else
                {
                    return;
                    currentBoard[move] = 2; // Update the board state for player's move
                    cell.textContent = 'O';
                    turn = 1;
                    return;
                }
                const player_turn = turn;

                cell.classList.add('occupied');

                // Make an AJAX POST request to the Flask server to play the player's move
                fetch('/api/play', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json'
                    },
                    body: JSON.stringify({ turn: player_turn, board: currentBoard })
                })
                .then(response => {
                    if (!response.ok) {
                        throw new Error('Network response was not ok');
                    }
                    return response.json();
                })
                .then(data => {
                    // Process the response from the Flask server
                    const botMove = data.bot_move;
                    currentBoard[botMove] = 2; // Update the board state for bot's move

                    const botCell = boardCells[botMove];
                    botCell.textContent = 'O';
                    botCell.classList.add('occupied');

                    // You can add more conditions to handle other game states as needed.
                })
                .catch(error => console.error('Error:', error));
            }
        });
    });
});
