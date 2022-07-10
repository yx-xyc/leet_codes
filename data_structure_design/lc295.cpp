#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> large;
    priority_queue<int> small;
    MedianFinder() {}
    
    void addNum(int num) {
        if (small.size()<=large.size()){
            large.push(num);
            int smallest = large.top();
            large.pop();
            small.push(smallest);
        } else {
            small.push(num);
            int largest = small.top();
            small.pop();
            large.push(largest);
        }
    }
    
    double findMedian() {
        if (large.size()<small.size()){
            return small.top();
        } else if (large.size()>small.size()){
            return large.top();
        } else {
            return (large.top()+small.top())/2.0;
        }
    }

    void printNums(){
        priority_queue<int, vector<int>, greater<>> c_large = priority_queue(large);
        priority_queue<int> c_small =  priority_queue(small);
        while(!c_small.empty()){
            cout << c_small.top() << endl;
            c_small.pop();
        }
        cout << 't';
        while(!c_large.empty()){
            cout << c_large.top() << endl;
            c_large.pop();
        }
        cout << endl;
    }
};
int main(void){
    MedianFinder medianFinder =  MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.printNums();
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.printNums();
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.printNums();
    medianFinder.findMedian(); // return 2.0
}