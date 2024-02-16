class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
         int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mpp; 
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum==goal)count++;
            if (mpp.find(sum-goal) != mpp.end()) {
                count += mpp[sum - goal];
            }
            mpp[sum]++;
        }
        return count;
    }
};