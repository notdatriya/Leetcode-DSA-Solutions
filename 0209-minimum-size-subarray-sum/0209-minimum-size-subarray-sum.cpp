class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l=0;
        int r=0;
        int sum=0;
        int mini=INT_MAX;
        
        int n=nums.size();
        
        while(r<n){
            
            sum+=nums[r];
            
            while(sum>=target){
                mini=min(mini,r-l+1);
                sum-=nums[l];
                l++;
            }
            
            r++;
            
        }
        
        if(mini==INT_MAX)return 0;
        return mini;
    }
};