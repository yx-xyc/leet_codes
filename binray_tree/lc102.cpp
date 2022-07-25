#include<vector>
#include<queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root==nullptr) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int> component;
        for (int i=0;i<sz;i++){
            TreeNode *curr = q.front();
            component.push_back(curr->val);
            if (curr->left!=nullptr){
                q.push(curr->left);
            }
            if (curr->right!=nullptr){
                q.push(curr->right);
            }
        }
        res.push_back(component);
    }
    return res;
}