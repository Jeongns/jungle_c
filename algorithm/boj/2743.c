#include <stdio.h>

int main(void) {
    while (1) {
        int c = getchar();
        if (c == '\n') break;
        putchar(c > 'Z' ? c - 32 : c + 32);
    }

    return 0;
}