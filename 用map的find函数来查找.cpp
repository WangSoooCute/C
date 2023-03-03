#include<iostream>
#include<map>
using namespace std;
//map的底层是一个二叉搜索树
//map相关见：https://en.cppreference.com/w/cpp/container/map

int main(){
    map<int,int>findIndex;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        findIndex[x]=i;
        //即把数组的元素和下标反过来
    }
    int x;
    cin>>x;

    if(findIndex.find(x)==findIndex.end())
        cout<<"NO!"<<endl;
    else{
        cout<<"yes!"<<endl;
        cout<<findIndex[x]+1<<endl;
    }
    return 0;
}
