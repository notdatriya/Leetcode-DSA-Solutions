class Solution {
public:
    
    const static int maxi=1e5+5;
    bool isprime[maxi];
    int spf[maxi];
    
    void sieve(){
        //this is O(maxi log log(maxi))
        fill(isprime,isprime+maxi,true);
        for(int i=0;i<maxi;i++){
            spf[i]=i;
        }
        
        isprime[0]=isprime[1]=false;
        
        for(int i=2;i*i<maxi;i++){
            if(isprime[i]){
                for(int j=i*i;j<maxi;j+=i){
                    if(isprime[j]){
                        spf[j]=i;
                        isprime[j]=false;
                    }
                }
            }
        }
    }
    
    //getting prime factors of numbers - O(log maxi)
    vector<int> getfact(int x){
        vector<int>ans;
        unordered_map<int,int>mpp;
        while(x!=1){
            mpp[spf[x]]++;
            x=x/spf[x];
        }
        
        for(auto i:mpp){
            ans.push_back(i.first);
        }
        return ans;
    }
    
    void dfs(int node,unordered_map<int,vector<int>>&gr,vector<bool>&vis,int &count){
        if(vis[node])return;
        
        vis[node]=true;
        count++;
        
        for(auto it:gr[node]){
            if(vis[it]==0){
                dfs(it,gr,vis,count);
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        
        sieve();
        unordered_map<int,vector<int>>mpp;
        
        //O(nlog maxi)
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[i]=getfact(nums[i]);
        }
        
        unordered_map<int,vector<int>>rmp;
        
        //O(nlog maxi)
        for(auto it:mpp){
            int id=it.first;
            for(auto prime:it.second){
                rmp[prime].push_back(id);
            }
        }
        
        unordered_map<int,vector<int>>gr;
        for(auto p:rmp){
            vector<int>ids=p.second;
            if(ids.size()<=1){
                continue;
            }
            
            for(int i=1;i<ids.size();i++){
                int u=ids[i-1];
                int v=ids[i];
                
                gr[u].push_back(v);
                gr[v].push_back(u);
            }
        }
        
        vector<bool>vis(n,0);
        int count=0;
        
        dfs(0,gr,vis,count);
        if(count==n)return true;
        return false;
        
        
    }
};