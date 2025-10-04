#include <stdio.h>

int main(void) {
    char str[100001];
    int arr[10];

    scanf("%s", str);

    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        arr[str[i] - '0']++;
        num += str[i] - '0';
    }

    if (num % 3 != 0 || arr[0] == 0) {
        printf("-1");
        return 0;
    }

    for (int i = 9; i >= 0; i--){
        while (arr[i]-- > 0) printf("%d",i);
    }

    return 0;
}