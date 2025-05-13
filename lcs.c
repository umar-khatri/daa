#include <stdio.h>
#include <string.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

int lcs(char *X, char *Y, int m, int n) {
    int dp[MAX][MAX];
    int i, j;

    // Build the dp table in a bottom-up manner
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // Print the LCS
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);

    return dp[m][n];
}

int main() {
    char X[MAX], Y[MAX];
    int m, n;

    clrscr(); // Clear screen for Turbo C
    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    printf("Length of Longest Common Subsequence: %d\n", lcs(X, Y, m, n));

    getch(); // Wait for a key press in Turbo C
    return 0;
}