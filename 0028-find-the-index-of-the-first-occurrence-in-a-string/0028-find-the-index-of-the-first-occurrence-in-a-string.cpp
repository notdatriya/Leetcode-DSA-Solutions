class Solution {
public:
    
    void findlps(string pattern,int m,int lps[]){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<m){
		if(pattern[i]==pattern[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}
    int strStr(string haystack, string needle) {
//         cout<<haystack[13]<<endl;
//         for(int i=0;i<haystack.size();i++){
//             int j;
//             for(j=0;j<needle.size();j++){
//                 if(haystack[i+j]!=needle[j]){
//                     break;
//                 }
//             }
//             if(j==needle.size()){
                
//             return i;
//             }
//         }
//         return -1;
        
        
        int m=needle.length();
	int n=haystack.length();

	
	int lps[m];
	vector<int>ans;
	findlps(needle,m,lps);
        int i=0;
	int j=0;
	while(i<n){
		if(haystack[i]==needle[j]){
			i++;
			j++;
		}
		if(j==m){
			 ans.push_back(i-j);
			 j=lps[j-1];
            // return i-j;
		}
		else if(i<n && needle[j]!=haystack[i]){
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}
        if(ans.empty()){
            return -1;
        }
	 return ans[0];
    
        
    }
};