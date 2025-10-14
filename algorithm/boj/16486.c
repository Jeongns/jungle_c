#include <stdio.h>
#define PI 3.141592

int main(void) {
    int testCase;

    scanf("%d", &testCase);
    getchar();
    for (int i = 0; i < testCase; i++) {
        char arr[26];
        for (int i = 0; i < 26; i++) arr[i] = 'A' + i;

        while (1) {
            char c = getchar();
            if (c == '\n') break;
            arr[c - 'A'] = 0;
        }
        int result = 0;
        for (int i = 0; i < 26; i++) result += arr[i];
        printf("%d\n", result);
    }
}