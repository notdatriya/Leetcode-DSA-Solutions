class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int >mpp;
        int n=nums.size();
        if(n==0){return 0;}
        for(int i=0;i<n;i++){
            mpp.insert(nums[i]);
        }
        
        int longest=1;
      
         for(auto it:mpp){
             
          
            if(mpp.find(it-1) ==mpp.end()){
                int count=1;
               int x=it;
                while(mpp.find(x+1)!=mpp.end()){
                    x=x+1;
                    count++;
                }
                longest=max(count,longest);
            }
              
        }
        
        
        return longest;
        
        
        
    }
};