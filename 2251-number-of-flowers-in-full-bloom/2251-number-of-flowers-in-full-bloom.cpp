class Solution {
public:
    static bool comp( vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
//         map<const int,const int>mpp;
// //         for(auto it:flowers){
// //             mpp[it->first]=it.second;
// //         }
        
//         for(int i=0;i<flowers.size();i++){
//             for(int j=0;j<flowers[0].size();j++){
//                 mpp[flowers[i]]=flowers[j];
//             }
//         }
        
//         for(int i=0;i<people.size();i++){
//             int count=0;
//             for(int j=0;j<=i;j++){
//                 if(mpp.find(j)!=mpp.end() && mpp[j]>=i){
//                     count++;
//                 }
//             }
//         }
//         return count;
        
        
        //binary serach
      vector<int>start;
        vector<int>finish;
        for(auto it:flowers){
            start.push_back(it[0]);
            finish.push_back(it[1]);
        }
        
        sort(start.begin(),start.end());
        sort(finish.begin(),finish.end());
        
        vector<int>ans;
        for(int i:people){
            int startt=upper_bound(start.begin(),start.end(),i)-start.begin(); //start time jinka <=i hai
            int end=lower_bound(finish.begin(),finish.end(),i)-finish.begin(); //finish time jinka <i hai
            ans.push_back(startt-end);

        }
        return ans;
        
    }
};