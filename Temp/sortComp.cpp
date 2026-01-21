#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>

void showArr(int arr[], int SIZE){
    for (int i = 0; i < SIZE; i++){ std::cout << arr[i] << ", "; }
}

void sortAlgorithm(int arr[], int SIZE){
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(arr, arr + SIZE);
    //showArr(arr, SIZE);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start; 
    std::cout << "\nTIME: " << duration.count() << std::endl;
}

void mySort(int arr[], int SIZE){
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            
            if (arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    } 
    //showArr(arr, SIZE);

    auto end = std::chrono::high_resolution_clock::now();
    auto dif = end - start;
    std::chrono::duration<double, std::milli> duration = end - start; 
    std::cout << "\nTIME: " << duration.count() << std::endl;
}

int main(){
    srand((unsigned int)time(NULL));
    const int SIZE = 10000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++){ arr[i] = rand() % SIZE; }

    sortAlgorithm(arr, SIZE);

    mySort(arr, SIZE);
    
    return 0;
}
