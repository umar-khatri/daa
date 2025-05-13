#include <stdio.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

// Structure to store items
struct Item {
    int weight;
    int value;
};

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                // Swap items[j] and items[j + 1]
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    int i;
    double totalValue = 0.0; // Total value of items in the knapsack

    sortItems(items, n); // Sort items by value/weight ratio

    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity, i;
    struct Item items[MAX];

    //clrscr(); // Clear screen for Turbo C
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Maximum value in the knapsack: %.2f\n", fractionalKnapsack(items, n, capacity));

    //getch(); // Wait for a key press in Turbo C
    return 0;
}