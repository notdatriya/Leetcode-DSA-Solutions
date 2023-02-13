class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int maxsum=nums[0];
        int n=nums.size();
        for(int i=0;i<=n-1;i++){
            currSum=currSum+nums[i];
            maxsum=max(currSum,maxsum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxsum;
    }
};