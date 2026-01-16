#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

const int N = 4; 
const int SYMBOLS_SIZE = 5;
const char SYMBOLS[SYMBOLS_SIZE] = {'A', 'B', 'C', '7', '*'};

std::unordered_map<char, int> sessionStats;

void genRandomMatrix(char matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        std::cout << "| ";
        for (int j = 0; j < N; j++) {
            matrix[i][j] = SYMBOLS[rand() % SYMBOLS_SIZE];
            std::cout << matrix[i][j] << " | ";
            sessionStats[matrix[i][j]]++; 
        }
        std::cout << "\n";
    }
}

int calculateScore(char matrix[N][N]) {
    int total = 0;
    char first = matrix[0][0];
    bool allSame = true;

    // CHECK ROWS 
    for (int i = 0; i < N; i++) {
        std::unordered_map<char, int> freq;
        for (int j = 0; j < N; j++) {
            freq[matrix[i][j]]++;
            if (matrix[i][j] != first) allSame = false;
        }
        for (auto const& [sym, count] : freq) {
            if (count == N) total += 10;
            else if (count >= N / 2) total += 5;
        }
    }

    // CHECK COLUMNS 
    for (int j = 0; j < N; j++) {
        std::unordered_map<char, int> freq;
        for (int i = 0; i < N; i++) freq[matrix[i][j]]++;
        for (auto const& [sym, count] : freq) {
            if (count == N) total += 10;
            else if (count >= N / 2) total += 5;
        }
    }

    // CHECK DIAGONALS 
    std::unordered_map<char, int> d1, d2;
    for (int i = 0; i < N; i++) {
        d1[matrix[i][i]]++;              
        d2[matrix[i][N - 1 - i]]++;     
    }

    for (auto const& [sym, count] : d1) {
        if (count == N) total += 15;
        else if (count >= N / 2) total += 10;
    }

    for (auto const& [sym, count] : d2) {
        if (count == N) total += 15;
        else if (count >= N / 2) total += 10;
    }

    if (allSame) total += 50;
    return total;
}

void showStats() {
    char mostFreqSym = '?';
    int maxCount = 0;

    std::cout << "\n SESSION STATISTICS (HASH MAP) \n";
    for (auto const& [sym, count] : sessionStats) {
        std::cout << "Symbol " << sym << ": " << count << " times\n";
        if (count > maxCount) {
            maxCount = count;
            mostFreqSym = sym;
        }
    }
    std::cout << "Most frequent symbol so far: " << mostFreqSym << " (" << maxCount << ")\n";
}

int main() {
    srand((unsigned int)time(NULL));
    char matrix[N][N];
    int choice = 1;

    while (choice != 0) {
        std::cout << "\n[1] Spin Machine  [0] Exit: ";
        std::cin >> choice;

        if (choice == 1) {
            system("clear"); 
            genRandomMatrix(matrix);
            int score = calculateScore(matrix);
            std::cout << "\nSPIN SCORE: " << score << "\n";
            showStats();
        }
    }
    return 0;
}
