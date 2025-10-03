#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *makeTable(char *pattern) {
    int patternSize = strlen(pattern);
    int *table = malloc(sizeof(int) * patternSize);

    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

void kmp(char *parent, char *pattern) {
    int *table = makeTable(pattern);
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);

    int j = 0;
    for (int i = 0; i < parentSize; i++) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (parent[i] == pattern[j]) {
            if (j == patternSize - 1) {
                printf("%d번째에서 찾았습니다.\n", i - patternSize + 2);
                j = table[j];
            } else {
                j++;
            }
        }
    }
}

int main(void) {
    char *parent = "ababacabacaabacaaba";
    char *pattern = "abacaaba";
    kmp(parent, pattern);

    int *table = makeTable(pattern);
    for (int i = 0; i < strlen(pattern); i++) {
        printf("%d ", table[i]);
    }

    return 0;
}