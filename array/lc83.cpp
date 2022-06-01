#include <vector>
#include<array>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr or head->next == nullptr){ return head; }
    ListNode *fast = head, *slow = head;
    while (fast != nullptr){
        if (fast->val != slow->val){
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = nullptr;
    return head;
}

int main(void){
    ListNode* l1 = new ListNode();
    ListNode* dummy1 = l1;
    vector<int> list1 = {1, 1, 2, 3, 3}; 
    for (int i=0;i<list1.size();i++){
        dummy1->next = new ListNode(list1[i]);
        // cout << dummy1->next->val;
        // cout << endl;
        dummy1 = dummy1->next;
    }
    l1 = l1->next;
    ListNode *l = deleteDuplicates(l1);
    while (l != nullptr){
        cout << l->val;
        cout << endl;
        l = l->next;
    }
}