#include <stdio.h>
#include <string.h>

int n;
int arr[1001] = {0};
int visit[1001] = {0};

int dfs(int number) {
    if (visit[number]) return 0;
    visit[number] = 1;

    dfs(arr[number]);

    return 1;
}

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);

    for (int i = 0; i < testCase; i++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += dfs(i);
        }

        printf("%d\n", result);
        memset(arr, 0, sizeof(arr));
        memset(visit, 0, sizeof(visit));
    }
    return 0;
}