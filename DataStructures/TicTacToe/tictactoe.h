#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define CLEAR       "\033[H\033[2J"
#define CURSOR_BACK "\033[H"

class TicTacToe
{
private:
    static constexpr char EMPTY = ' '; // I used constexpr to evaluate at compile time
    static constexpr int  ROW   = 3;
    static constexpr int  COL   = 3;

    char board[ROW][COL];
    
public:
    TicTacToe(); // Generates and empty board
    ~TicTacToe();

    void printBoard() const; // Shows the board
    bool gameOver()   const; // Verifies if someone win

    bool validPos(int rowPos, int colPos) const; // Verifies if selected pos is available

    void setBoardPosChar(int rowPos, int colPos, int Player); // Sets the 'X' 'O' in the board 

};

#endif // TIC_TAC_TOE_H!
