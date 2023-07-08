class Solution {
public:
    
    int minlen(vector<string>&strs){
        int len=strs[0].length();
        for(int i=1;i<strs.size();i++){
            if(strs[i].length()<len){
                len=strs[i].length();
            }
        }
        return len;
    }
    string longestCommonPrefix(vector<string>& strs) {
    
        string str="";
        int len=minlen(strs);
        for(int i=0;i<len;i++){
            char c=strs[0][i];
       for(int j=1;j<strs.size();j++){
           
           if(strs[j][i]!=c){
               return str;
           }
          
           
       }
            str+=c; 
        }
        

        return str;
        
        
    }
};