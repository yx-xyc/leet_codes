#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head==nullptr){return nullptr;}
    if (head->next==nullptr){return head;}
    ListNode *pre=nullptr, *cur=head, *tmp=nullptr;
    while (cur!=nullptr){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head->next==nullptr){return head;}
    ListNode *m = head, *n = head, *tail, *last;
    while (left>2){
        m = m->next;
        left--;
    }
    while (right>1){
        n = n->next;
        right--;
    }
    tail = n->next;
    n->next = nullptr;
    if (left==1){
        last = reverseList(head);
        head->next = tail;
        return last;
    } else{
        last = reverseList(m->next);
        m->next->next = tail;
        m->next = last;
    }
    return head;
}

int main(void){
    vector<int> ll {3,5};
    ListNode *head = new ListNode();
    ListNode *dummy = head;
    for (int e:ll){
        dummy->next = new ListNode(e);
        dummy = dummy->next;
    }
    head = head->next;
    ListNode *reversed = reverseBetween(head, 1, 2);
    while (reversed!=nullptr){
        cout << reversed->val << '\t';
        reversed = reversed->next;
    }
}