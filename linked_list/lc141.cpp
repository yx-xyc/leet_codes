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

bool hasCycle(ListNode *head) {
    if (head == nullptr){
        return false;
    }
    ListNode *pt1, *pt2;
    pt1 = head;
    pt2 = head;
    while (pt1 != nullptr && pt1->next != nullptr){
        pt1 = pt1->next->next;
        pt2 = pt2->next;
        if (pt1==pt2){
            return true;
        }
    }
    return false;
}

int main(void){
    ListNode* l1 = new ListNode();
    ListNode* dummy1 = l1;
    ListNode* dummy2 = l1;
    vector<int> list1 = {1}; 
    for (int i=0;i<list1.size();i++){
        dummy1->next = new ListNode(list1[i]);
        dummy1 = dummy1->next;
    }
    // dummy2 = dummy2->next->next;
    // dummy1->next = dummy2;
    l1 = l1->next;
    cout << hasCycle(l1);
}