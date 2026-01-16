#include <stdio.h>
#include "bookLib.h"

bool searchCode(Book bookArr[], int SIZE, int code){
    for (int i = 0; i < SIZE; i++){
        if (bookArr[i].code == code){
            format(bookArr, i); 
            return true;
        }
    }
    return false;
}

void insertVal(Book bookArr[], int SIZE, int &n, int pos, int code){
    if (searchCode(bookArr, SIZE, code) || n - 1 >= SIZE) {printf("\n"); return;}

    for (int i = n - 1; i >= pos; i--){ 
        bookArr[i + 1] = bookArr[i]; 
    } 
    bookArr[pos].code = code;
    n++;
}

void delVal(Book bookArr[], int SIZE, int &n, int pos){
    
    for (int i = pos; i <= n - 1; i++){ 
        bookArr[i] = bookArr[i + 1]; 
    } 
    n--;
}

int main(){
    const int SIZE = 10;

    int n      = 4;
    int code   = 0;
    int pos    = 0;
    int choice = 0;

    Book bookArr[SIZE] = { {120, "a"},
                           {111, "b"},
                           {134, "c"},
                           {119, "d"}
    };
    
    while (true){
        printArr(bookArr, SIZE); 
        printf("\n\t===== OPTIONS =====\n\t1)SEARCH\n\t2)INSERT\n\t3)DELETE\n\t4)EXIT");
        scanf("%d", &choice);

        switch (choice){
            case 1: 
                printf("\nSEARCH CODE :");
                scanf("%d", &code);
                searchCode(bookArr, SIZE, code); 
                break;

            case 2:
                printf("\nINSERT IN POS: ");
                scanf("%d", &pos);
                printf("\nCREATE CODE: ");
                scanf("%d", &code);
                insertVal(bookArr, SIZE, n, pos, code);
                break;

            case 3:
                printf("\nSELECT A POS: ");
                scanf("%d", &pos);
                delVal(bookArr, SIZE, n, pos);
                break;

            case 4: return 0;
        }
    }
    printf("\n");
    return 0;
}
