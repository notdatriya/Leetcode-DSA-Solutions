class KthLargest {
public:
    int k=0;
    // priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    
    int add(int val) {
        pq.push(val);
        // priority_queue<int>temp=pq;
        // int n=1;
        while(pq.size()>k){
            pq.pop();
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */