class Solution {
public:
    bool static comp(pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mpp;
        for(auto it: s){
            mpp[it]++;
        }
        
        vector<pair<char,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),comp);
        string ans="";
        
        for(auto it:v){
            for(int i=0;i<it.second;i++){
                ans+=it.first;
            }
        }
        return ans;
    }
};