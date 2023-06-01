brute force approach is to use two nested loops. Time complexity-O(n^2) Space-O(1)
​
Better approach - use hash maps
we want sum equal to target, so for every element , will will check if the remaining no to make sum equal to target is present in map.If present return the indexes. If not , add element and its index to mapp.
time- O(nlogn)  as searching in map in O(logn) , in unordered map, in worst case its O(n)
space complexity-O(n)
​
If the qs says to return only yes or no whether or not the two numbers are present, we can also sort the array and then use the two pointer approach . low=0 and high-n-1.If the sum is less , low++ .if sum is greater,high --.if sum  equal target,return yes
time - O(nlogn)
space-O(1)
​