class Solution {
public:
    
    void solve(int open,int close,int n,string ds,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(ds);
            return;
        }
        
        if(open<n){
            ds+='(';
            solve(open+1,close,n,ds,ans);
            ds.pop_back();
        }
        if(close<open){
            ds+=')';
            solve(open,close+1,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string ds="";
        vector<string>ans;
        solve(0,0,n,ds,ans);
        return ans;
    }
};