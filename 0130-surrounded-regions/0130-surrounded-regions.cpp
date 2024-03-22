class Solution {
public:
//   void dfs(int row, int col, vector<vector<int>> &vis, 
//     vector<vector<char>> &board, int delrow[], int delcol[]) {
//         vis[row][col] = 1; 
//         int n = board.size();
//         int m = board[0].size();
        
//         for(int i = 0;i<4;i++) {
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i]; 
//             if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
//             && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
//                 dfs(nrow, ncol, vis, board, delrow, delcol); 
//             }
//         }
//     }
    void solve(vector<vector<char>>& grid) {
//          int n = board.size();
//         int m = board[0].size();
        
//        int delrow[] = {-1, 0, +1, 0};
//         int delcol[] = {0, 1, 0, -1}; 
//         vector<vector<int>> vis(n, vector<int>(m,0)); 
//         for(int j = 0 ; j<m;j++) {
//             if(!vis[0][j] && board[0][j] == 'O') {
//                 dfs(0, j, vis, board, delrow, delcol); 
//             }
            
//             if(!vis[n-1][j] && board[n-1][j] == 'O') {
//                 dfs(n-1,j,vis,board, delrow, delcol); 
//             }
//         }
        
//         for(int i = 0;i<n;i++) {
//             if(!vis[i][0] && board[i][0] == 'O') {
//                 dfs(i, 0, vis, board, delrow, delcol); 
//             }
            
//             if(!vis[i][m-1] && board[i][m-1] == 'O') {
//                 dfs(i, m-1, vis, board, delrow, delcol); 
//             }
//         }
        
//         for(int i = 0;i<n;i++) {
//             for(int j= 0 ;j<m;j++) {
//                 if(!vis[i][j] && board[i][j] == 'O') 
//                     board[i][j] = 'X'; 
//             }
//         }
        
        
        
        
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 ||j==m-1){
                    if(grid[i][j]=='O'){
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
            if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1 && vis[nr][nc]==0 && grid[nr][nc]=='O'){
                vis[nr][nc]=1;
                q.push({nr,nc});    
            }
            
        }       
        }
        
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && vis[i][j]==0){
                   // count++;
                    grid[i][j]='X';
                }
            }
        }
        // return count;
        
        
        
    }
};