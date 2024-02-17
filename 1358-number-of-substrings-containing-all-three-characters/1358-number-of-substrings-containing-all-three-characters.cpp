class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n=s.size();
        
        int i=0;
        unordered_map<char,int>mpp;
        int count=0;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            
            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                count+=(n-1)-j+1;
                mpp[s[i]]--;
                i++;
            }
        }
        return count;
        
    }
};