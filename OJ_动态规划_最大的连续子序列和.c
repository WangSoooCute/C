//bug：如果把数组长度设为1000001，则编译会通过，但运行时会提示：Segmentation Fault

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    long long a[1000];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);

    long long dp[1000] = {a[0]}; //以当前位置i结尾的最大连续子序列和
    long long maximum = dp[0];//即=a[0]
    for (int i = 1; i < n; ++i) {
        if (dp[i - 1] < 0)
            dp[i] = a[i];
        else//可以续命
            dp[i] = a[i] + dp[i - 1];
        if (dp[i] > maximum)
            maximum = dp[i];
    }

    printf("%lld\n", maximum);
}
