The commented code is for finding the array with the largest sum;
We will use Kadane algoritm to find the largest sum, currentsum and maxsum , if the current sum is negative, we willl update currsum as 0 as this negative sum will only tend to decrease the overall sum value in the substring. Update the maxsum if current sum is greater than maximum sum.
Time complexity- O(n)
Space complexity- O(1)
