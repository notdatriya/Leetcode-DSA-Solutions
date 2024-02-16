class Solution {
public:
    
    // bool comp(pair<int,int> &i1,pair<int,int> &i2){
    //     return i1.second<i2.second;
    // }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int>mpp;
        if(k>arr.size())return -1;
        for(auto i:arr){
            mpp[i]++;
        }
        
        vector<int>freq;
        
        for(auto i:mpp){
            freq.push_back(i.second);
        }
        
        sort(freq.begin(),freq.end());
        
        
        int i=0;
        int count=0;
        while(k>0 && i<freq.size()){
            if(freq[i]>k){
                break;
            }
            else{
                k-=freq[i];
                count++;
                
            }
            i++;
        }
        return freq.size()-count;
    
    }
};