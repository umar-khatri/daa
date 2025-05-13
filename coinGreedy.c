#include <stdio.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

void coinChangeGreedy(int coins[], int n, int amount) {
    int count[MAX]; // Array to store the count of each coin used
    int i;

    for (i = 0; i < n; i++) {
        count[i] = 0; // Initialize counts to 0
    }

    printf("Coins used to make the amount %d:\n", amount);

    for (i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count[i]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (count[i] > 0) {
            printf("Coin %d: %d times\n", coins[i], count[i]);
        }
    }

    if (amount > 0) {
        printf("Remaining amount that cannot be made: %d\n", amount);
    }
}

int main() {
    int n, amount, i;
    int coins[MAX];

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    printf("Enter the coin denominations in descending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to make: ");
    scanf("%d", &amount);

    coinChangeGreedy(coins, n, amount);

    getch(); // Wait for a key press in Turbo C
    return 0;
}