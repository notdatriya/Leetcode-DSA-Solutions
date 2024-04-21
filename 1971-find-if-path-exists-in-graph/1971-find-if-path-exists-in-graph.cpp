class Solution {
public:
    
    bool solve(int i,vector<int>adj[],vector<int>&vis,int destination){
        vis[i]=true;
        
        if(i==destination)return true;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                if(solve(it,adj,vis,destination))return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        
        if(solve(source,adj,vis,destination)==true)return true;
        return false;
        
    }
};