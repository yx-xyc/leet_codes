#include <vector>
#include<array>
#include <iostream>
#include <numeric>

using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> answer(n);
    for (auto& booking:bookings){
        answer[booking[0]-1] += booking[2];
        if (booking[1]<n){
            answer[booking[1]] -= booking[2];
        }
    }
    partial_sum(answer.begin(),answer.end(),answer.begin());
    return answer;
}

int main(void){
    int length = 5;
    // vector<vector<int>> updates = {{2,4,6}, {5,6,8}, {1,9,-4}};
    vector<vector<int>> bookings = {{1,2,10}, {2,3,20}, {2,5,25}};
    vector<int> answer = corpFlightBookings(bookings, length); 
    for (int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }
}