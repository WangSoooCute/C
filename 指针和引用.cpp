#include<iostream>
using namespace std;

void swap_pointer(int* px, int* py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
void swap_reference(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int* addNode(int i) {
    int* pNewNode = new int; //申请在堆自由存储区上面
    *pNewNode = i;
    return pNewNode;
}

int main() {
    //指针的基本使用
    int i = 1;
    int* pi;
    pi = &i;
    i = 2;
    *pi = 3;

    int x = 1, y = 2;
    //用指针实现swap函数
    int* px = &x;
    int* py = &y;
    swap_pointer(px, py);
    //用引用实现swap函数
    swap_reference(x, y);

    //自由存储空间和内存泄漏问题
    int* array[10];
    for (int i = 0; i < 10; ++i)
        array[i] = addNode(i);
    for (int i = 0; i < 10; ++i)
        delete array[i];
}
