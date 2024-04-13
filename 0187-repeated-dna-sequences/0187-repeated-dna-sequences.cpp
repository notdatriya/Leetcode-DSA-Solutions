class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map<string,int>mpp;
        
        int l=0;
        int r=0;
        vector<string>ans;
        int len=0;
        int n=s.length();
        
        while(r<n){
            len++;
            
            if(len==10){
                if(mpp[s.substr(l,len)]==1){
                    ans.push_back(s.substr(l,len));
                    mpp[s.substr(l,len)]++;
                    l++;
                    len--;
                }
                else{
                    mpp[s.substr(l,len)]++;
                    l++;
                    len--;
                }
            }
            r++;
        
        }
        return ans;
    }
};