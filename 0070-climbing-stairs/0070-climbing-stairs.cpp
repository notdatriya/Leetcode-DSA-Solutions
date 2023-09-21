class Solution {
public:
    // int solve(int n,int idx,vector<int>&dp){
    //     if(idx==0) return 1;
    //     if(idx==1)return 1;
    //     if(dp[idx]!=-1) return dp[idx];
    //     return dp[idx]=solve(n,idx-1,dp)+solve(n,idx-2,dp);
    // }
    int climbStairs(int n) {
        // int idx=n;
        // vector<int>dp(n+1,-1);
        // return solve( n, idx,dp);
        
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1];
                dp[i]+=dp[i-2];

        }
        return dp[n];
        
    }
};