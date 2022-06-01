#include <vector>
#include<array>
#include <iostream>
using namespace std;

void moveZeros(vector<int>& nums){
    int k;
    if (nums.size() == 0){ 
        k = 0; 
    } else{
        int slow=0, fast=0;
        for (int i=0;i<nums.size();i++){
            if (nums[fast]!=0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        k = slow;
    }
    for (int i=k;i<nums.size();i++){
        nums[i] = 0;
    }
}

int main(void){
    vector<int> list1 = {0,0,1,1,1,2,2,3,3,4}; 
    moveZeros(list1);
    for (int i=0;i<list1.size();i++){
        cout << list1[i];
    }
}