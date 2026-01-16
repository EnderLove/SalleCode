#include <iostream>
#include "tictactoe.h"
    
enum Player    {PLAYER1, PLAYER2};
enum GameState {TWO_PLAYER = 1, MACHINE, EXIT};

int twoPlayerGame(TicTacToe *game, int rowPos, int colPos){
    std::cout << CLEAR;
    while (game->gameOver()){
        game->printBoard();
    
        do {
            std::cout << "PLAYER 1 TURN!\nROW: ";
            std::cin >> rowPos;
            std::cout << "COL: ";
            std::cin >> colPos;
        }while (!game->validPos(rowPos, colPos) && game->gameOver());

        game->setBoardPosChar(rowPos, colPos, PLAYER1);
        std::cout << CURSOR_BACK; 
        game->printBoard();
        
        do {
            std::cout << "PLAYER 2 TURN!\nROW: ";
            std::cin >> rowPos;
            std::cout << "COL: ";
            std::cin >> colPos;
        }while (!game->validPos(rowPos, colPos) && game->gameOver());
        
        game->setBoardPosChar(rowPos, colPos, PLAYER2);

        std::cout << CURSOR_BACK; 
    }
    return 0;
}

int machineGame(TicTacToe *game, int rowPos, int colPos){
    std::cout << CLEAR;
    while (game->gameOver()){
        game->printBoard();
    
        do {
            std::cout << "PLAYER 1 TURN!\nROW: ";
            std::cin >> rowPos;
            std::cout << "COL: ";
            std::cin >> colPos;
        }while (!game->validPos(rowPos, colPos) && game->gameOver());

        game->setBoardPosChar(rowPos, colPos, PLAYER1);
        std::cout << CURSOR_BACK; 
        game->printBoard();
        
        do {
            std::cout << "PLAYER 2 TURN!\nROW: ";
            std::cin >> rowPos;
            std::cout << "COL: ";
            std::cin >> colPos;
        }while (!game->validPos(rowPos, colPos) && game->gameOver());
        
        game->setBoardPosChar(rowPos, colPos, PLAYER2);

        std::cout << CURSOR_BACK; 
    }
    return 0;
}

int main(){
    TicTacToe *game = new(TicTacToe);
    
    int rowPos = 0;
    int colPos = 0;
    int userChoice = 0;

    std::cout << "WELCOME TO TIC TAC TOE" << std::endl;
    std::cout << "1)TWO PLAYERS\n2)AGAINST MACHINE\n3)EXIT\n";
    std::cin >> userChoice;
    
    while (userChoice != EXIT){
        if (userChoice == TWO_PLAYER) twoPlayerGame(game, rowPos, colPos);
    }

    delete(game);
    return 0;
}
