class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<=0)return false;
        // int a=log2(n);
        // double b=log2(n);
        // return a==b;
        
        if(n<=0)return false;
        if((n& (n-1))==0)return true;
        return false;
    }
};