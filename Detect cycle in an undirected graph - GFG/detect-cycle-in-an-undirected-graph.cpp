//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool bfs(vector<int>adj[],int vis[],int node){
    //     queue<pair<int,int>>q;
    //     q.push({node,-1});
    //     vis[node]=1;
    //     while(!q.empty()){
    //         int ele=q.front().first;
    //         int parent=q.front().second;
    //         q.pop();
    //         for(auto it:adj[ele]){
    //             if(!vis[it]){
    //                 q.push({it,ele});
    //                 vis[it]=1;
    //             }
    //             else if(it!=parent){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
        
    // }
    
    bool dfs(vector<int>adj[],int vis[],int node,int parent){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,it,node))return true;
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,i,-1))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends