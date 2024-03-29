class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        
         for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        
        vector<long long>dist(n,1e15);
        dist[0]=0;
        vector<int>ways(n,0);
        ways[0]=1;
        
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                long long adjdist=it.second;
                
                if(dis + adjdist < dist[adjnode]){
                    dist[adjnode]=dis + adjdist;
                    ways[adjnode]=ways[node];
                    pq.push({dist[adjnode],adjnode});
                }
                else if(dis +adjdist == dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%((int)1e9+7);
                }
            }
        }
        return ways[n-1]%((int)1e9+7);
        
        
        
        
    }
};