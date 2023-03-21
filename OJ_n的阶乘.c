#include <stdio.h>

//如果返回值用int的话，当n>=13时，计算结果会出错
long long factorial(int n){
    if(n==1)
        return 1;
    return n*factorial(n-1);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        //long long是64位输出，要用printf("%lld")
        printf("%lld\n", factorial(n));
    }
    return 0;
}
