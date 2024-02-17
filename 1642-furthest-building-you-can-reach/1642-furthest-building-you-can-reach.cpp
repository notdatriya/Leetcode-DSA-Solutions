class Solution {
public:
//     int solve(int idx,vector<int>&heights,int b,int l,vector<vector<vector<int>>>&dp){
//                 int n=heights.size();

//         if(idx==n-1){
//             return idx;
//         }
//          if(dp[idx][b][l]!=-1)return dp[idx][b][l];
        
//         int diff=heights[idx+1]-heights[idx];
        
//         if(diff>0){
//             int op1=0;
//             int op2=0;
//             if(b>=diff){
//                 op1=solve(idx+1,heights,b-diff,l,dp);
//             }
//             if(l>0){
//                 op2=solve(idx+1,heights,b,l-1,dp);
//             }
//         return dp[idx][b][l]=max(idx, max(op1, op2));
//         }
//         else{
//             return dp[idx][b][l]=solve(idx+1,heights,b,l,dp);
//         }
//     }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // int n=heights.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1)));
        // return solve(0,heights,bricks,ladders,dp);
        
        
        //this dp approach will not work as it will require 3d array, so it will take lot of space
        
        
        //greedy approach
        
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=heights.size();
        for(int i=0;i<n-1;i++){
            int diff=heights[i+1]-heights[i];
            
            if(diff>0){
                if(ladders>pq.size()){
                    pq.push(diff);
                }
                else{
                    if(pq.empty() || pq.top()>diff){
                        bricks-=diff;
                    }
                    else{
                        int num=pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks-=num;
                        
                    }
                    if(bricks<0){
                            return i;
                        }
                }
            }
        }
        return n-1;
    }
};