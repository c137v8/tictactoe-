#include<iostream>
#include<climits>
using namespace std;

//1 is representation for x and 2 is representation for o
//- represents unfilled space in the board 
int tic_board[3][3]{{0,0,0},{0,0,0},{0,0,0}};

int checkBoard(int board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        // Check row i
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            return board[i][0]; // Return the winner (1 or 2)
        }
        // Check column i
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            return board[0][i]; // Return the winner (1 or 2)
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        return board[0][0]; // Return the winner (1 or 2)
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return board[0][2]; // Return the winner (1 or 2)
    }
    
    // Check for empty spaces ( For incompleate game )
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return -1; // Return -1 if there's still an empty space
            }
        }
    }

    // Return 0 if game is draw
    return 0;
}

void print_board(int board[3][3]) 
{
    cout << " 0 1 2 ";
     for (int i = 0; i < 3; i++) {
        cout << endl;
        cout << i;
        
        for (int j = 0; j < 3; j++)
        {
            
           if (board[i][j] == 1 ) cout <<  "x ";
           if (board[i][j] == 2 ) cout <<  "o ";
           if (board[i][j] == 0 ) cout <<  "- "; 
        }
      
        
     }
       cout<< endl;
}
bool is_move_valid(int board[3][3], int row, int col) {
    return board[row][col] == 0;    
}
void add_move(int board[3][3], int player, int row, int col) {
    if (is_move_valid(board, row, col)) {
        board[row][col] = player;
    }
}





int minimax(int depth , int board[3][3], int ismax)
{
    int score = checkBoard(board);
       if (score != -1) {
        return score;
    }

   if (ismax) {
        int best = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1;  
                    best = max(best, minimax(depth +1 , board, false));
                    board[i][j] = 0;  
                }
            }
        }
        return best;
    }
    else {
        int best = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 2;  
                    best = min(best, minimax(depth + 1 , board, true));
                    board[i][j] = 0;  
                }
            }
        }
        return best;
    }
}


int main()
{

}
