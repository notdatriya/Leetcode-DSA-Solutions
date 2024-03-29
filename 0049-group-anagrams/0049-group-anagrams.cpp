class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<vector<int>,vector<string>>mpp;
//         for(auto w:strs){
//             vector<int>freq(26,0);
//             for(char c:w){
//                 freq[c-'a']++;
//             }
//             mpp[freq].push_back(w);
            
//         }
        
//         vector<vector<string>>ans;
//         for(auto k=mpp.begin();k!=mpp.end();k++){
//             ans.push_back(k->second);
//         }
//         return ans;
        
        
        map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            mpp[word].push_back(strs[i]);
        }
        
        for(auto k=mpp.begin();k!=mpp.end();k++){
            ans.push_back(k->second);
        }
        return ans;
       
    }
};