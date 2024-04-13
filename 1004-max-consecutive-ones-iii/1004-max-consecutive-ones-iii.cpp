class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
//         int n=nums.size();
        
//         int i=0;
//         int count=0;
//         unordered_map<int,int>mpp;
//         int maxcount=0;
//        for (int j = 0; j < n; j++) {
//             if (nums[j] == 0) {
//                 count++;
//             }
            
//             while (count > k) {
//                 if (nums[i] == 0) {
//                     count--;
//                 }
//                 i++;
//             }
            
//             maxcount = max(maxcount, j - i + 1);
//         }
        
//         return maxcount;
        
        
        //m-2 more optimal
        
        int count=0;
        int l=0;
        int r=0;
        int maxi=INT_MIN;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0)count++;
            
            if(count>k){
                if(nums[l]==0)count--;
                l++;
            }
            if(count<=k){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};