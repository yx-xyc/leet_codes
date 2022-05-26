#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *l1 = headA, *l2 = headB;
    while (l1!=nullptr){
        l1 = l1->next;
        lenA++;
    }
    while (l2!=nullptr){
        l2 = l2->next;
        lenB++;
    }
    l1 = headA;
    l2 = headB;

    if (lenA>lenB){
        for (int i=0;i<(lenA-lenB);i++){
            l1 = l1->next;
        }
    } else {
        for (int i=0;i<(lenB-lenA);i++){
            l2 = l2->next;
        }
    }
    while (l1!=l2){
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1;
}

int main(void){
    ListNode *dummy1 = new ListNode();
    ListNode *dummy2 = new ListNode();
    ListNode *l1 = dummy1, *l2 = dummy2, *marker = dummy1;

    vector<int> list1 = {4, 1, 8, 4, 5};
    vector<int> list2 = {5, 6, 1};
    for (int i=0;i<list1.size();i++){
        dummy1->next = new ListNode(list1[i]);
        dummy1 = dummy1->next;
    }
    for (int i=0;i<list2.size();i++){
        dummy2->next = new ListNode(list2[i]);
        dummy2 = dummy2->next;
    }
    marker = marker->next->next->next;
    dummy2->next = marker;
    // dummy1 = l1->next;
    // dummy2 = l2->next;
    // while(dummy1!=nullptr){
    //     cout << dummy1->val;
    //     cout << endl;
    //     dummy1 = dummy1->next;
    // }
    // cout << endl;
    // while(dummy2!=nullptr){
    //     cout << dummy2->val;
    //     cout << endl;
    //     dummy2 = dummy2->next;
    // }
    l1 = l1->next;
    l2 = l2->next;
    ListNode* result = getIntersectionNode(l1, l2);
    while (result != nullptr){
        cout << result->val;
        result = result->next;
    }
}