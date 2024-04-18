/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
//     int solve(int start,int end,vector<vector<int>>&dp){
//         if (start > end) return -1;
//         if(start==end)return start;
        
//         if(dp[start][end]!=-1)return dp[start][end];
        
//         for(int i=start;i<=end;i++){
//             if(guess(i)==0){
//                 return dp[start][end]=i;
//             }
//             else if(guess(i)==1){
//                 int ans=solve(i+1,end,dp);
//                 if(ans!=-1)return dp[start][end]=ans;
//             }
//             else{
//                 int ans=solve(start,i-1,dp);
//                 if(ans!=-1)return dp[start][end]=ans;
//             }
//         }
//         return -1;
//     }
    int guessNumber(int n) {
        
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(1,n,dp);
        
        int l=1,r=n;
        int mid;
        while(r>=l)
        {
            mid=l+(r-l)/2;
            if(guess(mid)==-1)
                r=mid-1;
            if(guess(mid)==1)
                l=mid+1;
            if(guess(mid)==0)
                break;
        }
        return mid;
        
    }
};