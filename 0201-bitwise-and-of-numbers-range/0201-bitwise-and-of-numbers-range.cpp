class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        
        //this will give TLE
//         int ans=left;
        
//         for(int i=left;i<=right;i++){
//             ans=ans& i;
//         }
//         return ans;
        
        
        //optimised approach, worst case tc-O(32) and space O(1)
        
        while(right>left){
            right=right &(right-1);
        }
        return right;
        
    }
};