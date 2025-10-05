#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void makeBadCharacterTable(char* pattern, int* badCharacterTable) {
    for (int i = 0; i < 256; i++) {
        badCharacterTable[i] = strlen(pattern);
    }

    for (int i = 0; i < strlen(pattern); i++) {
        badCharacterTable[pattern[i]] = strlen(pattern) - i - 1;
    }
}

void makeGoodSuffixTable(char* pattern, int* goodSuffixTable) {
    int m = strlen(pattern);
    int* borderPos = malloc(sizeof(int) * (m + 1));
    int i = m, j = m + 1;
    borderPos[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (goodSuffixTable[j] == 0) goodSuffixTable[j] = j - i;
            j = borderPos[j];
        }
        i--;
        j--;
        borderPos[i] = j;
    }

    j = borderPos[0];
    for (i = 0; i <= m; i++) {
        if (goodSuffixTable[i] == 0) goodSuffixTable[i] = j;
        if (i == j) j = borderPos[j];
    }

    free(borderPos);
}

int boyerMoore(char* parent, char* pattern) {
    int badCharacterTable[256] = {0};
    int goodSuffixTable[strlen(pattern) + 1];
    memset(goodSuffixTable, 0, sizeof(goodSuffixTable));

    int parent_pos = strlen(pattern) - 1;
    int pattern_pos = 0;

    makeBadCharacterTable(pattern, badCharacterTable);
    makeGoodSuffixTable(pattern, goodSuffixTable);

    while (parent_pos < strlen(parent)) {
        pattern_pos = strlen(pattern) - 1;
        while (parent[parent_pos] == pattern[pattern_pos]) {
            if (pattern_pos == 0) return parent_pos;

            parent_pos--;
            pattern_pos--;
        }
        parent_pos += MAX(badCharacterTable[parent[parent_pos]], goodSuffixTable[pattern_pos + 1]);
    }

    return -1;
}

int main(void) {
    int result = boyerMoore("ABAXABABA", "ABABA");
    if (result == -1)
        printf("텍스트 안에 패턴이 존재하지 않습니다.\n");
    else
        printf("%d번째 문자가 일치합니다.\n", result + 1);
    return 0;
}
