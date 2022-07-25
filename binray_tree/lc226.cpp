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

TreeNode* invertTree(TreeNode* root) {
    if (root==nullptr){
        return nullptr;
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    invertTree(left);
    invertTree(right);
    TreeNode *temp = left;
    root->left = right;
    root->right = temp;
    return root;
}

void traverse(TreeNode* root){
    if (root==nullptr){
        return;
    }
    TreeNode *temp=root->left;
    root->left = root->right;
    root->right = temp;
    traverse(root->left);
    traverse(root->right);

}

TreeNode* invertTree(TreeNode* root){
    traverse(root);
    return root;
}

