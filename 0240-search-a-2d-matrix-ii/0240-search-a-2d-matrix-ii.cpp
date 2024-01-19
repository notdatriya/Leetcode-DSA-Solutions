class Solution {
public:
    
//      bool bs(vector<int>&arr,int n,int target){
//         int low=0;
//         int high=n-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
            
//             if(arr[mid]==target)return true;
//             else if(arr[mid]>target){
//                 high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return false;
//     }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        // for(int i=0;i<n;i++){
        //     if(bs(matrix[i],m,target)==true)return true;
        // }
        // return false;
        
        
        //m-2 most optimal
          if (matrix.empty() || matrix[0].empty()) {
        return false; // Empty matrix
          }
        int row=0;
        int col=m-1;
        
        while(row<n && col>=0){
            if(matrix[row][col]==target)return true;
            
            else if(matrix[row][col]<target){
                row++;
            }
            else col--;
        }
        return false;
    }
};