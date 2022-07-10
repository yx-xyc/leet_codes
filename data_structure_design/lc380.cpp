#include<vector>
#include<unordered_map>
#include<random>
#include<iostream>
using namespace std;
class RandomizedSet{
public:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    bool insert(int val){
        if(valToIndex.count(val)){
            return false;
        }
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    bool remove(int val){
        if (!valToIndex.count(val)){
            return false;
        }
        int index = valToIndex[val];
        valToIndex[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    int getRandom(){
        return nums[rand() % nums.size()];
    }
};
int main(void){
    RandomizedSet randomizedSet = RandomizedSet();
    cout << randomizedSet.insert(1) << endl; // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << randomizedSet.remove(2) << endl; // Returns false as 2 does not exist in the set.
    cout << randomizedSet.insert(2) << endl; // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << randomizedSet.getRandom() << endl; // getRandom() should return either 1 or 2 randomly.
    cout << randomizedSet.remove(1) << endl; // Removes 1 from the set, returns true. Set now contains [2].
    cout << randomizedSet.insert(2) << endl; // 2 was already in the set, so return false.
    cout << randomizedSet.getRandom() << endl; // Since 2 is the only number in the set, getRandom() will always return 2.
}