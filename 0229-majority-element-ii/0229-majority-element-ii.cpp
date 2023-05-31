class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//       map<int,int>mpp;
//         vector<int>ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mpp[nums[i]]++;
//         }
        
//         for(auto it: mpp){
//             if(it.second>floor(n/3)){
//                 ans.push_back(it.first);
//             }        
//         }
//         return ans;
        
        //Optimal - Moose voting algo
        
        vector<int>ans;
        int el1=INT_MIN;
        int el2=INT_MIN;
        int c1,c2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=el2){
                c1=1;
                el1=nums[i];
            }
            else if(c2==0 && nums[i]!=el1){
                c2=1;
                el2=nums[i];
            }
            
            else if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                c1++;
            }
             if(nums[i]==el2){
                c2++;
            }
        }
        int min=int(n/3)+1;
        if(c1>=min){
            ans.push_back(el1);
        }
        
        if(c2>=min){
            ans.push_back(el2);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};