#include <stdio.h>
#include <string.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(char pattern[], int m, int lps[]) {
    int length = 0; // Length of the previous longest prefix suffix
    int i;
    lps[0] = 0; // lps[0] is always 0
    i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm for pattern matching
void KMPSearch(char text[], char pattern[]) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern
    int lps[MAX];            // LPS array
    int i, j, found;

    // Preprocess the pattern to compute the LPS array
    computeLPSArray(pattern, m, lps);

    i = 0; // Index for text[]
    j = 0; // Index for pattern[]
    found = 0; // Flag to track if the pattern is found

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            found = 1; // Set the flag to indicate the pattern is found
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
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

    KMPSearch(text, pattern);

    getch(); // Wait for a key press in Turbo C
    return 0;
}