class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()==true){
                    return false;
                }
                    char c=st.top();
                st.pop();
                    if( (c=='(' &&s[i]==')') || (c=='[' && s[i]==']') || (c=='{'&&s[i]=='}')){
                        
                    
                    }
                    else{
                        return false;
                    }   
            }
        }
        
        if(st.empty()==true){
            return true;
        }
        else{
            return false;
        }
    }
};