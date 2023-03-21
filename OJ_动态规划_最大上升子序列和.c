#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int dp[1000];//以A[i]结尾的上升子序列的最大长度
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i];
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && dp[i]<dp[j]+a[i])
                dp[i]=dp[j]+a[i];
            if (dp[i] > answer)
                answer = dp[i];
        }
    }

    printf("%d\n", answer);
}
