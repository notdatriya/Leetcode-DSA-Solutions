class Solution {
public:
    
    int solve(vector<int>&arr, map<pair<int,int>,int>&maxi,int start,int end, vector<vector<int>>&dp){
        
        if(start==end)return 0;  //we only have one node, no scope for creating non leaf node;
        
        if(dp[start][end]!=-1)return dp[start][end];
        
        int ans=INT_MAX;
        
        for(int i=start;i<end;i++){
            ans=min(ans,maxi[{start,i}]*maxi[{i+1,end}]+solve(arr,maxi,start,i,dp)+solve(arr,maxi,i+1,end,dp));
        }
        return dp[start][end]=ans;
    }
    
    
    int mctFromLeafValues(vector<int>& arr) {
        
        map<pair<int,int>,int>maxi;
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        
        return solve(arr,maxi,0,arr.size()-1,dp);
    }
};