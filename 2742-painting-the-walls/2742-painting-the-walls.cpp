class Solution {
public:
     int solve(vector<int>& cost, vector<int>& time, int i, int bank,vector<vector<int>> &dp){
        if(bank <= 0){
            return 0;
        }
        if(i >= cost.size()){
            return 1e9;   
        }
        if(dp[i][bank] != -1){
            return dp[i][bank];
        }
        else {
            // take or not take options
            int nottake = solve(cost, time, i+1, bank,dp);
            int take = cost[i] + solve(cost, time, i+1, bank -  time[i] -1,dp); 
            return dp[i][bank] = min(nottake, take);      
        }
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(cost, time, 0, time.size(),dp);
    }
};