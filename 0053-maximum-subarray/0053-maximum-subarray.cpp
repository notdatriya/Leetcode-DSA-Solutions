class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int currSum=0;
        int maxSum=INT_MIN;
        int n=nums.size();
        // int start=-1;
        // int ansSt=-1;
        // int ansEnd=-1;
        
        for(int i=0;i<n;i++){
            // if(currSum==0){
            //     start=i;
            // }
            currSum+=nums[i];
            
            if(currSum>maxSum){
            maxSum=currSum;
            }
            if(currSum<0){
                currSum=0;
            } 
            
             
                 // ansSt=start;
                 // ansEnd=i;
        }
        
       
        
        return maxSum;
    }
};