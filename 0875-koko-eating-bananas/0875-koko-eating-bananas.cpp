class Solution {
public:
    long long solve(int mid,vector<int>&piles,int h){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0){
            count+=(piles[i]/mid) ;
            }
            else{
                count+=(piles[i]/mid) +1;
            }
        }
        return count;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(auto i:piles){
            maxi=max(maxi,i);
        }
        int low=1;
        int high=maxi;
        int ans=1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(solve(mid,piles,h)<=h){
                ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};