class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         unordered_set<char>st;
//         int n= s.length();
//         if(n==0){
//             return 0;
//         }
//         int count=0;
//             int i=0;
//             for(int j=0;j<n;j++){
//                 if(st.find(s[j])!=st.end()){
//                     while(l<r && st.find(s[j])!=st.end()){
//                         set.erase(s[l]);
//                         l++;
//                     }
//                 }
                
//                 st.insert[s[j]];
//                 count=max(count,j-i+1);
//             }
         
            
        
//         return count;, so that we ca directly jump insted of l++ everytime
        //time -O(n) space-O(n)
        
        unordered_map<char,int>mpp;
        int n=s.length();
        int l=0;int r=0;
        int length=0;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                
                if(mpp[s[r]]>=l){
                l=mpp[s[r]]+1;
                }
            }
            length=max(length,r-l+1);
            mpp[s[r]]=r;
            r++;
        }
        return length;
        
        //optimal - using a map
    }
};