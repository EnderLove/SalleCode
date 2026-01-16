#ifndef BOOK_LIB_H
#define BOOK_LIB_H

#include <string>

struct Book{
    int code;
    std::string name;
};

void format  (Book bookArr[], int i   );
void printArr(Book bookArr[], int size);

#endif // BOOK_LIB_H!
