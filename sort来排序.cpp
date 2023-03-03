#include<iostream>
#include<algorithm>
using namespace std;

bool comp(int a,int b){
    if(a%2 && b%2==0)
        return true;
    if(a%2 && b%2 && a>b)
        return true;
    if(a%2==0 && b%2==0 && a<b)
        return true;
    return false;
}

int main() {
    int arr[10]={0};
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]
        >>arr[5]>>arr[6]>>arr[7]>>arr[8]>>arr[9]) {
        sort(arr,arr+10,comp);
        for(int i=0;i<10;i++)
            cout<<arr[i]<<' ';
        cout << endl;
    }
}

/*题目描述：
整数奇偶排序：http://t.cn/E9glPvp
输入10个整数，彼此以空格分隔。重新排序后输出（也按空格分隔），要求: 
先输出其中的奇数，并按从大到小排列；然后输出其中的偶数，并按从小到大排列
*/
