#include<vector>
#include<list>
#include<iostream>
#include<deque>

using namespace std;

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;
//     deque<signed int> dq;
//     for (int i=0;i<nums.size();i++){
//         while (!dq.empty()&&dq.back()<=nums[i]){
//             dq.pop_back();
//         }
//         dq.push_back(nums[i]);
//         if(i>=k-1){
//             result.push_back(dq.front());
//             if (dq.front()==nums[i-k+1]){ // this method is wrong because, it pop out element from dq by checking whether the front value is the same as the value of left window, however the value is repeatable, thus check by index is still a better solution.
//                 dq.pop_front();
//             }
//         } 
//     }
//     return result;
// }

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     deque<int>dq; //double ended queue
//     vector<int>ans;
//     for(int i=0;i<nums.size();i++){
//         //for each element in the dq
//         if(!dq.empty()&&dq.front()==i-k){
//             //dq.front()==i-k means the cur index started to be larger than k and to maintain the window size, the first elem should be popped out
//             dq.pop_front();
//         }
//         //before add each elem, check the previous elem if the previous is smaller, popped out the previous one until there is a larger one. 
//         //in other words, only the elem that larger than the cur one would be kept, which is the max for this window
//         while(!dq.empty() && nums[dq.back()]<=nums[i]){
//             dq.pop_back();
//         }
//         //store the index of this num
//         dq.push_back(i);
//         if(i>=k-1){
//             //when i is larger than K, start to store result.
//             ans.push_back(nums[dq.front()]);
//         }
//     }
//     return ans;
// }

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<signed int> dq;
    for (int i=0;i<nums.size();i++){
        while (!dq.empty()&&nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            result.push_back(nums[dq.front()]);
            if (dq.front()==i-k+1){
                dq.pop_front();
            }
        } 
    }
    return result;
}

int main(void){
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int i:res){
        cout << i << endl;
    }
}