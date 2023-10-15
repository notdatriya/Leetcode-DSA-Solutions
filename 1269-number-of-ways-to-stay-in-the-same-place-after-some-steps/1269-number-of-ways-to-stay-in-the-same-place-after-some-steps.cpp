class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int steps,int &arrLen,vector<vector<int>>&dp){
        if(steps==0){
            if(i==0)return 1;
            return 0;
        }
        if(dp[i][steps]!=-1)return dp[i][steps];
        
        int ans=solve(i,steps-1,arrLen,dp)%mod;
        if(i>0){
         ans= (ans+ solve(i-1,steps-1,arrLen,dp))%mod; //left
            }
        if(i<arrLen-1){
        ans=(ans + solve(i+1,steps-1,arrLen,dp))%mod; //right
        }
        
        return dp[i][steps]=ans;
        
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps);
        vector<vector<int>>dp(arrLen+1,vector<int>(steps+1,-1));
        return solve(0,steps,arrLen,dp);
    }
};