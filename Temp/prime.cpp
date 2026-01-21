#include <iostream>
#include <chrono>
#include <ratio>

void dullPrime(int num){
    int divs = 0;
    for (int j = 1; j <= num; j++){
        if (num % j == 0) divs++;
    }
    if (divs == 2) std::cout << "IS PRIME\n";
    else std::cout << "IS NOT PRIME\n";
}

bool isPrime(int num){
    auto start = std::chrono::high_resolution_clock::now();

    //if (num > 2 && num % 2 == 0) return false;

    bool state = true;
    for (int i = 2; i < ((num + 2) / 2); i++){
        state = (num % i == 0) ? false : true;
        if (state == false) return state;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "TIME: " << duration.count() << std::endl;

    return state;
}

int main(){
    int num = 283;
    int range = 1000000;

    for (int i = 2; i < range; i++){
        if (isPrime(i)) std::cout << i << ": IS PRIME\n";
    }
    return 0;
}
