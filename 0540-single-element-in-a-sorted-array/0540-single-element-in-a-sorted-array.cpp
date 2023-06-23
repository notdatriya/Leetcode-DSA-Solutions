class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       //we will have left and right halves. The first element of the right half will be the
        //number we want to find .So to find the break point
        //we can observe that in the left half 1st instance of the number is in the even position index and second instance is at odd, and it is opposite for right half because of the one occurence of that number
        
        //we will check if we are in the left half,by checking the other instance of the jumber we are standing. any even number xor with 1 gives next odd instance and any odd number xor with 1 gives its prev even instance.
        
        //left half- 1st instance-even index
        //2nd index-odd index
     //the number can also be the last number, so we will keep h on n-2;   
        
        int low=0;
        int high=nums.size()-2;
        
        while(low<=high){
            int mid=low+high>>1;  //divide by 2
            
            if(nums[mid]==nums[mid^1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return nums[low];
    }
};