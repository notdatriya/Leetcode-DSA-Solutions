class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        
        int i=0;
        int n=fruits.size();
        int maxcount=0;
        map<int,int>basket;
        for(int j=0;j<n;j++){
        basket[fruits[j]]++;
            
            while(basket.size()>2){
                int count=basket[fruits[i]];
                if(count==1){
                    basket.erase(fruits[i]);
                }
                else{
                    basket[fruits[i]]--;
                }
                i++;
            }
            
            maxcount=max(maxcount,j-i+1);
        }
        return maxcount;
    }
};