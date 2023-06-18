class Solution {
public:
    
    void subset(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
      ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
                 subset(i+1,nums,ds,ans);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //as in ex pehle 1 se saare subsets ,phir 1ko pop karke 2 se saare subsets
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        subset(0,nums,ds,ans);
        return ans;
    }
};