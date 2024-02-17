class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
//         int i=0;
//         int sum=0;
//         int minisum=INT_MAX;
//         int n=cardPoints.size();
//         int tsum=0;
        
//         for(int j=0;j<n;j++){
//             sum+=cardPoints[j];
        
            
//             if(j-i+1>n-k){
//                 sum-=cardPoints[i];
//                 i++;
//             }
//              if(j-i+1==n-k){
//                 minisum=min(minisum,sum);
//             }
            
//             tsum+=cardPoints[j];
//         }
//         cout<<minisum<<" "<<tsum<<endl;
//         return tsum-minisum;
        
        
        //m-2- second different approach, both are equally good
        
         int sum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        
        int maxSum = sum;
        for (int i = k - 1, j = n - 1; i >= 0; i--, j--) {
            sum -= cardPoints[i];
            sum += cardPoints[j];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};