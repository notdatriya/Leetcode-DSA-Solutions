class Solution {
public:
    int solve(int idx,int prev_idx,vector<int>&nums,vector<vector<int>>&dp){
        //Recursion
//         int n=nums.size();
//         if(idx==n)return 0;
        
//         int len =0+ solve(idx+1,prev_idx,nums);   //not take
        
//         if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
//             len=max(len,1+ solve(idx+1,idx,nums));
//         }
        
//         return len;
        
        
        
        //memoization
                  int n=nums.size();

        if(idx==n)return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int len =0+ solve(idx+1,prev_idx,nums,dp);   //not take
        
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            len=max(len,1+ solve(idx+1,idx,nums,dp));
        }
        
        return dp[idx][prev_idx+1]=len;
        
        
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int idx=0;
        int prev_idx=-1;
          int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1)) ; // idx - 0 to n-1 and prev_idx is from -1 to n-1 so we will store by +1;
        return solve(idx,prev_idx,nums,dp);
        
    }
};