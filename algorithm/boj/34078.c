#include <stdio.h>

int n;
int bangboos[200001];
int visit[200001];
int reverse_visit[200001];

int dfs(int number, int reverse) {
    int* cur_visit = reverse ? reverse_visit : visit;
    if (cur_visit[number]) return 0;
    cur_visit[number] = 1;

    return dfs(bangboos[reverse ? n - number + 1 : number], reverse) + 1;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bangboos[i]);
    }

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) a += dfs(i, 0) - 1;
        if (!reverse_visit[i]) b += dfs(i, 1) - 1;
    }
    
    printf("%d %d", n - 2, a < b ? a : b);

    return 0;
}