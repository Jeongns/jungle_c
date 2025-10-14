#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long BASE = 127;;

int primeList[26] = {628900176,  959664715, 1462105408, 1895868256, 2012384793, 216525281,
                     315078411,  737866955, 1295817737, 1376775932, 37445764,   1521978486,
                     477421146,  84525362,  719238153,  1985817325, 630092104,  1333767918,
                     669281004,  900354316, 1202553596, 1357038972, 1903295184, 249239982,
                     1956097880, 913997304};

unsigned long long hashing(char *str, int length, int flag) {
    unsigned long long hash = 0;
    unsigned long long power = 1;
    for (int i = length - 1; i >= 0; i--) {
        hash = (hash + (primeList[str[i] - 'a'] * power));
        if (flag) power = (power * BASE);
    }
    return hash;
}

int search(char *str, char *pattern) {
    int strSize = strlen(str);
    int patternSize = strlen(pattern);
    unsigned long long patternHash = hashing(pattern, patternSize, 0);

    char subStr[patternSize];
    memcpy(subStr, str, patternSize * sizeof(char));

    unsigned long long rabinHash = hashing(subStr, patternSize, 1);
    unsigned long long strHash = hashing(subStr, patternSize, 0);
    unsigned long long power = 1;
    for (int i = 0; i < patternSize - 1; i++) power *= BASE;

    long long hashList[100000];
    int hashListIndex = 0;

    for (int i = 0; i <= strSize - patternSize; i++) {
        if (patternHash == strHash) {
            int j = 0;
            for (; j < hashListIndex; j++)
                if (hashList[j] == rabinHash) break;
            if (j == hashListIndex) {
                hashList[hashListIndex++] = rabinHash;
            };
        }

        if (i == strSize - patternSize) break;

        strHash = strHash - primeList[str[i] - 'a'] + primeList[str[i + patternSize] - 'a'];

        rabinHash = BASE * (rabinHash - primeList[str[i] - 'a'] * power) +
                    primeList[str[i + patternSize] - 'a'];
    }

    return hashListIndex;
}

int main(void) {
    char pattern[200001], str[200001];
    scanf("%s", pattern);
    scanf("%s", str);

    printf("%d\n", search(str, pattern));
    return 0;
}