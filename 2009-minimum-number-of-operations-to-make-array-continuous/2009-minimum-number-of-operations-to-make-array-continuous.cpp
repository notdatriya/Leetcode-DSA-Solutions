class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        set<int>arr(nums.begin(),nums.end());
        vector<int>newnums;
        for(int it:arr){
            newnums.push_back(it);
        }
        
        for(int i=0;i<newnums.size();i++){
            int left=newnums[i];
            //right-left=n-1
            //right=n+left-1
            int right=n+left-1;
            int j=upper_bound(newnums.begin(),newnums.end(),right)-newnums.begin();
            int count=j-i;
            ans=min(ans,n-count);
        }
        return ans;
    }
};