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
    if (head==nullptr||head->next==nullptr){
        return head;
    }
    ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

int main(void){
    vector<int> ll {1,2,3,4,5};
    ListNode *head = new ListNode();
    ListNode *dummy = head;
    for (int e:ll){
        dummy->next = new ListNode(e);
        dummy = dummy->next;
    }
    head = head->next;
    ListNode *reversed = reverseList(head);
    while (reversed!=nullptr){
        cout << reversed->val << '\t';
        reversed = reversed->next;
    }
}