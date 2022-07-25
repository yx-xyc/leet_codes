#include<vector>
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

unordered_map<int, int>m;

TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int prel, int prer, int postl, int postr){
    if (prel>prer||postl>postr) return nullptr;
    TreeNode* root = new TreeNode(preorder[prel]);
    int leftRootVal = preorder[prel+1];
    int k = m[leftRootVal]-postl+1;
    root->left = helper(preorder, postorder, prel+1, prel+k-1, postl, postl+k-1);
    root-> right = helper(preorder, postorder, prel+k, prer, postl+k, postr-1);
    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    m.clear();
    for (int i=0;i<n;i++){
        m[postorder[i]] = i;
    }
    return helper(preorder, postorder, 0, n-1, 0, n-1);
};

