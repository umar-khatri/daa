#include <stdio.h>
#include <conio.h> // For Turbo C compatibility
#include <limits.h> // For INT_MAX

#define MAX 100 // Maximum size for arrays

void coinChangeDP(int coins[], int n, int amount) {
    int dp[MAX]; // Array to store the minimum coins required for each amount
    int coinUsed[MAX]; // Array to track the coins used
    int i, j;

    // Initialize dp array
    for (i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
        coinUsed[i] = -1;
    }
    dp[0] = 0; // Base case: 0 coins are needed to make amount 0

    // Fill the dp array
    for (i = 0; i < n; i++) {
        for (j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
                coinUsed[j] = i; // Track the coin used
            }
        }
    }

    // Print the result
    if (dp[amount] == INT_MAX) {
        printf("The amount %d cannot be made with the given coins.\n", amount);
    } else {
        printf("Minimum number of coins required: %d\n", dp[amount]);
        printf("Coins used to make the amount %d:\n", amount);

        int tempAmount = amount;
        while (tempAmount > 0) {
            int coinIndex = coinUsed[tempAmount];
            printf("%d ", coins[coinIndex]);
            tempAmount -= coins[coinIndex];
        }
        printf("\n");
    }
}

int main() {
    int n, amount, i;
    int coins[MAX];

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    printf("Enter the coin denominations:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to make: ");
    scanf("%d", &amount);

    coinChangeDP(coins, n, amount);

    getch(); // Wait for a key press in Turbo C
    return 0;
}
/*coinDP.c
Problem: Coin Change (DP - total ways)
Time Complexity: O(n * amount)
(n = number of coins)
*/