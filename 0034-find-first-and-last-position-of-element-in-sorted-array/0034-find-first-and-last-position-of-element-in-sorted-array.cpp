class Solution {
public:
    long long solve1(vector<int>&nums,int target,bool findleft){
        int l=0;
        int h=nums.size()-1;
        int index=-1;
        while(l<=h){
        long long mid=l +(h-l)/2;
        
        if(nums[mid]==target){
            index=mid;
            if(findleft){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
       
        else if(nums[mid]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
        return index;
    }
    
   
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left=solve1(nums,target,true);
        int right=solve1(nums,target,false);
        if(left<=right)return {left,right};
        else return {-1,-1};
    }
};