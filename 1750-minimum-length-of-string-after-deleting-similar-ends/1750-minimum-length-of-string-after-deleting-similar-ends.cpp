class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int l=0;
        int h=n-1;
        
        while(l<h){
            
            if(s[l]==s[h]){
                int val=s[l];
                while(l<=h && s[l]==val){
                    l++;
                }
                while(l<=h && s[h]==val){
                    h--;
                }
            }
            else{
                return (h-l+1);
                break;
            }
        }
        if(l==h)return 1;
        return 0;
    }
};