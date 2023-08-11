//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
         int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
        dfs(sr,sc,ans,image,row,col,newColor,iniColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends