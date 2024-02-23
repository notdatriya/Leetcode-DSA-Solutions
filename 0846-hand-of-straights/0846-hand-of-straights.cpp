class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        unordered_map<int,int>mpp;
        
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(auto i:mpp){
            if(i.second>0){
            pq.push(i.first);
            }
        }
        
        while(!pq.empty() && pq.size()>=groupSize){
                    vector<int>addq;
            int temp=pq.top()-1;
            for(int i=0;i<groupSize;i++){
                int ele=pq.top();
                pq.pop();
                mpp[ele]--;
                
                if(ele!=temp+1){
                    return false;
                }
                
                temp=ele;
                
                if(mpp[ele]>0){
                    addq.push_back(ele);
                }
                
            }
            
            for(auto t:addq){
                pq.push(t);
            }
            
        }
        
        if(!pq.empty()){
            return false;
        }
        return true;
        
        
    }
};