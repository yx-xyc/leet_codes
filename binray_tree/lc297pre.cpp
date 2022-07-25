#include<string>
#include<queue>
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
        string res;
        serialize_helper(root, res);
        return res;
    }

    void serialize_helper(TreeNode* root, string& res){
        if (root==nullptr){
            res.append(NONE).append(SEP);
            return;
        }
        res.append(to_string(root->val)).append(SEP);
        serialize_helper(root->left, res);
        serialize_helper(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for (int i=0;i<data.size();i++){
            if (data[i]==','){
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if (s.size()!=0) q.push(s);
        return deserialize_helper(q);
    }
    TreeNode* deserialize_helper(queue<string> &q){
        if (q.empty()) return nullptr;
        string s = q.front();
        q.pop();
        if (s=="NULL") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deserialize_helper(q);
        root->right = deserialize_helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(void){
    vector<int> nodes {1,2,3,4,5};
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