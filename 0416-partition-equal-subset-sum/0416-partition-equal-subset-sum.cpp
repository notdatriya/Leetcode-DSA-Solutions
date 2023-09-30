class Solution {
public:
    
    bool solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==0){
            return nums[0]==target;
        }
        
        bool notpick=solve(i-1,target,nums,dp);
        bool pick=false;
        if(nums[i]<=target){
            pick=solve(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]=pick||notpick;
    }
        
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++){
            totsum+=nums[i];
        }
         if(totsum%2)return false;
    vector<vector<bool>>dp(n,vector<bool>((totsum/2)+1,0));
        // return solve(n-1,totsum/2,nums,dp);
        
        
        //tabulation
//         for(int i=0;i<n;i++)dp[i][0]=true;
//         if(nums[0]<=totsum/2)dp[0][nums[0]]=true;
        
//         for(int i=1;i<n;i++){
//             for(int target=1;target<=totsum/2;target++){
                
//                 bool notpick=dp[i-1][target];
//                 bool pick=false;
//                 if(nums[i]<=target){
//                     pick=dp[i-1][target-nums[i]];
//                  }
//                      dp[i][target]=pick||notpick;
//                 }
//         }
//         return dp[n-1][totsum/2];
        
        //space
        int k=totsum/2;
         vector<bool>prev(k+1,false);
        vector<bool>curr(k+1,false);
        prev[0]=true;
        
        if(nums[0]<=totsum/2)prev[nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=totsum/2;target++){
                        curr[0]=true;
                
                bool notpick=prev[target];
                bool pick=false;
                if(nums[i]<=target){
                    pick=prev[target-nums[i]];
                 }
                     curr[target]=pick||notpick;
                }
            prev=curr;
        }
        return prev[totsum/2];
    }
};