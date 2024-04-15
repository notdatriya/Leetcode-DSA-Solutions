class Solution {
public:
    
    int solve(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        int n=nums.size();
        while(r<n){
            sum+=nums[r];
            
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //  int n = nums.size();
        // int count = 0;
        // int sum = 0;
        // unordered_map<int, int> mpp; 
        // mpp[0]=1;
        // for (int i = 0; i < n; i++) {
        //     sum += nums[i];
        //     if (mpp.find(sum-goal) != mpp.end()) {
        //         count += mpp[sum - goal];
        //     }
        //     mpp[sum]++;
        // }
        // return count;  
        
        
        return solve(nums,goal)-solve(nums,goal-1);
    }
};