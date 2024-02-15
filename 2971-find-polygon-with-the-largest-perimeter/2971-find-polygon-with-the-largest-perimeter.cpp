class Solution {
public:
    // int ispossible(int peri,vector<int>&nums){
    //      long long previousElementsSum = 0;
    // long long ans = -1;
    // for (int i = 0; i < nums.size(); i++) {
    //     if (i >= 2 && nums[i] < previousElementsSum) {
    //         ans = nums[i] + previousElementsSum;
    //     }
    //     previousElementsSum += nums[i];
    // }
    // if(ans==-1)return 0;
    //     return 1;
    // }

    long long largestPerimeter(vector<int>& nums) {
        
        
        //could not complete this approach
//         int n=nums.size();
//         if(n<3)return -1;
//         sort(nums.begin(),nums.end());
//         int low=nums[0]+nums[1]+nums[2];
//         int high = accumulate(nums.begin(), nums.end(),  0);
        
//         while(low<=high){
//             int mid=low+(high-low)/2;
            
//             if(ispossible(mid,nums)==1){
//                 low=mid+1;
//             }
//             else{
//                 high=mid-1;
//             }
//         }
//         return (high>=0)? high:-1;
        
        
        
        //m-2
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=0;
        for(auto i:nums){
            sum+=i;
        }
        
        for(int i=n-1;i>=2;i--){
            if(nums[i]<sum-nums[i]){
                return sum;
            }
            else{
                sum=sum-nums[i];
            }
        }
        return -1;
    
    }
};