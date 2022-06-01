#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int romanToInt(string s) {
    unordered_map<char, int> encoder = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int len = s.length();
    int rom = 0;
    for (int i=0;i<len-1;i++){
        if (encoder[s[i]]<encoder[s[i+1]]){
            rom -= encoder[s[i]];
        } else {
            rom += encoder[s[i]];
        }
    }
    rom += encoder[s[len-1]];
    return rom;
}
int main(void){
    string a = "MCMXCIV";
    cout << romanToInt(a);
    cout << endl;
}
