#include <stdio.h>
#include <stdbool.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

// Function to print the solution
void printSolution(int board[MAX][MAX], int N) {
    int i, j;
    printf("One of the solutions:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive utility function to solve the N-Queens problem
bool solveNQueensUtil(int board[MAX][MAX], int col, int N) {
    int i;
    if (col >= N) {
        return true; // All queens are placed
    }

    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // Place the queen

            if (solveNQueensUtil(board, col + 1, N)) {
                return true; // Recur to place the rest of the queens
            }

            board[i][col] = 0; // Backtrack
        }
    }

    return false; // If no queen can be placed in this column
}

// Function to solve the N-Queens problem
void solveNQueens(int N) {
    int board[MAX][MAX], i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0; // Initialize the board with 0
        }
    }

    if (!solveNQueensUtil(board, 0, N)) {
        printf("Solution does not exist.\n");
        return;
    }

    printSolution(board, N);
}

int main() {
    int N;

    clrscr(); // Clear screen for Turbo C
    printf("Enter the value of N (number of queens): ");
    scanf("%d", &N);

    solveNQueens(N);

    getch(); // Wait for a key press in Turbo C
    return 0;
}