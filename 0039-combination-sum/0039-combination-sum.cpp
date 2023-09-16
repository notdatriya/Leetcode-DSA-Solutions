class Solution {
public:
    
//     void subset(int index,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds){
//          if(index==candidates.size()){
//              if(target==0){
//                  ans.push_back(ds);
//              }
//              return;
//          }
    
//       if(candidates[index]<=target){
//           ds.push_back(candidates[index]);
//           subset(index,target-candidates[index],candidates,ans,ds);
//           ds.pop_back();
//       }
//           subset(index+1,target,candidates,ans,ds);
        
//     }
    
    void solve(int i,int target,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans,int sum){
        if(i==candidates.size()){
            if(sum==target){
                ans.push_back(ds);
            }
            return;
        }
        
        if(sum+candidates[i]<=target){
            ds.push_back(candidates[i]);
            solve(i,target,candidates,ds,ans,sum+candidates[i]);
            ds.pop_back();
        }
        
        solve(i+1,target,candidates,ds,ans,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,candidates,ds,ans,0);
        return ans;
    }
};