#include<vector>
#include<iostream>
#include<stack>
#include<array>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int length = temperatures.size();
    stack<int> stk;
    vector<int> result(length);
    for (int i=length-1;i>=0;i--){
        while(!stk.empty()&&temperatures[stk.top()]<=temperatures[i]){
            stk.pop();
        }
        result[i] = stk.empty() ? 0 : stk.top()-i;
        stk.push(i);
    }
    return result;
}

int main(void){
    vector<int> nums {73,74,75,71,69,76};
    vector<int> result = dailyTemperatures(nums);
    for (int n:result){
        cout << n << endl;
    }
}