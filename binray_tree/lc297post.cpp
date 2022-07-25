#include<string>
#include<stack>
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
        serialize_helper(root->left, res);
        serialize_helper(root->right, res);
        res.append(to_string(root->val)).append(SEP);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<string> stk;
        string s;
        for (int i=0;i<data.size();i++){
            if (data[i]==','){
                stk.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if (s.size()!=0) stk.push(s);
        return deserialize_helper(stk);
    }
    TreeNode* deserialize_helper(stack<string> &q){
        if (q.empty()) return nullptr;
        string s = q.top();
        q.pop();
        if (s=="NULL") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->right = deserialize_helper(q);
        root->left = deserialize_helper(q);
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