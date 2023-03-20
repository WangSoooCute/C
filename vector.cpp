#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(){
    //末尾插入元素
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(3);
    vector<int> vec2 {1,2,3};//[0] 1 [1] 2 [2] 3
    vector<int> vec3(10000);// [0]~[9999] 0
    
    //遍历
    for(int i=0;i<vec2.size();i++)
        cout<<vec2[i]<<endl;
    for(vector<int>::iterator it=vec2.begin();it!=vec2.end();it++)
        cout<<*it<<endl;

    //随机位置的插入和删除：其他元素要相应地整体前移或后移
    vector<int>::iterator it1 = vec2.begin() + 2;
    vec2.insert(it1,4);
    vec2.erase(vec2.begin());

    return 0;
}
//需用g++ vector.cpp =std=c++11进行编译
