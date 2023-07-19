class Solution {
public:
    int binarySearch(vector<int>&nums,int &target){
        int l=0;
        int h=nums.size()-1;
   
    while(l<=h){
         int mid=(l+h)/2;
     if(nums[mid]==target)return mid;
    else if (nums[mid] > target) {
      h=mid-1;
    }
    else {
        l=mid+1;
    }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int ans=binarySearch(nums,target);
        return ans;
    }
};