class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t){
        //     return true;
        // }
        // return false;
        
        vector<int>freq(26,0);
        
        for(char i:s){
            freq[i- 'a']++;
        }
        
        for(char i: t){
            freq[i - 'a']--;
        }
        
        for(int i:freq){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};