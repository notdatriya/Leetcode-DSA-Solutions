class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(int i=0;i<points.size();i++){
            int u=points[i][0];
            int v=points[i][1];
            
            int dist= (u*u)+(v*v);
            
            pq.push({dist,{u,v}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>>ans;
        while(!pq.empty()){
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            ans.push_back({u,v});
            pq.pop();
        }
        return ans;
        
        
    }
};