#include<string>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    const string SEP = ",";
    const string NONE = "NULL";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==nullptr){
            return "";
        }
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (cur==nullptr){
                res.append(NONE).append(SEP);
                continue;
            }
            res.append(to_string(cur->val)).append(SEP);
            q.push(cur->left);
            q.push(cur->right);
        }
        return res;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> nodes;
        queue<TreeNode*> q;
        string s;
        for (int i=0;i<data.size();i++){
            if (data[i]==','){
                nodes.push_back(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if (s.size()!=0) nodes.push_back(s);
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        q.push(root);
        for (int i=1; i<nodes.size();){
            TreeNode* parent = q.front();
            string left = nodes[i++];
            if (!(left==NONE)){
                parent->left = new TreeNode(stoi(left));
                q.push(parent->left);
            } else{
                parent->left = nullptr;
            }
            string right = nodes[i++];
            if (!(right==NONE)){
                parent->right = new TreeNode(stoi(right));
                q.push(parent->right);
            } else{
                parent->right = nullptr;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(void){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Codec ser, deser;
    string res = ser.serialize(root);
    cout << res << endl;
    deser.deserialize(res);
}