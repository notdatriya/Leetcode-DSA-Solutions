class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // vector<int>ans;
        // for(auto i:nums){
        //     ans.push_back(i*i);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        
        int n=nums.size();
        int i=0;
        int j=n-1;
        int idx=n-1;
        vector<int>ans(n);
        
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ans[idx]=nums[i]*nums[i];
                idx--;
                i++;
            }
            else{
                ans[idx]=nums[j]*nums[j];
                idx--;
                j--;
            }
        }
        return ans;
        
    }
};