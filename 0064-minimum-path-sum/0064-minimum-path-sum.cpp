class Solution {
public:
//     int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>dp){
//         if(i==0 && j==0)return grid[0][0];
//         if(i<0 || j<0) return INT_MAX;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=solve(i-1,j,grid,dp);
//         int left=solve(i,j-1,grid,dp);
//         return dp[i][j]=min(up,left)+grid[i][j];
        
//     }
        
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
         // return solve(m-1,n-1,grid,dp);
        
        // //tabulation
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0){
//                     dp[i][j]=grid[0][0];
//                     continue;
//                 }
//                 int up=0;
//                 int left=0;
//                 if(i>0)up=dp[i-1][j];
//                 else up=INT_MAX;
//                 if(j>0)left=dp[i][j-1];
//                 else left=INT_MAX;
                
//                 dp[i][j]=grid[i][j] +min(up,left);
                
//             }
//         }
//         return dp[m-1][n-1];
        
        
        //space optimized
        vector<int>prev(n,0);
         for(int i=0;i<m;i++){
             vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=grid[0][0];
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0)up=prev[j];
                else up=INT_MAX;
                if(j>0)left=curr[j-1];
                else left=INT_MAX;
                
                curr[j]=grid[i][j] +min(up,left);
                
            }
             prev=curr;
        }
        return prev[n-1];
    }
};