    int length = nums1.size();
    priority_queue<node, vector<node>, cmp> pq;
    for (int i=0;i<length;i++){
        pq.push(node(i,nums2[i]));
    }