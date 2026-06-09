#include <iostream>

using namespace std;

int board[20][20] = {0};
bool col[20] = {false};
bool diag1[40] = {false}; 
bool diag2[40] = {false};

void printSolution(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensBB(int row, int N) {
    if (row == N) {
        printSolution(N);
        return;
    }

    for (int c = 0; c < N; c++) {
        if (col[c] == false && diag1[row + c] == false && diag2[row - c + N - 1] == false) {
            
            board[row][c] = 1;
            col[c] = true;
            diag1[row + c] = true;
            diag2[row - c + N - 1] = true;

            solveNQueensBB(row + 1, N);

            board[row][c] = 0;
            col[c] = false;
            diag1[row + c] = false;
            diag2[row - c + N - 1] = false;
        }
    }
}

int main() {
    int N;
    cout << "Enter the board size (N) for N-Queens: ";
    cin >> N;

    if (N <= 0 || N > 20) {
        cout << "Please enter N between 1 and 20." << endl;
        return 0;
    }

    cout << "\nSolutions for " << N << "-Queens:" << endl << endl;
    solveNQueensBB(0, N);
    
    return 0;
}
