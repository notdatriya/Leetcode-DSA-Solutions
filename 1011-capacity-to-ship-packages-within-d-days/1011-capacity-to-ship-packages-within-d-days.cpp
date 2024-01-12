class Solution {
public:
    
    long long solve(int mid,vector<int>&weights,int days){
        long long sum=0;
        long long ans=0;    
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                ans+=ceil((double)sum/(double)mid);  //basically ans+=1
                // ans=ans+1;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
          ans+= ceil((double)sum/(double)mid);
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto i :weights){
            sum+=i;
        }
          int maxi=INT_MIN;
        // int mini=INT_MAX;
        for(auto i:weights){
            // mini=min(mini,i);
             maxi=max(maxi,i);
        }
        
        int low=maxi;
        int high=sum;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(solve(mid,weights,days)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return low;
    }
};