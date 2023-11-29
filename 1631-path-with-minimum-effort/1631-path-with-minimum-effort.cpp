class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
    
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        int delrow[]={0,0,-1,1};
        int delcol[]={-1,1,0,0};
        while(!pq.empty()){
            int diff = pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            
            pq.pop();
            
    
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                   int neweffort=max(abs(heights[nr][nc]-heights[r][c]),diff);
                    if(neweffort<dist[nr][nc]){
                        dist[nr][nc]=neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }
                    
                }
            }
        }
        
        
        if(dist[n-1][m-1]!=1e9)return dist[n-1][m-1];
        return -1;
    }
};