from flask import Flask, render_template, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/api/play', methods=['POST'])
def play_move():
    player_move = request.json['move']
    # Call the tic_tac_toe.exe program with the player's move as an argument
    # For example, assuming the compiled executable is in the same directory:
    # result = subprocess.run(['./tic_tac_toe.exe', player_move], capture_output=True, text=True)
    # You need to implement this subprocess call to communicate with the C program.
    # The `result.stdout` will contain the C program's response, which you can use to determine the bot's move and game status.
    # In this example, I'll assume that the C program returns JSON with the bot's move and game status.
    # Replace the following line with the actual subprocess call.
    result = {"bot_move": "A1", "game_status": "ongoing"}
    return jsonify(result)

if __name__ == '__main__':
    app.run(debug=True)
