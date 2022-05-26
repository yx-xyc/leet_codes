#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *pt1 = dummy;
    ListNode *pt2 = dummy;
    for (int i=0;i<n+1;i++){
        pt1 = pt1->next;
    }

    while (pt1 != nullptr){
        pt1 = pt1->next;
        pt2 = pt2->next;
    }

    pt2->next = pt2->next->next;

    if (pt2==dummy){
        return pt2->next;
    }
    return dummy->next;
}

// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode* pt1 = head;
//     ListNode* pt2 = head;
//     ListNode* pt3 = head;
//     int count = 0;
//     while (pt3 != nullptr){
//         count += 1;
//         pt3 = pt3->next;
//     }
//     if (count == n) {
//         return head->next;
//     }
//     for (int i=0;i<n;i++){
//         pt1 = pt1->next;
//         if (pt1 == nullptr){
//             return nullptr;
//         }
//     }
//     while (pt1->next != nullptr){
//         pt1 = pt1->next;
//         pt2 = pt2->next;
//     }
//     pt2->next = pt2->next->next;
//     return head;
// }

int main(void){
    ListNode* l1 = new ListNode();
    ListNode* dummy1 = l1;
    ListNode* dummy2 = l1;
    vector<int> list1 = {1, 2}; // {1, 0}, 1 / {1}, 1
    for (int i=0;i<list1.size();i++){
        dummy1->next = new ListNode(list1[i]);
        // cout << dummy1->val;
        dummy1 = dummy1->next;
    }
    dummy2 = dummy2->next;
    l1 = l1->next;
    ListNode *l = removeNthFromEnd(l1, 2);
    while (l != nullptr){
        cout << l->val;
        cout << endl;
        l = l->next;
    }
}
