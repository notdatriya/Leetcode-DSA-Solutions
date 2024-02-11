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
        
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // return solve(0,0,m-1,n,m,grid,dp);
        
        
        
        //tabulation
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
         for (int y1 = 0; y1 < m; y1++) {
        for (int y2 = 0; y2 < m; y2++) {
            if (y1 == y2)
                dp[n - 1][y1][y2] = grid[n - 1][y1];
            else
                dp[n - 1][y1][y2] = grid[n - 1][y1] + grid[n - 1][y2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int y2 = 0; y2 < m; y2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (y1 == y2)
                            ans = grid[i][y1];
                        else
                            ans = grid[i][y1] + grid[i][y2];

                        if ((y1 + di < 0 || y1 + di >= m) || (y2 + dj < 0 || y2 + dj >= m))
                            ans += -1e9; 
                        else
                            ans += dp[i + 1][y1 + di][y2 + dj]; 

                        maxi = max(ans, maxi); 
                    }
                }
                dp[i][y1][y2] = maxi; 
            }
        }
    }

    
    return dp[0][0][m - 1];

    }
};