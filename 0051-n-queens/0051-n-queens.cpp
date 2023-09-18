class Solution {
public:
    
//     void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n){
      
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
        
//         for(int row=0;row<n;row++){
//             if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 &&lowerDiagonal[row+col]==0){
//                 board[row][col]='Q';
//                 leftRow[row]=1;
//                 upperDiagonal[n-1+col-row]=1;
//                 lowerDiagonal[row+col]=1;
//                 solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
//                   board[row][col]='.';
//                 leftRow[row]=0;
//                 upperDiagonal[n-1+col-row]=0;
//                 lowerDiagonal[row+col]=0;
                
//             }
//         }
            
        
//     } 
    
    void solve(int col,vector<string>board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
            
        }
    }
    
    bool safe(int i,int j,vector<string>board,int n){
        int drow=i;
        int dcol=j;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')return false;
            i--;j--;
        }
        i=drow;
        j=dcol;
        while(i<n && j>=0){
            if(board[i][j]=='Q')return false;
            i++;
            j--;
        }
        i=drow;
        j=dcol;
        while(j>=0){
            if(board[i][j]=='Q')return false;
            j--;
        }
        return true;
    }
        
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        
        solve(0,board,ans,n);
        return ans;
        
        // //for checking the left row
        // vector<int>leftRow(n,0);
        // //for checking lower diagonal
        // vector<int>lowerDiagonal(2*n-1,0);
        // //for upper diagonal
        // vector<int>upperDiagonal(2*n-1,0);
        // solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
        // return ans;
    }
};