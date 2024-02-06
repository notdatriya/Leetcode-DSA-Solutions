class Solution {
public:
    int trap(vector<int>& height) {
        
        
        //Brute force
        
//         int n=height.size();
//         int watertrapped=0;
//         for(int i=0;i<n;i++){
//             int j=i;    
//     int leftmax = 0, rightmax = 0;
//             while(j>=0){
//                 leftmax=max(leftmax,height[j]);
//                 j--;
//             }
            
//             j=i;
            
//             while(j<n){
//                 rightmax=max(rightmax,height[j]);
//                 j++;
//             }
            
//             watertrapped+=min(leftmax,rightmax)-height[i];
//         }
//         return watertrapped;
        
        
        //better solution
        
//         int n=height.size();
//         vector<int>prefixmax(n);
//         vector<int>suffixmax(n);
        
//         prefixmax[0]=height[0];
        
//         for(int i=1;i<n;i++){
//             prefixmax[i]=max(prefixmax[i-1],height[i]);
//         }
        
//         suffixmax[n-1]=height[n-1];
        
//         for(int i=n-2;i>=0;i--){
//             suffixmax[i]=max(suffixmax[i+1],height[i]);
//         }
//         int waterTrapped = 0;
//   for (int i = 0; i < n; i++) {
//     waterTrapped += min(prefixmax[i], suffixmax[i]) - height[i];
//   }
//   return waterTrapped;
        
        
        //optimal solution
        
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxleft=0,maxright=0;
        int ans=0;
        
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft){
                    maxleft=height[left];
                }
                else{
                    ans+=maxleft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxright){
                    maxright=height[right];
                }
                else{
                    ans+=maxright-height[right];
                }
                right--;
            }
        }
        return ans;
        
        
        
    }
};