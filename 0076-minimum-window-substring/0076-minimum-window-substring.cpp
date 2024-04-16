class Solution {
public:
    string minWindow(string s, string t) {
        
// if (s.empty() || t.empty()) {
//             return "";
//         }        
//         int i=0;
        
//         unordered_map<char,int>smap;
//         unordered_map<char,int>tmap;
        
//         int left = 0;
//         int right = 0;
       

//         int anslength = INT_MAX;

//         for (char c : t) {
//             tmap[c]++;
//         }
        
//          int have = 0;
//         int need = tmap.size();
//         for (int j = 0; j < s.length(); j++) {
//             char c = s[j];
//             smap[c]++;

//             if (tmap.find(c) != tmap.end() && smap[c] == tmap[c]) {
//                 have++;
//             }

//             while (have == need) {
//                 if (j - i + 1 < anslength) {
//                     anslength = j - i + 1;
//                     left = i;
//                     right = j;
//                 }

//                 smap[s[i]]--;
//                 if (tmap.find(s[i]) != tmap.end() && smap[s[i]] < tmap[s[i]]) {
//                     have--;
//                 }
//                 i++;
//             }
//         }

//         if (anslength == INT_MAX) return "";
//         else {
//             return s.substr(left, anslength);
//         }
        
        
        
        
        
        
        //brute
        
//         int n=s.length();
//         int m=t.length();
//         int mini=INT_MAX;
//         int startIndex=-1;
//         int count=0;
        
//         for(int i=0;i<n;i++){
//             map<char,int>hash;
//             for(int j=0;j<m;j++){
//                 hash[t[j]]++;
//             }
            
//             for(int j=0;j<n;j++){
//                 if(hash[s[j]]>0)count=count+1;
//                 hash[s[j]]--;
//                 if(count==m){
//                     if((j-i+1)<mini){
//                         mini=j-i+1;
//                         startIndex=i;
//                         break;
//                     }
//                 }
//             }
//         }
        
//         return s.substr(startIndex,mini);
        
        
        //optimal - sliding window
        
        int l=0;
        int r=0;
        map<char,int>mpp;
        int n=s.length();
        int m=t.length();
        int mini=INT_MAX;
        int start=-1;
        int count=0;
        
        
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        
        while(r<n){
            
            if(mpp[s[r]]>0){
                count=count+1;
            }
            
               mpp[s[r]]--;
                
                while(count==m){
                    if((r-l+1)<mini){
                        mini=r-l+1;
                        start=l;
                    }
                    
                    mpp[s[l]]++;
                    if(mpp[s[l]]>0){
                        count=count-1;
                        
                    }
                    l++;
                }
                r++;
            
        }
        
        return start==-1?"":s.substr(start,mini);
        
    }
};