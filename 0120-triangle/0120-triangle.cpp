class Solution {
public:
    // int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    //     int m=triangle.size();
    //     if(i==m-1) return triangle[m-1][j];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int down=solve(i+1,j,triangle,dp);
    //     int dig=solve(i+1,j+1,triangle,dp);
    //     return dp[i][j]=triangle[i][j] + min(down,dig);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
         int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        // return solve(0,0,triangle,dp);
        
        //tabulation
        // for(int i=m-1;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         if(i==m-1){
        //             dp[i][j]=triangle[i][j];
        //             continue;
        //         }
        //         int down=dp[i+1][j];
        //         int dig=dp[i+1][j+1];
        //         dp[i][j]=triangle[i][j] +min(down,dig);
        //     }
        // }
        // return dp[0][0];
        
        //space-optimized
        vector<int>front(m,0);
        for(int i=m-1;i>=0;i--){
            vector<int>curr(m,0);
            for(int j=i;j>=0;j--){
                if(i==m-1){
                    curr[j]=triangle[i][j];
                    continue;
                }
                int down=front[j];
                int dig=front[j+1];
                curr[j]=triangle[i][j] +min(down,dig);
            }
            front=curr;
        }
        return front[0];
    }
};