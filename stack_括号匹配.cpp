/*
stack<typename> myStack
.size（）大小
.push（）加入元素到栈当中压栈
.top（）获取栈顶元素的内容
.pop（）弹栈
.empty（）判断栈是否为空
*/
#include<iostream>
#include<stack>
using namespace std;

int main() {
    char buf[200];
    while (fgets(buf, 200, stdin) != NULL) {//读取一行
        string str = buf;
        str.pop_back(); //str去掉了fegts多读的一个换行符

        stack<unsigned> indexStack;//存储了左圆括号的下标
        string res;//保存输出的结果

        for (unsigned i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                indexStack.push(i);//把下标压栈
                res.push_back('$');//姑且认为这个左圆括号是非法的
            } else if (str[i] == ')') {
                if (indexStack.empty())
                    res.push_back('?');
                else {
                    res.push_back(' ');
                    res[indexStack.top()] = ' ';
                    indexStack.pop();
                }
            } else
                res.push_back(' ');
        }
        printf("%s\n%s\n", str.c_str(), res.c_str());
    }
}

/*
括号匹配

输出：
对每组输出数据，输出两行，
第一行包含原始输入字符，
第二行由＂＂＂？＂和空格组成，＂＂和＂？＂表示与之对应的左括号和右括号不能匹配

样例输入：
)(rttyy())sss)(

样例输出：
)(rttyy())sss)(
?            ?$
*/
