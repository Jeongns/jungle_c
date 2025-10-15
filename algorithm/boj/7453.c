#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftList[leftSize], rightList[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftList[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightList[i] = arr[mid + 1 + i];
    }

    int leftPos = 0, rightPos = 0, arrPos = left;
    while (leftPos < leftSize && rightPos < rightSize)
        arr[arrPos++] =
            leftList[leftPos] <= rightList[rightPos] ? leftList[leftPos++] : rightList[rightPos++];
    while (leftPos < leftSize) arr[arrPos++] = leftList[leftPos++];

    while (rightPos < rightSize) arr[arrPos++] = rightList[rightPos++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(void) {
    int arr1[4000], arr2[4000], arr3[4000], arr4[4000];
    int sumArr1[16000000], sumArr2[16000000];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d %d %d %d", &arr1[i], &arr2[i], &arr3[i], &arr4[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumArr1[i * n + j] = arr1[i] + arr2[j];
            sumArr2[i * n + j] = arr3[i] + arr4[j];
        }
    }

    mergeSort(sumArr1, 0, n * n - 1);
    mergeSort(sumArr2, 0, n * n - 1);

    long long result = 0;
    for (int i = 0; i < n * n; i++) {
        int lower = 0;
        int left = 0, right = n * n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sumArr1[i] + sumArr2[mid] < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        lower = left;

        if (sumArr1[i] + sumArr2[lower] != 0) continue;

        left = 0, right = n * n;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (sumArr1[i] + sumArr2[mid] <= 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        result += right - lower;
    }

    printf("%lld\n", result);

    return 0;
}