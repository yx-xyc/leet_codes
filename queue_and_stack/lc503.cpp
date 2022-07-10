#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int length = nums.size();
    stack<int> stk;
    for(int i=nums.size()-1;i>=0;i--)
        stk.push(nums[i]);
    vector<int> result(length);
    for (int i=length-1;i>=0;i--){
        while(!stk.empty()&&stk.top()<=nums[i%length]){
            stk.pop();
        }
        result[i%length] = stk.empty() ? -1 : stk.top();
        stk.push(nums[i%length]);
    }
    return result;
}

// vector<int> nextGreaterElements(vector<int>& nums) {
//     stack<int>s;
//     vector<int>ans;
//     for(int i=nums.size()-1;i>=0;i--)
//         s.push(nums[i]);
//     for(int i=nums.size()-1;i>=0;i--)
//     {
//         if(s.size()==0)
//             ans.push_back(-1);
//         else if(s.size()>0&&s.top()>nums[i])
//             ans.push_back(s.top());
//         else if(s.size()>0&&s.top()<=nums[i])
//         {
//             while(s.size()>0&&s.top()<=nums[i])
//                 s.pop();
//             if(s.size()==0)
//                 ans.push_back(-1);
//             else
//                 ans.push_back(s.top());
//         }
//         s.push(nums[i]);
//         for (int n:ans){
//             cout << n << '\t';
//         }
//         cout << endl;
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }

int main(void){
    vector<int> nums {4,5,3,1};
    vector<int> result = nextGreaterElements(nums);
    for (int n:result){
        cout << n << endl;
    }
}