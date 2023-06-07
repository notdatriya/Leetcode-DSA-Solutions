class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        auto it=st.begin();
        for(int i=0;i<st.size();i++){
            nums[i]=*it;
            it++;
        }
        return st.size();
    }
};