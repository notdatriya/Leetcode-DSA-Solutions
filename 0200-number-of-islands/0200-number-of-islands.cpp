class Solution {
public:
    
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j){
          int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int n1=q.front().first;
            int n2=q.front().second;
            q.pop();
            
            int row[4]={-1,1,0,0};
            int col[4]={0,0,-1,1};
            for(int l=0;l<4;l++){  
                    int newn1=n1+row[l];
                    int newn2=n2+col[l];
                    if(newn1>=0 && newn1<n && newn2>=0 && newn2<m && grid[newn1][newn2]=='1' && !vis[newn1][newn2]){
                        q.push({newn1,newn2});
                        vis[newn1][newn2]=1;
                    }
                
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
          int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                     count++;
                    bfs(grid,vis,i,j);
                   
                }
            }
        }
        return count;
    }
};