#include<string>
#include<iostream>
#include<unordered_map>
#include <limits.h>
using namespace std;
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c:t) need[c]++;
    int left=0, right=0, valid=0;
    int start=0;
    int len = INT_MAX;
    while (right < s.size()){
        char c = s[right];
        right++;
        if (need.count(c)){
            window[c]++;
            if (window[c]==need[c]) valid++;
        }
        while (valid == need.size()){
            if (right - left < len){
                start = left;
                len = right -left;
            }
            char d = s[left];
            left ++;
            if (need.count(d)){
                if (window[d]==need[d]) valid--;
                window[d]--;
            }
        }
    }
    return len ==  INT_MAX ? "" : s.substr(start, len);
}

int main(void){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minWindow(s, t);
    for (char c:result){
        cout << c << endl;
    }
}

