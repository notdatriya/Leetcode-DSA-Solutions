class Solution {
public:
    
   
    int findKthPositive(vector<int>& arr, int k) {
        
        int low=0;
        int high=arr.size()-1 ;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing= arr[mid]-(mid+1);
            
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
           
        }
        
        
        //after completing the while loop, the high will be pointing to the lower number and the low will be pointing to the higher number in therange in which the answer is lying
        
        //we will return arr[high]+more         // more= k - missing
                                                 // missing =arr[high]-(high+1);
        
        // ans= arr[high] + more
        // ans= arr[high] + (k-arr[high]+(high+1))
        //ans=(k+high+1);
        //ans=low+k
        return high + 1+ k;
    }
};