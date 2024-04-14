class Solution {
public:
    int numberOfSubstrings(string s) {
        
//         int n=s.size();
        
//         int i=0;
//         unordered_map<char,int>mpp;
//         int count=0;
//         for(int j=0;j<n;j++){
//             mpp[s[j]]++;
            
//             while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
//                 count+=(n-1)-j+1;
//                 mpp[s[i]]--;
//                 i++;
//             }
//         }
//         return count;
        
        
        //m-2 considering substrings ending with characters
        
        int n=s.size();
        int lastseen[3]={-1,-1,-1};
        int count=0;
        
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            
            if(lastseen[0]!=-1 && lastseen[0]!=-1 && lastseen[0]!=-1){
                count+=(1+ min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
        }
        
        return count;
        
    }
};