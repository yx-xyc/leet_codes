#include <vector>
#include<array>
#include <iostream>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        preSum.resize(n+1);
        preSum[0] = 0;
        for (int i=0;i<nums.size();i++){
            preSum[i+1] = preSum[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1]-preSum[left];
    }
private:
    vector<int> preSum;
};

int main(void){
    vector<int> list1 = {1, 1, 2, 3, 3}; 
    NumArray *na1 = new NumArray(list1);
    int sr = na1->sumRange(0,4);
    cout << sr << endl;
}