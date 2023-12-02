class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        vector<int>t(n+1,INT_MAX);
        t[k]=0;
        
        while(!pq.empty()){
            int currtime=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            if(currtime>t[node])continue;
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int timetaken=it.second;
                
                if(currtime + timetaken< t[adjnode]){
                    pq.push({currtime+timetaken,adjnode});
                    t[adjnode]=currtime + timetaken;
                    
                }
            }
        }
        
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,t[i]);
        }
        return (maxi!=INT_MAX) ? maxi:-1;
        
        
        
        
    }
};