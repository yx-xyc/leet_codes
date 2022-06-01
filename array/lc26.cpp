#include <vector>
#include<array>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size()==0){return 0;}
    int slow = 0, fast = 0;
    while (fast<nums.size()){
        if (nums[fast]!=nums[slow]){
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow+1;
}
int main(void){
    vector<int> list1 = {0,0,1,1,1,2,2,3,3,4}; 
    vector<int> expectedNums = {0,1,2,3,4};
    int k = removeDuplicates(list1);
    for (int i=0;i<list1.size();i++){
        cout << list1[i];
    }
}