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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* p=nullptr;
    if(list1==nullptr)
        return list2;
    else if(list2==nullptr)
        return list1;
    if(list1->val<=list2->val){
        p=list1;
        p->next=mergeTwoLists(list1->next,list2);
    } else {
        p=list2;
        p->next=mergeTwoLists(list1,list2->next);
    }
    return p;
}

ListNode* merge(vector <ListNode*>& lists,  int l, int r){
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size() - 1);
}

int main(void){
    //[[1,4,5],[1,3,4],[2,6]]
    int list1 [3] = { 1,4,5 }; 
    int list2 [3] = { 1,3,4};
    int list3 [2] = { 2,6};
    ListNode *l1 = new ListNode(list1[0]);
    ListNode *dummy1 = l1;
    for (int i=1;i<3;i++){
        ListNode* temp = new ListNode(list1[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }
    ListNode *l2 = new ListNode(list2[0]);
    dummy1 = l2;
    for (int i=1;i<3;i++){
        ListNode* temp = new ListNode(list2[i]);
        dummy1->next = temp;
        dummy1 = dummy1->next;
    }
    ListNode *l3 = new ListNode(list3[0]);
    dummy1 = l3;
    for (int i=1;i<2;i++){
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