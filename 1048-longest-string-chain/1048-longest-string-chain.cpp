class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
   bool ispred(string &word1, string &word2) {
    if (word1.size() != word2.size() + 1)
        return false;  

    int i = 0;
    int j = 0;

    while (i < word1.size()) {
        if (word1[i] != word2[j]) {
           
            i++;
        } else {
            
            i++;
            j++;
        }
    }

   
    if(i==word1.size() && j==word2.size())return true;
       return false;
}

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        int maxi=1;
        int lastidx=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(ispred(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
        
       
    }
};