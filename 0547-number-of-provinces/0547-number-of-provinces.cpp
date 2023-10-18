class Solution {
public:
    void bfs(int i,vector<int>adj[],vector<int>&vis){
vis[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        for(auto it:adj[ele]){
            if(!vis[it]){
            vis[it]=1;
            q.push(it);
            }
        }
    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
         vector<int>vis(n,0);
    int count=0;
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]!=0){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
        bfs(i,adj,vis);
        }
    }
    return count;
    }
};