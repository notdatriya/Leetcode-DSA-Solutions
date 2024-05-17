class Solution {
public:
   int solve(vector<vector<int>>& grid, vector<vector<int>>&dis){
       int n=grid.size();
       queue<pair<int,int>>q;
       
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                   q.push({i,j});
                   dis[i][j]=0;
               }
           }
       }
       
       int maxi=0;
       while(!q.empty()){
           int size=q.size();
           for(int i=0;i<size;i++){
          int r=q.front().first;
           int c=q.front().second;
               
               maxi=max(maxi,dis[r][c]);
           
           q.pop();
               
               int dr[4]={-1,0,1,0};
               int dc[4]={0,1,0,-1};
               
               for(int j=0;j<4;j++){
                   int nr=r+dr[j];
                   int nc=c+dc[j];
                   
                   if(nr>=0 && nc>=0 && nr<n && nc<n && dis[r][c]+1<dis[nr][nc]){
                       dis[nr][nc]=1+dis[r][c];
                       q.push({nr,nc});
                   }
               }
         }
       }
       return maxi;
       
   }
    
    bool isPossible(int sf, vector<vector<int>>& dis){
        int n=dis.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        
        if(dis[0][0]<sf){
            return false;
        }
        
        q.push({0,0});
        visited[0][0]=true;
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            
            if(r==n-1 && c==n-1)return true;
            
             int dr[4]={-1,0,1,0};
               int dc[4]={0,1,0,-1};
               
               for(int j=0;j<4;j++){
                   int nr=r+dr[j];
                   int nc=c+dc[j];
                   
                   if(nr>=0 && nc>=0 && nr<n && nc<n && visited[nr][nc]==false && dis[nr][nc]>=sf){
                       visited[nr][nc]=true;
                       q.push({nr,nc});
                   }
               }
            
        }
        return false;
    }
    
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        
        int maxi=solve(grid,dis);
        
        int ans=0;
        int l=0;
        int h=maxi;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isPossible(mid,dis)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
        
    }
};