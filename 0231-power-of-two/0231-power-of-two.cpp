class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int a=log2(n);
        double b=log2(n);
        return a==b;
    }
};