class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        int n=s.length();
        string ans(n,'0');
        
        if(count==1){
            ans[n-1]='1';
        }
        else{
            for(int i=0;i<count-1;i++){
                ans[i]='1';
            }
            ans[n-1]='1';
        }
        return ans;
    }
};