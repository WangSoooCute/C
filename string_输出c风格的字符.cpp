#include <cstdio>
#include <stdio.h>
#include <string>
#include <iostream>
char arr[1000][3000]={0};
using namespace std;

int main(){
    //输出梯形
    int h;
    if(scanf("%d",&h)!=EOF){
        for(int i=0;i<h;i++){
            for(int j=0;j<2*(h-1-i);j++){
                arr[i][j]=' ';
            }
            for(int j=2*(h-1-i);j<3*h-2;j++){
               arr[i][j]='*';
            }
            //第1种输出C风格字符串的方法
            printf("%s\n",arr[i]);
            //因为每行以'\0'结尾，所以每行是一个字符串，所以用%s
        }
    }

    //第2种输出C风格字符串的方法
    char str_[100]={0};
    fgets(str_,100,stdin);
    string str=str_;
    printf("%s\n",str.c_str());

    //输出字符
    for(unsigned int i=0;i<str.size();i++)
        printf("%c\n",str[i]);
    for(string::iterator i=str.begin();i!=str.end();i++)
        printf("%c\n",*i);

    return 0;
}
