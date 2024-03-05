class Solution {
public:
      int solve(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(nums[idx]==0)return INT_MAX;
        
        if(dp[idx]!=-1)return dp[idx];
        
          int mini=INT_MAX;
        for(int i=1;i<=nums[idx];i++){
                int temp=solve(idx+i,nums,dp);
            if(temp!=INT_MAX){
               mini=min(mini,temp+1);
            }
        }
        return dp[idx]=mini;
        
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};