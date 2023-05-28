brute force is- we can keep two pointers i.e., for every i =0 to n-2 we will check for j=i+1 to n ,we will store the difference , and keep a maxp variable to store the max profit.
This approach time complexity- O(n^2)
Space complexity-O(1)
​
Optimal solution is to keep a variable min to store the min number from 0 to i-1 as we are on ith index, we will store the difference of arr[i] -min and store the max diff in variable maxp.
Time Complexity-O(n)
Space complexity-O(1)