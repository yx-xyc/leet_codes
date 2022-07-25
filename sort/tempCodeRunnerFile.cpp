int arr[100000]; //used to store the result using indices
// vector<int> countSmaller(vector<int>& nums) {
//     //we store the vector of pairs
//     //why we use pair , since we need to know the index of the element in the original array 
//     vector<pair<int,int>> pairs;
//     for(int i=0;i<nums.size();i++)
//     {   
//         // for each element in the nums vector, record the value and index
//         pairs.push_back({nums[i],i});
//     }
//     // merge sort the paris vector, and record the arr to store the result using indices
//     mergeSort(pairs,0,nums.size()-1);
//     // initialize the result array
//     vector<int> res(nums.size());
//     // add the result to result array
//     for(int i=0;i<nums.size();i++)
//     {
//         res[i]=arr[i];
//     }
//     return res;
// }
// void mergeSort(vector<pair<int,int>>& pairs,int low,int high)
// {
//     // split the input vector into two parts by middle
//     int mid=(low+high)/2;
//     // if the lower bound is still smaller than the higher bound
//     if(low<high)
//     {
//         //merge sort the smaller sub array
//         mergeSort(pairs,low,mid);
//         //merge sort the larger sub array
//         mergeSort(pairs,mid+1,high);
//         //merge them and calculate the result for every element
//         merge(pairs,low,mid+1,high);
//     }
// }

// void merge(vector<pair<int,int>>& pairs,int low,int mid,int high){
//     //mid is the starting element for the second array
//     int i=low;
//     int j=mid;
//     int count=0; //the number of elements smaller in the arr from mid to high
//     vector<pair<int,int>> temp(high-low+1);
//     int k=0;
//     while(i<=mid-1 && j<=high)
//     {
//         if(pairs[i].first<=pairs[j].first)
//         {
//             arr[pairs[i].second]+=count; //add the number of smaller elements
//             temp[k++]={pairs[i++]};
//         }
//         else{
//             //a smaller element found
//             count++;
//             temp[k++]={pairs[j++]};
//         }
//     }
//     //add the remaining first array element if left any
//     while(i<=mid-1)
//     {
//         arr[pairs[i].second]+=count; //add the number of smaller elements
//         temp[k++]={pairs[i++]}; 
//     }
//     //add the remaining second array elements if left any
//     while(j<=high)
//     {
//         temp[k++]={pairs[j++]};
//     }
//     //change the pairs to make it in sorted order 
//     for(int i=0;i<k;i++)
//     {
//         pairs[low++]=temp[i];
//     }
// }