class Solution {
public:
    int mod=1e9+7;
    int solve(int x,int y,int m,int n,int maxmove,vector<vector<vector<int>>>&dp){
       if(maxmove==0) 
        {
           if(x>=m || x<0 || y>=n || y<0) return 1;
           return 0; 
        }
        
        if(x>=m || x<0 || y>=n || y<0) return 1;
        
        if(dp[x][y][maxmove]!=-1)return dp[x][y][maxmove];
        
        int ans=0;
        ans+=solve(x,y-1,m,n,maxmove-1,dp)%mod;
        ans %= mod;
        ans+=solve(x,y+1,m,n,maxmove-1,dp)%mod;
        ans %= mod;
        ans+=solve(x-1,y,m,n,maxmove-1,dp)%mod;
        ans %= mod;
        ans+=solve(x+1,y,m,n,maxmove-1,dp)%mod;
        ans %= mod;
        
        return dp[x][y][maxmove]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,m,n,maxMove,dp);
        
    }
};