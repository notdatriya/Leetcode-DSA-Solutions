class Solution {
public:
    int solve(int i,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+solve(i+1,0,prices,n,dp),0+solve(i+1,1,prices,n,dp));
        }
        else return dp[i][buy]=max(prices[i]+solve(i+2,1,prices,n,dp),0+solve(i+1,0,prices,n,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(0,1,prices,n,dp);
        
        
        //tabulation 
        //base cas eme sab 0 hai already to likhne ka need nahi
        
//         vector<vector<int>>dp(n+2,vector<int>(2,0));
        
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//          if(buy){
//             dp[i][buy]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
//         }
//         else dp[i][buy]=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);       
//             }
//         }
//         return dp[0][1];
        
        
        
        //space-optimized
        vector<int>front2(2,0); 
          vector<int>front1(2,0);
        vector<int>curr(2,0);

        for(int i=n-1;i>=0;i--){
            
            curr[1]=max(-prices[i]+front1[0],0+front1[1]);
        
         curr[0]=max(prices[i]+front2[1],0+front1[0]);       
            
            front2=front1;
            front1=curr;
        }
        return front1[1];

    }
};