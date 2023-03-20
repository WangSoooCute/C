#include<iostream>
#include<queue>
using namespace std;

struct Animal {
    int num;
    int seq;
};

int main() {

    queue<Animal> catQue;
    queue<Animal> dogQue;
    int seq = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int method, para;
        cin >> method >> para;

        //入队
        if (method == 1) {
            //处理狗
            if (para > 0) {
                Animal dog;
                dog. num = para;
                dog. seq = seq;

                seq++;

                dogQue.push(dog);
            }
            //处理猫
            else {
                Animal cat;
                cat.num = para;
                cat.seq = seq;

                ++seq;

                catQue.push(cat);
            }
        }

        //出队
        else {
            // 不区分猫狗
            if (para == 0) {
                //1无猫无狗
                if (dogQue.empty() && catQue.empty())
                    continue;//跳过本次循环体的剩余代码
                //2收养狗
                //2.a狗非空猫为空
                //2.b狗非空猫非空 队首狗的序列号小一点
                else if (catQue. empty() ||
                         !dogQue.empty() && !catQue.empty() && dogQue.front().seq < catQue.front().seq) {
                    cout << dogQue.front().num << ' ';
                    dogQue.pop();
                } else {
                    cout << catQue.front().num << ' ';
                    catQue.pop();
                }
            }
            //领养狗
            else if (para == 1) {
                if (dogQue.empty())
                    continue;
                cout << dogQue.front().num << ' ';
                dogQue.pop();
            }
            //领养猫
            else{
                if (catQue.empty())
                    continue;
                cout << catQue.front().num << ' ';
                catQue.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}

/*
猫狗收容所

题目描述：
有家动物收容所只收留猫和狗，但有特殊的收养规则。收养人有两种收养方式：
第1种为直接收养所有动物中最早进入收容所的。
第2种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的。
给定一个操作序列代表所有事件。
若第一个元素为1，则代表有动物进入收容所。第二个元素为动物的编号，正数代表狗，负数代表猫。
若第一个元素为2，则代表有人收养动物。第二个元素若为0，则采取第一种收养方式；若为1，则指定收养狗；若为－1，则指定收养猫。
请按顺序输出收养动物的序列。
若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。

输入：
第一个是n，它代表操作序列的次数。接下来是n行，每行有两个值m和t，分别代表题目中操作的两个元素。

输出：
按顺序输出收养动物的序列，编号之间以空格间隔

样例输入：
6
1 1
1 -1
2 0
1 2
2 -1
2 1

样例输出：
1 -1 2
*/
