#include<vector>
#include<array>
#include <iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0){ return 0; }
    int slow=0, fast=0;
    for (int i=0;i<nums.size();i++){
        if (nums[fast]!=val){
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

int main(void){
    vector<int> list1 = {0,0,1,1,1,2,2,3,3,4}; 
    int k = removeElement(list1, 2);
    for (int i=0;i<list1.size();i++){
        cout << list1[i];
    }
}