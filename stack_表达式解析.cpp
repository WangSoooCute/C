#include <stack>
#include <string>
#include<iostream>
#include<cstdio>
#include <map>
using namespace std;

int main() {
    char buf[300];
    map<char, int> priority = {
        {'$', 0},
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2}
    };

    while (fgets(buf, 300, stdin) != NULL) {
        string expr = buf;
        expr.pop_back();
        expr.push_back('$');//补充一个虚拟的终止符
        
        string num="";//用来搜集单独的0-9以组成一个数
        stack<double> numstack;
        stack<char> operstack;

        for (unsigned i = 0; i < expr.size(); ++i) {
            if (expr[i] >= '0' && expr[i] <= '9')
                num.push_back(expr[i]);
            else if (expr[i] == ' ') {
                if (num != "") {
                    numstack.push(stod(num));//stod -> string to double
                    num = "";
                }
            }
            else {
                if (num != ""){
                    numstack.push(stod(num));
                    num="";
                }
                    
                //栈顶的优先级>=新来的运算符的优先级
                while (!operstack.empty() && priority[operstack.top()] >= priority[expr[i]]) {
                    char oper = operstack.top();
                    operstack.pop();
                    double rhs = numstack.top();
                    numstack.pop();
                    double lhs = numstack. top();
                    numstack.pop();
                    switch (oper) {
                        case '+':
                            numstack.push(lhs + rhs);
                            break;
                        case '-':
                            numstack.push(lhs - rhs);
                            break;
                        case '*':
                            numstack.push(lhs * rhs);
                            break;
                        case'/':
                            numstack.push(lhs / rhs);
                            break;
                    }
                }

                //所有比expr[i]优先级更高的运算符都计算过了
                operstack.push(expr[i]);
            }
        }

        cout<<numstack.top()<<endl;
    }
}
