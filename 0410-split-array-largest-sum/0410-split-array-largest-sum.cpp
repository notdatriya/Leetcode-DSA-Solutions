class Solution {
public:
    
    int count_arr(int mid,vector<int>&nums,int k){
        int num=1;
        int arrsum=0;
        for(int i=0;i<nums.size();i++){
            if(arrsum+nums[i]<=mid){
                arrsum+=nums[i];
            }
            else{
                num++;
                arrsum=nums[i];
            }
        }
        return num;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        
        int low=maxi;
        int high=sum;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(count_arr(mid,nums,k)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return low;
    }
};