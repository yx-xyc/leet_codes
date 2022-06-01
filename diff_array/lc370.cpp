#include <vector>
#include<array>
#include <iostream>

using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> modifyArray(length), modifiedArray(length);
    for (int i=0;i<updates.size();i++){
        modifyArray[updates[i][0]] += updates[i][2];
        if (updates[i][1] < length-1){
            modifyArray[updates[i][1]+1] -= updates[i][2];
        }
    }
    modifiedArray[0] = modifyArray[0];
    for (int j=1;j<length;j++){
        modifiedArray[j] = modifiedArray[j-1] + modifyArray[j];
    }
    return modifiedArray;
}

int main(void){
    int length = 5;
    // vector<vector<int>> updates = {{2,4,6}, {5,6,8}, {1,9,-4}};
    vector<vector<int>> updates = {{1,3,2}, {2,4,3}, {0,2,-2}};
    vector<int> modifiedArray = getModifiedArray(length, updates); 
    for (int i=0;i<modifiedArray.size();i++){
        cout << modifiedArray[i] << endl;
    }
}