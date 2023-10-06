class Solution {
public:
    int solve(int i,int target,vector<vector<int>>&dp){
        if(i==1){
            if(target==i){
                return i;
            }
            if(target==0){
                return 1;
            }
            return 1;
        }
        
        if(dp[i][target]!=-1)return dp[i][target];
        
        int notpick=1* solve(i-1,target,dp);
        int pick=1;
        if(i<=target){
            pick=i*solve(i,target-i,dp);
        }
        return dp[i][target]=max(pick,notpick);
    }
    int integerBreak(int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,dp);
    }
};