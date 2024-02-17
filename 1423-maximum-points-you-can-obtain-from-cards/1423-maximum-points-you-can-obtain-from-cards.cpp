class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int i=0;
        int sum=0;
        int minisum=INT_MAX;
        int n=cardPoints.size();
        int tsum=0;
        
        for(int j=0;j<n;j++){
            sum+=cardPoints[j];
        
            
            if(j-i+1>n-k){
                sum-=cardPoints[i];
                i++;
            }
             if(j-i+1==n-k){
                minisum=min(minisum,sum);
            }
            
            tsum+=cardPoints[j];
        }
        cout<<minisum<<" "<<tsum<<endl;
        return tsum-minisum;
    }
};