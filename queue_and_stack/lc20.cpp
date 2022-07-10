#include<string>
#include<iostream>
#include<stack>
using namespace std;

char leftOf(char c){
    if (c==')'){
        return '(';
    } else if (c==']'){
        return '[';
    } else {
        return '{';
    }
}

bool isValid(string s) {
    stack<char> st;
    char left;
    for (char c:s){
        if (c=='('||c=='['||c=='{'){
            st.push(c);
        } else {
            left = leftOf(c);
            if (!st.empty()&&st.top()==left){
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main(void){
    string s = "()[]{}";
    cout << isValid(s);
}