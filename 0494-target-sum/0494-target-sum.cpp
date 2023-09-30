class Solution {
public:
//     int solve(int i,int target,vector<int>&nums){
//         if(i==0){
//            if(target==0 && nums[0]==0)return 2;
//             if(target==0 || nums[i] == target)return 1;
//             return 0;
//         }
        
//         int notpick=solve(i-1,target,nums);
//         int pick=0;
//         if(nums[i]<=target){
//             pick=solve(i-1,target-nums[i],nums);
//         }
//         return pick+notpick;
//     }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        //s1-s2=target   // s2 are subset with minus sign
        //s1+s2=sum;
        if(sum-target<0) return 0;
        if((sum-target)%2)return 0;
            int k=(sum-target)/2;
            // return solve(n-1,target,nums);
        
        
        
        vector<int>prev(k+1,0);
      vector<int>curr(k+1,0);
    if(nums[0]==0){
		prev[0]=2;
	}
	else prev[0]=1;
	if(nums[0]!=0 && nums[0]<=k){
		prev[nums[0]]=1;
	}

		for(int i=1;i<n;i++){
			for(int target=0;target<=k;target++){
				int notpick=prev[target];
				int pick=0;
				if(nums[i]<=target){
					pick=prev[target-nums[i]];
				}
					curr[target]=(pick+notpick);
			}
            prev=curr;
		}
		return prev[k];

        
    }
};