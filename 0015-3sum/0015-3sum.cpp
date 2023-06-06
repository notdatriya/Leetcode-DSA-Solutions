class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int l1=0;l1<n;l1++){
             if(l1>0 && nums[l1]==nums[l1-1]) continue;
            int l2=l1+1;
            int h=n-1;
            while(l2<h){
              
                int sum=nums[l1]+nums[l2]+nums[h];
                if(sum<0){
                    l2++;
                }
                else if(sum>0){
                    h--;
                }
                else{
                    vector<int>temp={nums[l1],nums[l2],nums[h]};
                    ans.push_back(temp);
                    l2++;
                    h--;
                    while(l2<h && nums[l2]==nums[l2-1]) l2++;
                    while(l2<h && nums[h]==nums[h+1]) h--;
                }
               
            }
        }
        
        return ans;
    }
};