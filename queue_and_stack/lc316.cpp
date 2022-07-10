#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<array>
#include <algorithm>
using namespace std;

// string removeDuplicateLetters(string s) {
//     stack<char> stk;
//     array<bool, 26> inStack = {false};
//     array<int, 26> count = {0};
//     for (auto &c:s){
//         count[c-'a']++;
//     }
//     for (auto &c:s){
//         count[c-'a']--;
//         if (inStack[c-'a']) continue;
//         while (!stk.empty()&&stk.top()>c){
//             if(count[stk.top()-'a']==0){
//                 break;
//             }
//             inStack[stk.top()-'a']=false;
//             stk.pop();
//         }
//         stk.push(c);
//         cout << c << endl;
//         inStack[c-'a'] = true;
//     }
//     string result;
//     while (!stk.empty()){
//         result += stk.top();
//         stk.pop();
//     }
//     reverse(result.begin(), result.end());
//     return result;
// }

string removeDuplicateLetters(string s) {
    // initialize the string to store the result that remove duplicate letters
    string result = "";
    // initialize the array that record whether the letter is contained in the result string
    array<bool,26> inResult={false};
    // initialize the array that record the number of occurrence of each letter
    array<int,26> count={0};
    // for each occurrence of char in the string, record the number of occurrence of each char
    for(char c: s){
        count[c - 'a']++;
    }
    // for each occurrence of char int the string
    // minus one in the frequency array for this occurrence
    // check whether this char has occurred before
    // if so 
    // skip this iteration 
    // if not, 
    // while 
    // the result string still contains value 
    // and the alphabetic value of the last char in the result 
    // and the last char would repeat in the later iteration
    // remove the last letter of the result string
    // add this char to the result string
    for(char ch: s){
        count[ch - 'a']--;
        if(inResult[ch - 'a'])
            continue;
        while(result.length() > 0 && result[result.length() - 1] > ch && count[result[result.length() - 1] - 'a'] > 0){
            inResult[result[result.length() - 1] - 'a'] = false;
            result.pop_back();
        } 
        inResult[ch - 'a'] = true;
        result.push_back(ch);
    } 
    return result;
}

int main(void){
    string s ("bcac");
    string result = removeDuplicateLetters(s);
    cout << result << endl;
}