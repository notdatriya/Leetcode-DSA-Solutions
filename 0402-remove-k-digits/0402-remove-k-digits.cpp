class Solution {
public:
    
    string removeKdigits(string num, int k) {
        
       if (k >= num.size()) return "0";
        int n = num.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        if (st.empty()) return "0";

        string ans;
        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        
        return ans.empty() ? "0" : ans;
    }
};