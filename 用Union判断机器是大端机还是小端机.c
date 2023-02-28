#include<stdio.h>

union{
    char str;
    int data;
}u;

int main(){
    u.data=0x01020304;
    if(u.str==0x01)
        printf("此机器是大端！");
    else if(u.str==0x04)
        printf("此机器是小端！");
    else
        printf(" 暂无法判断此机器类型！");
    return 0;
}
