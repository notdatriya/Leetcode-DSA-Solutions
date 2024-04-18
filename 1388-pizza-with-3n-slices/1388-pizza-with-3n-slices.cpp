class Solution {
public:
    
    int solve(int idx,int end,vector<int>&slices,int k,vector<vector<int>>&dp){
        
        if(idx>end || k==0)return 0;
        
        if(dp[idx][k]!=-1)return dp[idx][k];
        
        int take=slices[idx]+solve(idx+2,end,slices,k-1,dp);
        int nottake=solve(idx+1,end,slices,k,dp);
        
        return dp[idx][k]=max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        
        int n=slices.size();
        
        vector<vector<int>>dp1(n,vector<int>(n+1,-1));
        vector<vector<int>>dp2(n,vector<int>(n+1,-1));
        
        int case1=solve(0,n-2,slices,n/3,dp1);
        int case2=solve(1,n-1,slices,n/3,dp2);
        
        return max(case1,case2);
        
    }
};