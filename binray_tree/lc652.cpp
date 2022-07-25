#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<string, int> m;
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> res;
    traverse(res, root);
    return res;
}

string traverse(vector<TreeNode*>& res, TreeNode* root){
    if (root==nullptr){
        return "#";
    }
    string left = traverse(res, root->left);
    string right = traverse(res, root->right);
    string subTree = left+","+right+","+to_string(root->val);
    if (!m.count(subTree)){
        m[subTree] = 1;
    } else if(m[subTree]==1){
        m[subTree] += 1;
        res.push_back(root);
    }
    return subTree;
}