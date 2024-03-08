class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        map<int,int>mpp;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            maxi=max(maxi,mpp[nums[i]]);
        }
        
        int count=0;
        for(auto i:nums){
            if(mpp[i]==maxi){
                count++;
            }
        }
        return count;
    }
};