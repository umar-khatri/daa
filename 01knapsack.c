#include <stdio.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[MAX][MAX];
    int i, w;

    // Build the dp table in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or weight is 0
            } else if (wt[i - 1] <= w) {
                // Include the item or exclude it
                dp[i][w] = (val[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w])
                               ? val[i - 1] + dp[i - 1][w - wt[i - 1]]
                               : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w]; // Exclude the item
            }
        }
    }

    return dp[n][W]; // Maximum value that can be obtained
}

int main() {
    int n, W, i;
    int val[MAX], wt[MAX];

    //clrscr(); // Clear screen for Turbo C
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum value in the knapsack: %d\n", knapsack(W, wt, val, n));

    //getch(); // Wait for a key press in Turbo C
    return 0;
}