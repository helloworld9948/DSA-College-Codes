#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, n, m, flag = 0;
    char t[40], p[30];

    printf("Enter text: ");
    gets(t);

    printf("Enter pattern: ");
    gets(p);

    n = strlen(t);
    m = strlen(p);

    for (i = 0; i <= n - m; i++) {
        j = 0;

        while (j < m && p[j] == t[j + i]) {
            j++;
            if (j == m) {
                flag = 1;
                k = i + 1;
            } else
                flag = 0;
        }
    }

    if (flag == 1)
        printf("Pattern found at position: %d\n", k);
    else
        printf("Pattern not found in text\n");

    return 0;
}
