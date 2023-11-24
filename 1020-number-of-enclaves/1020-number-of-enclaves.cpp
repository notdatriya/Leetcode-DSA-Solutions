class Solution {
public:
   
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 ||j==m-1){
                    if(grid[i][j]==1){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }
        
        
        int row[]={-1,0,0,1};
        int col[]={0,-1,1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
             for(int s=0;s<4;s++){
            int nr=r+row[s];
            int nc=c+col[s];
            if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1 && vis[nr][nc]==0 && grid[nr][nc]==1){
                vis[nr][nc]=1;
                q.push({nr,nc});    
            }
            
        }       
        }
        
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                   count++;
                }
            }
        }
        return count;
        
        
    }
};