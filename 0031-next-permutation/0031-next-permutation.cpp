class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //2154300 - we will find breakpoint 1 as there is someone greater than 1 on the //right, so isi ko replace karenge, then iterate from the back,find element which is just //greater than this 1, aur breakpoint ke aage ka array hamesha last se increasing hota hai..to
       // swap karne ke baad reverse kar denge baaki ka array to get the next permutation
        int n=nums.size();
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){;
                break;
            }
        }
        
        if(i<0){
             reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int j=n-1;j>i;j--){
            if(nums[j]>nums[i]){
                swap(nums[j],nums[i]);
                break;
            }
        }
        
          reverse(nums.begin()+i+1,nums.end());
        
    }
};