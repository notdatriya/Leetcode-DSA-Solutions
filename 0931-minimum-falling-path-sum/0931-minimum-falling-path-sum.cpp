class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,int n,int m,vector<vector<int>>&dp){
        
        if(j<0 || j>m-1 )return 1e9;
         if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up= solve(i-1,j,matrix,n,m,dp);
        int leftdig=solve(i-1,j-1,matrix,n,m,dp);
        int rightdig=solve(i-1,j+1,matrix,n,m,dp);
        
        return dp[i][j]=matrix[i][j] + min(up,min(leftdig,rightdig));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // int mini=INT_MAX;
        // for(int c=0;c<m;c++){
        //     int ans=solve(n-1,c,matrix,n,m,dp);
        //     mini=min(ans,mini);
        // }
        // return mini;
        
        
        //tabulation
//         vector<vector<int>>dp(n,vector<int>(m,0));
//         for(int i=0;i<m;i++){
//             dp[0][i]=matrix[0][i];
//         }
        
//         for(int i=1;i<n;i++){
//             for(int j=0;j<m;j++){
//                 int up= matrix[i][j]+dp[i-1][j];
                
//                 int leftdig=matrix[i][j];
//                 if(j-1>=0)leftdig+=dp[i-1][j-1];
//                 else leftdig+=1e9;
//                 int rightdig=matrix[i][j];
//                 if(j+1<m)rightdig+=dp[i-1][j+1];
//                 else rightdig+=1e9;
                
//                 dp[i][j]= min(up,min(leftdig,rightdig));
//             }
//         }
//         int mini=INT_MAX;
//         for(int j=0;j<m;j++){
//             mini=min(mini,dp[n-1][j]);
//         }
//         return mini;
        
        
        //space-optimized
        vector<int>prev(m,0);
        vector<int>curr(m,0);
        for(int i=0;i<m;i++){
            prev[i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up= matrix[i][j]+prev[j];
                
                int leftdig=matrix[i][j];
                if(j-1>=0)leftdig+=prev[j-1];
                else leftdig+=1e9;
                int rightdig=matrix[i][j];
                if(j+1<m)rightdig+=prev[j+1];
                else rightdig+=1e9;
                
                curr[j]= min(up,min(leftdig,rightdig));
            }
            prev=curr;
        }
        int mini=INT_MAX;
        for(int j=0;j<m;j++){
            mini=min(mini,prev[j]);
        }
        return mini;

    }
};