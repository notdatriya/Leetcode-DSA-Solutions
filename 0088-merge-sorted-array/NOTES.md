In the previous submission,
in the qs given is, nums1 is of length m+n, so we just added the elements of nums2 in the nums1 array and simply sort the array.
​
In the other approch where we assume nums1 is of size m only, we will compare, the last element of 1 array with 1st element of other array. If the first element is greater,then swap.Then after all the swapping,simply sort bot the arrays.
Time- O(min(m,n)) +mlogm +nlogn;
This show tle- commented code;
​
Another method gap method: Time complexity-O(log(m+n))+O(m+n)
Space Complexity-O(1)
​
In this gap method- first we will take gap as ceil value of m+n/2;
that is left value will always start from 0 and right will be gap steps ahead.
then we will compare the values, if left is greater, than swap. whenever one becomes n,
break,then again find gap that is gap/2 ka ceil. When gap becomes 1 , stop.
​
​
​