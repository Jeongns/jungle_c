#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M_PI 3.14159265358979323846
#define WIDTH 1

typedef struct {
    double r, i;
} cx;

int max(int a, int b) { return a > b ? a : b; }

cx cadd(cx a, cx b) { return (cx){a.r + b.r, a.i + b.i}; }
cx csub(cx a, cx b) { return (cx){a.r - b.r, a.i - b.i}; }
cx cmul(cx a, cx b) { return (cx){a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r}; }
cx expi(double theta) { return (cx){cos(theta), sin(theta)}; }

void numberStringtoComplexArray(char* numberString, cx* complexArray) {
    int length = strlen(numberString);
    int index = 0;
    for (int i = length; i > 0; i -= WIDTH) {
        int start = max(i - WIDTH, 0);
        char block[WIDTH] = {0};
        strncpy(block, numberString + start, i - start);

        complexArray[index].r = atof(block);
        complexArray[index].i = 0;
        index++;
    }
}

void bitReversePermute(cx* complexArray, int length) {
    int j = 0;
    for (int i = 1; i < length; i++) {
        int checkBit = length >> 1;
        for (; j & checkBit; checkBit >>= 1) j ^= checkBit;
        j ^= checkBit;

        if (i < j) {
            cx temp = complexArray[i];
            complexArray[i] = complexArray[j];
            complexArray[j] = temp;
        }
    }
}

void fft(cx* complexArray, int length, int direction) {
    bitReversePermute(complexArray, length);
    for (int len = 2; len <= length; len <<= 1) {
        double angle = (-direction * 2) * M_PI / len;
        cx wlen = expi(angle);

        for (int i = 0; i < length; i += len) {
            cx twiddleFactor = {1, 0};

            for (int j = 0; j < len / 2; j++) {
                cx upper = complexArray[i + j];
                cx lower = cmul(complexArray[i + j + len / 2], twiddleFactor);

                complexArray[i + j] = cadd(upper, lower);
                complexArray[i + j + len / 2] = csub(upper, lower);

                twiddleFactor = cmul(twiddleFactor, wlen);
            }
        }
    }

    if (direction == -1) {
        for (int i = 0; i < length; i++) {
            complexArray[i].r /= length;
            complexArray[i].i /= length;
        }
    }
}

int main(void) {
    char numberString1[1000001] = {0}, numberString2[1000001] = {0};
    scanf("%s %s", numberString1, numberString2);

    int complexArraySize = 1;

    int blocksLength = strlen(numberString1) / WIDTH + (strlen(numberString1) % WIDTH ? 1 : 0) +
                       strlen(numberString2) / WIDTH + (strlen(numberString2) % WIDTH ? 1 : 0);

    while (complexArraySize < blocksLength) complexArraySize <<= 1;

    cx *complexArray1 = calloc(complexArraySize, sizeof(cx)),
       *complexArray2 = calloc(complexArraySize, sizeof(cx)),
       *mulComplexArray = calloc(complexArraySize, sizeof(cx));

    numberStringtoComplexArray(numberString1, complexArray1);
    numberStringtoComplexArray(numberString2, complexArray2);

    fft(complexArray1, complexArraySize, 1);
    fft(complexArray2, complexArraySize, 1);

    for (int i = 0; i < complexArraySize; i++)
        mulComplexArray[i] = cmul(complexArray1[i], complexArray2[i]);

    fft(mulComplexArray, complexArraySize, -1);

    const int BASE = 10;
    int* result = calloc(complexArraySize + 5, sizeof(int));
    long long carry = 0;

    for (int i = 0; i < complexArraySize; i++) {
        long long x = llround(mulComplexArray[i].r) + carry;
        if (x < 0) x = 0;
        result[i] = x % BASE;
        carry = x / BASE;
    }
    int over = complexArraySize;
    while (carry) {
        result[over++] = carry % BASE;
        carry /= BASE;
    }

    int hi = complexArraySize - 1;
    while (hi > 0 && result[hi] == 0) {
        hi--;
    }

    printf("%d", result[hi--]);
    for (int i = hi; i >= 0; i--) {
        printf("%01d", result[i]);
    }
    printf("\n");

    return 0;
}