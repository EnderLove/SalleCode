#include <ctime>
#include <iostream>
#include <cstdlib>

const u_int ARR_SIZE = 100000000;
const int RANGE = 3;

clock_t start, end;

void showArr(u_int arr[]){
    for (u_int i = 0; i < ARR_SIZE; i++) { std::cout << arr[i] << ", "; }
}

int main(){
    srand((unsigned int)time(NULL));

    u_int *arr = new u_int[ARR_SIZE];

    start = clock();

    for (u_int i = 0; i < ARR_SIZE; i++) { arr[i] = rand() % RANGE; }

    //showArr(arr);
    
    end = clock();

    double deltaTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "\nTime: " << deltaTime << "s\n"; 
    std::cout << "\n";

    delete [] arr;
    return 0;
}
