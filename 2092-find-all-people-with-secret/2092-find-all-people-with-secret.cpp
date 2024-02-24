class disjointset{
vector<int>rank,parent;
public:
 disjointset(int n){
	 rank.resize(n,0);
	 parent.resize(n);
	
	 for(int i=0;i<n;i++){
		 parent[i]=i;
	 }
 }
 
 int findUParent(int node){
	 if(parent[node]==node)return node;
	 return parent[node]=findUParent(parent[node]);
 }

 void unionByRank(int u,int v){
	 int ulp_u=findUParent(u);
	 int ulp_v=findUParent(v);
	 if(ulp_u==ulp_v)return;
	 if(rank[ulp_u]>rank[ulp_v]){
		 parent[ulp_v]=ulp_u;
	 }
	 else if(rank[ulp_v]>rank[ulp_u]){
		 parent[ulp_u]=ulp_v;
         } else {
                 parent[ulp_v] = ulp_u;
                 rank[ulp_u]++;
         }
 }
    
    
    
void reset(int node){
    parent[node]=node;
    rank[node]=0;
}


 
};



class Solution {
public:
   
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        
        auto comp=[](const vector<int>&a,const vector<int>&b){
            if(a[2]==b[2]){
                return a[0]<b[0];
            }
            else{
                return a[2]<b[2];
            }
        };
        
        sort(meetings.begin(),meetings.end(),comp);
        disjointset dsu(n);
        dsu.unionByRank(0,firstPerson);
        
        for(int i=0;i<meetings.size();){
            int currtime=meetings[i][2];
            vector<int>currpeople;
            
            while(i<meetings.size() && meetings[i][2]==currtime){
                dsu.unionByRank(meetings[i][0],meetings[i][1]);
                currpeople.push_back(meetings[i][0]);
                currpeople.push_back(meetings[i][1]);
                i++;
            }
            
            for(auto it:currpeople){
                if(dsu.findUParent(it)!=dsu.findUParent(0)){
                    dsu.reset(it);
                }
            }
        }
        
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dsu.findUParent(i)==dsu.findUParent(0)){
                ans.push_back(i);
            }
        }
        
        return ans;
      
    }
};