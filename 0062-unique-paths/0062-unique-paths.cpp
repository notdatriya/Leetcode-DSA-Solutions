class Solution {
public:
    
//     int paths(int i,int j,int m,int n){
//         int count=0;
//         if(i==m-1 && j==n-1){
//             count++;
//             return 1;
//         }
//         if(i>m-1 || j>n-1){
//             count+=0;
//             return 0;
//         }
        
//        else return paths(i+1,j,m,n)+paths(i,j+1,m,n);
//     }
    
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up=solve(i-1,j,m,n,dp);
        int left=solve(i,j-1,m,n,dp);
        return dp[i][j]=up+left;
    
    }
    int uniquePaths(int m, int n) {
        // return paths(0,0,m,n);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,m,n,dp);
    }
};