class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
//         int n=s.size();
//         int count=0;
//         int maxcount=0;
//         int maxf=0;
//         map<char,int>mpp;
//         int i=0;
//         for(int j=0;j<n;j++){
//             mpp[s[j]]++;
            
//             maxf=max(maxf,mpp[s[j]]);  //dont use this, find maxf by traversing complete mpp
//             while((j-i+1)-maxf>k){
//                 mpp[s[i]]--;
//                 i++;
//             }
//             maxcount=max(maxcount,j-i+1);
//         }
//         return maxcount;
        
        
        
        
//         int maxlen=0;
//         int n=s.length();
        
//         for(int i=0;i<n;i++){
//             int hash[26]={0};
//             int maxf=0;
//             for(int j=i;j<n;j++){
//                 hash[s[j]-'A']++;
                
//                 maxf=max(maxf,hash[s[j]-'A']);
//                 int changes=(j-i+1)-maxf;
                
//                 if(changes<=k){
//                     maxlen=max(maxlen,j-i+1);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxlen;
        
        
        
        //optimal
        
        int l=0;
        int r=0;
        int maxlen=0;
        int maxf=0;
        int n=s.length();
        int hash[26]={0};
        
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            
            while(((r-l+1)-maxf)>k){
                hash[s[l]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++){
                    maxf=max(maxf,hash[i]);
                }
                l++;
            }
            
            if(((r-l+1)-maxf)<=k){
                maxlen=max(maxlen,(r-l+1));
            }
            r++;
        }
        return maxlen;
        
        
    }
};