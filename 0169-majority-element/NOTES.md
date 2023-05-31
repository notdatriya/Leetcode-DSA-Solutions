brute force- take two pinters, for every element,check the count and if the count is greate than n/2,return; time-O(n^2) space O(1)
​
better- hash maps- to store the frequency and then iterate over the map to find the largest freq,if its >n/2 return.Time(O(nlogn)+O(n) Space - O(n)
Another methid can be to sort the array and then finding the count
​
optimal- Moose voting algo
consider element as first element, count=0, iterate, if arr[i[=element,count++;
if not count--. if count becomes=0;element =next elemetn and count=1;
This algo this on the intuition that if an element exists more than n/2 times,then it will not get completely cancelled out.Then we can check if their exists a majority element.
time-O(n) space O(1)
​