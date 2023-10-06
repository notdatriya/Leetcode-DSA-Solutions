class Solution {
public:
    int solve(int i,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        // buy means if I can buy a stock on a particular day
        
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit= max(-prices[i] +solve(i+1,0,prices,n,dp),0+ solve(i+1,1,prices,n,dp));
        }
        else{
            profit=max(prices[i]+solve(i+1,1,prices,n,dp),0+solve(i+1,0,prices,n,dp));
        }
        return dp[i][buy]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // return solve(0,1,prices,n,dp);
        
        //tabulation
        
//         dp[n][0]=0;
//         dp[n][1]=0;
        
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0 ;buy<=1;buy++){
//                         int profit=0;
//                 if(buy){
//             profit= max(-prices[i] +dp[i+1][0],0+ dp[i+1][1]);
//         }
//         else{
//             profit=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
//         }
//             dp[i][buy]=profit;
//             }
//         }
//         return dp[0][1];
        
        //space optimized
        
        vector<int>ahead(2,0);
        vector<int>curr(2,0);
                ahead[0]=0;
                ahead[1]=0;

        
        for(int i=n-1;i>=0;i--){
            for(int buy=0 ;buy<=1;buy++){
                        int profit=0;
                if(buy){
            profit= max(-prices[i] +ahead[0],0+ ahead[1]);
        }
        else{
            profit=max(prices[i]+ahead[1],0+ahead[0]);
        }
            curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};