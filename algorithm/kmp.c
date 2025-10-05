#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makeTable(char *pattern, int *table) {
    int patternSize = strlen(pattern);

    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
}

void kmp(char *parent, char *pattern) {
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);
    int table[patternSize];
    memset(table, 0, sizeof(table));

    makeTable(pattern, table);

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

    return 0;
}