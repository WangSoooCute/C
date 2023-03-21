#include <stdio.h>

long long hanoi(int n) {
    if (n == 1)
        return 2;//先移到中间，再移到右边
    //移动次序：(n-1)A->C, A->B, (n-1)C->A, B->C, (n-1)A->C
    return 3 * hanoi(n - 1) + 2;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", hanoi(n));
}

/*
Hanoi改编：

题目描述：
在Hanoi塔基础上，不允许直接从最左（右）边移动到最右（左）边（每次移动一定是移到中间杆或从中间杆移出）

输入：
N个圆盘，1≤N≤35

输出：
移动最小的次数
*/
