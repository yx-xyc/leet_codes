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

ListNode* middleNode(ListNode* head) {
    ListNode *pt1, *pt2;
    pt1 = head;
    pt2 = head;
    while (pt1 != nullptr && pt1->next != nullptr){
        pt1 = pt1->next->next;
        pt2 = pt2->next;
    }
    return pt2;
}

int main(void){
    ListNode* l1 = new ListNode();
    ListNode* dummy1 = l1;
    ListNode* dummy2 = l1;
    vector<int> list1 = {1, 2, 3, 4, 5, 6}; 
    for (int i=0;i<list1.size();i++){
        dummy1->next = new ListNode(list1[i]);
        // cout << dummy1->next->val;
        // cout << endl;
        dummy1 = dummy1->next;
    }
    dummy2 = dummy2->next;
    l1 = l1->next;
    ListNode *l = middleNode(l1);
    while (l != nullptr){
        cout << l->val;
        cout << endl;
        l = l->next;
    }
}
