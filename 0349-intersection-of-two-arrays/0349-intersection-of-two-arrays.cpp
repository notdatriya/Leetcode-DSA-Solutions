class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // set<int>s1(nums1.begin(),nums1.end());
        // set<int>s2(nums2.begin(),nums2.end());
        
        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]++;
        }
        
        for(int i=0;i<nums1.size();i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                ans.push_back(nums1[i]);
                mpp.erase(nums1[i]);
            }
        }
        return ans;
        
    }
};