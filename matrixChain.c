#include <stdio.h>
#include <limits.h> // For INT_MAX
#include <conio.h>  // For Turbo C compatibility

#define MAX 100 // Maximum size for arrays

// Function to find the minimum number of multiplications needed
void matrixChainOrder(int p[], int n) {
    int m[MAX][MAX]; // m[i][j] stores the minimum number of multiplications needed
    int i, j, k, L, q;

    // Initialize the diagonal of the matrix to 0
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                // Calculate the cost of splitting at k
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("Minimum number of multiplications is: %d\n", m[1][n - 1]);
}

int main() {
    int n, i;
    int p[MAX]; // Fixed-size array for dimensions

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions of the matrices:\n");
    for (i = 0; i <= n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n + 1);

    getch(); // Wait for a key press in Turbo C
    return 0;
}