from flask import Flask, render_template, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/api/play', methods=['POST'])
def play_move():
    current_board = request.json['board']
    turn = request.json['turn']
    print("current board: ", current_board)
    print("turn:", turn)

    # Format the current board as a space-separated string of numbers
    current_board_str = ' '.join(str(move) for move in current_board)
    print("send board", current_board_str)

    # Replace the path to the compiled tic_tac_toe.exe file with the actual path on your system
    # The subprocess call will execute the C program and pass the current board and player's move as arguments
    result = subprocess.run(['C:\\Users\\Miki\\Documents\\Computer Science\\GitHub\\tic_tac_toe_website\\Tic-Tac-Toe Bot\\Debug\\Tic-Tac-Toe Bot.exe', current_board_str, str(turn)], capture_output=True, text=True)
    print("res: ")
    print(result.stdout)
    print(result.stderr)
    if 0 not in current_board:
        print("herer")
        return render_template("base.html", board=current_board)
        # insert code here


    # Parse the C program's response to get the bot's move
    try:
        bot_move = parse_bot_move(result.returncode)
    except ValueError:
        # Handle the case where the C program returned an invalid response or an error occurred
        return jsonify({'error': 'An error occurred during the game.'}), 500

    response = {
        'bot_move': bot_move
    }

    return jsonify(response)

def parse_bot_move(stdout):
    # This function parses the C program's response to extract the bot's move
    # Replace this with your actual logic based on your C program's output format
    # For example, if the C program returns just the bot's move as a single number (0-8), you can simply return it.
    return int(stdout)

if __name__ == '__main__':
    app.run(debug=True)
