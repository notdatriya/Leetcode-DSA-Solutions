class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        int n=s.size();
        int count=0;
        int maxcount=0;
        int maxf=0;
        map<char,int>mpp;
        int i=0;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            
            maxf=max(maxf,mpp[s[j]]);
            while((j-i+1)-maxf>k){
                mpp[s[i]]--;
                i++;
            }
            maxcount=max(maxcount,j-i+1);
        }
        return maxcount;
    }
};