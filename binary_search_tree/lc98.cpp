/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool helper(TreeNode * root , TreeNode * mini , TreeNode * maxi){
    if(root == NULL) return true;
    if((mini != NULL and root->val <= mini->val) or (maxi != NULL and root->val >= maxi->val))
        return false;
    return helper(root->left,mini,root) and helper(root->right,root,maxi);
}

bool isValidBST(TreeNode* root) {
    return helper(root,NULL,NULL);
}

TreeNode* pre;
bool isValidBST(TreeNode* root) {
    if (root==nullptr) return true;
    if (!isValidBST(root->left)) return false;
    if (pre && pre->val>=root->val) return false;
    pre = root;
    if (!isValidBST(root->right)) return false;
    return true;
}