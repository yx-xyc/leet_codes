#include <vector>
#include<array>
#include <iostream>
#include <numeric>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> stops(1001,0);
    for (auto& trip:trips){
        stops[trip[1]] += trip[0];
        stops[trip[2]] -= trip[0];
    }
    partial_sum(stops.begin(),stops.end(),stops.begin());
    for (auto n:stops){
        if (n>capacity){
            return false;
        }
    }
    return true;
}

int main(void){
    int length = 3;
    // vector<vector<int>> updates = {{2,4,6}, {5,6,8}, {1,9,-4}};
    vector<vector<int>> bookings = {{2,1,5}, {3,5,7}};
    bool answer = carPooling(bookings, length); 
    cout << answer << endl;
}