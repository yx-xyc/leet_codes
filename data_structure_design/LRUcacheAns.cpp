#include<unordered_map>
#include<iostream>
using namespace std;

class Node{
    public:
    int key, value;
    Node *prev, *next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> hashMap;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!hashMap.count(key)){
            return -1;
        }
        Node* cur = hashMap[key];
        int value = cur->value;
        
        // deleting key-value in LRU cache
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        // updating same key-value in LRU cache
        cur->prev = tail->prev;
        cur->next =tail;
        tail->prev->next = cur;
        tail->prev = cur;
        
        // there is no need to change key's position in hashMap
        // as its address is same and only some links are changed
        return value;
    }
    
    void put(int key, int value) {
        if (hashMap.count(key)){
            Node *cur = hashMap[key];
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            cur->prev = tail->prev;
            cur->next =tail;
            tail->prev->next = cur;
            tail->prev = cur;

            cur->value = value;
            
            return;
        } 

        Node *newKey = new Node(key, value);
        if(hashMap.size() == capacity){
           hashMap.erase(head->next->key); // erases key value pair
           head->next->next->prev = head;
           head->next = head->next->next;
        }

        newKey->prev = tail->prev;
        newKey->next = tail;
        tail->prev->next = newKey;
        tail->prev = newKey;

        // updating hashMap
        hashMap[key] = newKey;
        return;
    }
    void printCache(){
        for (auto const& i : hashMap) {
            cout << i.first << "\t" << i.second->value << endl;
        }
        Node *ptr = head->next;
        while (ptr!=nullptr){
            cout << ptr->key << '\t' << ptr->value << '\t';
            ptr = ptr->next;
        }
        cout << endl << endl;
    }
};

int main(void){
    // LRUCache cache(2);
    // cache.put(1,1);
    // cache.printCache();
    // cache.put(2,2);
    // cache.printCache();
    // cache.put(3,3);
    // cache.printCache();
    // cache.put(1,4);
    // cache.printCache();

    LRUCache cache(2);
    cache.put(1,1);
    cache.printCache();
    cache.put(2,2);
    cache.printCache();
    cout << cache.get(1) << endl;
    cache.printCache();
    cache.put(3,3);
    cache.printCache();
    cout << cache.get(3) << endl;
    cache.printCache();
    cout << cache.get(2) << endl;
    cache.printCache();
    cache.put(1,4);
    cache.printCache();
    cout << cache.get(1) << endl;
    cache.printCache();
    return 0;
}