#include<iostream>
#include<vector>
#include<stdlib.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int nonBlack;
    unordered_map<int, int>nums;
    Solution(int n, vector<int>& blacklist) {
        nonBlack = n-blacklist.size();
        int last = n-1;
        for (int b:blacklist){
            nums[b] = -1;
        }
        for (int b:blacklist){
            if (b>=nonBlack){continue;}
            while (nums.count(last)){
                last--;
            }
            nums[b] = last;
            last--;
        }
    }
    int pick() {
        int index = rand() % nonBlack;
        if (nums.count(index)){
            return nums[index];
        } else{
            return index;
        }
    }
    void printNums(){
        for (auto &pair:nums){
            cout << pair.first << '\t' << pair.second << endl;
        }
    }
};
int main(void){
    vector<int> blacklist {2,3,5};
    Solution solution = Solution(7, blacklist);
    cout << solution.pick() << endl; // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                    // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
    cout << solution.pick() << endl; // return 4
    cout << solution.pick() << endl; // return 1
    cout << solution.pick() << endl; // return 6
    cout << solution.pick() << endl; // return 1
    cout << solution.pick() << endl; // return 0
    cout << solution.pick() << endl; // return 4
}