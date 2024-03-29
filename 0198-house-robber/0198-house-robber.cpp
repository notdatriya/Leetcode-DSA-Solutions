class Solution {
public:
    // int solve(int idx,vector<int>&nums,vector<int>&dp){
    //     if(idx==0)return nums[0];
    //     if(idx<0)return 0;
    //     if(dp[idx]!=-1)return dp[idx];
    //     int take=nums[idx]+solve(idx-2,nums,dp);
    //     int nottake=0+ solve(idx-1,nums,dp);
    //     return dp[idx]=max(take,nottake);
    // }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n,-1);
        // return solve(n-1,nums,dp);
        
        
        // vector<int>dp(n+1,-1);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int take=nums[i];
        //     if(i>1)take+=dp[i-2];
        //     int nottake=0+dp[i-1];
        //     dp[i]=max(take,nottake);
        // }
        // return dp[n-1];
        
        
        //space optimized
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
             int take=nums[i];
            if(i>1)take+=prev2;
            int nottake=0+prev;
            int curri=max(take,nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};