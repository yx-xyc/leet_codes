#include<unordered_map>
#include<list>
#include<iostream>
#include<typeinfo>
using namespace std;

struct Node{
    // Node structure, each node has three fields which are key, value, and frequency
    int key, val, freq;
    Node(int _key, int _val, int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache{
public:
    int minFreq, capacity;
    // record the minFrequency among all nodes and the capacity of the cache
    unordered_map<int, list<Node>::iterator> keyTable;
    // keyTable
    // key: key of each node
    // value: an iterator in the Node list corresponding to the key
    unordered_map<int, list<Node>> freqTable;
    // freqTable
    // key: an freq value
    // value: a list of Node
    LFUCache(int _capacity){
        minFreq = 0;
        capacity = _capacity;
        keyTable.clear(); // make sure the map is empty
        freqTable.clear();
    }
    int get(int key){
        if (capacity==0) return -1;
        // if capacity is 0, simply return -1
        auto iter = keyTable.find(key);
        // try to find the key in keyTable (a hashmap iterator is returned)
        if (iter==keyTable.end()) return -1;
        // if not find return -1
        
        list<Node>::iterator node = iter->second;
        // the second value of the hashmap iterator would be the node we want to find
        int val = node->val;
        int freq = node->freq;
        // get the val and frequency
        
        freqTable[freq].erase(node);
        // delete this node from the original frequency list
        if (freqTable[freq].size()==0){
            // if there is no node left in the original frequency list delete the list
            freqTable.erase(freq);
            if (minFreq==freq) minFreq++;
            // if this list is indicating the minFreq, make minFreq plus 1, for this get request
        }
        freqTable[freq+1].push_front(Node(key, val, freq+1));
        // add the node to the plus 1 frequency list

        keyTable[key] = freqTable[freq+1].begin();
        // update the node iterator value in the key table of this node
        return val;
    }
    void put(int key, int value){
        if (capacity==0) return;
        // if the capacity is 0, simply return nothing
        auto iter = keyTable.find(key);
        // try to find the key in the keyTable
        if (iter==keyTable.end()){
            // if nothing find, a new node need to be added
            if (keyTable.size()==capacity){
                // if the the cache is full, the least frequent node needed to be deleted
                auto nodeToDelete = freqTable[minFreq].back();
                // get the node that is going to be deleted
                keyTable.erase(nodeToDelete.key);
                // delete the node in the keyTable
                freqTable[minFreq].pop_back();
                // delete the node in the freqTable
                if (freqTable[minFreq].size()==0){
                    // if the delete this node makes that frequency list empty, also delete list
                    freqTable.erase(minFreq);
                    // no need to worry about minFreq, because a new node is added, the minFreq would always be 1
                }
            }
            freqTable[1].push_front(Node(key, value, 1));
            // add the new node to the frequency table with frequency 1 and push to front to make it the latest node in the list
            keyTable[key] = freqTable[1].begin();
            // add the node iterator to the keyTable
            minFreq = 1;
            // set the minFreq to 1
        } else {
            // if the node is found, only need to update the node's value and frequency
            list<Node>::iterator node = iter->second;
            // get the node iterator
            int freq = node->freq;
            // get the frequency
            freqTable[freq].erase(node);
            // delete this node from its original frequency node list
            if (freqTable[freq].size()==0){
                // if the deletion makes the list empty, also delete the list
                freqTable.erase(freq);
                if (minFreq==freq) minFreq++;
                // the minFreq would be plus 1 for this put cache visit
            }
            freqTable[freq+1].push_front(Node(key, value, freq+1));
            // add the target node to the front of the plus 1 frequency list
            keyTable[key] = freqTable[freq+1].begin();
            // update the node iterator value in the keyTable
        }
    }
};

int main(void){
    LFUCache lfu =  LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3
    cout << lfu.keyTable.find(4)->first << typeid(lfu.keyTable.find(4)).name() << endl;
}