class Solution {
public:
    int solve(int i,int target){
        if(i==1){
            if(target==i){
                return i;
            }
            if(target==0){
                return 1;
            }
            return 1;
        }
        
        int notpick=1* solve(i-1,target);
        int pick=1;
        if(i<=target){
            pick=i*solve(i,target-i);
        }
        return max(pick,notpick);
    }
    int integerBreak(int n) {
        return solve(n-1,n);
    }
};