#include <vector>
#include<array>
#include <iostream>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if (rows==0 || cols==0){ return; }
        preSum.resize(rows+1, vector<int>(cols+1));

        for (int i=1;i<rows+1;i++){
            for (int j=1;j<cols+1;j++){
                preSum[i][j] = preSum[i-1][j]+preSum[i][j-1]+matrix[i-1][j-1]-preSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        return preSum[row2][col2] - preSum[row2][col1] - preSum[row1][col2] + preSum[row1][col1];
    }

    void printPreSum(){
        for (int i=0;i<preSum.size();i++){
            for (int j=0;j<preSum[0].size();j++){
                cout << preSum[i][j] << '\t';
            }
            cout << endl;
        }
    }
private:
    vector<vector<int>> preSum; 
};

int main(void){
    vector<vector<int>> matrix1 = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}}; 
    NumMatrix *nm1 = new NumMatrix(matrix1);
    nm1->printPreSum();
    int sr = nm1->sumRegion(2,1,4,3);
    cout << sr << endl;
}