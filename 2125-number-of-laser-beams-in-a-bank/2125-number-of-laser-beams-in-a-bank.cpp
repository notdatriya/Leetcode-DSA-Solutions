class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
//         map<int,int>mpp;
        
//         int i=0;
//         for(auto s:bank){
//             for(char c:s){
//                 if(c=='1'){
//                     mpp[i]++;
//                 }
//             }
//             i++;
//         }
        
//         int ans=0;
//         for(auto it:mpp){
//             for(int i=it.first-1;i>=0;i--){
//                 int p=mpp[i]*mpp[it.first];
//                 if(p!=0){
//                     ans+=p;
//                     break;
//                 }
//             }
//         }
//         return ans;
        
        
        
        
        //m-2
        int prevcount=0;
        int ans=0;
        for(string s:bank){
            int currcount=0;
            for(char c:s){
                if(c=='1')currcount++;
            }
            ans+=currcount*prevcount;
            if(currcount==0)prevcount=prevcount;
            else prevcount=currcount;
        }
        return ans;
    }
};