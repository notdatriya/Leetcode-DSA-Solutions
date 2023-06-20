class Solution {
public:
    
//     void p(int index,vector<int>&nums,vector<vector<int>>&ans){
//         if(index==nums.size()){
//             ans.push_back(nums);
//             return;
//         }
        
//         for(int i=index;i<nums.size();i++){
//             swap(nums[i],nums[index]);
//             p(index+1,nums,ans);
//             swap(nums[i],nums[index]);
//         }
//     }
    
    //mehtod-2
    void pp(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                ds.push_back(nums[i]);
                freq[i]=1;
                pp(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>>ans;
        // p(0,nums,ans);
        // return ans;
        
        //method-2 -extra space complexity
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)freq[i]=0;
        pp(ds,nums,ans,freq);
        return ans;
    }
};