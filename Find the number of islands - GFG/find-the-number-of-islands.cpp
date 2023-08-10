//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
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
            
            for(int row=-1;row<=1;row++){
                for(int col=-1;col<=1;col++){
                    int newn1=n1+row;
                    int newn2=n2+col;
                    if(newn1>=0 && newn1<n && newn2>=0 && newn2<m && grid[newn1][newn2]=='1' && !vis[newn1][newn2]){
                        q.push({newn1,newn2});
                        vis[newn1][newn2]=1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends