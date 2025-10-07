#include <stdio.h>

int main(void) {
    int arr[26] = {0};
    char str[100];

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) arr[str[i] - 'A'] = 1;
    
    printf("%s", arr[12] && arr[14] && arr[1] && arr[8] && arr[18] ? "YES" : "NO");

    return 0;
}