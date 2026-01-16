#include "bookLib.h"

void format(Book bookArr[], int i){
    printf("\n\tPOS: %2d || CODE: %3d || NAME: %s", i, bookArr[i].code, bookArr[i].name.c_str());
}

void printArr(Book bookArr[], int size){
    for (int i = 0; i < size; i++) format(bookArr, i);
}
