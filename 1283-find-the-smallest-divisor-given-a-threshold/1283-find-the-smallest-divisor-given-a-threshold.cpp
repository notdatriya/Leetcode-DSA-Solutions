class Solution {
public:
    
    int solve(int mid,vector<int>&nums,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
          int maxi=INT_MIN;
        // int mini=INT_MAX;
        for(auto i:nums){
            // mini=min(mini,i);
            maxi=max(maxi,i);
        }
        
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(solve(mid,nums,threshold)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return low;
    }
};