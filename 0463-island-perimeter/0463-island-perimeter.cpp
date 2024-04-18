class Solution {
public:
    
    int solve(int r,int c,vector<vector<int>>&grid,int n,int m){  //int &count
        
        if(r<0 || r>n-1 || c<0 || c>m-1 || grid[r][c]==0){
            // count++;
            return 1;
        }
        
        // if(vis[r][c]==1)return;
        
        if(grid[r][c]==-1){
            return 0;
        }
        
        grid[r][c]=-1;
        int dr[4]={-1,0,0,1};
        int dc[4]={0,1,-1,0};
        
        int count=0;
        
        for(int i=0;i<4;i++){
            
            int nr=r+dr[i];
            int nc=c+dc[i];
        
            
            count+=solve(nr,nc,grid,n,m);
        }
        return count;
        
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
        // vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){   //can also be !vis[i][j]
                    count+= solve(i,j,grid,n,m);
                }
            }
        }
         return count;
        
        
    }
};