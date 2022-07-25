class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() 
        : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) 
        : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (root==nullptr){
        return nullptr;
    }
    traverse(root->left, root->right);
    return root;
}

void traverse(Node *node1, Node *node2){
    if (node1==nullptr||node2==nullptr){
        return;
    }
    node1->next = node2;
    traverse(node1->left, node1->right);
    traverse(node1->right, node2->left);
    traverse(node2->left, node2->right);
}