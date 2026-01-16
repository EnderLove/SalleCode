#include <iostream>
#include <cstdlib> //C Standard Library {srand(), rand()}
#include <ctime>   //time()

const int SYMBOLS_SIZE = 5;
const int ROW = 4;
const int COL = 4;

const char symbols[SYMBOLS_SIZE] = {'A', 'B', 'C', '7', '*'};

void genRandomMatrix(char matrix[ROW][COL], int ROW, int COL){
    for (int i = 0; i < ROW; i++){
        std::cout << "| ";
        for (int j = 0; j < COL; j++){
            matrix[i][j] = symbols[rand() % SYMBOLS_SIZE];
            std::cout << matrix[i][j] << " | ";
        }
        std::cout << "\n";
    }
}

int main(){
    srand((unsigned int)time(NULL));
    
    int uInput = 1;

    char matrix[ROW][COL];
   
    while (uInput){
        std::cout << "REGEN MACHINE: ";
        std::cin >> uInput;
        system("clear");
        genRandomMatrix(matrix, ROW, COL);
        
        int diagCount = 0;
        int rowCount = 0;
        int colCount = 0;

        char temp = matrix[0][0];

        for (int i = 0; i < ROW; i++){
            
            char temp = matrix[0][0];

            for (int j = 0; j < COL; j++){
                
                if (matrix[i][j] == temp) rowCount++;
                else temp = matrix[i][j];
    
            }
            std::cout << "rowCount: " << rowCount << std::endl;
            rowCount = 1;
        }
    }

    return 0;
}
