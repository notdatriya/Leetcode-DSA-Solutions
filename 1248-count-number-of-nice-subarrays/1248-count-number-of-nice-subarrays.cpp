class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                count+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
        
    }
};