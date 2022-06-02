#include<string>
#include<iostream>
#include<unordered_map>
#include <limits.h>
#include<vector>
using namespace std;

// For main questions:
// 1. What to update when the right pointer move to right?
// 2. Under what condition should we move the left pointer?
// 3. What to update when we shrink the window?
// 4. For the final result, should it be updated when we expand window or shrink window?

vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> needs, window;
    for (char c:p) needs[c]++;
    int left = 0, right = 0, valid = 0;
    vector<int> result;
    while (right<s.size()){
        char c = s[right];
        right++;
        if (needs.count(c)){
            window[c]++;
            if (needs[c]==window[c]) valid++;
        }
        while (right-left>=p.size()){
            if (valid==needs.size()){
                result.push_back(left);
            }
            char d=s[left];
            left++;
            if (needs.count(d)){
                if(window[d]==needs[d]) valid--;
                window[d]--;
            }
        }
    }
    return result;
}

int main(void){
    string s = "abab";
    string t = "ab";
    vector<int> result = findAnagrams(s, t);
    // for (int idx:result){
    //     cout << idx << endl;
    // }
    float a = (2+3)/2;
    cout << a << endl;
}