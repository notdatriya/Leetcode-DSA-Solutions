class Solution {
public:
    int solve(int n,int idx,vector<int>&dp){
        if(idx==0) return 1;
        if(idx<0)return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=solve(n,idx-1,dp)+solve(n,idx-2,dp);
    }
    int climbStairs(int n) {
        int idx=n;
        vector<int>dp(n+1,-1);
        return solve( n, idx,dp);
    }
};