#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* third=nullptr;
    if(list1==nullptr)
        return list2;
    else if(list2==nullptr)
        return list1;
    
    if(list1->val<=list2->val)
    {
        third=list1;
        third->next=mergeTwoLists(list1->next,list2);
    }
    else
    {
        third=list2;
        third->next=mergeTwoLists(list1,list2->next);
    }
        return third;
}

int main(void){
    int foo [5] = { 2, 16, 40, 77, 100 }; 
    int bar [5] = { 3, 4, 5, 112, 344};
    int len = sizeof(foo)/sizeof(foo[0]);
    ListNode* l1 = new ListNode(foo[0]);
    ListNode *dummy1 = l1;
    ListNode *dummy2 = l1;

    for (int i=1;i<len;i++){
        ListNode* temp = new ListNode(foo[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }
    
    while (dummy2!=nullptr){
        cout << dummy2->val;
        cout << endl;
        dummy2 = dummy2->next;
    }

    ListNode* l2 = new ListNode(bar[0]);
    dummy1 = l2;
    dummy2 = l2;

    for (int i=1;i<len;i++){
        ListNode* temp = new ListNode(bar[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }

    while (dummy2!=nullptr){
        cout << dummy2->val;
        cout << endl;
        dummy2 = dummy2->next;
    }

    ListNode* l3 = mergeTwoLists(l1, l2);
    dummy2 = l3;

    while (dummy2!=nullptr){
        cout << dummy2->val;
        cout << endl;
        dummy2 = dummy2->next;
    }
}