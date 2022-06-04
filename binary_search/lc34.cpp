#include<vector>
#include<iostream>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int left_bound, right_bound, mid;
    int left=0, right=nums.size()-1;
    while (left<=right){
        mid = left+(right-left)/2;
        // cout << mid << endl;
        if (nums[mid]<target){
            left = mid+1;
        } else if(nums[mid]>target){
            right = mid-1;
        } else if(nums[mid]==target){
            right = mid-1;
        }
        // cout << left << '\t' << right << '\t' << nums[mid] << endl;
    }
    if (left>=nums.size()||nums[left]!=target){
        left_bound = -1;
    }else{
        left_bound = left;
    }
    left=0, right=nums.size()-1;
    while (left<=right){
        mid = left+(right-left)/2;
        // cout << mid << endl;
        if (nums[mid]<target){
            left = mid+1;
        } else if(nums[mid]>target){
            right = mid-1;
        } else if(nums[mid]==target){
            left = mid+1;
        }
        // cout << left << '\t' << right << '\t' << nums[mid] << endl;
    }
    if (right<0||nums[right]!=target){
        right_bound = -1;
    }else{
        right_bound = right;
    }
    return vector<int>{left_bound, right_bound};
}

int main(void){
    vector<int> nums {5,7,7,8,8,10};
    vector<int> result = searchRange(nums, 8);
    for (int i:result){
        cout << i << endl;
    }
}