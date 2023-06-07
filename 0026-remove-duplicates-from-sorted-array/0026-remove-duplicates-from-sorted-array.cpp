class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>st;
        // for(int i=0;i<nums.size();i++){
        //     st.insert(nums[i]);
        // }
        // auto it=st.begin();
        // for(int i=0;i<st.size();i++){
        //     nums[i]=*it;
        //     it++;
        // }
        // return st.size();
        
        //optimal-two pointer
        
        int i=0;
       for(int j=0;j<nums.size();j++){
           if(nums[j]!=nums[i]){
               nums[i+1]=nums[j];
               i++;
           }
       }
        
        return i+1;
    }
};