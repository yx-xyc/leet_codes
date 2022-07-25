void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
int partition(vector<int>& nums, int lo, int hi){
    int pivot = nums[lo];
    int i = lo+1, j = hi;
    while (i<=j){
        while (i<hi && nums[i]<=pivot){
            i++;
        }
        while (j>lo && nums[j]>pivot){
            j--;
        }
        if (i>=j){
            break;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[lo], nums[j]);
    return j;
}
int findKthLargest(vector<int>& nums, int k) {
    int rand;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,nums.size()-1);
    for (int i=0;i<nums.size();i++){
        rand = distribution(generator);
        swap(nums[i], nums[rand]);
    }
    int lo = 0, hi = nums.size()-1;
    k = nums.size()-k;
    while (lo <= hi){
        int p = partition(nums, lo, hi);
        if (p<k){
            lo = p+1;
        } else if (p>k){
            hi = p-1;
        } else {
            return nums[p];
        }
    }
    return -1;
}