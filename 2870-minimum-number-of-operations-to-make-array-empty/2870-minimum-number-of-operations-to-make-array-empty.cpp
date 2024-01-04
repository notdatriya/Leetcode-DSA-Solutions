class Solution {
public:
    
    
    int minOperations(vector<int>& nums) {
        map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        int count=0;
        for(auto i:mpp){
            if(i.second==1)return -1;
            if(i.second%3==0)count+=i.second/3;
            else{
                count+=(i.second/3)+1;
            }
        }
        return count;
        
        
    }
};