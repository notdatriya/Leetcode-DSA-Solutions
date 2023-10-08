class Solution {
public:
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=nums1[i]*nums2[j] + solve(i-1,j-1,nums1,nums2,dp);
        int op2=solve(i-1,j,nums1,nums2,dp);
        int op3=solve(i,j-1,nums1,nums2,dp);
        return dp[i][j]=max(op1,max(op2,op3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        int max1=INT_MIN, min1=INT_MAX;
        int max2=INT_MIN, min2=INT_MAX;

        for(int i=0;i<n;i++)
        {
            max1 = max(max1,nums1[i]);
            min1 = min(min1,nums1[i]);
        }
        for(int i=0;i<m;i++)
        {
            max2 = max(max2,nums2[i]);
            min2 = min(min2,nums2[i]);
        }

        //all elements are negative 
        if((max1<0 && min2>0) || (max2<0 && min1>0))
        {
            return max(max1*min2,min1*max2);
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,nums1,nums2,dp);
    }
};