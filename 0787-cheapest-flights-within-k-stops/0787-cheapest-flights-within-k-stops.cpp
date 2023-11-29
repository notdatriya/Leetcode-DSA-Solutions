class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights){
            int from=it[0];
            int to=it[1];
            int price=it[2];
            adj[from].push_back({to,price});
        }
        
        
        queue<pair<int,pair<int,int>>>q;
        
        //stop - distance(price) - source -ulta
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        
        dist[src]=0;
        
        while(!q.empty()){
            int stops= q.front().first;
            int cost=q.front().second.second;
            int node=q.front().second.first;
            
            q.pop();
            
            if(stops>k)continue;
    
            for(auto it: adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(cost+w<dist[adjnode] && stops<=k){  //k beacuse we can take one more to reach the destination
                    dist[adjnode]=cost+w;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        
        
        if(dist[dst]!=1e9)return dist[dst];
        return -1;
    }
};