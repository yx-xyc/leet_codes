#include<array>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxSum = 0;
int maxSumBST(TreeNode* root) {
    traverse(root);
    return maxSum;
}
array<int,4> traverse(TreeNode* root){
    // base case: if the root is nullptr, return a array {1,40000,-40000,0}
    if (root==nullptr){
        return array<int,4> {1, 40000, -40000, 0};
    }
    // traverse left and right tree
    array<int,4> left = traverse(root->left);
    array<int,4> right = traverse(root->right);
    // postorder position
    // initialize res array for current node
    // res[0] whether the tree use this node as root is a BST
    // res[1] the minumum value in the BST use this node as root
    // res[2] the maximum value in ths BST use this node as root
    // res[3] the sum of nodes value that is in the BST use this node as root
    array<int,4> res;
    // if both the left tree and the right tree are BST
    // the val of current node is larger than the maximum value of the left subtree
    // the val of current node is smaller than the minumum value of the right subtree
    if (left[0]==1 && right[0]==1 && root->val>left[2] && root->val<right[1]){
        // the if conditions ar satisfied, it is a BST
        res[0]=1;
        // the comparison to determine min and max is needed for that 
        // if one side is a nullptr, min = 40000 > max = -40000
        res[1]=left[1]<root->val ? left[1] : root->val;
        res[2]=right[2]>root->val ? right[2] : root->val;
        // calculate sum
        res[3]=left[3]+right[3]+root->val;
        maxSum=maxSum>res[3] ? maxSum : res[3];
    } else {
        res[0] = 0;
    }
    return res;
}
