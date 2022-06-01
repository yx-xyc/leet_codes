#include<vector>
#include<iostream>
using namespace std;


void reverseString(vector<char>& s) {
    int left = 0, right = s.size()-1;
    char temp;
    while (left < right){
        temp = s[right];
        s[right] = s[left];
        s[left] = temp;
        ++left;
        --right;
    }
}
int main(void){
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for (auto& c:s){
        cout << c << endl;
    }
}