class Solution {
public:
 
     int solve(int idx,vector<string> &ans,vector<string> &arr)
    {
        if(idx>=arr.size()) return 0;

        ans.push_back(arr[idx]);
        unordered_map<char,int> m;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++) m[ans[i][j]]++;
        }

        bool flag=1;
        for(auto val:m)
        {
            if(val.second>1)
            {
                flag=0;
                break;
            }
        }
        
        int take=0,nottake=0;
        if(flag) take=arr[idx].size()+solve(idx+1,ans,arr);
        ans.pop_back();
        nottake=solve(idx+1,ans,arr);

        return max(take,nottake);

    }
    int maxLength(vector<string>& arr) {
        vector<string>ans;
        return solve(0,ans,arr);
    }
};