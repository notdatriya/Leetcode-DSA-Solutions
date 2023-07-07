class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
         int n=s.length();                          
        string ans;
        string str;
        // int i=0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){  
            str+=s[i];
            }
            if((s[i+1]==' '&& !str.empty()) || (i==n-1 && s[i]!=' ')){
                st.push(str);
                cout<<st.top();
                str="";
            }
             
        }
        
        while(st.size()>1){
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans+=st.top();
        st.pop();
        
        return ans;
        
    }
};