#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int pt1=0, pt2=0;
    double median;
    vector<int> total;
    while (pt1<nums1.size()||pt2<nums2.size()){
        if (pt1==nums1.size()){
            total.push_back(nums2[pt2]);
            pt2++;
        }
        else if (pt2==nums2.size()){
            total.push_back(nums1[pt1]);
            pt1++;
        }else{
            if (nums1[pt1]<nums2[pt2]){
                total.push_back(nums1[pt1]);
                pt1++;
            }else{
                total.push_back(nums2[pt2]);
                pt2++;
            }
        }
    }
    if ((nums1.size()+nums2.size())%2==1){
        median = (float)total[(nums1.size()+nums2.size()-1)/2];
    } else{
        median = (float)(total[(nums1.size()+nums2.size())/2]+total[(nums1.size()+nums2.size())/2-1])/2;
    }
    return median;
}