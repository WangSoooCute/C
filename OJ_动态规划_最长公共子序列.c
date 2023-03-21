//最长公共子序列长度，不要求子序列连续
#include <stdio.h>

int max(int x,int y){
    return x>y?x:y;
}

int main() {
    int n,m;
    scanf("%d%d", &n, &m);

    char s1[1000];
    char s2[1000];
    scanf("%s%s", s1, s2);

    //s1的前i个元素、s2的前j个元素的最长公共子序列长度
    int dp[1000][1000];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (i == 0 | j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    
    printf("%d\n", dp[n][m]);
}
