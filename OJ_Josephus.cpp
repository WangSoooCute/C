#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n, p, m;
    while (true) {
        scanf("%d%d%d", &n, &p, &m);
        if (n == 0 && p == 0 && m == 0)
            break;

        queue<int> children;//队列中的元素是孩子的编号
        //把第一轮要喊编号的孩子排好队
        int i = p;//i用来遍历孩子的编号
        for (int j = 0; j < n; ++j) {
            children.push(i);
            i++;//p->p+1->p+2->...-->1->...->p-1if(i >n){
            if (i > n)
                i = 1;
        }

        //喊号的过程
        int num = 1;//将要喊的编号
        while (true) {
            int cur = children.front();//cur是队首孩子的编号
            children.pop();//喊完了，队首出队
            if (num == m) { //检查一下刚才喊的号码是不是m{
                num = 1; //下一个同学喊的号就是1
                if (children.empty()) {//所有同学都出来了
                    cout << cur << endl;
                    break;
                }
                else//还有同学在喊号
                    cout<<cur<<", ";
            }
            else{
                num++;
                children.push(cur);//喊的号码不是m，归队
            }
        }
    }
}
/*
Josephus问题：

题目描述：
n个小孩围坐成一圈，并按顺时针编号为1，2，…，n，从编号为p的小孩顺时针依次报数，由1报到m，报到m时，这名小孩从圈中出去；然后下一名小孩再从1报数，报到m时再出去。以此类推，直到所有小孩都从圈中出去。请按出去的先后顺序输出小孩的编号。

输入：
第一个是n，第二个是p，第三个是m（0<m，n<300）。最后一行是：0 0 0。

输出：
按出圈的顺序输出编号，编号之间以逗号间隔。

样例输入：
8 3 4
0 0 0

样例输出：
6，2，7，4，3，5，1，8
*/
