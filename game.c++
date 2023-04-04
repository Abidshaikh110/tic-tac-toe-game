#include <iostream>
#include <vector>

using namespace std;

// Prints the game board to the console
void print_board(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Checks if the game is over and returns the winning player ('X' or 'O') or a tie ('T')
char check_win(const vector<char>& board) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != '-' && board[i] == board[i+1] && board[i] == board[i+2]) {
            return board[i];
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] != '-' && board[i] == board[i+3] && board[i] == board[i+6]) {
            return board[i];
        }
    }
    // Check diagonals
    if (board[0] != '-' && board[0] == board[4] && board[0] == board[8]) {
        return board[0];
    }
    if (board[2] != '-' && board[2] == board[4] && board[2] == board[6]) {
        return board[2];
    }
    // Check for tie
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '-') {
            return ' ';
        }
    }
    return 'T';
}

// Plays a turn by prompting the player for their move and updating the game board
void play_turn(vector<char>& board, char player) {
    int move;
    do {
        cout << "Player " << player << ", enter a number between 1 and 9 to make your move: ";
        cin >> move;
        move--;  // Convert to 0-based index
    } while (move < 0 || move > 8 || board[move] != '-');
    board[move] = player;
}

int main() {
    vector<char> board(9, '-');  // Initialize board to all empty spaces
    char player = 'X';
    char winner = ' ';
    while (winner == ' ') {
        print_board(board);
        play_turn(board, player);
        winner = check_win(board);
        if (winner == ' ') {
            // Switch to other player
            player = (player == 'X' ? 'O' : 'X');
        }
    }
    print_board(board);
    if (winner == 'T') {
        cout << "It's a tie!" << endl;
    } else {
        cout << "Player " << winner << " wins!" << endl;
    }
    return 0;
}
