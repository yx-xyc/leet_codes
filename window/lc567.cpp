#include<string>
#include<iostream>
#include<unordered_map>
#include <limits.h>
using namespace std;

// For main questions:
// 1. What to update when the right pointer move to right?
// 2. Under what condition should we move the left pointer?
// 3. What to update when we shrink the window?
// 4. For the final result, should it be updated when we expand window or shrink window?


bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char c:s1) need[c]++;
    int left=0, right=0, valid=0;
    while (right < s2.size()){
        char c=s2[right];
        right++;
        if(need.count(c)){
            window[c]++;
            if(window[c]==need[c]) valid++;
        }
        while (right-left>=s1.size()){
            if (valid == need.size()){
                return true;
            }
            char d=s2[left];
            left++;
            if (need.count(d)){
                if(window[d]==need[d]) valid--;
                window[d]--;
            }
        }
    }
    return false;
}

int main(void){
    string s = "ab";
    string t = "eidbaooo";
    bool result = checkInclusion(s, t);
    cout << result << endl;
}