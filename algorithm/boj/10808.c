#include <stdio.h>
int main(void) {
    int arr[26] = {0};
    while (1) {
        char c = getchar();
        if (c == '\n') break;
        arr[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}