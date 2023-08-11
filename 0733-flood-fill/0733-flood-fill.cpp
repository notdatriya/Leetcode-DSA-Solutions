class Solution {
public:
    
    void dfs(int sr,int sc,vector<vector<int>>&ans, vector<vector<int>>&image,int row[],int col[],int newColor,int iniColor){
    int n=image.size();
    int m=image[0].size();
    ans[sr][sc]=newColor;
    
    for(int i=0;i<4;i++){
        int newsr=sr+row[i];
        int newsc=sc+col[i];
         if(newsr>=0 && newsr<n && newsc>=0 && newsc<m && image[newsr][newsc]==iniColor && ans[newsr][newsc]!=newColor){
             dfs(newsr,newsc,ans,image,row,col,newColor,iniColor);
         }
    }
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
         int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
        dfs(sr,sc,ans,image,row,col,color,iniColor);
        return ans;
    }
};