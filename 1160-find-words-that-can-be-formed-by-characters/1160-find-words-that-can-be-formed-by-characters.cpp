class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
//         int ans=0;
//         for(auto word:words){
//            string temp=chars;
//             bool valid=true;
//             for(char c: word){
//                 auto it=find(temp.begin(),temp.end(),c);
//                 if(it!=temp.end()){
//                     temp.erase(it);
//                 }
//                 else{
//                     valid=false;
//                     break;
//                 }
//             }
//             if(valid){
//                 ans+=word.length();
//             }
            
//         }
//         return ans;
        
        
        //map
        unordered_map<char,int>mpp;
        for(char c:chars){
            mpp[c]++;
        }
        
        int ans=0;
        for(auto word:words){
            unordered_map<char,int>temp=mpp;
            bool valid=true;
            for(char c:word){
                if(temp.find(c)!=temp.end() && temp[c] > 0){
                    temp[c]--;
                }
                else{
                    valid=false;
                    break;
                }
            }
            if(valid){
                ans+=word.length();
            }
        }
        return ans;
      
    }
};