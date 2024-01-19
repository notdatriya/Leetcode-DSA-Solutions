class Solution {
public:
    
  int findidx(vector<vector<int>>&mat,int n,int m,int row){
      int maxidx=-1;
      int maxi=-1;
      for(int i=0;i<m;i++){
          if(maxi<mat[row][i]){
              maxi=mat[row][i];
              maxidx=i;
          }
      }
      return maxidx;
  }
    
 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxidx= findidx(mat,n,m,mid);
            
            int top=mid-1>=0?mat[mid-1][maxidx]:-1;
            int bottom=mid+1<n?mat[mid+1][maxidx]:-1;
            
            if(mat[mid][maxidx]>top && mat[mid][maxidx]>bottom){
                return {mid,maxidx};
            }
            
            else if(mat[mid][maxidx]<top){
                high=mid-1;
                
            }
            
            else{
                low=mid+1;
            }
    }
        return {-1,-1};
    }
};