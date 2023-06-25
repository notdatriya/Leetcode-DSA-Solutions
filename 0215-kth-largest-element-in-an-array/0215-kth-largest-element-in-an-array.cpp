class Solution {
public:
      
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
       priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int c=k-1;
        while(c>0){
            pq.pop();
            c--;
        }
        
        return pq.top();
        
    }
};