class Solution {
public:
    
    bool ispal(string s){
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(auto i:words){
            if(ispal(i)){
                return i;
            }
        }
        return "";
    }
};