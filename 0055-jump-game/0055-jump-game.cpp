class Solution {
public:
//     bool solve(int idx,vector<int>&nums,vector<int>&dp){
//         if(idx>=nums.size()-1){
//             return true;
//         }
//         if(nums[idx]==0)return false;
        
//         if(dp[idx]!=-1)return dp[idx];
        
//         for(int i=1;i<=nums[idx];i++){
//             if(solve(idx+i,nums,dp)){
//                 return dp[idx]=1;
//             }
//         }
//         return dp[idx]=0;
        
//     }
    bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         if(n<=1)return true;
        
//         vector<int>dp(n+1,-1);
//         return solve(0,nums,dp);
        
        //m-2 bottom up
//           int n = nums.size();
//         if (n <= 1) return true;

//         vector<int> dp(n, 0);
//         dp[n - 1] = 1; // Destination is always reachable from itself

//         for (int i = n - 2; i >= 0; i--) {
//             int furthestJump = min(i + nums[i], n - 1); // Maximum reachable index from i
//             for (int j = i + 1; j <= furthestJump; j++) {
//                 if (dp[j] == 1) {
//                     dp[i] = 1;
//                     break;
//                 }
//             }
//         }
//         return dp[0] == 1;
        
       
        
        //greedy approach
        int n=nums.size();
        int final=n-1;
        
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=final){
                final=i;
            }
        }
        
        if(final==0)return true;
        return false;
    }
};