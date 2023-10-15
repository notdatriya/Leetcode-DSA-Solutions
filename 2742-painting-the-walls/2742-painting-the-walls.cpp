class Solution {
public:
     
    int solve(int i,int rem,vector<int>&cost,vector<int>&time,vector<vector<int>>&dp){
        //if rem walls becomes zero,that means free wale ne paint kardi, to cost zero
        if(rem<=0)return 0;
        if(i<0)return 1e9;
        if(dp[i][rem]!=-1)return dp[i][rem];
        int notpick= solve(i-1,rem,cost,time,dp);
        int pick= cost[i] + solve(i-1,rem-1-time[i],cost,time,dp);
        return dp[i][rem]=min(pick,notpick);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,cost, time,dp);
    }
};