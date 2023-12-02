class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        for(auto word:words){
           string temp=chars;
            bool valid=true;
            for(char c: word){
                auto it=find(temp.begin(),temp.end(),c);
                if(it!=temp.end()){
                    temp.erase(it);
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