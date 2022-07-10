#include<string>
#include<stack>
#include<iostream>
#include<deque>
using namespace std;

void printStk(stack<int> stk){
    cout << "Stack: ";
    while(!stk.empty()){
        cout << stk.top() << '\t';
        stk.pop();
    }
    cout << endl;
}

int helper(deque<char> &dq){
    char sign = '+';
    stack<int> stk;
    int num = 0;
    int pre;
    while (dq.size()>0){
        char c = dq.front();
        dq.pop_front();
        if (isdigit(c)){
            num = 10 * num + (c-'0');
        }
        if (c=='('){
            num = helper(dq);
        }
        if ((!isdigit(c)&&c!=' ')||dq.empty()||c==')'){
            switch(sign){
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre*num);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                    break;
            }
            sign = c;
            num = 0;
        }
        if (c==')') break;
    }
    int result = 0;
    while (!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    return result;
}

int calculate(string s) {
    deque<char> dq(s.begin(), s.end());
    return helper(dq);
}

int main(void){
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << calculate(" 2-1 + 2 ") << endl;
    cout << calculate("1+1") << endl;
}