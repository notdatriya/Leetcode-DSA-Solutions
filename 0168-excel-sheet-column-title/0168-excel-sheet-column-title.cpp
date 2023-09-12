class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n=columnNumber;
        string ans="";
        char c ='A' + (n-1)%26;
        while(n){
        char c ='A' + (n-1)%26;
            ans=c+ans;
            n=(n-1)/26;
        }
        return ans;
    }
};