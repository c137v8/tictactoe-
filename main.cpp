#include<iostream>
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
    cout << " 0 1 2 3";
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
}





int minimax(int depth , bool ismax, int board[3][3])
{
    
}



//int main(int argc, char *argv[])
int main() 
{
	print_board(tic_board);
}