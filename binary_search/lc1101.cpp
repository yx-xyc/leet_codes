#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int getDays(vector<int> &weights, int capacity){
    int amount=0, days=0;
    for (int weight:weights){
        if (amount+weight<=capacity){
            amount += weight;
        }else{
            days++;
            amount = weight;
        }
    }
    return ++days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left=*max_element(weights.begin(), weights.begin()+weights.size());
    int right = accumulate(weights.begin(), weights.end(), 0), mid, needed_days;
    while(left<=right){
        mid = left+(right-left)/2;
        needed_days = getDays(weights, mid);
        if (needed_days<days){
            right = mid-1;
        } else if (needed_days>days){
            left = mid+1;
        } else if(needed_days==days){
            right = mid-1;
        }
    }
    return left;
}

int main(void){
    vector<int> weights {1,2,3,1,1};
    int days=5;
    // int max = *max_element(weights.begin(), weights.begin()+weights.size());
    // cout << *max_element(weights.begin(), weights.begin()+weights.size()) <<endl;
    // cout << getDays(weights, 2) << endl;
    // cout << getDays(weights, 3) << endl;
    cout << shipWithinDays(weights, 4) << endl;
}