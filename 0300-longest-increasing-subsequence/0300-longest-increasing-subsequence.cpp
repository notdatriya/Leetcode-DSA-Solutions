class Solution {
public:
    // int solve(int idx,int prev_idx,vector<int>&nums,vector<vector<int>>&dp){
        //Recursion
//         int n=nums.size();
//         if(idx==n)return 0;
        
//         int len =0+ solve(idx+1,prev_idx,nums);   //not take
        
//         if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
//             len=max(len,1+ solve(idx+1,idx,nums));
//         }
        
//         return len;
        
        
        
        //memoization
//                   int n=nums.size();

//         if(idx==n)return 0;
//         if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
//         int len =0+ solve(idx+1,prev_idx,nums,dp);   //not take
        
//         if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
//             len=max(len,1+ solve(idx+1,idx,nums,dp));
//         }
        
//         return dp[idx][prev_idx+1]=len;
        
    // }
        
      
        
    // }
    
     
    
    
    int lengthOfLIS(vector<int>& nums) {
        int idx=0;
        int prev_idx=-1;
          int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1)) ; // idx - 0 to n-1 and prev_idx is from -1 to n-1 so we will store by +1;
        // return solve(idx,prev_idx,nums,n);
        
        
        
         //Tabulation
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int idx=n-1;idx>=0;idx--){
//             for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
//                 int len =0+ dp[idx+1][prev_idx+1];   //not take
        
//         if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
//             len=max(len,1+ dp[idx+1][idx+1]);
//         }
        
//         dp[idx][prev_idx+1]=len; 
//             }
//         }
//         return dp[0][-1+1];
        
        //space -optimized
        vector<int>after(n+1,0);
        vector<int>curr(n+1,0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
                int len =0+ after[prev_idx+1];   //not take
        
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            len=max(len,1+ after[idx+1]);
        }
        
        curr[prev_idx+1]=len;
            }
            after=curr;
        }
        return after[-1+1];
        
        
        
        //algo req. for printing LIS
//         vector<int>dp(n,1);
//         vector<int>hash;
//         int maxi=1;
//         int lastidx=0;
//         for(int i=0;i<n;i++){
//             hash[i]=i;
//             for(int prev=0;prev<i;prev++){
//                 if(nums[prev]<nums[i] && 1+dp[prev]>dp[i] ){
//                 dp[i]=1+dp[prev];
//                     hash[i]=prev;
//                 }
//             }
//             if(dp[i]>maxi){
//                 maxi=dp[i];
//                 lastidx=i;
//             }
//         }
        
        
//         vector<int>temp;
//         temp.push_back(nums[lastidx]);
//         while(hash[lastidx]!=lastidx){
//             lastidx=hash[lastidx];
//             temp.push_back(nums[lastidx]);
//         }
//         reverse(temp.begin(),temp.end());
        
    }
};