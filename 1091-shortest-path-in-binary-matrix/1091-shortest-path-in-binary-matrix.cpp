class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0 )return -1;
       if(grid[0][0]==0 && n==1)return 1;
        
//         // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        pq.push({0,{0,0}});
        
//         int delrow[]={-1,0,1,-1,1,-1,0,1};
//         int delcol[]={1,1,1,0,0,0,-1,-1,-1};
        
         int del[][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
        
        dist[0][0]=1;
        
        while(!pq.empty()){
            int d=pq.front().first;
            int r=pq.front().second.first;
            int c=pq.front().second.second;
            pq.pop();
            
            for(int i=0;i<8;i++){
                int nr=r+del[i][0];
                int nc=c+del[i][1];
                
                if(nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==0 && d+1<dist[nr][nc]){
                        dist[nr][nc]=dist[r][c]+1;
                    // if(nr==n-1 && nc==n-1)return dist[nr][nc];
                        pq.push({dist[nr][nc],{nr,nc}});
                }
            }
            
        }
        
    
         return dist[n-1][n-1] == INT_MAX ? - 1 : dist[n-1][n-1];
        
    }
};