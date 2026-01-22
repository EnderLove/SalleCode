#include <ctime>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

const u_int ARR_SIZE = 1e+5;
const int RANGE = ARR_SIZE;

clock_t start, end;

void showArr(u_int arr[]){
    for (u_int i = 0; i < ARR_SIZE; i++) { std::cout << arr[i] << ", "; }
}


// 1e+5 (time: 12.0648s)
void showDull(u_int arr[]){  
    for (int i = 0; i < ARR_SIZE; i++){
        for (int j = i + 1; j < ARR_SIZE - 1; j++){
           if (arr[i] == arr[j]) std::cout << arr[i] << ","; 
        }
    }
}


// 1e+5 (time: 0.0836...s)
void showOptim(u_int arr[]){  
    std::unordered_map<int, int> count;
    for (int i = 0; i < ARR_SIZE; i++){ count[arr[i]]++; }

    for (const auto &it : count){
        if (it.second > 1) { std::cout << it.first << ","; } 
    }
}

// 1e+5 (time: 0.12234...s)
void showHyper(u_int arr[]){
    std::unordered_map<int, int> count;
    for (int i = 0; i < ARR_SIZE; i++){ 
        if (count.find(arr[i]) != count.end()){
            continue;
        }else {
            count[arr[i]]; 
        }
    }

    for (const auto &it : count){
        std::cout << it.first << ",";
    }
}

// 1e+5 (time: 0.083234...s)
void showSort(u_int arr[]){
    std::sort(arr, arr + ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++){
        if (arr[i] == arr[i + 1]) { std::cout << arr[i] << ","; }
    }
}

int main(){
    srand((unsigned int)time(NULL));

    u_int *arr = new u_int[ARR_SIZE];

    start = clock();

    for (u_int i = 0; i < ARR_SIZE; i++) { arr[i] = rand() % RANGE; }

    //showDull(arr); 
    showOptim(arr);
    //showHyper(arr);
    //showSort(arr);

    end = clock();

    double deltaTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "\nTime: " << deltaTime << "s\n"; 
    std::cout << "\n";

    delete [] arr;
    return 0;
}
