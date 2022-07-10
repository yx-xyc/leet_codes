#include<string>
#include<iostream>
#include<stack>
using namespace std;

int minAddToMakeValid(string s) {
    int need=0,result=0;
    for (char c:s){
        if (c=='('){
            if (need%2==1){
                result++;
                need--;
            }
            need+=2;
        } else if (c==')'){
            need--;
        }
        if (need==-1){
            result++;
            need=1;
        }
    }
    return result+need;
}

int main(void){
    string s = "(()((()((";
    cout << minAddToMakeValid(s);
}