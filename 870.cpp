#include<vector>
#include<queue>
#include<iostream>
#include <algorithm>
using namespace std;

struct node{
    int idx, value;
    node(int idx, int value):idx(idx),value(value){}
};

struct cmp{
    bool operator() (node a, node b){
        return a.value<b.value;
    }
};


vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int length = nums1.size();
    priority_queue<node, vector<node>, cmp> pq;
    for (int i=0;i<length;i++){
        pq.push(node(i,nums2[i]));
    }
    sort(nums1.begin(), nums1.end());
    int left=0, right=length-1;
    int i, maxval;
    vector<int> result(length);
    while(!pq.empty()){
        node pair = pq.top();
        pq.pop();
        i = pair.idx;
        maxval = pair.value;
        if (maxval<nums1[right]){
            result[i]=nums1[right];
            right--;
        }else{
            result[i]=nums1[left];
            left++;
        }
    }
    return result;
}

int main(void){
    vector<int> nums1 {2,7,11,15};
    vector<int> nums2 {1,10,4,11};
    // advantageCount(nums1, nums2);
    vector<int> result = advantageCount(nums1, nums2);
    for (int n:result){
        cout << n << endl;
    }
}