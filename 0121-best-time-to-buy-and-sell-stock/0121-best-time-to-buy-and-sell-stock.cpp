class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min=prices[0];
        int diff=0;
        int maxp=0;
        for(int i=1;i<n;i++){
            diff=prices[i]-min;
            maxp=max(maxp,diff);
             if(prices[i]<min){
                min=prices[i];
            }
        }
        return maxp;
    }
};