#include<unordered_map>
#include<list>
#include<iostream>
using namespace std;
struct Node{
    int key, val, freq;
    Node *next;
    Node *prev;
    Node(int k, int v){
        key = k;
        val = v;
        freq = 1;
    }
};


class LFUCache{
    int cap;
    int size;
    int minFreq=0;
    unordered_map<int, list<Node>::iterator>keyToNode;
    unordered_map<int, list<Node>>freqToList;
public:
    LFUCache(int capacity){
        cap = capacity;
        size = 0;
    }
    int get(int key){

    }
    void put(int key, int val){
    
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

    LFUCache cache(2);
    cache.put(1,1);
    // cache.printCache();
    cache.put(2,2);
    // cache.printCache();
    cout << cache.get(1) << endl;
    // cache.printCache();
    cache.put(3,3);
    // cache.printCache();
    cout << cache.get(3) << endl;
    // cache.printCache();
    cout << cache.get(2) << endl;
    // cache.printCache();
    cache.put(1,4);
    // cache.printCache();
    cout << cache.get(1) << endl;
    // cache.printCache();
    return 0;
}