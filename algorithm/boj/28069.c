#include <stdio.h>
#define INF 100000000

int min(int a, int b) { return a < b ? a : b; }

int main(void) {
    int n;
    int k;

    scanf("%d %d", &n, &k);

    int dp[2000000];
    for (int i = 0; i < 1000001; i++) dp[i] = INF;

    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        dp[i + i / 2] = min(dp[i + i / 2], dp[i] + 1);
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }

    printf("%s", dp[n] > k ? "water" : "minigimbob");

    return 0;
}
