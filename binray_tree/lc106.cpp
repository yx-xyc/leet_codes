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
// int postIdx;
// unordered_map<int, int> inIndexOf;
// TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int left, int right){
//     if (left<=right){
//         int idx = inIndexOf[postorder[postIdx]];
//         TreeNode *t = new TreeNode(postorder[postIdx]);
//         postIdx--;
//         t->left = helper(postorder, inorder, left, idx-1);
//         t->right = helper(postorder, inorder, idx+1, right);
//         return t;
//     } else {
//         return nullptr;
//     }
// }
// TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder){
//     postIdx = postorder.size()-1;
//     inIndexOf.clear();
//     for (int i=0; i<postorder.size();i++){
//         inIndexOf[inorder[i]] = i;
//     }
//     return helper(postorder, inorder, 0, postIdx);
// }

unordered_map<int, int> inIndexOf;
    
TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr){
    if (il>ir || pl>pr) return nullptr;
    int k = inIndexOf[postorder[pr]] - il;
    TreeNode* root = new TreeNode(postorder[pr]);
    root->left = helper(inorder, postorder, il, il+k-1, pl, pl+k-1);
    root->right = helper(inorder, postorder, il+k+1, ir, pl+k, pr-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    int n = postorder.size();
    inIndexOf.clear();
    for (int i=0; i<n;i++){
        inIndexOf[inorder[i]] = i;
    }
    return helper(inorder, postorder, 0, n-1, 0, n-1);
}