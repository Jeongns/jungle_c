#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int t, w;
int arr[1001];
int dp[1001][31][2] = {0};

int jadu(int time, int power, int pos) {
    if (time < 0) return 0;
    if (dp[time][power][pos] != 0) return dp[time][power][pos];

    dp[time][power][pos] = pos + 1 == arr[time] ? 1 : 0;

    if (power == 0) {
        dp[time][power][pos] += jadu(time - 1, power, pos);
        return dp[time][power][pos];
    }

    dp[time][power][pos] +=
        max(jadu(time - 1, power, pos), jadu(time - 1, power - 1, (pos + 1) % 2));
    return dp[time][power][pos];
}

int main(void) {
    scanf("%d %d", &t, &w);
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", jadu(t, w, 0));

    return 0;
}