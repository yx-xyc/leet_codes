#include <vector>
#include<array>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size()-1;
    while (left < right){
        if ((numbers[left]+numbers[right])==target){
            return vector<int>{++left, ++right};
        } else if((numbers[left]+numbers[right])<target){
            left++;
        } else if((numbers[left]+numbers[right])>target){
            right--;
        }
    }
    return vector<int>{-1,-1};
}

int main(void){
    vector<int> list1 = {2, 7, 11, 15}; 
    vector<int> idxs = twoSum(list1, 9);
    for (int i=0;i<idxs.size();i++){
        cout << idxs[i];
    }
}