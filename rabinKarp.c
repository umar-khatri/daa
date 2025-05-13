#include <stdio.h>
#include <string.h>
#include <conio.h> // For Turbo C compatibility

#define d 256 // Number of characters in the input alphabet

// Rabin-Karp algorithm for pattern matching
void rabinKarp(char text[], char pattern[], int q) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern
    int i, j;
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the text
    int h = 1;
    int found = 0; // Flag to track if the pattern is found

    // The value of h would be "pow(d, m-1) % q"
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of the pattern and the first window of the text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text one character at a time
    for (i = 0; i <= n - m; i++) {
        // Check if the hash values of the current window of text and the pattern match
        if (p == t) {
            // If the hash values match, check the characters one by one
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

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // If the hash value becomes negative, convert it to positive
            if (t < 0) {
                t = (t + q);
            }
        }
    }

    // If the pattern was not found, print "Solution does not exist"
    if (!found) {
        printf("Solution does not exist.\n");
    }
}

int main() {
    char text[100], pattern[100];
    int q = 101; // A prime number for hashing

    //clrscr(); // Clear screen for Turbo C
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    rabinKarp(text, pattern, q);

    //getch(); // Wait for a key press in Turbo C
    return 0;
}