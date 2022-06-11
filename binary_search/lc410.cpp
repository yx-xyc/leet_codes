#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int getSubArrayNum(vector<int>& nums, int maxSum){
    long long sum=0,count=1;
    for (int num:nums){
        if (sum+num<=maxSum){
            sum+=num;
        }else{
            sum=num;
            ++count;
        }
    }
    return count;
}

int splitArray(vector<int>& nums, int m) {
    long long left = *max_element(nums.begin(), nums.begin()+nums.size());
    long long right = accumulate(nums.begin(), nums.end(), 0);
    int mid, subArrayNum;
    while (left<=right){
        mid = left + (right - left) / 2;
        subArrayNum = getSubArrayNum(nums, mid);
        if (subArrayNum>m){
            left = mid+1;
        }else if(subArrayNum<m){
            right = mid-1;
        }else if(subArrayNum==m){
            right = mid-1;
        }
    }
    return left;
}

int main(void){
    vector<int> nums {7,2,5,10,8};
    int m=2;
    cout << splitArray(nums, 2);
}