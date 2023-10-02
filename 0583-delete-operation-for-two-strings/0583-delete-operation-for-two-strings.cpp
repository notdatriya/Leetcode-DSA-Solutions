class Solution {
public:
     int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
                vector<int> prev(m+1,0),curr(m+1,0);
        
        for(int idx2=0;idx2<=m;idx2++) prev[idx2]=0;
        
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                
            if(text1[idx1-1]==text2[idx2-1]){
                
         curr[idx2]=1+prev[idx2-1] ; //charater match
        }
                
        else {
            curr[idx2]= 0+ max(prev[idx2],curr[idx2-1]);
            }
                
            }
        prev=curr;
        }
        
        return prev[m];
        
}
    
    
    int minDistance(string word1, string word2) {
        int lcs=longestCommonSubsequence(word1,word2);
        int l1=word1.size()-lcs;
        int l2=word2.size()-lcs;
        return l1+l2;
    }
};