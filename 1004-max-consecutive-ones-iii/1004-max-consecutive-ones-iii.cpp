class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int i=0;
        int count=0;
        unordered_map<int,int>mpp;
        int maxcount=0;
       for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                count++;
            }
            
            while (count > k) {
                if (nums[i] == 0) {
                    count--;
                }
                i++;
            }
            
            maxcount = max(maxcount, j - i + 1);
        }
        
        return maxcount;
    }
};