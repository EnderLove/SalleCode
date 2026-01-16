#include <iostream>
#include "tictactoe.h"

TicTacToe::TicTacToe(){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            board[i][j] = EMPTY;
        }
    }
}

TicTacToe::~TicTacToe(){}

void TicTacToe::printBoard() const {
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            std::cout << board[i][j] << " "; 
        }
        std::cout << "\n";
    }
}

bool TicTacToe::gameOver() const {
    bool state = false;

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (board[i][j] == EMPTY) state = true;
        }
    }
    return state;
}

void TicTacToe::setBoardPosChar(int rowPos, int colPos, int Player){
    if (Player == 0) board[rowPos][colPos] = 'X';
    else board[rowPos][colPos] = 'O';
}

bool TicTacToe::validPos(int rowPos, int colPos) const {
    if (board[rowPos][colPos] != EMPTY) return false;
    else return true;
}
