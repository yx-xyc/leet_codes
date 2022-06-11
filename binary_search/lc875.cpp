#include<vector>
#include<iostream>

using namespace std;

int getHours(vector<int>& piles, int k){
    int time = 0;
    for (int i:piles){
        time += i/k;
        if (i%k!=0){
            time++;
        }
    }
    return time;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = 1000000000;
    while(left <= right){
        int mid = left + (right-left)/2;
        int hours = getHours(piles, mid);
        if (hours < h){
            right = mid - 1;
        } else if (hours > h){
            left = mid + 1;
        } else if (hours == h){
            right = mid -1;
        }
    }
    return left;
}

int main(void){
    vector<int> piles {30,11,23,4,20};
    int h = 8;
    cout << minEatingSpeed(piles, 5);
    return 0;
}