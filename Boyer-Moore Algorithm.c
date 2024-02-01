#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char* pattern, int m, int badchar[NO_OF_CHARS]) {
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < m; i++)
        badchar[(int)pattern[i]] = i;
}

void boyerMooreSearch(char* text, char* pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pattern, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            printf("Pattern found at position: %d\n", s + 1);
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }
}

int main() {
    char text[40], pattern[30];

    printf("Enter text: ");
    gets(text);

    printf("Enter pattern: ");
    gets(pattern);

    boyerMooreSearch(text, pattern);

    return 0;
}
