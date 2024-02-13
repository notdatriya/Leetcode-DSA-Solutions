class Solution {
public:
    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       
//       int i=0;
//         int n=nums.size();
//     int j=i+k-1;
//     vector<int>ans;
//     while(j<=n-1){
//         int maxi=INT_MIN;
//         for(int k=i;k<=j;k++){
//             maxi=max(maxi,nums[k]);
//         }
//         ans.push_back(maxi);
//         i++;
//         j++;
//     }
//     return ans;
        
        
        //m-2 deque(we will be able to push and pop from both front and back)
        
        deque<int>q;
        vector<int>ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(!q.empty() && q.front()==i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};