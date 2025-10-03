#include <stdio.h>

int main(void) {
    char str[1000001];

    scanf("%s", str);

    int a = 0;
    int b = 0;

    for (int i = 0; str[i] != '\0';) {
        if (str[i] == '0') {
            a++;
            for (; str[i] == '0' && str[i] != '\0'; i++);
        }

        if (str[i] == '1') {
            b++;
            for (; str[i] == '1' && str[i] != '\0'; i++);
        }
    }

    printf("%d", a > b ? b : a);

    return 0;
}