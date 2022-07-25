#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, 0, nums.size());
}
TreeNode* build(vector<int> &nums, int lo, int hi){
    if (lo>hi) return nullptr;
    int index = -1;
    int maxVal = -1;
    for (int i=lo;i<=hi;i++){
        if (maxVal<nums[i]){
            index = i;
            maxVal = nums[i];
        }
    }
    TreeNode *root = new TreeNode(maxVal);
    root->left = build(nums, lo, index-1);
    root->right = build(nums, index+1, hi);
    return root;
}