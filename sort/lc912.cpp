#include<vector>

using namespace std;

// bubbleSort(nums);
void bubbleSort(vector<int>& nums){
    // for each num in the vector in backward order
    for(int i = nums.size() - 1; i >= 0; i--)
        // for each other num that is in front of the num of that loop in forward order
        for(int j = 0; j < i; j++)
            // compare the other num and the next num, arrange them in increasing order
            if(nums[j] > nums[j + 1]) 
                swap(nums[j], nums[j + 1]);
}

// insertionSort(nums);
void insertionSort(vector<int>& nums){
    // if there is no element or only one element in the vector, no need to sort
    if(nums.size() == 0 || nums.size() == 1) return;
    // for all the element that is after the first one
    for(int i = 1; i < nums.size(); i++){
        // let the element be the tmp
        int tmp = nums[i];
        // get the index of the last element
        int j = i - 1;
        // while there is previous element that is larger than tmp
        // put the larger one at the back position
        while(j >= 0 && nums[j] > tmp){
            nums[j + 1] = nums[j];
            j--;
        }
        // when nums[j] <= tmp, assign tmp to nums[j+1]
        nums[j + 1] = tmp;
    }
}

// heapSort
void siftDown(vector<int>& nums, int n, int i){
    int biggest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && nums[biggest] < nums[l])
        biggest = l;
    if(r < n && nums[biggest] < nums[r])
        biggest = r;
    if(biggest != i){
        swap(nums[i], nums[biggest]);
        siftDown(nums, n, biggest);
    }
}

// heapSort(nums);
void heapSort(vector<int>& nums){
    // heapify stage (bottom up approach)
    for(int i = nums.size() / 2 - 1; i >= 0; i--)
        siftDown(nums, nums.size(), i);
    // sorting stage
    for(int i = nums.size() - 1; i > 0; i--){
        swap(nums[0], nums[i]);
        siftDown(nums, i, 0);
    }
}

// given a vector, its start point, mid point and the end point
void merge(vector<int>& nums, int l, int m, int r){
    // initialize a tmp vector with the same length from start point to the end point
    vector<int> tmp(r - l + 1);
    int i = l; // index for left subarray
    int j = m + 1; // index for right subarray
    int k = 0; // index for temporary array
    // when the left cursor is on the left of the mid point and the right cursor is at the left of the end point
    while(i <= m && j <= r){
        // if the value of the left cursor is smaller thant the right cursor
        // assign the value of the left cursor to the tmp vector, move the left cursor one step right
        if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
        // otherwise assign the value of the right cursor to the tmp vector, move the right cursor one step right
        else tmp[k++] = nums[j++];
    }
    // for the left element either in the left subarray or the right subarray, put these elements to the tmp array
    while(i <= m) tmp[k++] = nums[i++];
    while(j <= r) tmp[k++] = nums[j++]; 
    for(i = 0; i < k; i++) nums[l + i] = tmp[i];
}

// mergeSort(nums, 0, nums.size() - 1);
void mergeSort(vector<int>& nums, int l, int r){
    if(l >= r) return;
    int m = l + (r - l) / 2; //middle index, same as (l+r)/2
    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);
}

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

// quickSort(nums, 0, nums.size() - 1);
// given a vector with its start index and end index
void quickSort(vector<int>& nums, int l, int r){
    // base case if the start index is larger than the end index return
    if(l >= r) return;
    // record the first element as the pivot
    int i = l; // cursor for final pivot location 
    // loop through [start, end-1]
    for(int j = l; j <= r - 1; j++){ // nums[r] is chosen as the pivot
        // compare these elements and the pivot
        if(nums[j] <= nums[r]){
            // if the element is smaller than the pivot, put the smaller element at the front of the vector
            swap(nums[i], nums[j]);
            // after each swap i++, so that all the smaller equal elements to pivot go to the left of i
            i++; // smaller or equal elements go to the left of i 
        }
    }
    // swap the position of pivot and i, then we get the the sub array that is smaller than the pivot and the sub array that is larger than the pivot
    swap(nums[i], nums[r]); // after swap, the pivot is nums[i]
    quickSort(nums, l, i - 1);
    quickSort(nums, i + 1, r);
}
int partition(vector<int>& a,int L,int R,int key){
    int iL=L;
    int iR=R;
    while (iL<=iR)
    {
        while (a[iL]<key)iL++;
        while (a[iR]>key)iR--;
        if (iL<=iR)
        {
            int temp=a[iL];
            a[iL]=a[iR];
            a[iR]=temp;
            iL++;iR--;
        }
    }
    return iL;
}
void quickSort(vector<int>& a,int L,int R){
    if (L>=R)return;
    int n=(L+R)/2;
    int key=a[n];
    int k=partition(a,L,R,key);
    quickSort(a,L,k-1);
    quickSort(a,k,R);
}

vector<int> sortArray(vector<int>& a)
{
        quickSort(a,0,a.size()-1);
        return a;
}
