struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        int Diameter = leftMax + rightMax;
        maxDiameter = maxDiameter > Diameter ? maxDiameter : Diameter;
        return leftMax > rightMax ? leftMax+1 : rightMax+1;
    }
};
