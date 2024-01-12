class Solution {
public:
    
    int solve(int mid, vector<int>&bloomDay,int k){
        long long count=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]>mid){
                ans+=(count/k);
                count=0;
                continue;
            }
            else{
                count+=1;
            }
        }
        ans += count/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        
        long long val= (long long )k* (long long)m;
        if(val>n)return -1;
        
          int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto i:bloomDay){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        
        int low=mini;
        int high=maxi;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
              if(solve(mid,bloomDay,k)>=m){
                // ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        return low;
    }
};