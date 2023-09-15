#define m 1000000007
class Solution {
public:
    
    long long solve(long long x,long long y){
        if(y==0)return 1;
        long long ans=solve(x,y/2);
        ans*=ans;
        ans=ans%m;
        if(y%2==1)ans*=x;
        ans%=m;
        return ans;
       
    }
    int countGoodNumbers(long long n) {
       long long odd=n/2;
        long long even=n/2+n%2;
        return (solve(5,even)*solve(4,odd))%m;
    }
};