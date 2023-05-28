In brute force method ,we can use any sorting algolike merge sort
In better approach,
we can count the number of 0,1 and 2 and then simply update the values of indexes of array with 0,1,and 2;
​
In better approach, dutch national flag algo, we use three pointers, low,mid and high
We the element at mid index is 1, we will increment mid.
if the element at mid is 0, swap mid and element at low, and then increment both mid and low.
if the element is 2, swap mid and high element and decrement high.
At the end of the loop , we will get updated sorted array
​
time complexity- O(n) as in every iteration, we are sorting one element
space complexity- O(1) as there is no extra space