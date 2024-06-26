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
                maxnum= maxnum | (1<<i);
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
    
    
    int findMaximumXOR(vector<int>& nums) {
        
        Trie trie;
        
        for(auto & it:nums){
            trie.insert(it);
        }
        
        int maxi=0;
        
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,trie.getMax(nums[i]));
        }
        return maxi;
        
    }
};