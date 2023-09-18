class Solution {
public:
    
    bool solve(int idx,int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board,string &word){
        int n=board.size();
        int m=board[0].size();
      if(idx==word.length())return true;
        
        if(row<0 || col<0 || row==n || col==m || board[row][col]!=word[idx] || vis[row][col]==true){
            return false;
        }
        
        vis[row][col]=true;
        
        bool down=solve(idx+1,row+1,col,vis,board,word);
        bool right=solve(idx+1,row,col+1,vis,board,word);
        bool up=solve(idx+1,row-1,col,vis,board,word);
        bool left=solve(idx+1,row,col-1,vis,board,word);
        vis[row][col]=0;
        return down||right||up||left;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        int idx=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[idx]){
                    if(solve(idx,i,j,vis,board,word))return true;
                }
            }
        }
        return false;
    }
};