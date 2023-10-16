class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 1; i <= rowIndex; i++){
            vector<int> temp(i + 1, 1);
            for(int j = 1; j < i; j++) temp[j] = ans[i-1][j] + ans[i-1][j-1];
            ans.push_back(temp);
        }
        return ans[rowIndex];
    }
};