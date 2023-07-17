// JavaScript code for handling game interactions and AJAX requests
document.addEventListener('DOMContentLoaded', function() {
    const boardCells = document.querySelectorAll('.cell');
    boardCells.forEach(cell => cell.addEventListener('click', makeMove));
});

function makeMove(event) {
    const cell = event.target;
    if (!cell.classList.contains('occupied')) {
        const move = cell.dataset.position;
        // Make an AJAX POST request to the Flask server to play the player's move
        fetch('/api/play', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ move: move })
        })
        .then(response => response.json())
        .then(data => {
            // Process the response from the Flask server
            const botMove = data.bot_move;
            const gameStatus = data.game_status;

            // Update the board based on the server's response
            if (botMove) {
                const botCell = document.querySelector(`[data-position='${botMove}']`);
                botCell.textContent = 'O';
                botCell.classList.add('occupied');
            }

            // Check the game status and update the UI accordingly
            if (gameStatus === 'player_win') {
                // Handle player win
            } else if (gameStatus === 'bot_win') {
                // Handle bot win
            } else if (gameStatus === 'draw') {
                // Handle draw
            }

            // You can add more conditions to handle other game states as needed.
        })
        .catch(error => console.error('Error:', error));
    }
}
