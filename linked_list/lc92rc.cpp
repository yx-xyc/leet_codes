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
    
ListNode *successor=nullptr;

ListNode* reverseN(ListNode* head, int n) {
    if (n==1){
        successor = head->next;
        return head;
    }
    ListNode *last = reverseN(head->next, n-1);
    head->next->next = head;
    head->next =successor;
    return last;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m==1){
        return reverseN(head, n);
    }
    head->next = reverseBetween(head->next, m-1,n-1);
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