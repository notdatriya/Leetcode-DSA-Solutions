class Solution {
public:
    void solve(int i,int target,int k,vector<int>&arr,vector<int>ds,vector<vector<int>>&ans){
        if(i==arr.size()){
            if(target==0 && ds.size()==k){
                ans.push_back(ds);
            }
            return;
        }
        
        
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            solve(i+1,target-arr[i],k,arr,ds,ans);
            ds.pop_back();
        }
        
        solve(i+1,target,k,arr,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9,0);
        for(int i=0;i<arr.size();i++){
            arr[i]=i+1;
        }
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,n,k,arr,ds,ans);
        return ans;
    }
};