class Solution {
public:
    
    void solve(int idx,map<int,vector<char>>mpp,string ds,vector<string>&ans,string &digits){
        if(idx>=digits.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<mpp[digits[idx]-'0'].size();i++){
            ds.push_back(mpp[digits[idx]-'0'][i]);
            solve(idx+1,mpp,ds,ans,digits);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,vector<char>>mpp;
        mpp[2]={'a','b','c'};
        mpp[3]={'d','e','f'};
        mpp[4]={'g','h','i'};
        mpp[5]={'j','k','l'};
        mpp[6]={'m','n','o'};
        mpp[7]={'p','q','r','s'};
        mpp[8]={'t','u','v'};
        mpp[9]={'w','x','y','z'};
        
        vector<string>ans;
        string ds="";
        if(digits.size()==0)return ans;
        solve(0,mpp,ds,ans,digits);
        return ans;

    }
};