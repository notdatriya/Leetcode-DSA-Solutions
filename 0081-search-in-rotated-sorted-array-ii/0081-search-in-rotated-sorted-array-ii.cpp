class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        int n=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==k)return true;
            else if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                low=low+1;
                high=high-1;
            }
            
            else if(arr[low]<=arr[mid]){
                if(k>=arr[low] && k<=arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(k>=arr[mid] && k<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};