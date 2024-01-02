class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<vector<int>>ans;
        
        while(true){
            vector<int>level;
        for(auto i:mpp){
            if(i.second>0){
                level.push_back(i.first);
                mpp[i.first]--;
            }
        }
        if(level.size()==0)break;
        ans.push_back(level);
        }
        
        return ans;
    }
};