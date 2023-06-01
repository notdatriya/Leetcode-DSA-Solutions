class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>ans;
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                 }
//             }
//         }
        
//         return ans;
        int n=nums.size();
        vector<int>ans;
        map<int ,int>mpp;
        for(int i=0;i<n;i++){
            int more=target- nums[i];
            if(mpp.find(more)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[more]);
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return {-1};
    }
};