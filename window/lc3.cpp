#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int length=0,left=0,right=0;
    unordered_map<char,int> window;
    while(right<s.size()){
        char c=s[right];
        right++;
        window[c]++;
        while (window[c]>1){
            char d=s[left];
            left++;
            window[d]--;
        }
        if (right-left>length){
            length = right-left;
        }
    }   
    return length;
}

int main(void){
    string s = "bbbbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
}
