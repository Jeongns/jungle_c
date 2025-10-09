#include <stdio.h>

int main(void) {
    int length = 0;
    int colon = 0;
    int underBar = 0;
    while (1) {
        char c = getchar();
        if (c == '\n') break;
        if (c == ':') colon++;
        if (c == '_') underBar++;
        length++;
    }

    printf("%d", length + colon + underBar * 5);
}