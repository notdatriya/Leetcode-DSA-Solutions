class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        map<int,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int count=0;
        for(auto i:g){
            for(auto j :s){
                if(j>=i && mpp[j]>0){
                    count++;
                    mpp[j]--;
                    break;
                }
            }
        }
        return count;
    }
};