class Solution {
public:
    int solve(int i,int transaction,vector<int>&prices,int n,vector<vector<int>>&dp,int k){
        if(i==n || transaction==2*k)return 0;
        if(dp[i][transaction]!=-1)return dp[i][transaction];
        int profit=0;
        if(transaction%2==0){
            //buy
        profit= max(-prices[i] +solve(i+1,transaction+1,prices,n,dp,k),0+ solve(i+1,transaction,prices,n,dp,k));

        }
        else{
    profit=max(prices[i]+solve(i+1,transaction+1,prices,n,dp,k),0+solve(i+1,transaction,prices,n,dp,k));
         
        }
        return dp[i][transaction]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        // return solve(0,0,prices,n,dp,k);
        
        //tabulation
        
//         for(int i=n-1;i>=0;i--){
//             for(int transaction=2*k-1;transaction>=0;transaction--){
//                 int profit=0;
//         if(transaction%2==0){
//             //buy
//         profit= max(-prices[i] +dp[i+1][transaction+1],0+ dp[i+1][transaction]);

//         }
//         else{
//     profit=max(prices[i]+dp[i+1][transaction+1],0+dp[i+1][transaction]);
         
//         }
//          dp[i][transaction]=profit;
//             }
//         }
//         return dp[0][0];
        
        //space
        vector<int>after(2*k+1,0);
        vector<int>curr(2*k+1,0);
        for(int i=n-1;i>=0;i--){
            for(int transaction=2*k-1;transaction>=0;transaction--){
                int profit=0;
        if(transaction%2==0){
            //buy
        profit= max(-prices[i] +after[transaction+1],0+ after[transaction]);

        }
        else{
    profit=max(prices[i]+after[transaction+1],0+after[transaction]);
         
        }
         curr[transaction]=profit;
            }
            after=curr;
        }
        return after[0];
        
    }
};