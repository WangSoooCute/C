#include <cstdio>
char arr[1000][3000]={0};

int main(){
    int h;
    while(scanf("%d",&h)!=EOF){
        for(int i=0;i<h;i++){
            for(int j=0;j<2*(h-1-i);j++){
                arr[i][j]=' ';
            }
            for(int j=2*(h-1-i);j<3*h-2;j++){
               arr[i][j]='*';
            }
            printf("%s\n",arr[i]);
            //因为每行以'\0'结尾，所以每行是一个字符串，所以用%s
        }
    }
    return 0;
}
