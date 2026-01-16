#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

const int SYMBOLS_SIZE = 5;
const int N = 4; // Using N for ROW and COL as per instructions
const char SYMBOLS[SYMBOLS_SIZE] = {'A', 'B', 'C', '7', '*'};

// Part 2: Multipliers for symbols using a Map
std::unordered_map<char, int> symbolValues = {
    {'A', 1}, {'B', 1}, {'C', 2}, {'7', 5}, {'*', 3}
};

void genRandomMatrix(char matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        std::cout << "| ";
        for (int j = 0; j < N; j++) {
            matrix[i][j] = SYMBOLS[rand() % SYMBOLS_SIZE];
            std::cout << matrix[i][j] << " | ";
        }
        std::cout << "\n";
    }
}

int calculateScore(char matrix[N][N], std::unordered_map<char, int>& globalFreq) {
    int totalScore = 0;
    bool allSameMatrix = true;
    char firstSym = matrix[0][0];

    // 1. Check Rows & Update Global Frequencies
    for (int i = 0; i < N; i++) {
        std::unordered_map<char, int> rowFreq;
        for (int j = 0; j < N; j++) {
            rowFreq[matrix[i][j]]++;
            globalFreq[matrix[i][j]]++; // Track total game stats
            if (matrix[i][j] != firstSym) allSameMatrix = false;
        }
        // Scoring logic for this row
        for (auto const& [sym, count] : rowFreq) {
            if (count == N) totalScore += 10;
            else if (count >= N / 2) totalScore += 5;
        }
    }

    // 2. Check Columns
    for (int j = 0; j < N; j++) {
        std::unordered_map<char, int> colFreq;
        for (int i = 0; i < N; i++) {
            colFreq[matrix[i][j]]++;
        }
        for (auto const& [sym, count] : colFreq) {
            if (count == N) totalScore += 10;
            else if (count >= N / 2) totalScore += 5;
        }
    }

    // 3. Check Diagonals (Main and Anti-diagonal)
    std::unordered_map<char, int> diag1, diag2;
    for (int i = 0; i < N; i++) {
        diag1[matrix[i][i]]++;
        diag2[matrix[i][N - 1 - i]]++;
    }
    
    // Scoring Diagonals
    for (auto const& [sym, count] : diag1) {
        if (count == N) totalScore += 15;
        else if (count >= N / 2) totalScore += 10;
    }
    for (auto const& [sym, count] : diag2) {
        if (count == N) totalScore += 15;
        else if (count >= N / 2) totalScore += 10;
    }

    // 4. Bonus for full matrix
    if (allSameMatrix) totalScore += 50;

    return totalScore;
}

int main() {
    srand((unsigned int)time(NULL));
    char matrix[N][N];
    int uInput = 1;

    while (uInput) {
        std::cout << "\n--- SLOT MACHINE (Press 1 to Spin, 0 to Exit) ---\n";
        std::cin >> uInput;
        if (uInput == 0) break;

        std::unordered_map<char, int> globalFreq; // Part 2: Stat collection
        genRandomMatrix(matrix);
        
        int score = calculateScore(matrix, globalFreq);
        
        std::cout << "\n>>> TOTAL SCORE: " << score << " <<<\n";
        
        // Part 2: Show Hash Summary
        std::cout << "--- Session Stats (Hash Map) ---\n";
        for (auto const& [sym, count] : globalFreq) {
            std::cout << "Symbol [" << sym << "] appeared " << count << " times. ";
            std::cout << "Value per unit: " << symbolValues[sym] << "\n";
        }
    }

    return 0;
}