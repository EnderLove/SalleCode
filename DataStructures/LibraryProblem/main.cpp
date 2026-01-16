#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "bookLib.h"

void insertBook(Book arrBooks[], int size, int &upperBound, int code, int pos){
    if(upperBound == size)return;


}

bool validCode(Book arrBooks[], int size, int code){
    for (int i = 0; i < size; i++){
        if (arrBooks[i].getCode() == code){
            return false;
        }
    }  
    return true;
}

void searchCode(Book arrBooks[], int size, int code){
    for (int i = 0; i < size; i++){
        if (arrBooks[i].getCode() == code){
            std::cout << "\n\tPOS: " << i << " || ";
            arrBooks[i].showBookVals();
            std::cout << "\n";
        }
    }   
}

int main(){
    
    const int SIZE_ARR = 10;

    Book arrBooks[SIZE_ARR];
    
    int upperBound = SIZE_ARR;
    int userChoice = 0;
    int code       = 0;
    int pos        = 0;
    
    for (int i = 0; i < SIZE_ARR; i++){
        code = (rand() % 101) + 100;
        arrBooks[i].setCode(code);
    }

    while (userChoice != 3){

        int i = 0;
        for (auto it : arrBooks){
            std::cout << "\tPOS: " << i << " || ";
            it.showBookVals();
            i++;
        }

        std::cout << "\n\tSELECT AN OPTION:\n\t1)SEARCH CODE\n\t2)INSERT BOOK\n\t3)DELETE BOOK";    
        std::cin >> userChoice;
        
        switch (userChoice)
        {
            case 1: 
                std::cout << "\n\tINSERT A CODE: ";
                std::cin >> code;
                searchCode(arrBooks, SIZE_ARR, code);
                break;
            
            case 2:
                std::cout << "\n\tSELECT A POSITION: ";
                do { std::cin >> pos; } while (pos <= 0 || pos >= SIZE_ARR);
                std::cout << "\n\tCREATE A CODE: ";
                do { std::cin >> code;} while (!validCode(arrBooks, SIZE_ARR, code));
                insertBook(arrBooks, SIZE_ARR, upperBound, code, pos);
        }
        
        //system("clear");
    }

    return 0;
}
