class Solution {
public:
    
    void swapgreater(vector<int>&nums1,vector<int>&nums2,int left,int right){
        if(nums1[left]>nums2[right]){
            swap(nums1[left],nums2[right]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//      int left=m-1;
//         int right=0;
        
//         while(left>0 && right <n){
//             if(nums1[left]<nums2[right]){
//                 swap(nums1[left--],nums2[right++]);
//             }
//         }
        
//         sort(nums1.begin(),nums1.begin()+m);
//         sort(nums2.begin(),nums2.begin()+n);
        
//         for(int i=0;i<n;i++){
//             nums1[m+i]=nums2[i];
//         }
        
        //gap method
        
//         int length=m+n;
//         int gap=length/2+length%2;
//         while (gap>0){
//             int left=0;
//             int right=left+gap;
//             while(left<=right){
//                 if(left<m && right>=m){
//                     swapgreater(nums1,nums2,left,right-m);
//                 }
                
//                 else if(left >=m && right>=m){
//                     swapgreater(nums2,nums2,left-m,right-m);
//                 }
//                 else{
//                     swapgreater(nums1,nums1,left,right);
//                 }
//                 left++;right++;
//             }
//             if(gap==1){
//                 break;
//             }
//             gap=gap/2+gap%2;
//         }
        
//         for(int i=0;i<n;i++){
//             nums1[m+i]=nums2[i];
//         }
        
         for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        
        sort(nums1.begin(),nums1.end());
    }
};