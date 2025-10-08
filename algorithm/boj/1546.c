#include <stdio.h>

int main(void) {
    int n;
    int arr[1000];
    float max = 0;
    float result = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        max = max > arr[i] ? max : arr[i];
    }

    for (int i = 0; i < n; i++) {
        result += (arr[i] / max) * 100;
    }

    printf("%f", result / n);

    return 0;
}