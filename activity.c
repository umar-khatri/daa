#include <stdio.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

void activitySelection(int start[], int finish[], int n) {
    int i, j;

    printf("Selected activities are:\n");

    i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);

    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            i = j;
        }
    }
}

int main() {
    int n, i;
    int start[MAX], finish[MAX];

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    printf("Enter the start times of the activities:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter the finish times of the activities:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &finish[i]);
    }

    activitySelection(start, finish, n);

    getch(); // Wait for a key press in Turbo C
    return 0;
}