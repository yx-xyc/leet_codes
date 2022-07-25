# Segment Trees

What's the point of using segment trees?

It's a common situation that we need to query over a range of available data. It is a slow and tedious process, when the number of queries is large and repetitive. The segment Trees allow us to do the query in a logarithmic order of time.&#x20;

How to create a Segment Tree?

Assume data is in an array form `arr[]` of size `n`.

1. The root represent the entire interval, thus it should be `arr[0:n-1]`.
2. Each leaf is a range comprising of single element, thus, leaves are `arr[0]`, `arr[1]`, ... , `arr[n-1]`.
3. The internal nodes of the tree represent ht merged result of their children nodes. For node at index `i`, its two children would be at `(2i+1)` and `(2i+2)`.
4. Each of the children nodes could represent approximately half of the range represented by their parent.

