class Solution {
public:
    
    int solve(int x,int y1,int y2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(y1<0 || y1>=m || y2<0 || y2>=m){
            return INT_MIN;
        }
        if(x==n-1){
            if(y1==y2){
                return grid[x][y1];
            }
            else{
                return grid[x][y1]+grid[x][y2];
            }
        }
        
        if(dp[x][y1][y2]!=-1)return dp[x][y1][y2];
        
        int maxi=INT_MIN;
        for(int j1=-1 ;j1<=1;j1++){
            for(int j2=-1;j2<=1;j2++){
                int ans;
                if(y1==y2){
                    ans=grid[x][y1]+solve(x+1,y1+j1,y2+j2,n,m,grid,dp);
                }
                else{
                    ans=grid[x][y1]+grid[x][y2]+solve(x+1,y1+j1,y2+j2,n,m,grid,dp); 
                }
                maxi=max(maxi,ans);
            }
        }
        return dp[x][y1][y2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};