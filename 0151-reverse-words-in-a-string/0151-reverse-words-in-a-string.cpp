class Solution {
public:
    string reverseWords(string s) {
//         stack<string>st;
//          int n=s.length();                          
//         string ans;
//         string str;
//         // int i=0;
//         for(int i=0;i<n;i++){
//             if(s[i]!=' '){  
//             str+=s[i];
//             }
//             if((s[i+1]==' '&& !str.empty()) || (i==n-1 && s[i]!=' ')){
//                 st.push(str);
//                 cout<<st.top();
//                 str="";
//             }
             
//         }
        
//         while(st.size()>1){
//             ans+=st.top();
//             ans+=" ";
//             st.pop();
//         }
//         ans+=st.top();
//         st.pop();
        
//         return ans;
        
        
        
        //m-2 two pointer approach
        
        int n = s.size();
        string ans = "";
            int i=n-1;
        while(i>=0) {

            if (s[i] != ' ') {

                int end = i;
                while (i >= 0 && s[i] != ' ') {
                    i--;
                }
                int start = i + 1;

                if (ans == "")
                    ans = ans + s.substr(start, end - start + 1);
                else
                    ans = ans + " " + s.substr(start, end - start + 1);
            }
            
            i--;
        }

        return ans;
        
        
        
    }
};