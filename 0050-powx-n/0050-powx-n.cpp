class Solution {
public:
    
    double solve(double x,long long n1,double ans){
        if(n1<=0)return ans;
        if(n1%2==0) return solve(x*x,n1/2,ans);
        else{
            return solve(x,n1-1,ans*x);
        }
    }
    double myPow(double x, int n) {
//         double mul=1;
//         long long n1=n;//this is done because, if n<0 then on making it positive it will overflow, check range of int
//         if(n1<0){
//             n1=-1*n1;
//         }
       
//       while(n1>0){
//           if(n1%2==0){
//               x=x*x;
//               n1=n1/2;
//           }
//           else{
//               mul=mul*x;
//               n1=n1-1;
//           }
//       }
//         if(n<0){
//             mul=double(1.0)/double(mul);
//         }        
//         return mul;
       
        
        //recursive
        long long n1=n;
        if(n1<0)n1*=-1;
        double ans=1;
        ans= solve(x,n1,ans);
        if(n<0)return double(1.0)/double(ans);
        return ans;
        
    }
};