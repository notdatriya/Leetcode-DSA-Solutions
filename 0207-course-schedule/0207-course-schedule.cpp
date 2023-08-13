class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj,int vis[],int pathvis[],int i){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(adj,vis,pathvis,it)==true)return true;
            }
            
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto num : prerequisites){
            adj[num[1]].push_back(num[0]);
        }
        int vis[numCourses];
        int pathvis[numCourses];
        for(int i=0;i<numCourses;i++){
            vis[i]=0;
            pathvis[i]=0;
        }
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathvis,i)==true)return false;
            }
        }
        return true;
    }
};