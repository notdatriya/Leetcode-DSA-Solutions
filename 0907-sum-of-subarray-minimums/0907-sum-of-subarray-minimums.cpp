#define mod 1000000007

class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        stack<pair<int,int>>sleft,sright;
        
        for(int i=0;i<n;i++){
            int count=1;
            while(!sleft.empty() && sleft.top().first>arr[i]){
                count+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i],count});
            left[i]=count;
        }
        
        for(int i=n-1;i>=0;i--){
            int count=1;
            while(!sright.empty() && sright.top().first>=arr[i]){
                count+=sright.top().second;
                sright.pop();
            }
            sright.push({arr[i],count});
            right[i]=count;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+((long long)arr[i]*left[i]*right[i])%mod)%mod;
        }
        return ans;
        
    }
};
