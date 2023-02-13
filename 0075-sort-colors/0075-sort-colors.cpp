class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int a=count(nums.begin(),nums.end(),0);
        int b=count(nums.begin(),nums.end(),1);
        int c=count(nums.begin(),nums.end(),2);

        for(int i=0;i<a;i++){
            nums[i]=0;
        }
        
        for(int j=a;j<a+b;j++){
            nums[j]=1;
        }
        
        for(int z=a+b;z<a+b+c;z++){
            nums[z]=2;
        }

        for(int k=0;k<n;k++){
            cout<<nums[k]<<" ";
        }
    }
};