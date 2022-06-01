#include<vector>
#include<array>
#include<iostream>
#include<string>
using namespace std;

// This file use the strategy expand from center, check out methods dynamic programming and Manacher's Algorithm.

array<int,2> palindorme(string s, int l, int r){
    while(l>=0&&r<s.size()&&s[l]==s[r]){
        --l;++r;
    }
    return {++l,--r};
}

string longestPalindrome(string s) {
    int start=0, end=0;
    array<int, 2> oddP;
    array<int, 2> evenP;
    for (int i=0;i<s.size();i++){
        oddP = palindorme(s,i,i);
        evenP = palindorme(s,i,i+1);
        if (oddP[1]-oddP[0]>end-start){
            start = oddP[0];
            end = oddP[1];
        }
        if (evenP[1]-evenP[0]>end-start){
            start = evenP[0];
            end = evenP[1];
        }
    }
    return s.substr(start, end-start+1);
}

int main(void){
    string s = "babad";
    longestPalindrome(s);
    string palindorme = longestPalindrome(s);
    for(auto& c:palindorme){
        cout << c << endl;
    }
}
