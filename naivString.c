#include <stdio.h>
#include <string.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

// Naive string matching algorithm
void naiveStringMatching(char text[], char pattern[]) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern
    int i, j, found;

    found = 0; // Flag to track if the pattern is found

    // Slide the pattern over the text one character at a time
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If the pattern is found
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1; // Set the flag to indicate the pattern is found
        }
    }

    // If the pattern was not found, print "Solution does not exist"
    if (!found) {
        printf("Solution does not exist.\n");
    }
}

int main() {
    char text[MAX], pattern[MAX];

    clrscr(); // Clear screen for Turbo C
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    naiveStringMatching(text, pattern);

    getch(); // Wait for a key press in Turbo C
    return 0;
}

/*naivString.c
Problem: Naive String Matching
Time Complexity: O((n - m + 1) * m)
(n = length of text, m = length of pattern)
*/