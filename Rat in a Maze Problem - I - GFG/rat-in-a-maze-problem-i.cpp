//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int row,int col,vector<vector<int>>&m,int n,vector<vector<int>>&visited,vector<string>&ans,string move){
        if(row==n-1 && col==n-1){
            ans.push_back(move);
            return;
        }
        
        if(row+1<=n-1 && !visited[row+1][col] && m[row+1][col]==1){
            visited[row][col]=true;
            solve(row+1,col,m,n,visited,ans,move+"D");
             visited[row][col]=false;

        }
         if(col-1>=0 && !visited[row][col-1] && m[row][col-1]==1){
            visited[row][col]=true;
            solve(row,col-1,m,n,visited,ans,move+"L");
             visited[row][col]=false;
        }
        
         if(col+1<=n-1 && !visited[row][col+1] && m[row][col+1]==1){
            visited[row][col]=true;
            solve(row,col+1,m,n,visited,ans,move+"R");
             visited[row][col]=false;

        }
        
         if(row-1>=0 && !visited[row-1][col] && m[row-1][col]==1){
            visited[row][col]=true;
            solve(row-1,col,m,n,visited,ans,move+"U");
             visited[row][col]=false;
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>visited(n,vector<int>(n,0));
        
        vector<string>ans;
        
        if(m[0][0]==1)solve(0,0,m,n,visited,ans,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends