class Solution {
public:
    bool halvesAreAlike(string s) {
        string str = "aeiouAEIOU";
        if(s.length()%2)return false;
        int count1=0;
        int count2=0;

        int mid=s.length()/2;
        for(int i=0;i<s.length()/2;i++){
            if(str.find(s[i]) != string::npos){
                count1++;
            }
            if(str.find(s[i+mid]) != string::npos){
                count2++;
            }
        }
        
        // for(int i=s.length()/2;i<s.length();i++){
        //     if(str.find(s[i]) != string::npos){
        //         count2++;
        //     }
        // }
        
        if(count1==count2)return true;
        else return false;
    }
};