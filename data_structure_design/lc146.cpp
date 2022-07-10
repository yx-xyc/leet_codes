#include<map>
#include<iostream>
using namespace std;

class Node{
public:
    int key, val;
    Node *next, *prev;
    Node(int k, int v){
        this->key = k;
        this->val = v;
    }
};

class DoubleList{
private:
    Node *head, *tail;
    int size;
public:
    DoubleList(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node *n){
        n->prev = tail->prev;
        n->next = tail;
        tail->prev->next = n;
        tail->prev = n;
        size++;
    }
    void remove(Node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
        size--;
    }
    Node* removeFirst(){
        if(head->next == tail) return nullptr;
        Node *first = head->next;
        remove(first);
        return first;
    }
    int getSize(){ return size; }
};

class LRUCache{
private:
    map<int, Node*> *hashMap;
    DoubleList *cache;
    int capacity;
    void makeRecently(int key){
        Node *n = hashMap->at(key);
        cache->remove(n);
        cache->addLast(n);
    }
    void addRecently(int key, int val){
        Node *n = new Node(key, val);
        cache->addLast(n);
        hashMap->insert(pair<int, Node*>(key, n));
    }
    void deleteKey(int key){
        Node *n = hashMap->at(key);
        cache->remove(n);
        hashMap->erase(key);
    }
    void removeLeastRecently(){
        Node *deletedNode = cache->removeFirst();
        int deletedKey = deletedNode->key;
        hashMap->erase(deletedKey);
    }
public:
    LRUCache(int capacity){
        this->capacity = capacity;
        hashMap =  new map<int, Node*>;
        cache = new DoubleList();
    }
    int get(int key){
        if (!hashMap->count(key)){
            return -1;
        }
        makeRecently(key);
        return hashMap->at(key)->val;
    }
    void put(int key, int val){
        if (hashMap->count(key)){
            deleteKey(key);
            addRecently(key, val);
            return;
        } else{
            if (capacity==cache->getSize()){
                removeLeastRecently();
            }
            addRecently(key, val);
        }
    }
};

int main(void){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout << cache.get(1) << endl;
    cache.put(3,3);
    cout << cache.get(3) << endl;
    cout << cache.get(2) << endl;
    cache.put(1,4);
    cout << cache.get(1) << endl;
    return 0;
}