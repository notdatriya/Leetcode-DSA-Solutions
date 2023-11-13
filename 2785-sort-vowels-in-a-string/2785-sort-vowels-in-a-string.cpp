class Solution {
public:
    bool isvowel(char x){
        string match="aeiouAEIOU";
       for(auto i:match){
           if(x==i)return true;
       }
        return false;
    }
    string sortVowels(string s) {
        string arr="";
        for(auto i:s){
            if(isvowel(i)){
                arr.push_back(i);
            }
        }
        
        sort(arr.begin(),arr.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(isvowel(s[i])){
                // ans+=arr[j];
                s[i]=arr[j];
                j++;
            }
            // else{
            //     ans+=s[i];
            // }
        }
        
        
        return s;
    }
};