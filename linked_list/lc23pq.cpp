#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct comp {
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

priority_queue <ListNode*, vector<ListNode*>, comp> q;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    for (auto anode: lists){
        if (anode) q.push(anode);
    }
    ListNode *head = new ListNode();
    ListNode *tail = head;
    while (!q.empty()){
        ListNode *node = q.top();
        q.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next){
            q.push(node->next);
        }
    }
    return head->next;
}

int main(void){
    //[[1,4,5],[1,3,4],[2,6]]
    vector <int> list1 = { 1,4,5,123,435 }; 
    vector <int> list2 = { 1,3,4,21,1521 };
    vector <int> list3 = { 2,6,1234,213213 };
    ListNode *l1 = new ListNode(list1[0]);
    ListNode *dummy1 = l1;
    for (int i=1;i<list1.size();i++){
        ListNode* temp = new ListNode(list1[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }
    ListNode *l2 = new ListNode(list2[0]);
    dummy1 = l2;
    for (int i=1;i<list2.size();i++){
        ListNode* temp = new ListNode(list2[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }
    ListNode *l3 = new ListNode(list3[0]);
    dummy1 = l3;
    for (int i=1;i<list3.size();i++){
        ListNode* temp = new ListNode(list3[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }
    vector<ListNode*> ln = {l1, l2, l3};
    ListNode *l4 = mergeKLists(ln);
    ListNode *dummy = l4;
    while (dummy!=nullptr){
        cout << dummy->val;
        cout << endl;
        dummy = dummy->next;
    }
}