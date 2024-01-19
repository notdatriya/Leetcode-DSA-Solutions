class Solution {
public:
    
    bool bs(vector<int>&arr,int n,int target){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==target)return true;
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        int low=0;
        int high=matrix.size()-1;
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(m==0 || n==0)return false;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
             if (n == 1) {
                // Handle single-element row separately
                if (matrix[mid][0] == target) return true;
                else if (matrix[mid][0] > target) high = mid - 1;
                else low = mid + 1;
            }
            
            else if(n > 0 && target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                return bs(matrix[mid],n,target);
            }
            
            else if(n > 0 && target>matrix[mid][n-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
        
    }
};