class Solution {
public:
    
    int kDistinctChars(int k, vector<int>&str)
{
    // Write your code here
    int n=str.size();
    if(k>=n)return n;
    int i=0;
    unordered_map<int,int>mpp;
    int count=0;
    // int maxlength=0;
    for(int j=0;j<n;j++){
        
            mpp[str[j]]++;
        

        while(mpp.size()>k){
                mpp[str[i]]--;
            if(mpp[str[i]]==0)mpp.erase(str[i]);
            i++;
            
        }

        // maxlength=max(maxlength,j-i+1);
        count+=j-i+1;

    }
    return count;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kDistinctChars(k,nums)-kDistinctChars(k-1,nums);
    }
};