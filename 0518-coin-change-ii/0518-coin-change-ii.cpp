class Solution {
public:
    int solve(int i,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(target % coins[0]==0)return 1;
            if(target==0 )return 1;
            return 0;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        int notpick=solve(i-1,target,coins,dp);
        int pick=0;
        if(coins[i]<=target){
        pick=solve(i,target-coins[i],coins,dp);
        }
        return dp[i][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        return ans;
    }
};