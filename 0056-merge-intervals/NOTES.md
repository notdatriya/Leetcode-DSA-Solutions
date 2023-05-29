In brute force, we first sort the array, then by using two pointers, that is two for loops,
for every i that is for every array element, we will check for j=i+1 to n arrays, if agle array ka first element is less than equal to iss array ka last element, then merge kar denge,yani ki update kar denge start and end pointer.start end is pehle element ka first and last element.
phir next array ke liye check karenge, if that array is already merged in the answer, last element is less than ans back ka last element, to next array me badh jaayenge
time comp= O(nlogn)+O(2n) kyuki har element pe 2 baar iterate karre the 2 for loops me
​
optimized me - single loop me karenge, jaise code me hai, ki agar ans khali hai that is kuch compare karne ko nahi hai ya phir merge nahi kar skte, to naya array add kar denge, wrna merge kar denge.
time comp.- O(nlog(n)) +O(n)