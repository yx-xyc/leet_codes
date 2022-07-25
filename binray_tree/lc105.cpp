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

// TreeNode* build(vector<int>& preorder, int preStart, vector<int>& inorder, int inStart, int inEnd){
//     if (inStart>inEnd){
//         return nullptr;
//     }
//     int rootVal = preorder[preStart];
//     TreeNode* root = new TreeNode(rootVal);
//     int index;
//     for (int i=inStart;i<=inEnd;i++){
//         if (inorder[i]==rootVal){
//             index = i;
//             break;
//         }
//     }
//     root->left = build(preorder, preStart+1, inorder, inStart, index-1);
//     root->right = build(preorder, index+1, inorder, index+1, inEnd);
//     return root;
// }
// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     return build(preorder, 0, inorder, 0, inorder.size()-1);
// }


// int preIdx; // record the index of current node value
// unordered_map<int,int> inIndexOf; // inorder index of a number

// TreeNode* helper (vector<int>& preorder, vector<int>& inorder, int left, int right) {
//     // keep recursion only if the input interval is larger or equal to 0
//     if (left <= right) {
//         int inIdx = inIndexOf[preorder[preIdx]];
//         TreeNode *t = new TreeNode(inorder[inIdx]);
//         preIdx ++;
        
//         t->left = helper(preorder, inorder, left, inIdx-1);
//         t->right = helper(preorder, inorder, inIdx+1, right);
//         return t;
//     }
//     else return nullptr;
// }

// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     // initialize the int to record node value
//     preIdx = 0;
//     inIndexOf.clear();
//     // initialize the hashmap to record the index of a given value in inorder vector
//     int n = preorder.size();
//     for (int i=0 ; i<n ; i++)
//         inIndexOf[inorder[i]] = i;
//     // start recursion
//     return helper(preorder, inorder, 0, n-1);
// }

unordered_map<int,int> inIndexOf; // inorder index of a number

TreeNode* helper (vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
    // keep recursion only if the input interval is larger or equal to 0
    if (il>ir || pl>pr) return nullptr;
    
    int k = inIndexOf[preorder[pl]] - il;
    TreeNode* t = new TreeNode(preorder[pl]);

    t->left = helper(preorder, inorder, pl+1, pl+k, il, il+k-1);
    t->right = helper(preorder, inorder, pl+k+1, pr, il+k+1, ir);
    return t;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // initialize the int to record node value
    int n = preorder.size();
    inIndexOf.clear();
    // initialize the hashmap to record the index of a given value in inorder vector
    for (int i=0 ; i<n ; i++)
        inIndexOf[inorder[i]] = i;
    // start recursion
    return helper(preorder, inorder, 0, n-1, 0, n-1);
}