class Node{
  public:
    
    Node* links[2];
    
    bool containsKey(int ind){
        return (links[ind]!=NULL);
    }
    
    
    void put(int ind, Node* node){
        links[ind]=node;
    }
    
    Node* get(int ind){
        return links[ind];
    }
};


class Trie{
  
    private: 
    Node* root;
    
    public:
    
    Trie(){
        root=new Node();
    }
    
    
    void insert(int num){
        Node* node=root;
        
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            
            node=node->get(bit);
        }
    }
    
    
    int getMax(int num){
        Node* node=root;
        
        int maxnum=0;
        
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxnum;
    }
    
    
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        int q=queries.size();
        
                vector<int>ans(q,0);
        sort(nums.begin(),nums.end());
        
        vector<pair<int,pair<int,int>>>oq;
        
        for(int i=0;i<q;i++){
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        sort(oq.begin(),oq.end());
        
        
        int n=nums.size();
        
        int ind=0;
        Trie trie;
        
        for(int i=0;i<q;i++){
            int ai=oq[i].first;
            int xi=oq[i].second.first;
            int qind=oq[i].second.second;
            
            while(ind<n && nums[ind]<=ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0)ans[qind]=-1;
            else{
                ans[qind]=trie.getMax(xi);
            }
        }
        return ans;
    }
};