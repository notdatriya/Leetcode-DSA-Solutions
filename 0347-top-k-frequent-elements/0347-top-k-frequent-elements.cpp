class Solution {
public:
    
    struct compare{
    bool operator()(pair<int,int>a,pair<int,int>b){
        if(a.second<b.second)return true;
        else if(a.second==b.second){
            if(a.first<b.first)return true;
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
         // vector<pair<int,int>v;
        
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
      priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq(freq.begin(),freq.end());
        vector<int>ans;
        while(k>0){
            // pair<int,int>temp=pq.top();
            int temp=pq.top().first;
            ans.push_back(temp);
            pq.pop();
           
            
            k--;
        }
        return ans;
        
        
    }
};