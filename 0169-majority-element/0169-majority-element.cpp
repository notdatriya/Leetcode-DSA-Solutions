class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n=nums.size();
        // we can take a map
        //map<int,int>mpp;
        // int ans=-1;
        // for(int i=0;i<n;i++){
//             mpp[nums[i]]++;
//         //    
//         // }
    
//         for(auto it:mpp){
//             if(it.second>floor(n/2)){
//                 return it.first;
//             }
//         }
//         return -1;
        
//         sort(nums.begin(),nums.end());
//         int curr=1;
//         int maxc=0;
//         int maxnum=INT_MIN;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1]){
//                 curr++;
//                 maxc=max(curr,maxc);
//                 maxnum=nums[i];
//             }
//             else{
//                 curr=1;
//             }
            
//         }
//         if(maxc>floor(nums.size()/2)){
//             return maxnum;
//         }
        
//         return -1;
        
        
        //Moose voting algo
        
        int n=nums.size();
        int element;
        int count=0;
        int elecount=0;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                element=nums[i];
                
            }
            else if(nums[i]==element){
                count++;
            }
            else{
                count--;
            }
        }
        
        //this step is not required as given in qs that there mustexist a majority element
        for(int i=0;i<n;i++){
            if(nums[i]==element){
                elecount++;
            }
        }
        if(elecount>floor(n/2)){
            return element;
        }
        return -1;
    }
};