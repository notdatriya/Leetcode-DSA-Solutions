
class Solution {
public:
   
//     long long createhash(string s,int n){
//         long long result=0;
//         for(int i=0;i<n;i++){
//             result+=(long long)(s[i]*(long long)pow(3,i));
//         }
//         return result;
        
//     }
    
//     long long recalhash(string str,int oldidx,int newidx,long long oldhash,int patlen){
//         long long newhash=oldhash-str[oldidx];
//         newhash/=3;
//         newhash+=(long long)(str[newidx]*(long long)(pow(3,patlen-1)));
//         return newhash;
//     }
//     bool checkequal(string str1,string str2,int start1,int end1,int start2,int end2){
//        if(end1-start1!=end2-start2){
//            return false;
//        }
//         while(start1<=end1 && start2<=end2){
//             if(str1[start1]!=str2[start2]){
//                 return false;
//             }
//             start1++;
//             start2++;
//         }
//         return true;
//     }
    
//     bool subs(string source,string target){
//         long long pathash=createhash(target,target.length());
//         long long strhash=createhash(source,target.length());
        
//         for(int i=0;i<=source.length()-target.length();i++){
//             if(pathash==strhash && checkequal(source,target,i,i+target.length()-1,0,target.length()-1)){
//                 return true;
//             }
//             if(i<source.length()-target.length()){
//                 strhash=recalhash(source,i,i+target.length(),strhash,target.length());
//             }
//         }
//         return false;
//     }
    
        
  bool check(string &a, string &b)
    {
        int m=a.size();
        int n=b.size();
        
        for(int i=0;i<=m-n;i++)
        {
            int j;
            for(j=0;j<n;j++){
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==n)
                return true;
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
//         int m=a.size();
//         int n=b.size();
//         int count=1;
//         string source=a;
//         while(a.length()<b.length()){
//             count++;
//             source+=a;
//         }
        
//         // if(source==b){
//         //     return count;
//         // }
        
//         if(subs(source,b))return count;
//         source+=a;
//         if(subs(source,b))return count+1;
//         return -1;
        
        int count=1;
        string source=a;
        while(a.size() < b.size()){
            a += source;
            count++;
        }
        
        if(check(a,b)){
            return count;
        }
        a += source;
        if(check(a,b)){
            return count+1;
        }
        return -1;
    }
};