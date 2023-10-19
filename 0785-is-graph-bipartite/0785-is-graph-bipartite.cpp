class Solution {
public:
    
    // bool bfs(vector<vector<int>>&graph,int color[],int i){
    //     queue<int>q;
    //     q.push(i);
    //     color[i]=0;
    //     while(!q.empty()){
    //         int node=q.front();
    //         q.pop();
    //         for(auto it :graph[node]){
    //             if(color[it]==-1){
    //                 color[it]=1-color[node];
    //                 q.push(it);
    //             }
    //             else if(color[it]==color[node]){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    bool dfs(vector<vector<int>>&graph,int color[],int i,int col){
        color[i]=col;
        for(auto it:graph[i]){
            if(color[it]==-1){
                color[it]=1-col;
                if(dfs(graph,color,it,1-col)==false)return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
//         vector<int>adj[V];
//         for(int i=0;i<graph.size();i++){
//             for(int j=0;j<graph[0].size();j++){
//                 if(graph[i][j]!=0){
//                     adj[i].push_back(j);
//                 }
//             }
//         }
        
        int color[V];
        for(int i=0;i<V;i++){
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(graph,color,i,0)==false)return false;
            }
        }
        return true;
    }
};