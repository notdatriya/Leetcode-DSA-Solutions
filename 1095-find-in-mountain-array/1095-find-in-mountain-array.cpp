/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(int n,MountainArray &mountainArr){
        int l=0;int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return l;
    }
    
    int solve(int l,int h,bool left,int target,int n,MountainArray &mountainArr){
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(left){
                if(mountainArr.get(mid)==target){
                return mid;
                }
            
            else if(mountainArr.get(mid)<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            }
            
            else{
                 if(mountainArr.get(mid)==target){
                return mid;
                }
            
            else if(mountainArr.get(mid)<target){
                    h=mid-1;
                }
            else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peak=bs(n,mountainArr);
        int idx1=solve(0,peak,true,target,n,mountainArr);
        if(idx1!=-1)return idx1;
        int idx2=solve(peak+1,n-1,false,target,n,mountainArr);
        if(idx2!=-1)return idx2;
         return -1;
        
    }
};